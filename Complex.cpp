#include <iostream>
#include<fstream>
#include"Complex.h"
using namespace std;

Complex::Complex()
{
    real=0;
    imag=0;
}

Complex::Complex(double x=0, double y=0)
{
     real=x;
     imag=y;
}

Complex::Complex(const Complex& c)
{
    real=c.real;
    imag=c.imag;
}
Complex& Complex::operator=(const Complex& c)
{
    real=c.real;
    imag=c.imag;
    return(*this);
}

ifstream& operator >>(ifstream& finc, Complex& ob)
{
    finc>>ob.real>>ob.imag;
    return finc;
}

istream & operator >>(istream & in, Complex& ob)
{
    in>>ob.real>>ob.imag;
    return in;
}

ostream & operator <<(ostream & out, Complex& ob)
{
    out<<ob.real<<"+"<<ob.imag<<"i\n";
    return out;
}

void Complex::display()
{
    cout<<real<<"+"<<imag<<"i";
}

 void Complex::citire(istream & in)
{
    Object::citire(in);
    in>>real>>imag;
}

 void Complex::afisare(ostream & out)
{
    Object::afisare(out);
    out<<real<<"+"<<imag<<"i";
}
