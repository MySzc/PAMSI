#include <iostream>
#include <fstream>
#include "MacierzSasiedztwa.h"
#include "ListaSasiedztwa.h"
#include "Dijkstra.h"


int main() {

    MacierzSasiedztwa wrkMacierz;

    wrkMacierz.OdczytajGraf("test2.txt");

    std::cout << "*********************************************" << std::endl << std::endl;

    ListaSasiedztwa wrkLista;

    wrkLista.OdczytajGraf("test2.txt");

    std::cout << std::endl << "*********************************************" << std::endl << std::endl;

    Dijkstra_M(wrkMacierz, 0);

    std::cout << std::endl << "*********************************************" << std::endl << std::endl;

    Dijkstra_L(wrkLista, 0);

    return 0;
}