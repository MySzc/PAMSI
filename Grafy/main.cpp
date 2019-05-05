#include <iostream>
#include <fstream>
#include "MacierzSasiedztwa.h"
#include "ListaSasiedztwa.h"
#include "Dijkstra.h"


int main() {

    MacierzSasiedztwa wrkMacierz;

    wrkMacierz.OdczytajGraf("test3.txt");

    std::cout << "*********************************************" << std::endl << std::endl;

    ListaSasiedztwa wrkLista;

    wrkLista.OdczytajGraf("test3.txt");

    std::cout << std::endl << "*********************************************" << std::endl << std::endl;

    wrkMacierz.WyswietlMacierz();


    Dijkstra_M(wrkMacierz, 1);

    std::cout << std::endl << "*********************************************" << std::endl << std::endl;

    wrkLista.WyswietlListe();

    Dijkstra_L(wrkLista, 1);

    return 0;
}