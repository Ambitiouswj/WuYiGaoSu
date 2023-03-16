#include "diagram.h"
#include "ui_diagram.h"
#include "testchart.h"
#include <QDateTime>
#include <QDebug>
#include <QMap>
#include <QStandardItem>
diagram::diagram(QWidget *parent) :
    QWidget(parent),
    series(new QPieSeries),
    chart(new QChart),
    chartview(new QChartView(chart,this)),
    ui(new Ui::diagram)
{
    ui->setupUi(this);
    //车牌归属地统计饼状图
    initExcel();
    initUI();
    initData();
    initConnect();
    //超速车辆统计
    widget_car();
}
//读取Excel表格
void diagram::initExcel()
{
    QFile re("pointnum.txt");
    re.open(QIODevice::ReadOnly);
    QByteArray line = re.readLine();
    QString ptnum=line;
    ui->setupUi(this);
    QString filename="D:\\武易高速人车监测系统\\武易高速部分监控数据\\";
    if(ptnum=="K31+950")
        filename+="K31+950-car.xlsx";
    else if(ptnum=="K56+400")
        filename+="K56+400-car.xlsx";
    else if(ptnum=="K96+430")
        filename+="K96+430-car.xlsx";
    myexcel = new QAxObject("Excel.Application");
    myworks=myexcel->querySubObject("WorkBooks");   //获取工作薄
    myworks->dynamicCall("Open(const QString&)",filename);
    //myworks->dynamicCall("Add"); //添加工作薄
    workbook=myexcel->querySubObject("ActiveWorkBook");

    mysheets=workbook->querySubObject("WorkSheets");    //获取电子表格集
    QAxObject *sheet=workbook->querySubObject("Sheets(int)",1);
    QStringList headname;
    QAxObject *range=sheet->querySubObject("UsedRange");

    QVariant var=range->dynamicCall("Value");
    QList<QList<QVariant>> res;//表格
    QVariantList varRows = var.toList();
    const int rowCount = varRows.size();
    QVariantList rowData;
    for(int i=0;i<rowCount;++i)
    {
        rowData = varRows[i].toList();
        res.push_back(rowData);
    }
     int row_count=res.count();
     int column_count=res.at(0).count();
     for(int i=0;i<res.at(0).count();i++)
     {
         headname<<res.at(0).at(i).toString();
     }
     ui->tableWidget->setColumnCount(column_count);
     ui->tableWidget->setRowCount(row_count-2);
    //设置表头
    QTableWidgetItem    *headerItem;
    for (int i=0;i<ui->tableWidget->columnCount();i++)//列编号从0开始
    {
      ui->tableWidget->setColumnWidth(i,150);
      headerItem=new QTableWidgetItem(headname.at(i)); //新建一个QTableWidgetItem， headerText.at(i)获取headerText的i行字符串
      QFont font=headerItem->font();//获取原有字体设置
      font.setPointSize(10);//字体大小
      headerItem->setTextColor(Qt::red);//字体颜色
      headerItem->setFont(font);//设置字体
      ui->tableWidget->setHorizontalHeaderItem(i,headerItem); //设置表头单元格的Item
     }

    QTableWidgetItem *item;
    ui->tableWidget->setColumnWidth(1,200);

    QDateTime m_start=QDateTime::fromString(res.at(2).at(1).toString(),"yyyy-MM-dd hh:mm:ss");
    QDateTime m_end=QDateTime::fromString(res.at(row_count-1).at(1).toString(),"yyyy-MM-dd hh:mm:ss");

    for(int i=2;i<row_count;i++)
    {
       QDateTime t= QDateTime::fromString((res.at(i).at(1)).toString(),"yyyy-MM-dd hh:mm:ss");
        for(int j=0;j<column_count;j++)
        {
            item=new QTableWidgetItem(res.at(i).at(j).toString());
            item->setFlags(Qt::ItemIsEnabled);
            item->setTextAlignment(Qt::AlignHCenter|Qt::AlignVCenter);
            ui->tableWidget->setItem(i-2,j,item);
        }
    }
    ui->tableWidget->setVisible(false);
}
//设置饼状图各项参数
void diagram::initUI()
{
    setWindowTitle("车牌归属地——超速车辆统计");


    //调节饼状图大小
    series->setPieSize(0.85);
    //设置饼状图文字是否可见
    //series->setLabelsVisible(true);
    //chart = new QChart();
    chart->addSeries(series);
    chart->setAnimationOptions(QChart::AllAnimations); // 设置显示时的动画效果
    chart->legend()->setAlignment(Qt::AlignRight); //竖向图例
    chart->setTitle("车牌归属地——饼状图");
    chart->setTitleFont(QFont("微软雅黑",15));

    // 图表主题可选：
    // QChart::ChartThemeLight
    // QChart::ChartThemeBlueCerulean
    // QChart::ChartThemeDark
    // QChart::ChartThemeBrownSand
    // QChart::ChartThemeBlueNcs
    // QChart::ChartThemeHighContrast
    // QChart::ChartThemeBlueIcy
    // QChart::ChartThemeQt
    chart->setTheme(QChart::ChartThemeBlueCerulean);
    chart->legend()->setFont(QFont("Arial",11));
    chartview->setRenderHint(QPainter::Antialiasing); //抗锯齿处理
    chartview->show();
    chartview->setChart(chart);
    ui->verticalLayout->insertWidget(0, chartview);

    QString css = QString("QTableWidget{border:none;border:0px;background-color: rgba(219, 255, 171, 0);}"
                              "QTableWidget::item{background-color: rgba(219, 255, 171, 0);color:#663E00;}"
                              "QTableWidget::item:hover{background-color: rgba(219, 255, 171, 0);color:#DB5D00;}"
                              "QTableWidget::item:selected{background-color: rgba(219, 255, 171, 0);color:#DB5D00;}");
        ui->tableWidget_2->setStyleSheet(css);

}
//处理数据并向饼状图中添加数据
void diagram::initData()
{
    Rowcount = ui->tableWidget->rowCount();
    int row=0;//行
    int col=4;//列  车牌号在第4列
    //统计各地车牌出现的次数
    for(int i=0;i<Rowcount;i++)
    {
        QString str=ui->tableWidget->item(row,col)->text().mid(1,1);
        if(str!='A'&&str!='W'&&str!='O')
            place[str]+=1;
        else
            place["未知"]+=1;
        row++;
    }
    for(auto it = place.begin();it!=place.end();it++)
    {
       it.value()/=Rowcount;//算出各地的比率
    }
//    测试place 容器
//    QMapIterator<QString, double> iterator(place);
//    while (iterator.hasNext())
//    {
//        iterator.next();
//        qDebug()<<iterator.key()<<" "<<iterator.value();
//    }
    for(auto it =place.begin();it!= place.end();it++)
    {
       series->append(it.key(),it.value());
    }
}
//连接鼠标点击
void diagram::initConnect()
{
    connect(series, SIGNAL(clicked(QPieSlice *)), this,SLOT(clickedItem(QPieSlice *)));
}
//鼠标点击各分块功能
void diagram::clickedItem(QPieSlice *slice)
{
    if (!slice->isExploded())
    {
        slice->setExploded();
        slice->setLabelVisible();
        slice->setLabelFont(QFont("微软雅黑",15));
        slice->setPen(QPen(Qt::red, 2));//饼状图各区域的边框颜色以及粗细
    }
    else
    {
        slice->setLabelVisible(false);
        slice->setExploded(false);
        slice->setPen(QPen(Qt::white, 1));
    }
}
//处理Excel表格数据并打印超速车辆
void diagram::widget_car()
{
    //超速车表
    row=0,col=3;
    int cnt=0;
    int list[100];
    for(int i=0;i<Rowcount;i++)
    {
        QString str=ui->tableWidget->item(row,col)->text();
        double data=str.toDouble();
        if(data>120)
        {
            list[cnt]=i;
            cnt++;
        }
        row++;
    }
    ui->tableWidget_2->setColumnCount(5);
    QStringList header;
    header<<"探测器编号"<<"时间"<<"桩号"<<"车速(km/h)"<<"车牌";
    ui->tableWidget_2->setHorizontalHeaderLabels(header);
    ui->tableWidget_2->horizontalHeaderItem(3)->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\车速表.png"));
    ui->tableWidget_2->horizontalHeaderItem(1)->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\时间.png"));
    ui->tableWidget_2->horizontalHeaderItem(0)->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\视频监控.png"));
    ui->tableWidget_2->horizontalHeaderItem(2)->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\路桩.png"));
    ui->tableWidget_2->horizontalHeaderItem(4)->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\车牌.png"));
    ui->tableWidget_2->horizontalHeader()->setStyleSheet("QHeaderView::section{background-color:white;font:11pt '宋体';color: red;};");
    int nCount;
    for(int i=0;i<cnt;i++)
    {
        nCount=ui->tableWidget_2->rowCount();
        ui->tableWidget_2->insertRow(nCount);
        ui->tableWidget_2->setItem(i,0,new QTableWidgetItem(ui->tableWidget->item(list[i],0)->text()));
        ui->tableWidget_2->setItem(i,1,new QTableWidgetItem(ui->tableWidget->item(list[i],1)->text()));
        ui->tableWidget_2->setItem(i,2,new QTableWidgetItem(ui->tableWidget->item(list[i],2)->text()));
        ui->tableWidget_2->setItem(i,3,new QTableWidgetItem(ui->tableWidget->item(list[i],3)->text()));
        ui->tableWidget_2->setItem(i,4,new QTableWidgetItem(ui->tableWidget->item(list[i],4)->text()));
    }
    for(int i=0;i<ui->tableWidget_2->rowCount();i++)
    {
        ui->tableWidget_2->item(i,3)->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\警告.png"));
    }
    ui->tableWidget_2->resizeColumnsToContents();//单元格长度适应内容
    ui->tableWidget_2->setEditTriggers(QAbstractItemView::NoEditTriggers);//设置不可修改单元格内容
    ui->tableWidget_2->setAlternatingRowColors(true);
    Rowcount1=ui->tableWidget_2->rowCount();
}

diagram::~diagram()
{
    delete ui;
}
