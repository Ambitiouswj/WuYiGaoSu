#include "chart.h"
#include "ui_chart.h"
#include <QDebug>

Chart::Chart(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Chart)
{
    ui->setupUi(this);
    setWindowTitle(tr("流量曲线图"));
    QFile re("pointnum.txt");
    re.open(QIODevice::ReadOnly);
    QByteArray line = re.readLine();
    QString ptnum=line;
    ui->PointNum->setText(ptnum);

    QString l1,l2,l3;
    for(auto it:mp1.PointBin)
    {
        if(it.getNum()==ptnum)
        {
            Coord tcd=it.getCoord();
            l1=QString::number(tcd.getLongit());
            l2=QString::number(tcd.getLatit());
            l1+=" E";
            l2+=" N";
            l3=it.getLocate();
            break;
        }
    }
    ui->longit->setText(l1);
    ui->latit->setText(l2);
    ui->pos->setText(l3);
}

void Chart::drawCarChart()
{
    QVector<CarRecord> cset;
    if(ui->PointNum->text()=="K31+950")
    {
        cset=crset1.Cbin;
        QString bdt="2021-4-25 9:30";
        QString edt="2021-4-25 15:20";
        ui->begin->setDateTime(QDateTime::fromString(bdt,"yyyy-M-dd h:mm"));
        ui->end->setDateTime(QDateTime::fromString(edt,"yyyy-M-dd h:mm"));
    }
    else if(ui->PointNum->text()=="K56+400")
    {
        cset=crset2.Cbin;
        QString bdt="2021-4-25 15:10";
        QString edt="2021-4-25 21:30";
        ui->begin->setDateTime(QDateTime::fromString(bdt,"yyyy-M-dd h:mm"));
        ui->end->setDateTime(QDateTime::fromString(edt,"yyyy-M-dd h:mm"));
    }
    else if(ui->PointNum->text()=="K96+430")
    {
        cset=crset3.Cbin;
        QString bdt="2021-4-25 0:00";
        QString edt="2021-4-25 9:40";
        ui->begin->setDateTime(QDateTime::fromString(bdt,"yyyy-M-dd h:mm"));
        ui->end->setDateTime(QDateTime::fromString(edt,"yyyy-M-dd h:mm"));
    }

    QDateTime beginT=ui->begin->dateTime();
    QDateTime endT=ui->end->dateTime();

    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    //x轴(时间轴方式)
    QDateTimeAxis * AxisX = new QDateTimeAxis();
    AxisX->setTitleText("时间"); //x轴显示标题
    AxisX->setGridLineVisible(true); //隐藏背景网格X轴框线
    AxisX->setFormat("M-dd hh:mm"); //x轴格式
    AxisX->setLabelsAngle(30); //x轴显示的文字倾斜角度
    AxisX->setTickCount(11); //轴上点的个数
    AxisX->setRange(beginT, endT); //范围

    // y轴
    QValueAxis *AxisY = new QValueAxis();
    AxisY->setTitleText("通过数量"); //y轴显示标题
    AxisY->setRange(0, 40); //范围
    AxisY->setTickCount(11);  //轴上点的个数
    AxisY->setGridLineVisible(true); //隐藏背景网格Y轴框线

    // 图表
    QChart *chart = new QChart();
    chart->setAnimationOptions(QChart::SeriesAnimations); //动画方式

    // 图表视图
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing); //反锯齿绘制
    chartView->chart()->addSeries(mSeries); //添加线段
    chartView->chart()->setTheme(QtCharts::QChart::ChartThemeBlueNcs); //设置主题
    chartView->chart()->setTitle("车流量曲线图"); //设置标题
    chartView->chart()->addAxis(AxisX, Qt::AlignBottom); //设置x轴位置
    chartView->chart()->addAxis(AxisY, Qt::AlignLeft); //设置y轴位置

    mSeries->setPen(QPen(Qt::red, 1, Qt::SolidLine)); //设置线段pen
    mSeries->attachAxis(AxisX); //线段依附的x轴
    mSeries->attachAxis(AxisY);

    CarRecord temp=cset[0];
    int num=1;
    for(int i=1;i<cset.size()&&cset[i].getReTime()>=beginT&&cset[i].getReTime()<=endT;i++)
    {
        if(cset[i].getReTime()==temp.getReTime())
            num++;
        else
        {
            mSeries->append(temp.getReTime().toMSecsSinceEpoch(),num);
            num=0;
            temp=cset[i];
        }
    }

    // 将图表扔进QWidget
    ui->gridLayout->addWidget(chartView);
}

