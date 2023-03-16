#ifndef MAIN_H
#define MAIN_H
#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <QDate>
#include <QDateTime>
#include <QString>
#include <QVector>
#include <QVariant>
#include <QDialog>
#include <QWidget>
#include <QChartView>
#include <QChart>
#include <QLineSeries>
#include <QSplineSeries>
#include <QValueAxis>
#include <QDateTimeAxis>
#include <QChartView>
#include <QChart>
#include <QLineSeries>
#include <QSplineSeries>
#include <QValueAxis>
#include <QDateTimeAxis>
#include <QMainWindow>
#include <windows.h>
#include <QPixmap>
#include <QSplashScreen>
#include <QTextEdit>
#include <QMessageBox>
#include <QLabel>
#include <QPushButton>
#include <QAxObject>
#include <QTextCodec>
#include <QStringList>
#include <QFile>
#include <QTabWidget>
#include <QTableWidgetItem>
#include <QDebug>
#include <QToolButton>
using namespace std;

enum WorkState{working,fault,dead};//工作状态：运行|故障|停用
enum dirWE{west,east};  //经度：西|东
enum dirNS{north,south};//维度：北|南
extern QVector<QToolButton*> Btn;
extern int count1;
//坐标类
class Coord
{
private:
    double longit; //经度
    enum dirWE dirOfLongit; //东经|西经
    double latit; //纬度
    enum dirNS dirOfLatit; //南纬|北纬
public:
    void setLongit(double m_longit);
    void setWE(int we);
    void setLatit(double m_latit);
    void setNS(int ns);
    double getLongit();
    int getWE();
    double getLatit();
    int getNS();
};

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

//设备类
class Device
{
protected:
    QString e_num; //设备编号
    QDate dateOfSet; //安装日期
    enum WorkState status; //工作状态
    QString model; //型号
    int scope; //探测范围
    QString numOfPoint; //所在监测点的编号
public:
    void setNum(QString m_num);
    void setDate(QDate sDate);
    void setStatus(int m_status);
    void setModedl(QString m_model);
    void setScope(int scope);
    void setPointNum(QString m_pnum);
    QString getNum();
    QDate getDate();
    int getStatus();
    QString getModel();
    int getScope();
    QString getPointNum();
};

//车流探测器类|继承设备类
class CarDevice:public Device
{
private:
    double accuracy; //准确率
public:
    void setAccur(double m_accur);
    double getAccur();
};

//4G探针类|继承设备类
class PersonDevice:public Device
{
private:
    double accuracy; //精度
public:
    void setAccur(double m_accur);
    double getAccur();
};

//监控摄像头类|继承设备类
class VideoDevice:public Device
{
private:
    int ratio; //分辨率
public:
    void setRatio(int m_ratio);
    int getRatio();
};

//设备集合
class DSet
{
public:
    int num;
public:
    int getNum();
};

//存储车流设备的集合
class CDSet:public DSet
{
public:
    QVector<CarDevice> CDbin;
public:
    void addDevice(CarDevice &obj);
    void startDevice(QString deviceNum);
    void faultDevice(QString deviceNum);
    void stopDevice(QString deviceNum);
    bool findDecice(QString deviceNum);
};

//存储人流设备的集合
class PDSet:public DSet
{
public:
    QVector<PersonDevice> PDbin;
public:
    void addDevice(PersonDevice &obj);
    void startDevice(QString deviceNum);
    void faultDevice(QString deviceNum);
    void stopDevice(QString deviceNum);
    bool findDecice(QString deviceNum);
};

//存储监控摄像头的集合
class VDSet:public DSet
{
public:
    QVector<VideoDevice> VDbin;
public:
    void addDevice(VideoDevice &obj);
    void startDevice(QString deviceNum);
    void faultDevice(QString deviceNum);
    void stopDevice(QString deviceNum);
    bool findDecice(QString deviceNum);
};

/*分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线*/

//监测点类
class SenPoint
{
private:
    QString sp_num; //桩号
    QString location; //所在位置
    Coord coordOfPos; //经纬度
    enum WorkState status; //工作状态
public:
    void setNum(QString m_num);
    void setLocate(QString m_locate);
    void setCoord(Coord m_coord);
    void setStatus(int m_status);
    QString getNum();
    QString getLocate();
    Coord getCoord();
    int getStatus();
};

//存储监测点的集合
class MyPoint
{
public:
    int num;
    QVector<SenPoint> PointBin;
public:
    void addPoint(SenPoint &obj); //添加
    void startPoint(QString pointNum); //启用
    void faultPoint(QString pointNum); //故障
    void stopPoint(QString pointNum); //停用
    bool findPoint(QString pointNum); //查找
    int getNum();
};

/*分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线*/

//记录类
class Record
{
protected:
    QString r_num; //记录编号
    QString numOfPoint; //监测点编号
    QString numOfEquip; //设备编号
    QDateTime ReTime; //记录时间
public:
    void setNum(QString m_num);
    void setPointNum(QString m_pnum);
    void setDeviceNum(QString m_enum);
    void setRTime(QDateTime m_time);
    QString getNum();
    QString getPointNum();
    QString getDeviceNum();
    QDateTime getReTime();
};

//车流记录类|继承记录类
class CarRecord:public Record
{
private:
    double speed; //车速
    QString CarNum; //车牌号
public:
    void setSpeed(double m_speed);
    void setCarNum(QString m_cnum);
    double getSpeed();
    QString getCarNum();
};

//人流记录类|继承记录类
class PersonRecord:public Record
{
private:
    QString IMEI; //IMEI
public:
    void setIMEI(QString imei);
    QString getIMEI();
};

//视频记录类|继承记录类
class VideoRecord:public Record
{
private:
    QString filePath; //视频文件路径
    QDateTime beginTime; //开始时间
    QDateTime endTime; //结束时间
public:
    void setFilePath(QString m_path);
    void setBTime(QDateTime b_time);
    void setETime(QDateTime e_time);
    QString getFilePath();
    QDateTime getBTime();
    QDateTime getETime();
};

//储存车流记录
class CRSet
{
public:
    QString numOfPoint; //监测点编号
    QVector<CarRecord> Cbin; //存储车流记录的集合
public:
    void setNum(QString n);
    void addRecord(CarRecord &obj);
    QString getNum();
};

//储存人流记录
class PRSet
{
public:
    QString numOfPoint; //监测点编号
    QVector<PersonRecord> Pbin; //存储人流记录的集合
public:
    void setNum(QString n);
    void addRecord(PersonRecord &obj);
    QString getNum();
};

//储存视频记录
class VRSet
{
public:
    QString numOfPoint; //监测点编号
    QVector<VideoRecord> Vbin; //存储车流记录的集合
public:
    void setNum(QString n);
    void addRecord(VideoRecord &obj);
    QString getNum();
};

extern CRSet crset1; //第一个监测点的车流记录
extern CRSet crset2; //第二个监测点的车流记录
extern CRSet crset3; //第三个监测点的车流记录

extern PRSet prset1; //第一个监测点的人流记录
extern PRSet prset2; //第二个监测点的人流记录
extern PRSet prset3; //第三个监测点的人流记录

extern VRSet vrset1; //第一个监测点的视频记录
extern VRSet vrset2; //第二个监测点的视频记录
extern VRSet vrset3; //第三个监测点的视频记录

extern CDSet cdset; //车流探测设备
extern PDSet pdset; //4G探针
extern VDSet vdset; //监控摄像头

extern MyPoint mp1; //监测点的集合

extern int N;

#endif // MAIN_H
