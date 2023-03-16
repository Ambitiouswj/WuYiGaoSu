#include "Main.h"

void CRSet::setNum(QString n)
{
    numOfPoint=n;
}

void CRSet::addRecord(CarRecord &obj)
{
    Cbin.push_back(obj);
}

QString CRSet::getNum()
{
    return numOfPoint;
}

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

void PRSet::setNum(QString n)
{
    numOfPoint=n;
}

void PRSet::addRecord(PersonRecord &obj)
{
    Pbin.push_back(obj);
}

QString PRSet::getNum()
{
    return numOfPoint;
}

/**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**分割线**/

void VRSet::setNum(QString n)
{
    numOfPoint=n;
}

void VRSet::addRecord(VideoRecord &obj)
{
    Vbin.push_back(obj);
}

QString VRSet::getNum()
{
    return numOfPoint;
}
