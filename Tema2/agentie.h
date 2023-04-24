#include"locuinta.h"

class AgentieImobiliara
{
private:
    std::vector<Locuinta*> vAI;
    static int numar_locuinte;
public:
    AgentieImobiliara() = default;
    AgentieImobiliara(const std::vector<Locuinta*>& vector_ptr )
    {
        if ( vector_ptr.size() == 0)
            throw std::runtime_error("Vector it's empty");
        for (auto element = vector_ptr.begin(); element != vector_ptr.end(); element++ )
            {
            this->vAI.push_back(*element);
            AgentieImobiliara::numar_locuinte++;
            }
    }
    ~AgentieImobiliara() = default;
    void AfisCase()
    {
        int i=1;
        for (auto element = vAI.begin(); element != vAI.end(); element++ )
       {
        if ( dynamic_cast<Casa*>(*element) != nullptr)
            {
            std::cout << "\nCasa numarul: " << i << std::endl;
            i++;
            std::cout << *element;
            }
       }
       std::cout << "Numarul total de case este: " << i-1 << std::endl; 
    }
    void AfisAp()
    {
        int i=1;
        for (auto element = vAI.begin(); element != vAI.end(); element++ )
       {
        if ( dynamic_cast<Apartament*>(*element) != nullptr)
            {
            std::cout << "\nApartamentul numarul: " << i << std::endl;
            i++;
            std::cout << *element;
            }
       }
       std::cout << "Numarul total de apartamente este: " << i-1 << std::endl; 
    }
    static int getNrLoc() { return AgentieImobiliara::numar_locuinte; }
    Locuinta* getElement(const int& i) 
    { if ( i < 0 || i > AgentieImobiliara::numar_locuinte-1 )
        throw std::invalid_argument("Locuinta cu numarul dat nu exista");
        return vAI[i]; 
    }
    AgentieImobiliara& add(Locuinta* loc)
    {
        if ( dynamic_cast<Casa*>(loc) != nullptr )
        {   
            loc = dynamic_cast<Casa*>(loc);
            this->vAI.push_back(loc) ;
            AgentieImobiliara::numar_locuinte ++;
        }
        else if ( dynamic_cast<Apartament*>(loc) != nullptr )
        {
            loc = dynamic_cast<Apartament*>(loc);
            this->vAI.push_back(loc) ;
            AgentieImobiliara::numar_locuinte ++;
        }
        else { throw std::invalid_argument("Trebuie sa fie fie de type casa sau apartament"); }
        return *this;
    }
    AgentieImobiliara& pop()
    {
        delete this->vAI[AgentieImobiliara::numar_locuinte-1];
        this->vAI.pop_back();
        AgentieImobiliara::numar_locuinte--;
        return *this;
    }
    friend std::ostream& operator<<( std::ostream& os, const AgentieImobiliara& agentieI );
    friend std::istream& operator>>(std::istream& in, AgentieImobiliara& agentieI );
    AgentieImobiliara& operator=( AgentieImobiliara& AI); 
};
std::istream& operator>>(std::istream& in, AgentieImobiliara& agentieI )
{
  for (auto element = agentieI.vAI.begin(); element != agentieI.vAI.end(); element++ )
       {
        in >> *element;
       }
    return in;  
}
std::ostream& operator<<(std::ostream& os, const AgentieImobiliara& agentieI )
{
    int i=1;
    for (auto element = agentieI.vAI.begin(); element != agentieI.vAI.end(); element++ )
        {
        std::cout<<"Locuinta numarul: "<< i << std::endl;
        i++; 
        os << *element << "\n";
        }
    return os;
}

AgentieImobiliara& AgentieImobiliara::operator=( AgentieImobiliara& AI )
{
    if ( this == &AI  ) return *this;
    for (auto element = AI.vAI.begin(); element != AI.vAI.end(); element++ )
        this->vAI.push_back(*element);  
    return *this;
}


