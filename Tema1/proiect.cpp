#include <iostream>
#include <cstring>
#include "data.h"


class Medicament
{
    std::string denumire;
    float pret;
    Data fabricat;
public:
    ~Medicament() {}
    Medicament( std::string const& param1, float const& param2, int const& zi, int const& luna, int const& an)
    {
        denumire = param1;
        pret= param2;
        fabricat.zi = zi;
        fabricat.luna = luna;
        fabricat.an = an; 

    }
    Medicament( std::string const& param1, float const& param2, Data const& data)
    {
        denumire = param1;
        pret = param2;
        fabricat=data;
    }
    Medicament() { }
    friend std::ostream& operator<<(std::ostream& os, const Medicament& med);
    friend std::istream& operator>>(std::istream& in, Medicament& med);
    bool friend operator<(Medicament const& med1, Medicament const& med2);
    bool friend operator>(Medicament const& med1, Medicament const& med2);
};

bool operator>( Medicament const& med1, Medicament const& med2)
{
    return !( med1.fabricat < med2.fabricat );
}

bool operator<(Medicament const& med1, Medicament const& med2)
{
    if( med1.fabricat < med2.fabricat )
        return true;
    else return false;
}

std::ostream& operator<<(std::ostream& os, const Medicament& med)
{
    os << med.denumire << ' ' << med.pret <<' '<< med.fabricat <<std::endl;
    return os;
}
std::istream& operator>>( std::istream& in, Medicament& med)
{
    in >> med.denumire >> med.pret >> med.fabricat;
    return in;
}
class Farmacie
{
    char denumire[50];
    int nrMedicamente;
    Medicament* med;
public:
    Farmacie()
    {
        Medicament* med= NULL;
        nrMedicamente = 0;
    }
    Farmacie (char* const& nume)
    {
        strcpy(denumire,nume);
        nrMedicamente = 0;
        Medicament* med= NULL;
    }
    char* const getNume()
    {
        return denumire;
    }
    Medicament* getVmed()
    {
        return med;
    }
    Farmacie& operator+=(const Medicament& newmed)
    {   
        nrMedicamente++;
        Medicament *aux = new Medicament[nrMedicamente];
        for ( int i=0; i < nrMedicamente - 1; i++ )
            aux[i] = med[i];
        aux[nrMedicamente - 1] = newmed;
        med = aux;
        return *this;

    }
    Farmacie& operator+(const Medicament& plusmed)
    {
        nrMedicamente++;
        Medicament *aux = new Medicament[nrMedicamente];
        for ( int i=0; i < nrMedicamente - 1; i++ )
            aux[i] = med[i];
        aux[nrMedicamente - 1] = plusmed;
        med = aux;
        return *this;
    }
    Farmacie& operator=(const Farmacie& farma)
    {
        if(this == &farma) return *this;
        strcpy( denumire, farma.denumire );
        med = new Medicament[farma.nrMedicamente];
        for ( int i=0; i < farma.nrMedicamente; i++ )
        {   
            med[i] = farma.med[i];
        }
        nrMedicamente = farma.nrMedicamente;
        return *this;
    }
    friend std::ostream& operator<<(std::ostream& os, const Farmacie& farma);
};

std::ostream& operator<<(std::ostream& os,const Farmacie& farma)
{
    for ( int i=0; i < farma.nrMedicamente; i++ )
        os<<farma.med[i]<<' ';
    return os;
}

int main()
{
  	Data d(1,1,2020);
    d.afisData();
    Medicament m1("Parasinus",9.5, 10, 12, 2019), m2("Aspirina",5.12, d),m3;
    // colebil 6 12 2 1999
    std::cin>>m3;
    std::cout<<m1;
    Data d1;
    std::cin>>d1;
    std::cout<<std::endl<<d1;
    if ( d > d1 )
        std::cout<<"d este mai tarziu decat d1"<<std::endl;
    else 
        std::cout<<"d este mai devreme sau aceeasi cu d1"<<std::endl;
    if (m1<m2) std::cout<<"m1 este fabricat inaintea m2"<<'\n';
    else std::cout<<"m2 este fabricat inaintea m1"<<std::endl;
    Farmacie f1("Farmac");
    Farmacie f2;
    std::cout<<f1.getNume()<<'\n';
    f1 += m1;
    f1 += m2;
    f1 += m3;
    std::cout<<f1<<std::endl;
    f2 = f2 + m1; //adaugare medicament m2 in lista de medicamente a farmaciei
    std::cout<< f2;
    f2 = f1;
    std::cout<<f2;	//afisarea tuturor medicamentelor
    return 0;
}