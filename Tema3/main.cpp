#include "farmacie.h"

template <class T>
int GestionareFarmacii<T>::indexFarmacie = 0;

int main() {
    int idLant = 123;
    GestionareFarmacii<Farmacie>* gestionareFarmacii = GestionareFarmacii<Farmacie>::getInstance(idLant);

    Farmacie_online* farmacie_online = FarmacieOnlineBuilder()
    .setWeb("www.farmacieonline.com")
    .setNrVizitatori(500)
    .setDiscount(10)
    .build();

    std::cout << farmacie_online << '\n';

    std::string farmacieType;
    std::cout << "Enter the type of farmacie (Farmacie/Farmacie_online): ";
    std::cin >> farmacieType;

    Farmacie* farmacie = FarmacieFactory::createFarmacie(farmacieType);
    std::cin >> farmacie;
    gestionareFarmacii->add(farmacie);
    // Adaugare farmacii online
    ///Farmacie* farmacie = new Farmacie();
    //std::cin >> farmacie;
    //gestionareFarmacii->add(farmacie);

    Farmacie_online* farmacieOnline2 = new Farmacie_online();
    //std::cin >> farmacieOnline2;
    ///gestionareFarmacii->add(farmacieOnline2);

    // Afisare farmacii online
   // gestionareFarmacii->afisareFarmacii();

    // Calculare si afisare numar total vizitatori pentru farmaciile online
  //  std::cout << "Numar total vizitatori farmacii online: " << gestionareFarmacii->getNrVizitatoriTotal() << '\n';

    // Eliberare memorie
   // delete farmacie;
   // delete farmacieOnline2;
    int choice;
    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Add Farmacie\n";
        std::cout << "2. Add FarmacieOnline\n";
        std::cout << "3. View Farmacii\n";
        std::cout << "4. View Total Number of Visitors for FarmaciiOnline\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1: {
                std::cout << "Adding Farmacie:\n";
                std::string denumire;
                int nrAngajati;
                std::vector<double> profitLunar;
                std::cout << "Denumire: ";
                std::cin >> denumire;
                std::cout << "NrAngajati: ";
                std::cin >> nrAngajati;
                std::cout << "Pe ultimele cate luni stiti profitul lunar? ";
                int nrProfitLunar;
                std::cin >> nrProfitLunar;
                for (int i = 0; i < nrProfitLunar; i++) {
                    double profit;
                    std::cout << "Profit lunar: ";
                    std::cin >> profit;
                    profitLunar.push_back(profit);
                }
                Farmacie* farmacie = FarmacieBuilder().setDenumire(denumire).setNrAngajati(nrAngajati).addProfitLunar(profitLunar).build();
                gestionareFarmacii->add(farmacie);
                std::cout << "Farmacie added successfully.\n";
                break;
            }
            case 2: {
                std::cout << "Adding FarmacieOnline:\n";
                std::string web;
                int nrVizitatori;
                double discount;
                std::cout << "Web: ";
                std::cin >> web;
                std::cout << "NrVizitatori: ";
                std::cin >> nrVizitatori;
                std::cout << "Discount: ";
                std::cin >> discount;
                Farmacie_online* farmacie_online = FarmacieOnlineBuilder().setWeb(web).setNrVizitatori(nrVizitatori).setDiscount(discount).build();
                gestionareFarmacii->add(farmacie_online);
                std::cout << "FarmacieOnline added successfully.\n";
                break;
            }
            case 3: {
                std::cout << "Viewing Farmacii:\n";
                gestionareFarmacii->afisareFarmacii<Farmacie>();
                gestionareFarmacii->afisareFarmacii<Farmacie_online>();
                break;
            }
            case 4: {
                std::cout << "Total Number of Visitors for FarmaciiOnline: ";
                std::cout << gestionareFarmacii->getNrVizitatoriTotal() << '\n';
                break;
            }
            case 5: {
                std::cout << "Exiting the program.\n";
                // Deallocate memory for the GestionareFarmacii instance
                delete gestionareFarmacii;
                return 0;
            }
            default:
                std::cout << "Invalid choice. Please try again.\n";
                break;
        }

        std::cout << '\n';
    }

    return 0;

}
