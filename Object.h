#include <iostream>
#ifndef Object_h
#define Object_h

using namespace std;
class Object
{
public:

    Object(){};
    virtual ~Object(){};
    virtual void display ()=0;
    virtual void citire(istream & in){};
    virtual void afisare(ostream & out){};
    friend istream& operator>>(istream& in, Object&rp);
    friend ostream& operator<<(ostream& out, Object&rp);
};
#endif // Object
