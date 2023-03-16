#include "Main.h"

void SenPoint::setNum(QString m_num)
{
    sp_num=m_num;
}

void SenPoint::setLocate(QString m_locate)
{
    location=m_locate;
}

void SenPoint::setCoord(Coord m_coord)
{
    coordOfPos=m_coord;
}

void SenPoint::setStatus(int m_status)
{
    status=(enum WorkState)m_status;
}

QString SenPoint::getNum()
{
    return sp_num;
}

QString SenPoint::getLocate()
{
    return location;
}

Coord SenPoint::getCoord()
{
    return coordOfPos;
}

int SenPoint::getStatus()
{
    return status;
}

void MyPoint::addPoint(SenPoint &obj)
{
    PointBin.push_back(obj);
    num++;
}

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

void MyPoint::startPoint(QString pointNum)
{
    for(auto item:PointBin)
    {
        if(item.getNum()==pointNum)
        {
            item.setStatus(working);
        }
    }
}

void MyPoint::faultPoint(QString pointNum)
{
    for(auto item:PointBin)
    {
        if(item.getNum()==pointNum)
        {
            item.setStatus(fault);
        }
    }
}

void MyPoint::stopPoint(QString pointNum)
{
    for(auto item:PointBin)
    {
        if(item.getNum()==pointNum)
        {
            item.setStatus(dead);
        }
    }
}

bool MyPoint::findPoint(QString pointNum)
{
    for(auto item:PointBin)
    {
        if(item.getNum()==pointNum)
        {
            return true;
        }
    }
    return false;
}

int MyPoint::getNum()
{
    return num;
}

