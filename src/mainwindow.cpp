#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "user.h"

CRSet crset1;
CRSet crset2;
CRSet crset3;
PRSet prset1;
PRSet prset2;
PRSet prset3;
VRSet vrset1;
VRSet vrset2;
VRSet vrset3;

MyPoint mp1;

CDSet cdset;
PDSet pdset;
VDSet vdset;

void init()
{
    crset1.setNum("K31+950");
    crset2.setNum("K56+400");
    crset3.setNum("K96+430");
    prset1.setNum("K31+950");
    prset2.setNum("K56+400");
    prset3.setNum("K96+430");

    QFile f1c("D:\\武易高速人车监测系统\\txt文件\\K31+950-car.txt");
    QFile f1p("D:\\武易高速人车监测系统\\txt文件\\K31+950-p.txt");
    QFile f2c("D:\\武易高速人车监测系统\\txt文件\\K56+400-car.txt");
    QFile f2p("D:\\武易高速人车监测系统\\txt文件\\K56+400-p.txt");
    QFile f3c("D:\\武易高速人车监测系统\\txt文件\\K96+430-car.txt");
    QFile f3p("D:\\武易高速人车监测系统\\txt文件\\K96+430-p.txt");

    f1c.open(QIODevice::ReadOnly);
    f1p.open(QIODevice::ReadOnly);
    f2c.open(QIODevice::ReadOnly);
    f2p.open(QIODevice::ReadOnly);
    f3c.open(QIODevice::ReadOnly);
    f3p.open(QIODevice::ReadOnly);

    QString tNum;
    QString tTime;
    QString tPointNum;
    int tSpeed;
    QString tCarNum;
    QString tIMEI;
    int i=0,j=0,k=0;
    QString tLocate;
    QTextCodec *tc = QTextCodec::codecForName("UTF-8");
    while(!f1c.atEnd())
    {
        QByteArray line = f1c.readLine(); //自动添加
        QString str=tc->toUnicode(line);
        str.truncate(str.length()-1);  //去除结尾增加的空行
        QStringList strlist=str.split("\t");
        tNum=strlist.at(0);
        tTime=strlist.at(1);
        tTime.replace(4,1,"-");
        tTime.replace(6,1,"-");
        tPointNum=strlist.at(2);
        tSpeed=strlist.at(3).toDouble();
        tCarNum=strlist.at(4);
        QDateTime tDt;
        tDt=QDateTime::fromString(tTime,"yyyy-M-dd h:mm");
        //QString tdt=tDt.toString("yyyy-M-dd h:mm");
        //qDebug()<<tNum<<' '<<tdt<<' '<<tPointNum<<' '<<tSpeed<<' '<<tCarNum;
        CarRecord tcr;
        QString tnum=QString((++i)+'0');
        tcr.setNum(tnum);
        tcr.setPointNum(tPointNum);
        tcr.setDeviceNum(tNum);
        tcr.setRTime(tDt);
        tcr.setSpeed(tSpeed);
        tcr.setCarNum(tCarNum);
        //QString tdt=tcr.getReTime().toString("yyyy-M-dd h:mm");
        //qDebug()<<tcr.getNum()<<' '<<tcr.getPointNum()<<' '<<tcr.getDeviceNum()<<' '
                //<<tcr.getReTime()<<' '<<tcr.getSpeed()<<' '<<tcr.getCarNum();
        crset1.addRecord(tcr);
    }
    tc = QTextCodec::codecForName("UTF-8");

    while(!f2c.atEnd())
    {
        QByteArray line = f2c.readLine(); //自动添加
        QString str=tc->toUnicode(line);
        str.truncate(str.length()-1);  //去除结尾增加的空行
        QStringList strlist=str.split("\t");
        tNum=strlist.at(0);
        tTime=strlist.at(1);
        tTime.replace(4,1,"-");
        tTime.replace(6,1,"-");
        tPointNum=strlist.at(2);
        tSpeed=strlist.at(3).toDouble();
        tCarNum=strlist.at(4);
        QDateTime tDt;
        tDt=QDateTime::fromString(tTime,"yyyy-M-dd h:mm");
        //QString tdt=tDt.toString("yyyy-M-dd h:mm");
        //qDebug()<<tNum<<' '<<tdt<<' '<<tPointNum<<' '<<tSpeed<<' '<<tCarNum;
        //QString tdt=tDt.toString("yyyy-M-dd h:mm");
        //qDebug()<<tNum<<' '<<tdt<<' '<<tPointNum<<' '<<tSpeed<<' '<<tCarNum;
        CarRecord tcr;
        QString tnum=QString((++i)+'0');
        tcr.setNum(tnum);
        tcr.setPointNum(tPointNum);
        tcr.setDeviceNum(tNum);
        tcr.setRTime(tDt);
        tcr.setSpeed(tSpeed);
        tcr.setCarNum(tCarNum);
        //QString tdt=tcr.getReTime().toString("yyyy-M-dd h:mm");
        //qDebug()<<tcr.getNum()<<' '<<tcr.getPointNum()<<' '<<tcr.getDeviceNum()<<' '
                //<<tcr.getReTime()<<' '<<tcr.getSpeed()<<' '<<tcr.getCarNum();
        crset2.addRecord(tcr);
    }

    tc = QTextCodec::codecForName("UTF-8");
    while(!f3c.atEnd())
    {
        QByteArray line = f3c.readLine(); //自动添加
        QString str=tc->toUnicode(line);
        str.truncate(str.length()-1);  //去除结尾增加的空行
        QStringList strlist=str.split("\t");
        tNum=strlist.at(0);
        tTime=strlist.at(1);
        tTime.replace(4,1,"-");
        tTime.replace(6,1,"-");
        tPointNum=strlist.at(2);
        tSpeed=strlist.at(3).toDouble();
        tCarNum=strlist.at(4);
        QDateTime tDt;
        tDt=QDateTime::fromString(tTime,"yyyy-M-dd h:mm");
        //QString tdt=tDt.toString("yyyy-M-dd h:mm");
        //qDebug()<<tNum<<' '<<tdt<<' '<<tPointNum<<' '<<tSpeed<<' '<<tCarNum;
        //QString tdt=tDt.toString("yyyy-M-dd h:mm");
        //qDebug()<<tNum<<' '<<tdt<<' '<<tPointNum<<' '<<tSpeed<<' '<<tCarNum;
        CarRecord tcr;
        QString tnum=QString((++i)+'0');
        tcr.setNum(tnum);
        tcr.setPointNum(tPointNum);
        tcr.setDeviceNum(tNum);
        tcr.setRTime(tDt);
        tcr.setSpeed(tSpeed);
        tcr.setCarNum(tCarNum);
        //QString tdt=tcr.getReTime().toString("yyyy-M-dd h:mm");
        //qDebug()<<tcr.getNum()<<' '<<tcr.getPointNum()<<' '<<tcr.getDeviceNum()<<' '
                //<<tcr.getReTime()<<' '<<tcr.getSpeed()<<' '<<tcr.getCarNum();
        crset3.addRecord(tcr);
    }
    while(!f1p.atEnd())
    {
        QByteArray line = f1p.readLine(); //自动添加
        QString str=tc->toUnicode(line);
        str.truncate(str.length()-1);  //去除结尾增加的空行
        QStringList strlist=str.split("\t");
        tNum=strlist.at(0);
        tTime=strlist.at(1);
        tTime.replace(4,1,"-");
        tTime.replace(6,1,"-");
        tPointNum=strlist.at(2);
        tIMEI=strlist.at(3);
        QDateTime tDt;
        tDt=QDateTime::fromString(tTime,"yyyy-M-dd h:mm");
        //QString tdt=tDt.toString("yyyy-M-dd h:mm");
        //qDebug()<<tNum<<' '<<tdt<<' '<<tPointNum<<' '<<tIMEI;
        PersonRecord tpr;
        QString tnum=QString((++j)+'0');
        tpr.setNum(tnum);
        tpr.setPointNum(tPointNum);
        tpr.setDeviceNum(tNum);
        tpr.setRTime(tDt);
        tpr.setIMEI(tIMEI);
        prset1.addRecord(tpr);
        //QString tdt=tpr.getReTime().toString("yyyy-M-dd h:mm");
        //qDebug()<<tpr.getNum()<<' '<<tpr.getPointNum()<<' '<<tpr.getDeviceNum()<<' '
                //<<tdt<<' '<<tpr.getIMEI();
    }
    while(!f2p.atEnd())
    {
        QByteArray line = f2p.readLine(); //自动添加
        QString str=tc->toUnicode(line);
        str.truncate(str.length()-1);  //去除结尾增加的空行
        QStringList strlist=str.split("\t");
        tNum=strlist.at(0);
        tTime=strlist.at(1);
        tTime.replace(4,1,"-");
        tTime.replace(6,1,"-");
        tPointNum=strlist.at(2);
        tIMEI=strlist.at(3);
        QDateTime tDt;
        tDt=QDateTime::fromString(tTime,"yyyy-M-dd h:mm");
        //QString tdt=tDt.toString("yyyy-M-dd h:mm");
        //qDebug()<<tNum<<' '<<tdt<<' '<<tPointNum<<' '<<tIMEI;
        PersonRecord tpr;
        QString tnum=QString((++j)+'0');
        tpr.setNum(tnum);
        tpr.setPointNum(tPointNum);
        tpr.setDeviceNum(tNum);
        tpr.setRTime(tDt);
        tpr.setIMEI(tIMEI);
        prset2.addRecord(tpr);
        //QString tdt=tpr.getReTime().toString("yyyy-M-dd h:mm");
        //qDebug()<<tpr.getNum()<<' '<<tpr.getPointNum()<<' '<<tpr.getDeviceNum()<<' '
                //<<tdt<<' '<<tpr.getIMEI();
    }
    while(!f3p.atEnd())
    {
        QByteArray line = f3p.readLine(); //自动添加
        QString str=tc->toUnicode(line);
        str.truncate(str.length()-1);  //去除结尾增加的空行
        QStringList strlist=str.split("\t");
        tNum=strlist.at(0);
        tTime=strlist.at(1);
        tTime.replace(4,1,"-");
        tTime.replace(6,1,"-");
        tPointNum=strlist.at(2);
        tIMEI=strlist.at(3);
        QDateTime tDt;
        tDt=QDateTime::fromString(tTime,"yyyy-M-dd h:mm");
        //QString tdt=tDt.toString("yyyy-M-dd h:mm");
        //qDebug()<<tNum<<' '<<tdt<<' '<<tPointNum<<' '<<tIMEI;
        PersonRecord tpr;
        QString tnum=QString((++j)+'0');
        tpr.setNum(tnum);
        tpr.setPointNum(tPointNum);
        tpr.setDeviceNum(tNum);
        tpr.setRTime(tDt);
        tpr.setIMEI(tIMEI);
        prset3.addRecord(tpr);
        //QString tdt=tpr.getReTime().toString("yyyy-M-dd h:mm");
        //qDebug()<<tpr.getNum()<<' '<<tpr.getPointNum()<<' '<<tpr.getDeviceNum()<<' '
                //<<tdt<<' '<<tpr.getIMEI();
    }

    QFile spt("D:\\武易高速人车监测系统\\txt文件\\Point.txt");
    QFile dv1("D:\\武易高速人车监测系统\\txt文件\\Device1.txt");
    QFile dv2("D:\\武易高速人车监测系统\\txt文件\\Device2.txt");
    QFile dv3("D:\\武易高速人车监测系统\\txt文件\\Device3.txt");

    spt.open(QIODevice::ReadOnly);
    dv1.open(QIODevice::ReadOnly);
    dv2.open(QIODevice::ReadOnly);
    dv3.open(QIODevice::ReadOnly);

    //qDebug()<<123;
    while(!spt.atEnd())
    {
        int c=1;
        //qDebug()<<111;
        QByteArray line = spt.readLine(); //自动添加
        QString str=tc->toUnicode(line);
        str.truncate(str.length()-1);  //去除结尾增加的空行
        QStringList strlist=str.split("\t");
        tNum=strlist.at(0);
        tLocate=strlist.at(1);
        SenPoint tPoint;
        Coord tCod;
        //qDebug()<<tNum<<' '<<tLocate;
        if(c==1)
        {
            tCod.setLongit(102.31);
            tCod.setLatit(25.22);
        }
        else if(c==2)
        {
            tCod.setLongit(102.29);
            tCod.setLatit(25.01);
        }
        else if(c==3)
        {
            tCod.setLongit(102.21);
            tCod.setLatit(24.71);
        }
        tCod.setWE(west);
        tCod.setNS(north);
        tPoint.setCoord(tCod);
        tPoint.setNum(tNum);
        tPoint.setLocate(tLocate);
        tPoint.setStatus(working);
        //qDebug()<<tPoint.getNum()<<' '<<tPoint.getLocate()<<' '<<tPoint.getStatus();
        mp1.addPoint(tPoint);
        ++c;
    }

    while(!dv1.atEnd())
    {
        QByteArray line = dv1.readLine(); //自动添加
        QString str=tc->toUnicode(line);
        str.truncate(str.length()-1);  //去除结尾增加的空行
        QStringList strlist=str.split("\t");
        QString tDeviceNum=strlist.at(0);
        QString tDt=strlist.at(1);
        QString tMod=strlist.at(2);
        int tScope=strlist.at(3).toInt();
        QString tPointNum=strlist.at(4);
        double tAccur=strlist.at(5).toDouble();
        QDate tDate=QDate::fromString(tDt,"yyyy/M/d");
        //QString tdt=tDate.toString("yyyy/M/d");
        //qDebug()<<tDeviceNum<<' '<<tdt<<' '<<tMod<<' '<<tScope<<' '<<tPointNum<<' '<<tAccur;
        CarDevice temp;
        temp.setNum(tDeviceNum);
        temp.setDate(tDate);
        temp.setStatus(working);
        temp.setModedl(tMod);
        temp.setScope(tScope);
        temp.setPointNum(tPointNum);
        temp.setAccur(tAccur);
        //qDebug()<<temp.getNum()<<temp.getDate()<<temp.getStatus()<<temp.getModel()
        //        <<temp.getScope()<<temp.getAccur();
        cdset.addDevice(temp);
    }
//    qDebug()<<cdset.CDbin.size();
//    for(auto it:cdset.CDbin)
//    {
//        qDebug()<<it.getNum()<<it.getDate()<<it.getStatus()<<it.getModel()
//                        <<it.getScope()<<it.getAccur();
//    }
    while(!dv2.atEnd())
    {
        QByteArray line = dv2.readLine(); //自动添加
        QString str=tc->toUnicode(line);
        str.truncate(str.length()-1);  //去除结尾增加的空行
        QStringList strlist=str.split("\t");
        QString tDeviceNum=strlist.at(0);
        QString tDt=strlist.at(1);
        QString tMod=strlist.at(2);
        int tScope=strlist.at(3).toInt();
        QString tPointNum=strlist.at(4);
        double tAccur=strlist.at(5).toDouble();
        QDate tDate=QDate::fromString(tDt,"yyyy/M/d");
        QString tdt=tDate.toString("yyyy/M/d");
        //qDebug()<<tDeviceNum<<' '<<tdt<<' '<<tMod<<' '<<tScope<<' '<<tPointNum<<' '<<tAccur;
        PersonDevice temp;
        temp.setNum(tDeviceNum);
        temp.setDate(tDate);
        temp.setStatus(working);
        temp.setModedl(tMod);
        temp.setScope(tScope);
        temp.setPointNum(tPointNum);
        temp.setAccur(tAccur);
        //qDebug()<<temp.getNum()<<temp.getDate()<<temp.getStatus()<<temp.getModel()
        //        <<temp.getScope()<<temp.getAccur();
        pdset.addDevice(temp);
    }
    while(!dv3.atEnd())
    {
        QByteArray line = dv3.readLine(); //自动添加
        QString str=tc->toUnicode(line);
        str.truncate(str.length()-1);  //去除结尾增加的空行
        QStringList strlist=str.split("\t");
        QString tDeviceNum=strlist.at(0);
        QString tDt=strlist.at(1);
        QString tMod=strlist.at(2);
        int tScope=strlist.at(3).toInt();
        QString tPointNum=strlist.at(4);
        int tRatio=strlist.at(5).toInt();
        QDate tDate=QDate::fromString(tDt,"yyyy/M/d");
        //QString tdt=tDate.toString("yyyy/M/d");
        //qDebug()<<tDeviceNum<<' '<<tdt<<' '<<tMod<<' '<<tScope<<' '<<tPointNum<<' '<<tRatio;
        VideoDevice temp;
        temp.setNum(tDeviceNum);
        temp.setDate(tDate);
        temp.setStatus(working);
        temp.setModedl(tMod);
        temp.setScope(tScope);
        temp.setPointNum(tPointNum);
        temp.setRatio(tRatio);
        //qDebug()<<temp.getNum()<<temp.getDate()<<temp.getStatus()<<temp.getModel()
        //        <<temp.getScope()<<temp.getRatio();
        vdset.addDevice(temp);
    }

    VideoRecord vr1;
    vr1.setNum("1");
    vr1.setPointNum("K31+950");
    vr1.setDeviceNum("M20211120001");
    QDateTime btime=QDateTime::fromString("2021-4-26 17:25:13","yyyy-M-d h:mm:ss");
    QDateTime etime=QDateTime::fromString("2021-4-26 17:25:49","yyyy-M-d h:mm:ss");
    //QString s1=btime.toString("yyyy-M-d h:mm:ss");
    //QString s2=etime.toString("yyyy-M-d h:mm:ss");
    //qDebug()<<s1<<s2;
    vr1.setRTime(etime);
    vr1.setFilePath("D:\\武易高速人车监测系统\\武易高速部分监控数据\\1、前营立交视频（视频头编号：M20211120001，地点：前营立交，桩号：K31+950）.mp4");
    vr1.setBTime(btime);
    vr1.setETime(etime);
    vrset1.addRecord(vr1);

    VideoRecord vr2;
    vr2.setNum("1");
    vr2.setPointNum("K56+400");
    vr2.setDeviceNum("M20211120119");
    btime=QDateTime::fromString("2021-4-25 21:37:34","yyyy-M-d h:mm:ss");
    etime=QDateTime::fromString("2021-4-25 21:38:31","yyyy-M-d h:mm:ss");
    //QString s1=btime.toString("yyyy-M-d h:mm:ss");
    //QString s2=etime.toString("yyyy-M-d h:mm:ss");
    //qDebug()<<s1<<s2;
    vr2.setRTime(etime);
    vr2.setFilePath("D:\\武易高速人车监测系统\\武易高速部分监控数据\\2、青龙立交视频（视频头编号：M20211120119，地点：青龙立交，桩号：K56+400）.mp4");
    vr2.setBTime(btime);
    vr2.setETime(etime);
    vrset2.addRecord(vr2);

    VideoRecord vr3;
    vr3.setNum("1");
    vr3.setPointNum("K96+430");
    vr3.setDeviceNum("M20211120231");
    btime=QDateTime::fromString("2021-4-26 17:35:17","yyyy-M-d h:mm:ss");
    etime=QDateTime::fromString("2021-4-26 17:36:03","yyyy-M-d h:mm:ss");
    //QString s1=btime.toString("yyyy-M-d h:mm:ss");
    //QString s2=etime.toString("yyyy-M-d h:mm:ss");
    //qDebug()<<s1<<s2;
    vr3.setRTime(etime);
    vr3.setFilePath("D:\\武易高速人车监测系统\\武易高速部分监控数据\\3、易门服务区右幅视频（视频头编号：M20211120231，地点：易门服务区右，桩号：K96+430）.mp4");
    vr3.setBTime(btime);
    vr3.setETime(etime);
    vrset3.addRecord(vr3);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle(tr("武易高速人车监测数据展示系统"));
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_CheckIn_clicked()
{
    UserInFo *u1=new UserInFo();
    u1->show();
}


void MainWindow::on_TakeOff_clicked()
{
    this->close();
}

