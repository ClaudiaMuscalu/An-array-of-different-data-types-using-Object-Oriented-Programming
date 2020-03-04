#include <iostream>
#include<fstream>
#include"ObArray.h"
#include"Points.h"
#include"Complex.h"
using namespace std;

ObArray::ObArray()
{
    siz=0;
    grows=2;
    dimens=10;
    p=new Object*[10];

}
ObArray::ObArray (int s=0,int g=2,int d=10)
{
    siz=s;
    grows=g;
    dimens=d;
    p=new Object*[dimens];
}

ObArray::~ObArray()
{
    for(int i=0;i<siz;i++)
        delete[]p[i];
    delete[]p;
}

ObArray::ObArray(const ObArray &c)
{
    if(c.getSize()==0)
        return;

    this->dimens=c.dimens;
    this->siz=0;
    this->grows=c.grows;

    p=new Object*[c.dimens];
    for(int i=0;i<c.getSize();i++)
        add(c.getAT(i));
}

void ObArray::RemoveAll()
{
    for(int i=0;i<siz;i++)
        delete[]p[i];
    delete[]p;
}

ObArray& ObArray::operator= (const ObArray &c)
{
    RemoveAll();

    this->dimens=c.dimens;
    this->siz=0;
    this->grows=c.grows;

    p=new Object*[c.dimens];
    for(int i=0;i<c.getSize();i++)
        add(c.getAT(i));

    return(*this);
}

int ObArray::getSize ()const
{
    return siz;
}

int ObArray::getGrows()
{
    return grows;
}

int ObArray::getDimens()
{
    return dimens;
}

void ObArray::add (Object* x)
{
    if(siz==(dimens-1))
    {
        dimens=dimens*grows;
        Object** q;
        q=new Object*[dimens];
        p=q;
    }
    p[siz]=x;
    siz++;

}

void ObArray::insertAt(int i, Object* x)
{
    if(i>siz)
    {
        cout<<"Numarul dat este incorect.";
        return;
    }
    if(siz==(dimens-1))
    {
        dimens=dimens*grows;
        Object** q;
        q=new Object*[dimens];
        p=q;
    }

    if(i!=siz)
        {
            for(int j=siz;j>i;j--)
                p[j]=p[j-1];
        }

    siz++;
    p[i]=x;
}

void ObArray::removeAt(int i)
{
    if(i>=siz)
    {
        cout<<"Valorea data pentru stergere este incorecta.";
        return;
    }
    for(int j=i;j<siz;j++)
        p[j]=p[j+1];
    siz--;
}

Object* ObArray::getAT(int i)const
{
  return p[i];
}

void ObArray::display()
{
    for(int i=0;i<siz;i++)
     {
      p[i]->display();
      cout<<" ";
     }
    cout<<"\n";
}

istream& operator>>( istream & in,ObArray & ob)
{
    int i,n;
    in>>n;
    char c;
    Object *x;
    for(i=0;i<n;i++)
    {   in>>c;

        if(c=='P')
            x=new Points;
        if(c=='C')
            x=new Complex;

        in>>(*x);
        ob.add(x);
    }
    return in;
}

ostream& operator<<(ostream & out, ObArray & ob)
{
    int i;
    out<<"Dimensiunea este: "<<ob.getSize()<<"\n";
    for(i=0;i<ob.getSize();i++)
    {
        out<<*(ob.getAT(i))<<" ";
    }
    return out;
}
