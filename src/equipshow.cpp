#include "equipshow.h"
#include "ui_equipshow.h"

int s1;
int s2;
int s3;

int p1=0,p2=0,p3=0;
int q1=0,q2=0,q3=0;
int r1=0,r2=0,r3=0;
int sum,ps,qs,rs;
QString str;

EquipShow::EquipShow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EquipShow)
{
    p1=0,p2=0,p3=0;
    q1=0,q2=0,q3=0;
    r1=0,r2=0,r3=0;
    sum=0,ps=0,qs=0;
    s1=cdset.CDbin.size();
    s2=pdset.PDbin.size();
    s3=vdset.VDbin.size();
    ui->setupUi(this);
    setWindowTitle(tr("设备信息"));


    sum=s1+s2+s3;
    ui->sum->setText(str.setNum(sum));

    for(auto it:cdset.CDbin)
    {
        if(it.getStatus()==0) p1++;
        else if(it.getStatus()==1) r1++;
        else q1++;
    }
    for(auto it:pdset.PDbin)
    {
        if(it.getStatus()==0) p2++;
        else if(it.getStatus()==1) r2++;
        else q2++;
    }
    for(auto it:vdset.VDbin)
    {
        if(it.getStatus()==0) p3++;
        else if(it.getStatus()==1) r3++;
        else q3++;
    }

    ps=p1+p2+p3;
    qs=q1+q2+q3;
    rs=r1+r2+r3;
    ui->work->setText(str.setNum(ps));
    ui->died->setText(str.setNum(qs));
    ui->fault->setText(str.setNum(rs));
    QStringList heads;
    heads<<QStringLiteral("类型")<<QStringLiteral("设备编号")<<QStringLiteral("所在监测点")
         <<QStringLiteral("运行状态")<<QStringLiteral("安装日期");
    ui->tableWidget->setColumnCount(5);
    ui->tableWidget->setHorizontalHeaderLabels(heads);

    ui->sum->setText(str.setNum(sum));
    ui->work->setText(str.setNum(ps));
    ui->died->setText(str.setNum(qs));
    ui->fault->setText(str.setNum(rs));
    ui->tableWidget->setColumnWidth(0,38);
    ui->tableWidget->setColumnWidth(1,175);
    ui->tableWidget->setColumnWidth(2,145);
    ui->tableWidget->setColumnWidth(3,130);
    ui->tableWidget->setColumnWidth(4,130);
    allShow();
}

