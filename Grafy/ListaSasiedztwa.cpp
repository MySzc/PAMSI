//
// Created by msz on 5/4/19.
//

#include <iostream>
#include <string>
#include <fstream>
#include "ListaSasiedztwa.h"

void ListaSasiedztwa::WyswietlListe() {

    for (int rzad = 0; rzad < lNodow; ++rzad) {
        std::cout << "[" << rzad << "] ";
        for (int kolumna = 0; kolumna < lNodow; ++kolumna) {

            if(Lista[rzad][kolumna].second != 0)
            std::cout << Lista[rzad][kolumna].first << " , " << Lista[rzad][kolumna].second << " ; ";

        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

}

void ListaSasiedztwa::InicjalizacjaWielkosciListy(int liczbaKrawedzi, int liczbaNodow) {

    lKrawedzi = liczbaKrawedzi;
    lNodow = liczbaNodow;

    Lista = new std::pair<int,int> * [liczbaNodow];

    for (int i = 0; i < liczbaKrawedzi; i++)
        Lista[i] = new std::pair<int,int> [liczbaNodow];

}

void ListaSasiedztwa::ZainicjujListe(int node_1, int node_2, int waga) {

    int i = 0;

    while(Lista[node_1][i].second != 0){
        i++;
    }

    Lista[node_1][i].first = node_2;
    Lista[node_1][i].second = waga;

}

void ListaSasiedztwa::OdczytajGraf(std::string nazwaPliku) {

    int liczbaKrawedzi;
    int liczbaNodow;
    int rzad, kolumna, waga;

    std::ifstream plik;

    plik.open(nazwaPliku);
    if (plik.is_open()) {

        plik >> liczbaKrawedzi >> liczbaNodow;

        this->InicjalizacjaWielkosciListy(liczbaKrawedzi, liczbaNodow);

        //this->WyswietlListe();

        while (plik >> rzad >> kolumna >> waga) {
            this->ZainicjujListe(rzad, kolumna, waga);
        }

        this->WyswietlListe();

    }else
        std::cout << "Nie udalo sie otworzyc pliku.";
    plik.close();

}
