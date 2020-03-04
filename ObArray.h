#include <iostream>
#include "Object.h"
using namespace std;

class ObArray:public Object
{
    Object **p; /**vector de pointeri**/

    int siz; /**numarul de elemente la un moment dat**/

    int grows; /**increment de crestere a dimensiunii**/

    int dimens; /**dimensiune vector**/

public:
    ObArray();
    /**Constructor**/
    ObArray (int s,int g, int d);

    /**Destructor**/
    ~ObArray();

    ObArray(const ObArray &c);

    /**Elimina toate obiectele din vector**/
    void RemoveAll();

    /**Intoarce numarul de elemente din vector**/
    int getSize ()const;

    int getGrows();

    int getDimens();

    /**Adauga un element la vector**/
    void add(Object* x);

    /**Insereaza un element pe o pozitie data**/
    void insertAt(int i, Object* x);

    /**Elimina elementul de pe pozitia i**/
    void removeAt(int i);

    /**Intoarce elementul de la pozitia i**/
    Object* getAT(int i)const;

    ObArray& operator=(const ObArray &c);

    /**Afisarea elementelor din tablou**/
    void display();

    friend istream& operator>>( istream & in,ObArray & ob);

    friend ostream& operator<<(ostream & out, ObArray & Ob);
};
