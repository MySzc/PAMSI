#include <iostream>
#include <fstream>
#include "MacierzSasiedztwa.h"
#include "ListaSasiedztwa.h"
#include "Dijkstra.h"
#include "BellmanFord.h"


int main() {

    MacierzSasiedztwa wrkMacierz;

    wrkMacierz.OdczytajGraf("test3.txt");

    std::cout << "*********************************************" << std::endl << std::endl;

    ListaSasiedztwa wrkLista;

    wrkLista.OdczytajGraf("test3.txt");

    std::cout << std::endl << "*********************************************" << std::endl << std::endl;

    Dijkstra_M(wrkMacierz, 0);

    std::cout << std::endl << "*********************************************" << std::endl << std::endl;

    Dijkstra_L(wrkLista, 0);

    std::cout << std::endl << "*********************************************" << std::endl << std::endl;

    BellmanFord_M(wrkMacierz, 0);

    std::cout << std::endl << "*********************************************" << std::endl << std::endl;

    BellmanFord_L(wrkLista, 0);

    return 0;
}