#include "Main.h"

void Record::setNum(QString m_num)
{
    r_num=m_num;
}

void Record::setPointNum(QString m_pnum)
{
    numOfPoint=m_pnum;
}

void Record::setDeviceNum(QString m_enum)
{
    numOfEquip=m_enum;
}

void Record::setRTime(QDateTime m_time)
{
    ReTime=m_time;
}

QString Record::getNum()
{
    return r_num;
}

QString Record::getPointNum()
{
    return numOfPoint;
}

QString Record::getDeviceNum()
{
    return numOfEquip;
}

QDateTime Record::getReTime()
{
    return ReTime;
}

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

void CarRecord::setSpeed(double m_speed)
{
    speed=m_speed;
}

void CarRecord::setCarNum(QString m_cnum)
{
    CarNum=m_cnum;
}

double CarRecord::getSpeed()
{
    return speed;
}

QString CarRecord::getCarNum()
{
    return CarNum;
}

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

void PersonRecord::setIMEI(QString imei)
{
    IMEI=imei;
}

QString PersonRecord::getIMEI()
{
    return IMEI;
}

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

void VideoRecord::setFilePath(QString m_path)
{
    filePath=m_path;
}

void VideoRecord::setBTime(QDateTime b_time)
{
    beginTime=b_time;
}

void VideoRecord::setETime(QDateTime e_time)
{
    endTime=e_time;
}

QString VideoRecord::getFilePath()
{
    return filePath;
}

QDateTime VideoRecord::getBTime()
{
    return beginTime;
}

QDateTime VideoRecord::getETime()
{
    return endTime;
}

