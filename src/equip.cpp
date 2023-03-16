#include "equip.h"
#include "Main.h"
#include "mainwindow.h"
#include "equipment.h"
#include "equipment2.h"
#include "equipment3.h"
#include "ui_equip.h"
#include <QDebug>

int N;
Equip::Equip(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Equip)
{

    ui->setupUi(this);
    setWindowTitle(tr("设备运行状态"));
    QFile re("pointnum.txt");
    re.open(QIODevice::ReadOnly);
    QByteArray line = re.readLine();
    QString ptnum=line;
    ui->label_2->setText(ptnum);

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
    ui->label_3->setText(l1);
    ui->label_5->setText(l2);
    ui->label_7->setText(l3);
    QString str=ptnum;
//    QFile file("D:\\武易高速人车监测系统\\txt文件\\123.txt");
//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
//        qDebug()<<"Can't open the file!"<<endl;
//    }
//    while(!file.atEnd()) {
//        QByteArray line = file.readLine();
//        str=line;
//        //qDebug()<< str;
//    }
    if(str=="K31+950")
        N=0;
    else if(str=="K56+400")
        N=1;
    else if(str=="K96+430")
        N=2;
    qDebug()<<N;
    //车流监测器
    ui->label_11->setText(cdset.CDbin[N].Device::getNum());
    QString str1;
    str1=cdset.CDbin[N].getDate().toString("yyyy-MM-dd");
    ui->label_12->setText(str1);
    if(cdset.CDbin[N].getStatus()==0)
       ui->label_13->setText("运行中");
    else if(cdset.CDbin[N].getStatus()==1)
       ui->label_13->setText("设备故障");
    else if(cdset.CDbin[N].getStatus()==2)
       ui->label_13->setText("已停用");
    //人流监测器

    ui->label_17->setText(pdset.PDbin[0].getNum());
    QString str2;
    str2=pdset.PDbin[N].getDate().toString("yyyy-MM-dd");
    ui->label_18->setText(str2);
    if(pdset.PDbin[N].getStatus()==0)
       ui->label_19->setText("运行中");
    else if(pdset.PDbin[N].getStatus()==1)
       ui->label_19->setText("设备故障");
    else if(pdset.PDbin[N].getStatus()==2)
       ui->label_19->setText("已停用");
    //监控探头
    ui->label_23->setText(vdset.VDbin[0].getNum());
    QString str3;
    str3=vdset.VDbin[N].getDate().toString("yyyy-MM-dd");
    ui->label_24->setText(str3);
    if(vdset.VDbin[N].getStatus()==0)
       ui->label_25->setText("运行中");
    else if(vdset.VDbin[N].getStatus()==1)
       ui->label_25->setText("设备故障");
    else if(vdset.VDbin[N].getStatus()==2)
       ui->label_25->setText("已停用");
    setWindowTitle(tr("设备运行状态"));
}

Equip::~Equip()
{
    delete ui;
}

void Equip::GetDate(CarDevice c)
{
        ui->label_11->setText(c.getNum());
        QString str;
        str=c.getDate().toString("yyyy-MM-dd");
        ui->label_12->setText(str);
        if(c.getStatus()==0)
            ui->label_13->setText("运行中");
        else if(c.getStatus()==1)
            ui->label_13->setText("设备故障");
        else if(c.getStatus()==2)
            ui->label_13->setText("已停用");
}

void Equip::GetpDate(PersonDevice p)
{
        ui->label_17->setText(p.getNum());
        QString str2;
        str2=p.getDate().toString("yyyy-MM-dd");
        ui->label_18->setText(str2);
        //ui->label_12->setText(c.getStatus())
        if(p.getStatus()==0)
            ui->label_19->setText("运行中");
        else if(p.getStatus()==1)
            ui->label_19->setText("设备故障");
        else if(p.getStatus()==2)
            ui->label_19->setText("已停用");
}

void Equip::GetvDate(VideoDevice v)
{
        ui->label_23->setText(v.getNum());
        QString str3;
        str3=v.getDate().toString("yyyy-MM-dd");
        ui->label_24->setText(str3);
        if(v.getStatus()==1)
            ui->label_25->setText("运行中");
        else if(v.getStatus()==2)
            ui->label_25->setText("设备故障");
        else if(v.getStatus()==3)
            ui->label_25->setText("已停用");
}

void Equip::setLabel(QString point,QString zuobiao1,QString zuobiao2,QString location)
{
    ui->label_2->setText(point);
    ui->label_3->setText((zuobiao1));
    ui->label_5->setText(zuobiao2);
    ui->label_7->setText(location);
}






void Equip::on_pushButton_5_clicked()
{
    this->close();
}


void Equip::on_pushButton_clicked()
{
    equipment *e1=new equipment(this);
        connect(e1,&equipment::senddata,this,&Equip::GetDate);
        e1->setLine(ui->label_2->text());
        e1->show();
        this->hide();

}


void Equip::on_pushButton_2_clicked()
{
    equipment2 *e2=new equipment2(this);
        connect(e2,&equipment2::senddata,this,&Equip::GetpDate);
        e2->setLine(ui->label_2->text());
        e2->show();
        this->hide();

}


void Equip::on_pushButton_3_clicked()
{
    equipment3 *e3=new equipment3(this);
        connect(e3,&equipment3::senddata,this,&Equip::GetvDate);
        e3->setLine(ui->label_2->text());
        e3->show();
        this->hide();

}

