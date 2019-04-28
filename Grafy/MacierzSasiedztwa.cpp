//
// Created by msz on 4/28/19.
//
#include <iostream>
#include <string>
#include <fstream>
#include "MacierzSasiedztwa.h"

MacierzSasiedztwa::MacierzSasiedztwa(int liczbaKrawedzi){
    lKrawiedzi = liczbaKrawedzi;

    Macierz = new int * [liczbaKrawedzi];

    for (int i = 0; i < liczbaKrawedzi; i++)
        Macierz[i] = new int [liczbaKrawedzi];

}




void MacierzSasiedztwa::WyswietlMacierz() {

    for (int rzad = 0; rzad < lKrawiedzi; ++rzad) {
        for (int kolumna = 0; kolumna < lKrawiedzi; ++kolumna) {
            std::cout << Macierz[rzad][kolumna] << "  ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void MacierzSasiedztwa::ZainicjujMacierz(int rzad, int kolumna, int waga) {

    Macierz[rzad-1][kolumna-1] = waga;
}

void MacierzSasiedztwa::InicjalizacjaWielkosciMacierzy(int liczbaKrawedzi) {

    lKrawiedzi = liczbaKrawedzi;

    Macierz = new int * [liczbaKrawedzi];

    for (int i = 0; i < liczbaKrawedzi; i++)
        Macierz[i] = new int [liczbaKrawedzi];

}

void MacierzSasiedztwa::OdczytajGraf(std::string nazwaPliku) {

    int liczbaKrawedzi;
    int rzad, kolumna, waga;

    std::ifstream plik;

    plik.open(nazwaPliku);
    if (plik.is_open()) {

        plik >> liczbaKrawedzi;

        this->InicjalizacjaWielkosciMacierzy(liczbaKrawedzi);

        this->WyswietlMacierz();

        while (plik >> rzad >> kolumna >> waga) {
            this->ZainicjujMacierz(rzad, kolumna, waga);
        }

        this->WyswietlMacierz();

    }else
        std::cout << "Nie udalo sie otworzyc pliku.";
    plik.close();

}







