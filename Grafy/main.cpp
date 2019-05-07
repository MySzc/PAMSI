#include <iostream>
#include <fstream>
#include "MacierzSasiedztwa.h"
#include "ListaSasiedztwa.h"
#include "Dijkstra.h"
#include "BellmanFord.h"

//Dostepne testy: test_100.txt test_75.txt test_50.txt test_25.txt - test dla grafu o 100 wierzcholkach i wypelnieniu 100,75,50,25 %
int main() {

    MacierzSasiedztwa wrkMacierz;

    wrkMacierz.OdczytajGraf("test_25.txt");

    std::cout << "*********************************************" << std::endl << std::endl;

    ListaSasiedztwa wrkLista;

    wrkLista.OdczytajGraf("test_25.txt");

    std::cout << std::endl << "*********************************************" << std::endl << std::endl;

    Dijkstra_M(wrkMacierz, 0);

    std::cout << std::endl << "*********************************************" << std::endl << std::endl;

    Dijkstra_L(wrkLista, 0);

    std::cout << std::endl << "*********************************************" << std::endl << std::endl;

    BellmanFord_M(wrkMacierz, 0);

    std::cout << std::endl << "*********************************************" << std::endl << std::endl;

    BellmanFord_L(wrkLista, 0);


}