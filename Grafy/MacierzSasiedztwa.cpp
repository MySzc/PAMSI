//
// Created by msz on 4/28/19.
//
#include <iostream>
#include <string>
#include <fstream>
#include "MacierzSasiedztwa.h"

/*
MacierzSasiedztwa::MacierzSasiedztwa(int liczbaKrawedzi){
    lKrawedzi = liczbaKrawedzi;

    Macierz = new int * [liczbaKrawedzi];

    for (int i = 0; i < liczbaKrawedzi; i++)
        Macierz[i] = new int [liczbaKrawedzi];

}*/

void MacierzSasiedztwa::WyswietlMacierz() {

    // DLA ESTETYKI
    std::cout << "    ";
    for (int i = 0; i < lNodow; ++i) {
        std::cout << "[" << i << "]  ";
    }
    std::cout << std::endl;


    for (int rzad = 0; rzad < lNodow; ++rzad) {
        std::cout << "[" << rzad << "] ";
        for (int kolumna = 0; kolumna < lNodow; ++kolumna) {
            std::cout << " " << Macierz[rzad][kolumna] << "   ";
        }
        std::cout << std::endl << std::endl;
    }
    std::cout << std::endl;
}

void MacierzSasiedztwa::ZainicjujMacierz(int rzad, int kolumna, int waga) {

    Macierz[rzad][kolumna] = waga;
}

void MacierzSasiedztwa::InicjalizacjaWielkosciMacierzy(int liczbaKrawedzi, int liczbaNodow) {

    lKrawedzi = liczbaKrawedzi;
    lNodow = liczbaNodow;

    Macierz = new int * [liczbaKrawedzi];

    for (int i = 0; i < liczbaKrawedzi; i++)
        Macierz[i] = new int [liczbaKrawedzi];

}

void MacierzSasiedztwa::OdczytajGraf(std::string nazwaPliku) {

    int liczbaKrawedzi;
    int liczbaNodow;
    int rzad, kolumna, waga;

    std::ifstream plik;

    plik.open(nazwaPliku);
    if (plik.is_open()) {

        plik >> liczbaKrawedzi >> liczbaNodow;

        this->InicjalizacjaWielkosciMacierzy(liczbaKrawedzi, liczbaNodow);

        //this->WyswietlMacierz();

        while (plik >> rzad >> kolumna >> waga) {
            this->ZainicjujMacierz(rzad, kolumna, waga);
        }

        this->WyswietlMacierz();

    }else
        std::cout << "Nie udalo sie otworzyc pliku.";
    plik.close();

}







