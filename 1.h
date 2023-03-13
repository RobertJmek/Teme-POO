#include<iostream>
#include<string>

class Data
{
    int zi,an;
    int luna;
public:
    ~Data() {}
    Data(const int& param1, const int& param2, const int& param3)
    {
        luna = param2;
        zi = param1;
        an = param3;
    }
    void const afisData()
    {
        std::cout<<zi<<" "<<luna<<" "<<an<<'\n';
    }
    
    Data() {  }

    friend std::ostream& operator<<(std::ostream& os,const Data& obj);
    friend std::istream& operator>>(std::istream& in, Data& obj);
    bool friend operator<(Data const& data1, Data const& data2);
    bool friend operator>(Data const& data1, Data const& data2);

    friend class Medicament;

};

bool operator>(Data const& data1, Data const& data2)
{
    if ( data1.an < data2.an )
        return false;
    else if (data1.an > data2.an)
        return true;
    else if (data1.luna < data2.luna )
        return false;
    else if (data1.luna > data2.luna )
        return true;
    else if (data1.zi < data2.zi )
        return false;
    else return true;

}

bool operator<(Data const& data1, Data const& data2)
{
    if ( data1.an < data2.an )
        return true;
    else if (data1.an > data2.an)
        return false;
    else if (data1.luna < data2.luna )
        return true;
    else if (data1.luna > data2.luna )
        return false;
    else if (data1.zi < data2.zi )
        return true;
    else return false;
}

std::istream& operator>>(std::istream& in, Data& obj)
{
    in >> obj.zi >> obj.luna >> obj.an;
    return in;
}
std::ostream& operator<<(std::ostream& os,const Data& obj)
{
    os << obj.zi << ' ' << obj.luna << ' ' << obj.an <<std::endl;
    return os;
}
