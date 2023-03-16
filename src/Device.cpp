#include "Main.h"

void Device::setNum(QString m_num)
{
    e_num=m_num;
}

void Device::setDate(QDate sDate)
{
    dateOfSet=sDate;
}

void Device::setStatus(int m_status)
{
    status=(enum WorkState)m_status;
}

void Device::setModedl(QString m_model)
{
    model=m_model;
}

void Device::setScope(int scope)
{
    this->scope=scope;
}

void Device::setPointNum(QString m_pnum)
{
    numOfPoint=m_pnum;
}

QString Device::getNum()
{
    return e_num;
}

QDate Device::getDate()
{
    return dateOfSet;
}

int Device::getStatus()
{
    return status;
}

QString Device::getModel()
{
    return model;
}

int Device::getScope()
{
    return scope;
}

QString Device::getPointNum()
{
    return numOfPoint;
}

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

void CarDevice::setAccur(double m_accur)
{
    accuracy=m_accur;
}

double CarDevice::getAccur()
{
    return accuracy;
}

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

void PersonDevice::setAccur(double m_accur)
{
    accuracy=m_accur;
}

double PersonDevice::getAccur()
{
    return accuracy;
}

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

void VideoDevice::setRatio(int m_ratio)
{
    ratio=m_ratio;
}

int VideoDevice::getRatio()
{
    return ratio;
}

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

int DSet::getNum()
{
    return num;
}

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

void CDSet::addDevice(CarDevice &obj)
{
    CDbin.push_back(obj);
}

void CDSet::startDevice(QString deviceNum)
{
    for(auto item:CDbin)
    {
        if(item.getNum()==deviceNum)
        {
            item.setStatus(working);
        }
    }
}

void CDSet::faultDevice(QString deviceNum)
{
    for(auto item:CDbin)
    {
        if(item.getNum()==deviceNum)
        {
            item.setStatus(fault);
        }
    }
}

void CDSet::stopDevice(QString deviceNum)
{
    for(auto item:CDbin)
    {
        if(item.getNum()==deviceNum)
        {
            item.setStatus(dead);
        }
    }
}

bool CDSet::findDecice(QString deviceNum)
{
    for(auto item:CDbin)
    {
        if(item.getNum()==deviceNum)
        {
            return true;
        }
    }
    return false;
}

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

void PDSet::addDevice(PersonDevice &obj)
{
    PDbin.push_back(obj);
}

void PDSet::startDevice(QString deviceNum)
{
    for(auto item:PDbin)
    {
        if(item.getNum()==deviceNum)
        {
            item.setStatus(working);
        }
    }
}

void PDSet::faultDevice(QString deviceNum)
{
    for(auto item:PDbin)
    {
        if(item.getNum()==deviceNum)
        {
            item.setStatus(fault);
        }
    }
}

void PDSet::stopDevice(QString deviceNum)
{
    for(auto item:PDbin)
    {
        if(item.getNum()==deviceNum)
        {
            item.setStatus(dead);
        }
    }
}

bool PDSet::findDecice(QString deviceNum)
{
    for(auto item:PDbin)
    {
        if(item.getNum()==deviceNum)
        {
            return true;
        }
    }
    return false;
}

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

void VDSet::addDevice(VideoDevice &obj)
{
    VDbin.push_back(obj);
}

void VDSet::startDevice(QString deviceNum)
{
    for(auto item:VDbin)
    {
        if(item.getNum()==deviceNum)
        {
            item.setStatus(working);
        }
    }
}

void VDSet::faultDevice(QString deviceNum)
{
    for(auto item:VDbin)
    {
        if(item.getNum()==deviceNum)
        {
            item.setStatus(fault);
        }
    }
}

void VDSet::stopDevice(QString deviceNum)
{
    for(auto item:VDbin)
    {
        if(item.getNum()==deviceNum)
        {
            item.setStatus(dead);
        }
    }
}

bool VDSet::findDecice(QString deviceNum)
{
    for(auto item:VDbin)
    {
        if(item.getNum()==deviceNum)
        {
            return true;
        }
    }
    return false;
}
