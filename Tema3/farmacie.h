#include<iostream>
#include<vector>
#include<string>

class Farmacie
{
protected:
    std::string denumire;
    int nr_angajati;
    std::vector<double> profit_lunar;
public:
    Farmacie() = default;
    Farmacie(const std::string& denumire,const int& nr_angajati, const std::vector<double>& profit_lunar) : denumire(denumire), nr_angajati(nr_angajati), profit_lunar(profit_lunar) {};
    friend  std::istream& operator>>(std::istream& in, Farmacie* farma);
    friend  std::ostream& operator<<(std::ostream& out,const Farmacie* farma);
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
    friend std::ostream& operator<<(std::ostream& out,const Farmacie_online* farma);
    int getNrVizitatori() const { return nr_vizitatori; }
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

std::ostream& operator<<(std::ostream& out,const Farmacie_online* farma)
{
    out << "Adresa web: " << farma->web << '\n';
    out << "Numar vizitatori: " << farma->nr_vizitatori << '\n';
    out << "Discount: " << farma->discount << '\n';
    return out;
}

template <class T>
class GestionareFarmacii {
private:
    static GestionareFarmacii* instance;
    static int indexFarmacie;
    const int idLant;
    std::vector<T*> farmacii;
    GestionareFarmacii(int& lant) : idLant(lant) {}
public:
    ~GestionareFarmacii() = default;
    GestionareFarmacii() = delete;
    static GestionareFarmacii* getInstance(int& lant) {
        if (!instance) {
            instance = new GestionareFarmacii(lant);
        }
        return instance;
    }  
    void add(T* farmacie) {
        farmacii.push_back(farmacie);
        GestionareFarmacii::indexFarmacie++;
    }
    std::vector <T*> getFarmacii() const {
        return farmacii;
    }
    int getNrVizitatoriTotal() const {
        int nrVizitatoriTotal = 0;
        for (const T* farmacie : farmacii) {
            const Farmacie_online* farmacieOnline = dynamic_cast<const Farmacie_online*>(farmacie);
            if ( farmacieOnline != nullptr) {
                nrVizitatoriTotal += farmacieOnline->getNrVizitatori();
            }
        }
        return nrVizitatoriTotal;
    }
    GestionareFarmacii(const GestionareFarmacii&) = delete;
    GestionareFarmacii& operator=(const GestionareFarmacii&) = delete; 


template <class U>
 void afisareFarmacii() const {
        for (const T* farmacie : farmacii) {
            const U* farmacieDerived = dynamic_cast<const U*>(farmacie);
            if (farmacieDerived != nullptr) {
                std::cout << farmacieDerived << '\n';
            }
        }

 }
};

class FarmacieFactory {
public:
    static Farmacie* createFarmacie(const std::string& type)
    {
        if (type == "Farmacie")
            return new Farmacie();
        else if (type == "Farmacie_online")
            return new Farmacie_online();
        else
            return nullptr;
    }
};

class FarmacieBuilder {
private:
    std::string denumire;
    int nr_angajati;
    std::vector<double> profit_lunar;

public:
    FarmacieBuilder() {}

    FarmacieBuilder& setDenumire(const std::string& denumire) {
        this->denumire = denumire;
        return *this;
    }

    FarmacieBuilder& setNrAngajati(int nr_angajati) {
        this->nr_angajati = nr_angajati;
        return *this;
    }

    FarmacieBuilder& addProfitLunar(std::vector<double> vectorprofit) {
        this->profit_lunar = vectorprofit;
        return *this;
    }

    Farmacie* build() {
        return new Farmacie(denumire, nr_angajati, profit_lunar);
    }
};

class FarmacieOnlineBuilder {
private:
    std::string web;
    int nr_vizitatori;
    int discount;

public:
    FarmacieOnlineBuilder() {}

    FarmacieOnlineBuilder& setWeb(const std::string& web) {
        this->web = web;
        return *this;
    }

    FarmacieOnlineBuilder& setNrVizitatori(int nr_vizitatori) {
        this->nr_vizitatori = nr_vizitatori;
        return *this;
    }

    FarmacieOnlineBuilder& setDiscount(int discount) {
        this->discount = discount;
        return *this;
    }

    Farmacie_online* build() {
        Farmacie_online* farmacie_online = new Farmacie_online(web, nr_vizitatori, discount);
        return farmacie_online;
    }
};


template <class T>
GestionareFarmacii<T>* GestionareFarmacii<T>::instance = nullptr;