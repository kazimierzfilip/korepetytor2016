#include <iostream>
#include <fstream>
#include<windows.h>
#include<conio.h>

using namespace std;

int rozm=500;
int zzz=300;

string pytpoz="bin/pytpoz.txt";

void otwieracz(fstream *plik,fstream *plik2);

void wkuwacz(fstream *plik,fstream *plik2);

void quiz(fstream *plik);

fstream plik,plik2;

int main()
{
    for(;;)
    {
        otwieracz(&plik,&plik2);
    }
    cout << "Hello world!" << endl;
    return 0;
}

void otwieracz(fstream *plik,fstream *plik2)
{
    char z;
    cout << "Jaki przedmiot chcesz powtorzyc?" <<endl<< "Wpisz \"1\" jezeli poznawcza"<<endl
         << "wpisz \"2\" jezeli roznice" <<endl<<"wpisz \"3\" jezeli rozwojowa"<<endl
         <<"Wpisz \"4\" jezeli emocje"<<endl
         <<"wpisz \"5\" aby wyjsc"<<endl<<"i zatwierdz ENTEREM: ";
    cin>>z;
    switch(z)
    {
    case '1':
    {
        plik->open(pytpoz.c_str(),ios::in);
        plik2->open("bin/odppoz.txt",ios::in);
        if(plik->good()==false || plik2->good()==false)
        {
            cout <<endl<<"nie mozna otworzyc pliku"<<endl;
            system("pause");
            exit(0);
        }
        wkuwacz(plik,plik2);
    }
    break;
    case '2':
    {
        plik->open("bin/pytri.txt",ios::in);
        plik2->open("bin/odpri.txt",ios::in);
        if(plik->good()==false || plik2->good()==false)
        {
            cout <<endl<<"nie mozna otworzyc pliku"<<endl;
            system("pause");
            exit(0);
        }
        wkuwacz(plik,plik2);
    }
    break;
    case '3':
    {
        int x;
        cout << "Test 1, 2 czy 3?: ";
        cin >>x;
        if(x==1)
            plik->open("bin/rozw.txt",ios::in);
        else if(x==2)
            plik->open("bin/rozw2.txt",ios::in);
        else if(x==3)
            plik->open("bin/rozw3.txt",ios::in);
        else
            cout << "blad";
        if(plik->good()==false)
        {
            cout <<endl<<"nie mozna otworzyc pliku"<<endl;
            system("pause");
            exit(0);
        }
        quiz(plik);
    }
    break;
    case '4':
    {
            plik->open("bin/emoc.txt",ios::in);
        if(plik->good()==false)
        {
            cout <<endl<<"nie mozna otworzyc pliku"<<endl;
            system("pause");
            exit(0);
        }
        quiz(plik);
    }
    break;
    case '5': exit(0); break;
    default :
    {
        cout << "Blad otwarcia";
        system("pause");
        exit(0);
    }
    }
}

void wkuwacz(fstream *plik,fstream *plik2)
{
    cout<<endl<<endl<<"----------------------------------------------------"<<endl;
    cout << "Aby wyjsc nacisnij SPACJE i zatwierdz ENTEREM" <<endl<<
         "Aby poznac odpowiedz lub przejsc do nastepnego pytania wcisnij ENTER"<<endl;
    cout<<"----------------------------------------------------"<<endl<<endl;
    string linia;
    string pyt,odp;
    while(!plik->eof()||!plik2->eof())
    {
        getline(*plik,pyt);
        cout <<endl<<endl<<endl;
        cout << pyt <<endl;
        cin.clear();
        getch();
        getline(*plik2,odp);
        cout <<endl<<endl<<endl;
        cout << odp<<endl;
        cin.clear();
        getch();
    }
    plik->close();
    plik2->close();
    system("pause");
    cout <<endl;
}

void quiz(fstream *plik)
{
    cout<<endl<<endl<<"----------------------------------------------------------------"<<endl;
    cout <<" Aby wyjsc nacisnij SPACJE i zatwierdz ENTEREM"<<"\n"<<endl<<
         " Wpisz odpowiedz aby sprawdzic i przejsc do nastepnego pytania"<<endl;
    cout<<"----------------------------------------------------------------"<<endl<<endl;

    string linia;
    string pyt,a,b,c,d,pop,odp;
    int pkt=0,i=0;
    while(!plik->eof())
    {
        getline(*plik,pyt);
        getline(*plik,a);
        getline(*plik,b);
        getline(*plik,c);
        getline(*plik,d);
        getline(*plik,pop);
        cout <<endl<<endl<<endl;
        cout << pyt <<endl<<endl;
        //  Sleep(zzz);
        cout<< a <<endl;
        //  Sleep(zzz);
        cout<< b <<endl;
        // Sleep(zzz);
        cout<< c <<endl;
        // Sleep(zzz);
        cout<< d <<endl;
        cout <<endl<< "Wpisz odpowiedz: ";
        i++;
        cin.clear();
        cin.sync();
        if(getchar()==pop[0])
        {
            cout <<endl<<endl;
            cout << "BRAWO!!!"<<endl;
            pkt++;
        }
        else
        {
            // pop=atoi(pop.c_str());
            cout <<endl<< "Niestety, poprawna odpowiedz: ";
            switch(pop[0])
            {
            case 'a':
                cout << a <<endl;
                break;
            case 'b':
                cout << b <<endl;
                break;
            case 'c':
                cout << c <<endl;
                break;
            case 'd':
                cout << d <<endl;
                break;
            default:
            {
                cout << "NIE WIADOMO"<<endl;
                i--;
            }
            }
        }
        Sleep(zzz);
    }
    plik->close();
    cout <<endl<< "Masz "<<pkt<< " punktow na "<<i<<" !"<<endl;
    system("pause");
    cout <<endl;
}