void EquipShow::allShow()
{
    sum=s1+s2+s3;
    ps=p1+p2+p3;
    qs=q1+q2+q3;
    rs=r1+r2+r3;
    ui->sum->setText(str.setNum(sum));
    ui->work->setText(str.setNum(ps));
    ui->died->setText(str.setNum(qs));
    ui->fault->setText(str.setNum(rs));
    ui->tableWidget->setRowCount(0);
    for(auto it:cdset.CDbin)
    {

        int row=ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(row+1);

        QTableWidgetItem *tType=new QTableWidgetItem;
        QTableWidgetItem *tDNum=new QTableWidgetItem;
        QTableWidgetItem *tPNum=new QTableWidgetItem;
        QTableWidgetItem *tStatus=new QTableWidgetItem;
        QTableWidgetItem *tTime=new QTableWidgetItem;
        QString sts;
        if(it.getStatus()==0)
            sts="运行中";
        else if(it.getStatus()==1)
            sts="故障";
        else if(it.getStatus()==2)
            sts="停用";
        tType->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\汽车.png"));
        tDNum->setText(it.getNum());
        tPNum->setText(it.getPointNum());
        tStatus->setText(sts);
        tTime->setText(it.getDate().toString("yyyy/M/d"));
        ui->tableWidget->setItem(row,0,tType);
        ui->tableWidget->setItem(row,1,tDNum);
        ui->tableWidget->setItem(row,2,tPNum);
        ui->tableWidget->setItem(row,3,tStatus);
        ui->tableWidget->setItem(row,4,tTime);
        ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,4)->setTextAlignment(Qt::AlignCenter);
    }
    for(auto it:pdset.PDbin)
    {
        int row=ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(row+1);
        QTableWidgetItem *tType=new QTableWidgetItem;
        QTableWidgetItem *tDNum=new QTableWidgetItem;
        QTableWidgetItem *tPNum=new QTableWidgetItem;
        QTableWidgetItem *tStatus=new QTableWidgetItem;
        QTableWidgetItem *tTime=new QTableWidgetItem;


        QString sts;
        if(it.getStatus()==0)
            sts="运行中";
        else if(it.getStatus()==1)
            sts="故障";
        else if(it.getStatus()==2)
            sts="停用";

        tType->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\个人头像.png"));
        tDNum->setText(it.getNum());
        tPNum->setText(it.getPointNum());
        tStatus->setText(sts);
        tTime->setText(it.getDate().toString("yyyy/M/d"));

        ui->tableWidget->setItem(row,0,tType);
        ui->tableWidget->setItem(row,1,tDNum);
        ui->tableWidget->setItem(row,2,tPNum);
        ui->tableWidget->setItem(row,3,tStatus);
        ui->tableWidget->setItem(row,4,tTime);

        //ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,4)->setTextAlignment(Qt::AlignCenter);
    }
    for(auto it:vdset.VDbin)
    {
        int row=ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(row+1);
        QTableWidgetItem *tType=new QTableWidgetItem;
        QTableWidgetItem *tDNum=new QTableWidgetItem;
        QTableWidgetItem *tPNum=new QTableWidgetItem;
        QTableWidgetItem *tStatus=new QTableWidgetItem;
        QTableWidgetItem *tTime=new QTableWidgetItem;

        QString sts;
        if(it.getStatus()==0)
            sts="运行中";
        else if(it.getStatus()==1)
            sts="故障";
        else if(it.getStatus()==2)
            sts="停用";

        tType->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\摄像头.png"));
        tDNum->setText(it.getNum());
        tPNum->setText(it.getPointNum());
        tStatus->setText(sts);
        tTime->setText(it.getDate().toString("yyyy/M/d"));

        ui->tableWidget->setItem(row,0,tType);
        ui->tableWidget->setItem(row,1,tDNum);
        ui->tableWidget->setItem(row,2,tPNum);
        ui->tableWidget->setItem(row,3,tStatus);
        ui->tableWidget->setItem(row,4,tTime);

        ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,4)->setTextAlignment(Qt::AlignCenter);
    }
}

EquipShow::~EquipShow()
{
    delete ui;
}

void EquipShow::show1()
{
    sum=s1+s2+s3;
    ps=p1+p2+p3;
    qs=q1+q2+q3;
    rs=r1+r2+r3;
    ui->sum->setText(str.setNum(s1));
    ui->work->setText(str.setNum(p1));
    ui->died->setText(str.setNum(q1));
    ui->fault->setText(str.setNum(r1));
    ui->tableWidget->setRowCount(0);

    for(auto it:cdset.CDbin)
    {

        int row=ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(row+1);

        QTableWidgetItem *tType=new QTableWidgetItem;
        QTableWidgetItem *tDNum=new QTableWidgetItem;
        QTableWidgetItem *tPNum=new QTableWidgetItem;
        QTableWidgetItem *tStatus=new QTableWidgetItem;
        QTableWidgetItem *tTime=new QTableWidgetItem;
        QString sts;
        if(it.getStatus()==0)
            sts="运行中";
        else if(it.getStatus()==1)
            sts="故障";
        else if(it.getStatus()==2)
            sts="停用";

        tType->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\汽车.png"));
        tDNum->setText(it.getNum());
        tPNum->setText(it.getPointNum());
        tStatus->setText(sts);
        tTime->setText(it.getDate().toString("yyyy/M/d"));

        ui->tableWidget->setItem(row,0,tType);
        ui->tableWidget->setItem(row,1,tDNum);
        ui->tableWidget->setItem(row,2,tPNum);
        ui->tableWidget->setItem(row,3,tStatus);
        ui->tableWidget->setItem(row,4,tTime);

        ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,4)->setTextAlignment(Qt::AlignCenter);
    }
}

