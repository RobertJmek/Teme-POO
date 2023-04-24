#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <stdexcept>

class Locuinta
{
protected:
    std::string numeClient;
    int suprafataUtila;
    float discount;

public:
    Locuinta() = default;
    Locuinta(const std::string &nume, const int &suprafata, const float &disc)
    {
        this->numeClient = nume;
        this->suprafataUtila = suprafata;
        this->discount = disc;
    }
    Locuinta(const Locuinta &loc)
    {
        this->numeClient = loc.numeClient;
        this->suprafataUtila = loc.suprafataUtila;
        this->discount = loc.discount;
    }
    virtual ~Locuinta() = default;
    virtual float CalculChirie(const int &X, const bool &Y) = 0;
    virtual float CalculImpozit() = 0;
    virtual float CalculpGunoi(const int& nrPers) = 0;
    std::string Getnume() { return numeClient; }
    int getSuprafata() { return suprafataUtila; }
    float getDisount() { return discount; }
    Locuinta& operator=(const Locuinta* loc);
    friend std::ostream &operator<<(std::ostream &os, Locuinta* loc);
    friend std::istream &operator>>(std::istream &in, Locuinta* loc);
};

class Casa : public Locuinta
{
private:
    int suprafataCurte;
    static float TarifP;

public: 
    Casa( const std::string &nume, const int &suprafata, const float &disc, const int &suprafataC ):Locuinta( nume, suprafata, disc )
    {
    if ( disc < 0 || disc > 99.99) { throw std::invalid_argument("Disount-ul este invalid"); }
    if ( suprafata < 1 || suprafataC < 1) { throw std::invalid_argument("Suprafata este invalida\n"); }
    this->numeClient = nume;
    this->suprafataUtila = suprafata;
    this->discount = disc;
    this->suprafataCurte = suprafataC;

    }
    Casa( const Casa& casa ) { 
        this->numeClient = casa.numeClient;
        this->suprafataUtila = casa.suprafataUtila;
        this->suprafataCurte = casa.suprafataCurte;
        this->discount = casa.discount;
        }
    Casa( Locuinta* loc, const int& suprafataCurte )
    {
        this->numeClient = loc->Getnume();
        this->discount = loc->getDisount();
        this->suprafataCurte = suprafataCurte;
        this->suprafataUtila = loc->getSuprafata();
        delete loc;
    }
    Casa() = default;
    ~Casa() = default;
    static float getTarif() { return Casa::TarifP; }
    static void SetTarif(const int& tarif) { Casa::TarifP = tarif; }
    float CalculChirie(const int &X, const bool &Y)
    {
        return X * (suprafataUtila + 0.2 * suprafataCurte) * (1 - Y * discount / 100.0);
    }
    float CalculImpozit();
    float CalculpGunoi(const int& nrPers);
    Casa& operator=(const Casa* casa);
    friend std::ostream &operator<<(std::ostream &os, const Casa* casa);
    friend std::istream &operator>>(std::istream &in, Casa* casa);
};

class Apartament : public Locuinta
{
private:
    int etaj;
    static float TarifP;

public:
    Apartament() = default;
    Apartament(const std::string& nume, const int& suprafata, const float& disc, const int& etj):Locuinta(nume,suprafata,disc) 
    {
        if ( disc < 0 || disc > 99.99) { throw std::invalid_argument("Disount-ul este invalid"); }
        if ( etj < -1 || etj > 99 ) { throw std::invalid_argument("Etajul este invalid"); }
        if ( suprafata < 1) { throw std::invalid_argument("Suprafata este invalida"); }
        this->numeClient = nume;
        this->suprafataUtila = suprafata;
        this->discount = disc;
        this->etaj = etj;
    }
    Apartament(Locuinta* loc, const int& etj) { 
        this->numeClient = loc->Getnume();
        this->suprafataUtila = loc->getSuprafata();
        this->etaj = etj;
        this->discount = loc->getDisount();
        delete loc;
     }
    Apartament(const Apartament& apt)
    {
        this->numeClient = apt.numeClient;
        this->etaj = apt.etaj;
        this->suprafataUtila = apt.suprafataUtila;
        this->discount = apt.discount;
    }
    ~Apartament() = default;
    static void SetTarif(const int& tarif) { Apartament::TarifP = tarif; }
    float CalculChirie(const int &X, const bool &Y)
    {
        return X * suprafataUtila * (1 - Y * discount / 100.0);
    }
    float CalculImpozit();
    float CalculpGunoi(const int& nrPers);
    static float getTarif() { return Apartament::TarifP; }
    Apartament& operator=(const Apartament* apt );
    friend std::ostream &operator<<(std::ostream &os, const Apartament* apartament);
    friend std::istream &operator>>(std::istream &in, Apartament* apartament);
};

