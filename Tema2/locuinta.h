#include<agentie.h>

class Locuinta
{
private:
    std::string numeClient;
    int suprafataUtila;
    float discount;
public:
    Locuinta() = default;
    Locuinta( const std::string& nume , const int& suprafata , const float& disc )
    {
        this->numeClient = nume;
        this->suprafataUtila = suprafata;
        this->discount = disc;
    }
    Locuinta ( const Locuinta& loc )
    {
        this->numeClient = loc.numeClient;
        this->suprafataUtila = loc.suprafataUtila;
        this->discount = loc.discount;
    }
    ~Locuinta() = default;
};