void Chart::drawPersonChart()
{
    QVector<PersonRecord> pset;
    if(ui->PointNum->text()=="K31+950")
    {
        pset=prset1.Pbin;
        QString bdt="2021-4-26 20:30";
        QString edt="2021-4-26 21:00";
        ui->begin->setDateTime(QDateTime::fromString(bdt,"yyyy-M-dd h:mm"));
        ui->end->setDateTime(QDateTime::fromString(edt,"yyyy-M-dd h:mm"));
    }
    else if(ui->PointNum->text()=="K56+400")
    {
        pset=prset2.Pbin;
        QString bdt="2021-4-26 20:30";
        QString edt="2021-4-26 21:00";
        ui->begin->setDateTime(QDateTime::fromString(bdt,"yyyy-M-dd h:mm"));
        ui->end->setDateTime(QDateTime::fromString(edt,"yyyy-M-dd h:mm"));
    }
    else if(ui->PointNum->text()=="K96+430")
    {
        pset=prset3.Pbin;
        QString bdt="2021-4-26 19:30";
        QString edt="2021-4-26 21:00";
        ui->begin->setDateTime(QDateTime::fromString(bdt,"yyyy-M-dd h:mm"));
        ui->end->setDateTime(QDateTime::fromString(edt,"yyyy-M-dd h:mm"));
    }

    QDateTime beginT=ui->begin->dateTime();
    QDateTime endT=ui->end->dateTime();


    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    // x轴(时间轴方式)
    QDateTimeAxis * AxisX = new QDateTimeAxis();
    AxisX->setTitleText("时间");  //x轴显示标题
    AxisX->setGridLineVisible(true); //隐藏背景网格X轴框线
    AxisX->setFormat("M-dd hh:mm"); //x轴格式
    AxisX->setLabelsAngle(30); //x轴显示的文字倾斜角度
    AxisX->setTickCount(11); //轴上点的个数
    AxisX->setRange(beginT, endT); //范围

    // y轴
    QValueAxis *AxisY = new QValueAxis();
    AxisY->setTitleText("通过数量"); //y轴显示标题
    AxisY->setRange(0, 15); //范围
    AxisY->setTickCount(6); //轴上点的个数
    AxisY->setGridLineVisible(true); //隐藏背景网格Y轴框线

    // 图表
    QChart *chart = new QChart();
    chart->setAnimationOptions(QChart::SeriesAnimations); //动画方式

    // 图表视图
    chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing); //反锯齿绘制
    chartView->chart()->addSeries(mSeries); //添加线段
    chartView->chart()->setTheme(QtCharts::QChart::ChartThemeBlueNcs); //设置主题
    chartView->chart()->setTitle("人流量曲线图"); //设置标题
    chartView->chart()->addAxis(AxisX, Qt::AlignBottom); //设置x轴位置
    chartView->chart()->addAxis(AxisY, Qt::AlignLeft); //设置y轴位置

    mSeries->setPen(QPen(Qt::blue, 1, Qt::SolidLine)); //设置线段pen
    mSeries->attachAxis(AxisX); //线段依附的x轴
    mSeries->attachAxis(AxisY);


    PersonRecord temp=pset[0];
    int num=1;
    for(int i=1;i<pset.size()&&pset[i].getReTime()>=beginT&&pset[i].getReTime()<=endT;i++)
    {
        if(pset[i].getReTime()==temp.getReTime())
            num++;
        else
        {
            mSeries->append(temp.getReTime().toMSecsSinceEpoch(),num);
            num=0;
            temp=pset[i];
        }
    }

    // 将图表扔进QWidget
    ui->gridLayout->addWidget(chartView);
}

Chart::~Chart()
{
    delete ui;
}

void Chart::on_comboBox_activated(const QString &arg1)
{
    if(arg1=="车流统计")
        drawCarChart();
    else if(arg1=="人流统计")
        drawPersonChart();
}


void Chart::on_pushButton_5_clicked()
{
    this->close();
}