std::ostream &operator<<(std::ostream &os, const Apartament* apartament)
{

    os << "Tip Locuinta: Apartament\n"
    << "Nume client: " << apartament->numeClient << "\n"
    << "Suprafata utila(m2): " << apartament->suprafataUtila << '\n'
    << "Etaj: " << apartament->etaj << '\n'
    << "Discount: " << apartament->discount << '\n';
    return os;
}

std::istream &operator>>(std::istream &in, Apartament* apartament)
{

    std::cout << "Nume client: ";
    in >> apartament->numeClient;
    std::cout << '\n';
    std::cout << "Suprafata utila(m2): ";
    in >> apartament->suprafataUtila;
    std::cout << '\n';
    std::cout << "Etaj: ";
    in >> apartament->etaj;
    std::cout << "Discount: ";
    in >> apartament->discount;
    std::cout << '\n';
    return in;
}

std::ostream &operator<<(std::ostream &os, Locuinta* loc)
{
    if ( dynamic_cast<Casa*>(loc) != nullptr )
      {
        os << dynamic_cast<Casa*>(loc);
        return os;
      }
    else if ( dynamic_cast<Apartament*>(loc) != nullptr )
      {
        os << dynamic_cast<Apartament*>(loc);
        return os;
      }
        else
    {

    os << " Nume client: " << loc->numeClient << "Suprafata utila(m2): " << std::endl
       << loc->suprafataUtila << std::endl
       << "Discount: " << std::endl
       << loc->discount << std::endl;
    return os;
    }
}

 std::ostream &operator<<(std::ostream &os, const Casa* casa)
{
    os << "Tip Locuinta: Casa\n"
       << "Suprafata curte: " << casa->suprafataCurte << "\n"
       << "Nume client: " << casa->numeClient << "\n"
       << "Suprafata utila(m2): "
       << casa->suprafataUtila << '\n'
       << "Discount: " << casa->discount << '\n';
    return os;
}

std::istream &operator>>(std::istream &in, Casa* casa)
{

    std::cout << "Nume client: ";
    in >> casa->numeClient;
    std::cout << "Suprafata utila(m2): ";
    in >> casa->suprafataUtila;
    std::cout << "Suprafata curte(m2): ";
    in >> casa->suprafataCurte;
    std::cout << "Discount: ";
    in >> casa->discount;
    return in;
}

std::istream &operator>>(std::istream &in, Locuinta* loc)
{
    if ( dynamic_cast<Casa*>(loc) != nullptr )
      {
         in >> dynamic_cast<Casa*>(loc);
        return in;
      }
    else if ( dynamic_cast<Apartament*>(loc) != nullptr )
      {
         in >> dynamic_cast<Apartament*>(loc);
        return in;
      }
        else
    {
        std::cout << "Nume client: ";
        in >> loc->numeClient;
        std::cout << '\n';
        std::cout << "Suprafata utila: ";
        in >> loc->suprafataUtila;
        std::cout << '\n';
        std::cout << "Discount: ";
        in >> loc->discount;
        std::cout << '\n';
        return in;
    }
 }

Casa& Casa::operator=(const Casa* casa)
{
    this->numeClient = casa->numeClient;
    this->suprafataUtila = casa->suprafataUtila;
    this->suprafataCurte = casa->suprafataCurte;
    this->discount = casa->discount;
    return *this;
}

Apartament& Apartament::operator=(const Apartament* apt)
{
    this->numeClient = apt->numeClient;
    this->suprafataUtila = apt->suprafataUtila;
    this->etaj = apt->etaj;
    this->discount = apt->discount;
    return *this;
}

 Locuinta& Locuinta::operator=(const Locuinta* loc)
 {
    this->numeClient = loc->numeClient;
    this->suprafataUtila = loc->suprafataUtila;
    this ->discount = loc->discount;
    return *this;
 }

 float Casa::CalculImpozit()
 {
    return ((this->suprafataUtila*0.8)+(this->suprafataCurte*0.05));
 }

 float Apartament::CalculImpozit()
{
    return ((this->suprafataUtila*1.6)+(23));
}

float Casa::CalculpGunoi(const int& nrPers)
{
    return (nrPers*Casa::TarifP);
}

float Apartament::CalculpGunoi(const int& nrPers)
{
    return (nrPers*Apartament::TarifP);
}