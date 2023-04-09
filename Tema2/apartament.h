#include<locuinta.h>

class Apartament : public Locuinta
{
private:
    int etaj;
public:
    Apartament() = default;
    Apartament(const Locuinta& loc, const int& et )
    {
        
    }
    ~Apartament() = default;

};