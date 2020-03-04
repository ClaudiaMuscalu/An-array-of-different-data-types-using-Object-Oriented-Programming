#include <iostream>
#include "Object.h"
using namespace std;


class Points: public Object
{
    int abscisa;
    int ordonata;

public:
      Points();

      Points(int lin, int col);

      Points(const Points& c);

      Points& operator=(const Points &c);

      friend ifstream& operator >>(ifstream& finp,Points& ob);

      friend istream & operator >>(istream & in,Points& ob);

      friend ostream& operator <<(ostream& out,Points& ob);

      void display();

      void citire(istream & in);

      void afisare(ostream & out);
};
