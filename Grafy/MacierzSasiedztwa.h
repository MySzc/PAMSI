//
// Created by msz on 4/28/19.
//

#ifndef GRAFY_MACIERZSASIEDZTWA_H
#define GRAFY_MACIERZSASIEDZTWA_H

#include <string>

class MacierzSasiedztwa{
public:
    int lKrawedzi;
    int lNodow;
    int **Macierz;

    MacierzSasiedztwa()=default;


    void WyswietlMacierz();
    void InicjalizacjaWielkosciMacierzy(int liczbaKrawedzi, int liczbaNodow);
    void ZainicjujMacierz(int rzad, int kolumna, int waga);
    void OdczytajGraf(std::string nazwaPliku);
};



#endif //GRAFY_MACIERZSASIEDZTWA_H
