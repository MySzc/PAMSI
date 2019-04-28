//
// Created by msz on 4/28/19.
//

#ifndef GRAFY_MACIERZSASIEDZTWA_H
#define GRAFY_MACIERZSASIEDZTWA_H

class MacierzSasiedztwa{
public:
    int lKrawiedzi;
    int **Macierz;

    MacierzSasiedztwa(){};
    MacierzSasiedztwa(int liczbaKrawedzi);



    void WyswietlMacierz();
    void InicjalizacjaWielkosciMacierzy(int liczbaKrawedzi);
    void ZainicjujMacierz(int rzad, int kolumna, int waga);
    void OdczytajGraf(std::string nazwaPliku);
};



#endif //GRAFY_MACIERZSASIEDZTWA_H
