#include <iostream>
#include"Object.h"
#include"Points.h"
#include"Complex.h"
#include"ObArray.h"

using namespace std;
int main()
{
   unsigned int optiune;

   do
   {
       cout<<"Optiuni:\n";
       cout<<"1. Verificari pentru clasa Points.\n";
       cout<<"2. Verificari pentru clasa Complex\n";
       cout<<"3. Verificari pentru clasa ObArray\n";
       cout<<"4.Iesire\n";

       cin>>optiune;

       switch(optiune)
       {
        case 1:
        {
            Points p;
            cout<<"Dati doua coordonate pentru un punct:\n";
            cin>>p;
            cout<<"Punctul cu coordonatele date este: "<<p<<"\n";

            Points q;
            q=p;
            cout<<"Test pentru operatorul =:\n"<<q<<"\n";

            Points r(q);
            cout<<"Test pentru constructorul de copiere:\n"<<r<<"\n";
            break;

        }

        case 2:
        {
            Complex c;
            cout<<"Dati doua valori ce vor reprezenta partea reala si partea imaginara:\n";
            cin>>c;
            cout<<"Numarul complex este: "<<c<<"\n";

            Complex d;
            d=c;
            cout<<"Test pentru operatorul =:"<<d<<"\n";

            Complex e(d);
            cout<<"Test pentru constructorul de copiere: "<<e<<"\n";
            break;


        }
        case 3:
        {
            Object *y=new Complex(6,1);
            Object *z=new Points(9,5);

            ObArray arrPoints;
            cout<<"Dati dimensiunea vectorului si coordonatele punctelor ce il contin:\n";
            cin>>arrPoints;
            cout<<"Vectorul de puncte este:\n";
            cout<<arrPoints<<"\n";

            ObArray arrComplex;
            cout<<"Dati dimensiunea vectorului si numerele complexe ce il contin:\n";
            cin>>arrComplex;
            cout<<"Vectorul de numere complexe este:\n";
            cout<<arrComplex<<"\n";

            ObArray arr_P_C;
            cout<<"Dati dimensiunea vectorului ce va contine atat puncte cat si numere complexe:\n";
            cin>>arr_P_C;
            cout<<"Vectorul de puncte si numere complexe este:\n";
            arr_P_C.display();

            cout<<"Test pentru functia de adaugare la final:\n";
            cout<<"Se adauga la final punctul (9,5) in vectorul de puncte si complex:\n";
            arr_P_C.add(z);
            arr_P_C.display();

            cout<<"Test pentru functia de adaugare pe o pozitie data:\n";
            cout<<"Dati pozitia unde doriti inserarea:\n";
            int i;
            do
            {
               cin>>i;
            }
            while(i<0||i>arr_P_C.getSize());

            cout<<"Se adauga pe pozitia "<<i<<" complexul (6+i) in vectorul de puncte si complex:\n";
            arr_P_C.insertAt(i,y);
            arr_P_C.display();

            cout<<"Test pentru stergerea de pe o pozitie data:\n";
            cout<<"Dati pozitia unde doriti sa fie facuta stergerea:\n";
            int j;
            do
            {
               cin>>j;
            }
            while(j<0||j>arr_P_C.getSize());
            cout<<"Vectorul dupa stergerea de pe pozitia "<<j<<"\n";
            arr_P_C.removeAt(j);
            arr_P_C.display();

        }
       }
   }
   while(optiune<4);

    return 0;
}
