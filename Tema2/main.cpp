#include "agentie.h"
#include <limits>

float Casa::TarifP = 0;
float Apartament::TarifP = 0;
int AgentieImobiliara::numar_locuinte = 0;

Locuinta *NewObject(const int &n)
{
  Locuinta *casa = new Casa;
  if (n == 0)
    return casa;
  Locuinta *apt = new Apartament;
  delete casa;
  if (n == 1)
    return apt;
  else
  {
    delete apt;
    throw std::invalid_argument("Nu e bun");
  }
}

int main()
{
  int Pretm2Casa;
  int Pretm2Apartament;
  int tarifGunoiAp;
  int tarifGunoiCa;
  int NumarMeniu;
  int Numar_meniu_1;
  std::string numeClient;
  int SuprafataUtila;
  int suprafataCurte;
  float discount;
  int etaj;
  float Leim2;
  bool disc;
  int numar_persoane;
  int Numar_meniu_2;
  int Numar_meniu_3 = 1;
  int Numar_meniu_4;
  int Numar_meniu_5;
  int Numar_meniu_6;
  int Numar_meniu_7;
  int Numar_meniu_8;
  AgentieImobiliara AgentiaMea;
  std::cout << "**************************************************\n";
  std::cout << "*************Bine ai venit!***********************\n";
  std::cout << "**************************************************\n";
  std::cout << "Inainte de toate...Hai sa stabilim niste lucruri...:\n";
  std::cout << "Pretul care este platit la gunoi.\n  Cati lei/persoana se platesc la apartament? ";
  std::cin >> tarifGunoiAp;
  while (1)
  {
    if (std::cin.fail() || tarifGunoiAp < 0) // returns true when input fails
    {
      std::cin.clear(); // use to clear error state of buffer
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Nu e bun, baga un numar fara virgula si pozitiv: " << std::endl;
      std::cin >> tarifGunoiAp;
    }
    if (!std::cin.fail() && tarifGunoiAp > 0)
      break;
  }
  Apartament::SetTarif(tarifGunoiAp);
  std::cout << "  Dar la casa? ";
  std::cin >> tarifGunoiCa;
  while (1)
  {
    if (std::cin.fail() || tarifGunoiCa < 0) // returns true when input fails
    {
      std::cin.clear(); // use to clear error state of buffer
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
      std::cout << "Nu e bun, baga un numar fara virgula si pozitiv: " << std::endl;
      std::cin >> tarifGunoiCa;
    }
    if (!std::cin.fail() && tarifGunoiCa > 0)
      break;
  }
  Casa::SetTarif(tarifGunoiCa);
  do
  {
    std::cout << "**************************************************\n";
    std::cout << "*************Meniu principal**********************\n";
    std::cout << "**************************************************\n";
    std::cout << "1. Introdu 1 + enter pentru a-ti prelucra propria ta agentie imobiliara.\n";
    std::cout << "2. Introdu 2 + enter pentru a afisa toate locuintele din agentia ta imboliara.\n";
    std::cout << "3. Introdu 3 + enter pentru a elimina ultima locuinta adaugata.\n";
    std::cout << "4. Introdu 4 + enter pentru a calcula chiria pentru o anumita locuinta.\n";
    std::cout << "5. Introdu 5 + enter pentru a calcula pretul gunoiului pentru o anumita locuinta.\n";
    std::cout << "6. Introdu 6 + enter pentru a calcula impozitul pentu o anumita locuinta.\n";
    std::cout << "7. Introdu 7 + enter pentru a afisa toate casele \n";
    std::cout << "8. Introdu 8 + enter pentru a afisa toate apartamentele\n";
    std::cout << "0. Introdu 0 + enter pentru a iesi. \n";
    std::cin >> NumarMeniu;
    while (NumarMeniu < 0 || NumarMeniu > 10)
    {
      {
        std::cout << "Numarul de meniu nu e valid, te rog sa introduci altul: ";
        std::cin >> NumarMeniu;
      }
      break;
    }
    switch (NumarMeniu)
    {
    case 0:
      break;
    case 1:
      do
      {
        std::cout << "Apasa 0 + enter pentru a te intoarce la meniul principal.\n";
        std::cout << "Apasa 1 + enter pentru a introduce o casa in agentia ta\n";
        std::cout << "Apasa 2 + enter pentru a introduce un apartament in agentia ta\n";
        std::cin >> Numar_meniu_1;
        switch (Numar_meniu_1)
        {
        case 0:
          break;
        case 1:
          try
          {
            {
              std::cout << "Nume client: ";
              std::cin >> numeClient;
              std::cout << "Suprafata utila(m2): ";
              std::cin >> SuprafataUtila;
              std::cout << "Suprafata curte(m2): ";
              std::cin >> suprafataCurte;
              std::cout << "Discount: ";
              std::cin >> discount;
            }
            Locuinta *casa = new Casa(numeClient, SuprafataUtila, discount, suprafataCurte);
            AgentiaMea.add(casa);
            ////delete casa;
          }
          catch (const std::exception &e)
          {
            std::cerr << e.what() << ". Locuinta nu s-a adaugat. Introduceti o locuinta cu date corecte: \n"
                      << '\n';
            break;
          }
          {
            std::cout << "Locuinta a fost adaugata cu succes!\n ";
            break;
          }
        case 2:
          try
          {
            {
              std::cout << "Nume client: ";
              std::cin >> numeClient;
              std::cout << "Suprafata utila(m2): ";
              std::cin >> SuprafataUtila;
              std::cout << "Etaj: ";
              std::cin >> etaj;
              std::cout << "Discount: ";
              std::cin >> discount;
            }
            Locuinta *apt = new Apartament(numeClient, SuprafataUtila, discount, etaj);
            AgentiaMea.add(apt);
            /// delete apt;
          }
          catch (const std::exception &e)
          {
            std::cerr << e.what() << ". Locuinta nu s-a adaugat. Introduceti o locuinta cu date corecte: \n"
                      << '\n';
            break;
          }
          std::cout << "Locuinta a fost adaugata cu succes!\n ";
          break;
        }
      } while (Numar_meniu_1 != 0);
      break;
    case 2:
    {
      do
      {
        std::cout << "Locuintele din cadrul agentiei dumneavosta imobiliare sunt:\n"
                  << '\n';
        std::cout << AgentiaMea;
        std::cout << "Numar total locuinte: " << AgentieImobiliara::getNrLoc() << std::endl;
        std::cout << "Apasati 0 + enter pentru a reveni la meniul principal\n";
        std::cin >> Numar_meniu_2;
      } while (Numar_meniu_2 != 0);
      break;
    }
    case 3:
      do
      {
        if (Numar_meniu_3 == 1)
        {
          AgentiaMea.pop();
          std::cout << "Ultima locuinta adaugata a fost stearsa cu succes!\n";
        }
        std::cout << "Apasa 1 + enter pentru a sterge inca o locuinta\n";
        std::cout << "Apasa 0 + enter pentru a reveni la meniul principal\n";
        std::cin >> Numar_meniu_3;
      } while (Numar_meniu_3 != 0);
      break;
    case 4:
      do
      {
        try
        {
          int i;
          std::cout << "Introdu numarul de ordine al locuintei pentru care vrei sa calculezi chiria:\n";
          std::cin >> i;
          Locuinta *obj = AgentiaMea.getElement(i - 1);
          std::cout << "Introdu pretul/m2 in lei: ";
          std::cin >> Leim2;
          std::cout << std::endl;
          std::cout << "Vrei ca discountul sa fie luat in considerare(0 + enter pentru nu si 1 + enter pentru da)? Discountul pentru aceasta locuinta este " << obj->getDisount() << "%:" << std::endl;
          std::cin >> disc;
          std::cout << "Pretul chiriei pentru aceasta locuinta este " << obj->CalculChirie(Leim2,disc) << " lei pe luna" << std::endl;

        }
        catch (const std::exception &e)
        {
          std::cerr << e.what() << '!!\n';
          break;
        }
        std::cout << "Introdu 0 + enter pentru a te intoarce la meniul principal! \n";
        std::cin >> Numar_meniu_4;

      } while (Numar_meniu_4 != 0);
      break;
    case 5:
    do
      {
        try
        {
          int i;
          std::cout << "Introdu numarul de ordine al locuintei pentru care vrei sa calculezi pretul gunoiului:\n";
          std::cin >> i;
          Locuinta *obj = AgentiaMea.getElement(i - 1);
          std::cout << "Introdu numarul de persoane din locuinnta:\n";
          std::cin >> numar_persoane;
          std::cout << std::endl;
          std::cout << "Pretul la gunoi pentru aceasta locuinta este " << obj->CalculpGunoi(numar_persoane) << " lei pe luna" << std::endl;

        }
        catch (const std::exception &e)
        {
          std::cerr << e.what() << "!!" << std::endl;
          break;
        }
        std::cout << "Introdu 0 + enter pentru a te intoarce la meniul principal! \n";
        std::cin >> Numar_meniu_5;

      } while (Numar_meniu_5 != 0);
      break;
    case 6:
    do
      {
        try
        {
          int i;
          std::cout << "Introdu numarul de ordine al locuintei pentru care vrei sa calculezi pretul impozitului:\n";
          std::cin >> i;
          Locuinta *obj = AgentiaMea.getElement(i - 1);
          std::cout << std::endl;
          std::cout << "Pretul impozitului pentru aceasta locuinta este " << obj->CalculImpozit() << " lei pe an" << std::endl;

        }
        catch (const std::exception &e)
        {
          std::cerr << e.what() << "!!" << std::endl;
          break;
        }
        std::cout << "Introdu 0 + enter pentru a te intoarce la meniul principal! \n";
        std::cin >> Numar_meniu_6;

      } while (Numar_meniu_6 != 0);
      break;
    case 7:
    do
    {
      AgentiaMea.AfisCase(); 
      
      std::cout << "\n\n\n\n\n";
      std::cout << "Apasati 0 + enter pentru revenire la meniul principal\n";
      std::cin >> Numar_meniu_7;
    } while( Numar_meniu_7 != 0);
    break;
    case 8:
    do
    {
      AgentiaMea.AfisAp();
      std::cout << "\n\n\n\n\n";
      std::cout << "Apasati 0 + enter pentru revenire la meniul principal\n";
      std::cin >> Numar_meniu_8;
    } while ( Numar_meniu_8 != 0 );
    break;
  }
} while (NumarMeniu != 0);
std::cout<<"\n Ati ales sa inchideti programul! Bye Bye ";
}


