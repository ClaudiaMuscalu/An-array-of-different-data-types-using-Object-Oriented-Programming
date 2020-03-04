#include <iostream>
#include "Object.h"
using namespace std;


istream& operator >>(istream & in,Object&rp)
{
    rp.citire(in);
    return in;
}
ostream& operator <<(ostream & out,Object&rp)
{
    rp.afisare(out);
    return out;
}
