#include "widget1.h"
#include "ui_widget1.h"
#include "Main.h"
#include "equip.h"
#include "chart.h"
#include "testchart.h"
#include "mediaplayer.h"

QString numOfPoint;
Widget1::Widget1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget1)
{
    ui->setupUi(this);
    ui->setupUi(this);
    setWindowTitle(tr("武易高速人车监测数据展示系统"));
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
    ui->tableWidget->resizeColumnsToContents();//单元格长度适应内容
    QString bdt="2021-4-25 0:00";
    QString edt="2021-4-27 0:00";
    ui->begin->setDateTime(QDateTime::fromString(bdt,"yyyy-M-dd h:mm"));
    ui->end->setDateTime(QDateTime::fromString(edt,"yyyy-M-dd h:mm"));
    numOfPoint=ui->PointNum->text();
    //QString dt=m1.pointnum;
}

Widget1::~Widget1()
{
    delete ui;
}

void Widget1::CarShow(QVector<CarRecord> &obj,QDateTime begin,QDateTime end)
{
    ui->tableWidget->setRowCount(0);
    //qDebug()<<"1";
    for(auto item:obj)
    {
        //qDebug()<<"5";
        if(item.getReTime()>=begin&&item.getReTime()<=end)
        {

            //qDebug()<<"7";
            int row=ui->tableWidget->rowCount();
            ui->tableWidget->setRowCount(row+1);
            //qDebug()<<row;
            QTableWidgetItem *tDNum=new QTableWidgetItem;
            QTableWidgetItem *tTime=new QTableWidgetItem;
            QTableWidgetItem *tPNum=new QTableWidgetItem;
            QTableWidgetItem *tSpeed=new QTableWidgetItem;
            QTableWidgetItem *tCNum=new QTableWidgetItem;

            QString str;
            tDNum->setText(item.getDeviceNum());
            tTime->setText(item.getReTime().toString("yyyy-M-dd h:mm"));
            tPNum->setText(item.getPointNum());
            tSpeed->setText(str.setNum(item.getSpeed()));
            tCNum->setText(item.getCarNum());

            ui->tableWidget->setItem(row,0,tDNum);
            ui->tableWidget->setItem(row,1,tTime);
            ui->tableWidget->setItem(row,2,tPNum);
            ui->tableWidget->setItem(row,3,tSpeed);
            ui->tableWidget->setItem(row,4,tCNum);

            ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,4)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void Widget1::PersonShow(QVector<PersonRecord> &obj,QDateTime begin,QDateTime end)
{
    ui->tableWidget->setRowCount(0);
    for(auto item:obj)
    {
        if(item.getReTime()>=begin&&item.getReTime()<=end)
        {

            qDebug()<<"7";
            int row=ui->tableWidget->rowCount();
            ui->tableWidget->setRowCount(row+1);
            qDebug()<<row;
            QTableWidgetItem *tDNum=new QTableWidgetItem;
            QTableWidgetItem *tTime=new QTableWidgetItem;
            QTableWidgetItem *tPNum=new QTableWidgetItem;
            QTableWidgetItem *tIMEI=new QTableWidgetItem;

            QString str;
            tDNum->setText(item.getDeviceNum());
            tTime->setText(item.getReTime().toString("yyyy-M-dd h:mm"));
            tPNum->setText(item.getPointNum());
            tIMEI->setText(item.getIMEI());

            ui->tableWidget->setItem(row,0,tDNum);
            ui->tableWidget->setItem(row,1,tTime);
            ui->tableWidget->setItem(row,2,tPNum);
            ui->tableWidget->setItem(row,3,tIMEI);

            ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void Widget1::on_comboBox_activated(const QString &arg1)
{
    QString str=ui->PointNum->text();
    QStringList heads;
    QDateTime begin=ui->begin->dateTime();
    QDateTime end=ui->end->dateTime();
    if(arg1=="车流统计")
    {

        heads<<QStringLiteral("设备编号")<<QStringLiteral("探测时间")
             <<QStringLiteral("桩号")<<QStringLiteral("车速(km/h)")<<QStringLiteral("车牌号");
        ui->tableWidget->setColumnCount(5);
        ui->tableWidget->setHorizontalHeaderLabels(heads);

        ui->tableWidget->setColumnWidth(0,190);
        ui->tableWidget->setColumnWidth(1,160);
        ui->tableWidget->setColumnWidth(2,128);
        ui->tableWidget->setColumnWidth(3,145);
        ui->tableWidget->setColumnWidth(4,188);

        if(numOfPoint=="K31+950")
            CarShow(crset1.Cbin,begin,end);
        if(numOfPoint=="K56+400")
            CarShow(crset2.Cbin,begin,end);
        if(numOfPoint=="K96+430")
            CarShow(crset3.Cbin,begin,end);
    }
    else if(arg1=="人流统计")
    {
        heads<<QStringLiteral("设备编号")<<QStringLiteral("探测时间")
             <<QStringLiteral("桩号")<<QStringLiteral("IMEI");
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->setHorizontalHeaderLabels(heads);

        ui->tableWidget->setColumnWidth(0,212);
        ui->tableWidget->setColumnWidth(1,207);
        ui->tableWidget->setColumnWidth(2,160);
        ui->tableWidget->setColumnWidth(3,240);

        if(numOfPoint=="K31+950")
            PersonShow(prset1.Pbin,begin,end);
        if(numOfPoint=="K56+400")
            PersonShow(prset2.Pbin,begin,end);
        if(numOfPoint=="K96+430")
            PersonShow(prset3.Pbin,begin,end);
    }
}


void Widget1::on_chart_clicked()
{
    Chart *c1=new Chart;
    c1->show();
}


void Widget1::on_data_clicked()
{
    Testchart *t1=new Testchart();
    t1->show();
}


void Widget1::on_video_clicked()
{
    MediaPlayer *mw=new MediaPlayer();
    mw->show();
}


void Widget1::on_equip_clicked()
{
    Equip *e1=new Equip;
    e1->show();
}




void Widget1::on_reset_2_clicked()
{
    QString arg1=ui->comboBox->currentText();
    QString str=ui->PointNum->text();
    QStringList heads;
    QDateTime begin=ui->begin->dateTime();
    QDateTime end=ui->end->dateTime();
    if(arg1=="车流统计")
    {

        heads<<QStringLiteral("设备编号")<<QStringLiteral("探测时间")
             <<QStringLiteral("桩号")<<QStringLiteral("车速(km/h)")<<QStringLiteral("车牌号");
        ui->tableWidget->setColumnCount(5);
        ui->tableWidget->setHorizontalHeaderLabels(heads);

        ui->tableWidget->setColumnWidth(0,190);
        ui->tableWidget->setColumnWidth(1,160);
        ui->tableWidget->setColumnWidth(2,128);
        ui->tableWidget->setColumnWidth(3,145);
        ui->tableWidget->setColumnWidth(4,188);

        if(numOfPoint=="K31+950")
            CarShow(crset1.Cbin,begin,end);
        if(numOfPoint=="K56+400")
            CarShow(crset2.Cbin,begin,end);
        if(numOfPoint=="K96+430")
            CarShow(crset3.Cbin,begin,end);
    }
    else if(arg1=="人流统计")
    {
        heads<<QStringLiteral("设备编号")<<QStringLiteral("探测时间")
             <<QStringLiteral("桩号")<<QStringLiteral("IMEI");
        ui->tableWidget->setColumnCount(4);
        ui->tableWidget->setHorizontalHeaderLabels(heads);

        ui->tableWidget->setColumnWidth(0,212);
        ui->tableWidget->setColumnWidth(1,207);
        ui->tableWidget->setColumnWidth(2,160);
        ui->tableWidget->setColumnWidth(3,240);

        if(numOfPoint=="K31+950")
            PersonShow(prset1.Pbin,begin,end);
        if(numOfPoint=="K56+400")
            PersonShow(prset2.Pbin,begin,end);
        if(numOfPoint=="K96+430")
            PersonShow(prset3.Pbin,begin,end);
    }
}

void Widget1::on_toback_clicked()
{
    this->close();
}

