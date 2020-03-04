#include <iostream>
#include<fstream>
#include"Points.h"

using namespace std;
Points::Points()
{
    abscisa=0;
    ordonata=0;
}

Points::Points(int lin=0, int col=0)
{
    abscisa=lin;
    ordonata=col;
}

Points::Points(const Points& c)
{
    abscisa=c.abscisa;
    ordonata=c.ordonata;
}

Points& Points::operator=(const Points& c)
{
    abscisa=c.abscisa;
    ordonata=c.ordonata;
    return (*this);
}

ifstream & operator >> (ifstream & finp, Points& ob)
{
    finp>>ob.abscisa>>ob.ordonata;
    return finp;
}

istream & operator >> (istream & in, Points& ob)
{
    in>>ob.abscisa;
    in>>ob.ordonata;
    return in;
}

ostream & operator << (ostream & out, Points& ob)
{
    out<<"("<<ob.abscisa<<","<<ob.ordonata<<")\n";
    return out;
}

void Points::display()
{
    cout<<"("<<abscisa<<","<<ordonata<<")";
}

void Points::citire(istream & in)
{
    Object::citire(in);
    in>>abscisa>>ordonata;
}

void Points::afisare(ostream & out)
{
    Object::afisare(out);
    out<<"("<<abscisa<<","<<ordonata<<")";
}
