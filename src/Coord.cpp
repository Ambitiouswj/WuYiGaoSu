#include "Main.h"

void Coord::setLongit(double m_longit)
{
    longit=m_longit;
}

void Coord::setWE(int we)
{
    dirOfLongit=(enum dirWE)we;
}

void Coord::setLatit(double m_latit)
{
    latit=m_latit;
}

void Coord::setNS(int ns)
{
    dirOfLatit=(enum dirNS)ns;
}

double Coord::getLongit()
{
    return longit;
}

int Coord::getWE()
{
    return dirOfLongit;
}

double Coord::getLatit()
{
    return latit;
}

int Coord::getNS()
{
    return dirOfLatit;
}
