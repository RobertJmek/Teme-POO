#include<iostream>
#include<vector>
#include<string>


// Tema 6. Se dorește implementarea unei aplicații OOP care sa permita gestionarea activității unor farmacii apartinand proprietarului X.
// Pentru fiecare farmacie se cunoaște cel puțin denumirea, numărul de angajați și profiturile pe fiecare luna. Farmaciile pot fi și online. 
// În acest caz se cunoaște doar adresa web, numărul de vizitatori și discountul utilizat.

// Cerința suplimentară: 
// - Să se adauge toate câmpurile relevante pentru modelarea acestei probleme.
// - Să se construiască clasa template GestionareFarmacii care sa conțină informații despre diversele tipuri de farmacii. Clasa conține indexul farmaciei (incrementat automat la adaugarea unei noi file), id-ul lanțului (constant) și o structura de obiecte, alocată dinamic. Sa se supraincarce operatorul += pentru inserarea unei noi farmacii online în structura.
// - Să se construiască o specializare pentru tipul Farmacie_online care sa conțină și să afișeze doar numărul total de vizitatori ai farmaciilor online. 

// Structura de date: vector sau list <tuple<web, nr_vizitatori, discount>> se rețin farmaciile online.



class Farmacie
{
protected:
    std::string denumire;
    int nr_angajati;
    std::vector<double> profit_lunar;
public:
    Farmacie() = default;
    Farmacie(const std::string& denumire,const int& nr_angajati, const std::vector<double>& profit_lunar) : denumire(denumire), nr_angajati(nr_angajati), profit_lunar(profit_lunar) {};
    friend std::istream& operator>>(std::istream& in, Farmacie* farma);
    friend std::ostream& operator<<(std::ostream& out,const Farmacie* farma);
    virtual ~Farmacie() = default;


};

class Farmacie_online : public Farmacie
{
private:
    std::string web;
    int nr_vizitatori;
    int discount;
public:
    Farmacie_online() = default;
    Farmacie_online(const std::string& web, const int& nr_vizitatori, const int& discount) : web(web), nr_vizitatori(nr_vizitatori), discount(discount) {};
    friend std::istream& operator>>(std::istream& in, Farmacie_online* farma);
    friend std::ostream& operator<<(std::ostream& out, Farmacie_online* farma);
    ~Farmacie_online() = default;
};

std::istream& operator>>(std::istream& in, Farmacie* farma)
{
    std::cout << "Denumire: ";
    in >> farma->denumire;
    std::cout << "Numar angajati: ";
    in >> farma->nr_angajati;
    std::cout << "Pe ultimele cate luni stii profitul? ";
    int nr_luni;
    in >> nr_luni;
    for (int i = 0; i < nr_luni; i++)
    {
        double profit;
        in >> profit;
        farma->profit_lunar.push_back(profit);
    }
    return in;
}

std::ostream& operator<<(std::ostream& out,const Farmacie* farma)
{
    out << "Denumire: " << farma->denumire << '\n';
    out << "Numar angajati: " << farma->nr_angajati << '\n';
    out << "Profit pe ultimele luni: ";
    for (auto& profit : farma->profit_lunar)
    {
        out << profit << ' ';
    }
    out << '\n';
    return out;
}

std::istream& operator>>(std::istream& in, Farmacie_online* farma)
{
    std::cout << "Adresa web: ";
    in >> farma->web;
    std::cout << "Numar vizitatori: ";
    in >> farma->nr_vizitatori;
    std::cout << "Discount: ";
    in >> farma->discount;
    return in;
}

std::ostream& operator<<(std::ostream& out, Farmacie_online* farma)
{
    out << "Adresa web: " << farma->web << '\n';
    out << "Numar vizitatori: " << farma->nr_vizitatori << '\n';
    out << "Discount: " << farma->discount << '\n';
    return out;
}



template <class T>
class GestionareFarmacii {
private:
    static int indexFarmacie;
    const int idLant;
    std::vector<T*> farmacii;

public:
    GestionareFarmacii(int idLant) : idLant(idLant) {}

    ~GestionareFarmacii() {
        for (T* farmacie : farmacii) {
            delete farmacie;
        }
    }

    void operator+=(T* farmacie) {
        farmacii.push_back(farmacie);
        GestionareFarmacii::indexFarmacie++;
    }

    void afisareFarmacii() const {
        for (const T* farmacie : farmacii) 
            std::cout << farmacie << '\n';
        }
    };