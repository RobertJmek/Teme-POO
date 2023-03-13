#include <iostream>
#include<cstring>
#include </home/robert/Desktop/POO/1.h>


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
    Farmacie& operator+=(Medicament const& newmed)
    {   
        nrMedicamente++;
        Medicament *aux = new Medicament[nrMedicamente + 1];
        med = new Medicament[nrMedicamente + 1];
        for ( int i=0; i <= nrMedicamente - 1; i++ )
            aux[i] = med[i];
        aux[nrMedicamente - 1] = newmed;
        med = aux;
        return *this;

    }
    Farmacie& operator+(Medicament const& plusmed)
    {
        nrMedicamente++;
        Medicament *aux = new Medicament[nrMedicamente + 1];
        med = new Medicament[nrMedicamente + 1];
        for ( int i=0; i < nrMedicamente - 1; i++ )
            aux[i] = med[i];
        aux[nrMedicamente - 1] = plusmed;
        med = aux;
        return *this;
    }
    Farmacie& operator=(Farmacie const& farma)
    {
        strcpy( denumire, farma.denumire );
        for ( int i=0; i < farma.nrMedicamente - 1; i++ )
        {   
            med[i] = farma.med[i];
        }
        nrMedicamente = farma.nrMedicamente;
    }
    friend std::ostream& operator<<(std::ostream& os, const Farmacie& farma);
};

std::ostream& operator<<(std::ostream& os,const Farmacie& farma)
{
    for ( int i=0; i < farma.nrMedicamente - 1; i++ )
        os<<farma.med[i]<<'\n';
    return os;
}

int main()
{
  	Data d(1,1,2020);
    d.afisData();
    Medicament m1("Parasinus",9.5, 10, 12, 2019), m2("Aspirina",5.12, d),m3;
///    std::cin>>m3;
    std::cout<<m1;
    if (m1<m2) std::cout<<"m1 este fabricat inaintea m2"<<'\n';
    else std::cout<<"m2 este fabricat inaintea m1";
    Farmacie f1("Farmac");
    std::cout<<f1.getNume()<<'\n';
    f1 += m1;
    std::cout<<f1.getVmed()[0];
    std::cout<<f1.getVmed()[0];
    std::cout<<f1.getVmed()[1];
    f1 += m2;
    std::cout<<f1.getVmed()[0];
    std::cout<<f1.getVmed()[1];
    f1 = f1 + m1; //adaugare medicament m2 in lista de medicamente a farmaciei
    std::cout<<f1.getVmed()[1];
    Farmacie f2 = f1;
    std::cout<<f2.getVmed()[0];
    std::cout<<f2;	//afisarea tuturor medicamentelor
    return 0;
}