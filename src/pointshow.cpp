#include "pointshow.h"
#include "ui_pointshow.h"


PointShow::PointShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::PointShow)
{
    ui->setupUi(this);
    setWindowTitle(tr("监测点信息"));
    QString str;
    ui->sum->setText(str.setNum(mp1.PointBin.size()));
    int a=0,b=0;
    for(auto it:mp1.PointBin)
    {
        if(it.getStatus()==0) a++;
        else if(it.getStatus()==1||it.getStatus()==1) b++;
    }
    ui->work->setText(str.setNum(a));
    ui->died->setText(str.setNum(b));
    QStringList heads;
    heads<<QStringLiteral("桩号")<<QStringLiteral("坐标")
         <<QStringLiteral("运行状态")<<QStringLiteral("地点");
    ui->tableWidget->setColumnCount(4);
    ui->tableWidget->setHorizontalHeaderLabels(heads);
    ui->tableWidget->setColumnWidth(0,145);
    ui->tableWidget->setColumnWidth(1,150);
    ui->tableWidget->setColumnWidth(2,140);
    ui->tableWidget->setColumnWidth(3,230);
    for(auto it:mp1.PointBin)
    {
        ui->tableWidget->setRowCount(0);
        int row=ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(row+1);

        QTableWidgetItem *tPNum=new QTableWidgetItem;
        QTableWidgetItem *tCoord=new QTableWidgetItem;
        QTableWidgetItem *tStatus=new QTableWidgetItem;
        QTableWidgetItem *tPos=new QTableWidgetItem;

        Coord tcd=it.getCoord();

        double l1=tcd.getLongit();
        double l2=tcd.getLatit();

        QString ll1=QString::number(l1);
        QString ll2=QString::number(l2);

        QString tc=ll1+"E,"+ll2+"S";

        QString sts;
        if(it.getStatus()==0)
            sts="运行中";
        else if(it.getStatus()==1)
            sts="故障";
        else if(it.getStatus()==2)
            sts="停用";

        tPNum->setText(it.getNum());
        tCoord->setText(tc);
        tStatus->setText(sts);
        tPos->setText(it.getLocate());

        ui->tableWidget->setItem(row,0,tPNum);
        ui->tableWidget->setItem(row,1,tCoord);
        ui->tableWidget->setItem(row,2,tStatus);
        ui->tableWidget->setItem(row,3,tPos);

        ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
    }
}

PointShow::~PointShow()
{
    delete ui;
}

void PointShow::show()
{
    for(auto it:mp1.PointBin)
    {
        ui->tableWidget->setRowCount(0);
        int row=ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(row+1);

        QTableWidgetItem *tPNum=new QTableWidgetItem;
        QTableWidgetItem *tCoord=new QTableWidgetItem;
        QTableWidgetItem *tStatus=new QTableWidgetItem;
        QTableWidgetItem *tPos=new QTableWidgetItem;

        Coord tcd=it.getCoord();

        double l1=tcd.getLongit();
        double l2=tcd.getLatit();

        QString ll1=QString::number(l1);
        QString ll2=QString::number(l2);

        QString tc=ll1+"E,"+ll2+"S";

        QString sts;
        if(it.getStatus()==0)
            sts="运行中";
        else if(it.getStatus()==1)
            sts="故障";
        else if(it.getStatus()==2)
            sts="停用";

        tPNum->setText(it.getNum());
        tCoord->setText(tc);
        tStatus->setText(sts);
        tPos->setText(it.getLocate());

        ui->tableWidget->setItem(row,0,tPNum);
        ui->tableWidget->setItem(row,1,tCoord);
        ui->tableWidget->setItem(row,2,tStatus);
        ui->tableWidget->setItem(row,3,tPos);

        ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
    }
}

void PointShow::show1()
{
    for(auto it:mp1.PointBin)
    {
        if(it.getStatus()==0)
        {
            ui->tableWidget->setRowCount(0);
            int row=ui->tableWidget->rowCount();
            ui->tableWidget->setRowCount(row+1);

            QTableWidgetItem *tPNum=new QTableWidgetItem;
            QTableWidgetItem *tCoord=new QTableWidgetItem;
            QTableWidgetItem *tStatus=new QTableWidgetItem;
            QTableWidgetItem *tPos=new QTableWidgetItem;

            Coord tcd=it.getCoord();

            double l1=tcd.getLongit();
            double l2=tcd.getLatit();

            QString ll1=QString::number(l1);
            QString ll2=QString::number(l2);

            QString tc=ll1+"E,"+ll2+"S";

            QString sts;
            if(it.getStatus()==0)
                sts="运行中";
            else if(it.getStatus()==1)
                sts="故障";
            else if(it.getStatus()==2)
                sts="停用";

            tPNum->setText(it.getNum());
            tCoord->setText(tc);
            tStatus->setText(sts);
            tPos->setText(it.getLocate());

            ui->tableWidget->setItem(row,0,tPNum);
            ui->tableWidget->setItem(row,1,tCoord);
            ui->tableWidget->setItem(row,2,tStatus);
            ui->tableWidget->setItem(row,3,tPos);

            ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
        }
    }
}

void PointShow::show2()
{
    for(auto it:mp1.PointBin)
    {
        if(it.getStatus()==1)
        {
            ui->tableWidget->setRowCount(0);
            int row=ui->tableWidget->rowCount();
            ui->tableWidget->setRowCount(row+1);

            QTableWidgetItem *tPNum=new QTableWidgetItem;
            QTableWidgetItem *tCoord=new QTableWidgetItem;
            QTableWidgetItem *tStatus=new QTableWidgetItem;
            QTableWidgetItem *tPos=new QTableWidgetItem;

            Coord tcd=it.getCoord();

            double l1=tcd.getLongit();
            double l2=tcd.getLatit();

            QString ll1=QString::number(l1);
            QString ll2=QString::number(l2);

            QString tc=ll1+"E,"+ll2+"S";

            QString sts;
            if(it.getStatus()==0)
                sts="运行中";
            else if(it.getStatus()==1)
                sts="故障";
            else if(it.getStatus()==2)
                sts="停用";

            tPNum->setText(it.getNum());
            tCoord->setText(tc);
            tStatus->setText(sts);
            tPos->setText(it.getLocate());

            ui->tableWidget->setItem(row,0,tPNum);
            ui->tableWidget->setItem(row,1,tCoord);
            ui->tableWidget->setItem(row,2,tStatus);
            ui->tableWidget->setItem(row,3,tPos);

            ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
            ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
        }
    }
}


void PointShow::on_comboBox_activated(const QString &arg1)
{
    if(arg1=="运行中")
        show1();
    else if(arg1=="已停用")
        show2();
    else if(arg1=="所有")
        show();
}