void EquipShow::show2()
{
    sum=s1+s2+s3;
    ps=p1+p2+p3;
    qs=q1+q2+q3;
    rs=r1+r2+r3;
    ui->sum->setText(str.setNum(s2));
    ui->work->setText(str.setNum(p2));
    ui->died->setText(str.setNum(q2));
    ui->fault->setText(str.setNum(r2));
    ui->tableWidget->setRowCount(0);
    for(auto it:pdset.PDbin)
    {
        int row=ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(row+1);
        QTableWidgetItem *tType=new QTableWidgetItem;
        QTableWidgetItem *tDNum=new QTableWidgetItem;
        QTableWidgetItem *tPNum=new QTableWidgetItem;
        QTableWidgetItem *tStatus=new QTableWidgetItem;
        QTableWidgetItem *tTime=new QTableWidgetItem;

        QString sts;
        if(it.getStatus()==0)
            sts="运行中";
        else if(it.getStatus()==1)
            sts="故障";
        else if(it.getStatus()==2)
            sts="停用";

        tType->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\个人头像.png"));
        tDNum->setText(it.getNum());
        tPNum->setText(it.getPointNum());
        tStatus->setText(sts);
        tTime->setText(it.getDate().toString("yyyy/M/d"));

        ui->tableWidget->setItem(row,0,tType);
        ui->tableWidget->setItem(row,1,tDNum);
        ui->tableWidget->setItem(row,2,tPNum);
        ui->tableWidget->setItem(row,3,tStatus);
        ui->tableWidget->setItem(row,4,tTime);

        //ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,4)->setTextAlignment(Qt::AlignCenter);
    }
}

void EquipShow::show3()
{
    sum=s1+s2+s3;
    ps=p1+p2+p3;
    qs=q1+q2+q3;
    rs=r1+r2+r3;
    ui->sum->setText(str.setNum(s3));
    ui->work->setText(str.setNum(p3));
    ui->died->setText(str.setNum(q3));
    ui->fault->setText(str.setNum(r3));
    ui->tableWidget->setRowCount(0);
    for(auto it:vdset.VDbin)
    {
        int row=ui->tableWidget->rowCount();
        ui->tableWidget->setRowCount(row+1);
        QTableWidgetItem *tType=new QTableWidgetItem;
        QTableWidgetItem *tDNum=new QTableWidgetItem;
        QTableWidgetItem *tPNum=new QTableWidgetItem;
        QTableWidgetItem *tStatus=new QTableWidgetItem;
        QTableWidgetItem *tTime=new QTableWidgetItem;

        QString sts;
        if(it.getStatus()==0)
            sts="运行中";
        else if(it.getStatus()==1)
            sts="故障";
        else if(it.getStatus()==2)
            sts="停用";

        tType->setIcon(QIcon("D:\\武易高速人车监测系统\\ICON\\摄像头.png"));
        tDNum->setText(it.getNum());
        tPNum->setText(it.getPointNum());
        tStatus->setText(sts);
        tTime->setText(it.getDate().toString("yyyy/M/d"));

        ui->tableWidget->setItem(row,0,tType);
        ui->tableWidget->setItem(row,1,tDNum);
        ui->tableWidget->setItem(row,2,tPNum);
        ui->tableWidget->setItem(row,3,tStatus);
        ui->tableWidget->setItem(row,4,tTime);

        ui->tableWidget->item(row,0)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,1)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,2)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,3)->setTextAlignment(Qt::AlignCenter);
        ui->tableWidget->item(row,4)->setTextAlignment(Qt::AlignCenter);
    }
}


void EquipShow::on_comboBox_activated(const QString &arg1)
{
    if(arg1=="所有")
        allShow();
    else if(arg1=="车流探测器")
        show1();
    else if(arg1=="4G探针")
        show2();
    else if(arg1=="监控摄像头")
        show3();
}

