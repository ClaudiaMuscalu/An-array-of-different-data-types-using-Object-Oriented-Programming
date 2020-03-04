#include <iostream>
#include<iostream>
#include "Object.h"
using namespace std;


class Complex: public Object
{
    double real;
    double imag;

public:
    Complex();

    Complex(double x, double y);

    Complex(const Complex& c);

    Complex& operator=(const Complex &c);

    friend ifstream& operator >>(ifstream& finc, Complex& ob);

    friend istream & operator >>(istream & in,Complex& ob);

    friend ostream& operator <<(ostream& out, Complex& ob);

    void display();

    void citire(istream & in);

    void afisare(ostream & out);
};
