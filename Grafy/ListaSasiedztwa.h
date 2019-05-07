//
// Created by msz on 5/4/19.
//

#ifndef GRAFY_LISTASASIEDZTWA_H
#define GRAFY_LISTASASIEDZTWA_H

#include <utility>

class ListaSasiedztwa{
public:

    int lKrawedzi;
    int lNodow;
    std::pair <int, int> **Lista;

    ListaSasiedztwa()=default;


    void WyswietlListe();
    void InicjalizacjaWielkosciListy(int liczbaKrawedzi, int liczbaNodow);
    void ZainicjujListe(int node_1, int node_2, int waga);
    void OdczytajGraf(std::string nazwaPliku);


};

#endif //GRAFY_LISTASASIEDZTWA_H
