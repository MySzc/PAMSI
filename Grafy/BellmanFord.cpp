//
// Created by msz on 5/6/19.
//

#include "BellmanFord.h"
#include <iostream>
#include <chrono>

#define INT_MAX 1000000000

void BellmanFord_M(MacierzSasiedztwa M, int Node_Start) {

    int *dystans = new int [M.lNodow];

    std::cout << "BELLMANFORD_MACIERZ:" << std::endl;

    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < M.lNodow; ++i) {
        dystans[i] = INT_MAX;
    }

    dystans[Node_Start] = 0;

    for (int i = 0; i <  M.lNodow-1 ; ++i) {


        for (int rzad = 0; rzad < M.lNodow; ++rzad) {
            for (int kolumna = 0; kolumna < M.lNodow; ++kolumna) {
                if ((dystans[rzad] + M.Macierz[rzad][kolumna] < dystans[kolumna]) && M.Macierz[rzad][kolumna] != 0)
                    dystans[kolumna] = dystans[rzad] + M.Macierz[rzad][kolumna];
            }
        }

    }

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    std::cout << "Node koncowy:" << "           " << "Dystans od node zrodlowego:" << std::endl;
    for (int l = 0; l < M.lNodow; ++l) {
        std::cout << l <<  "          -----        " << dystans[l] << std::endl;
    }

    std::cout << std::endl << "Szukanie najkrotszej drogi zakonczono w " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl << std::endl << std::endl;
}

void BellmanFord_L(ListaSasiedztwa L, int Node_Start) {

    int *dystans = new int [L.lNodow];

    std::cout << "BELLMANFORD_LISTA:" << std::endl;

    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < L.lNodow; ++i) {
        dystans[i] = INT_MAX;
    }

    dystans[Node_Start] = 0;

    for (int i = 0; i <  L.lNodow-1 ; ++i) {


        for (int rzad = 0; rzad < L.lNodow; ++rzad) {
            for (int kolumna = 0; L.Lista[rzad][kolumna].second != 0 ; ++kolumna) {
                if (dystans[rzad] + L.Lista[rzad][kolumna].second < dystans[L.Lista[rzad][kolumna].first])
                    dystans[L.Lista[rzad][kolumna].first] = dystans[rzad] + L.Lista[rzad][kolumna].second;
            }
        }

    }

    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;

    std::cout << "Node koncowy:" << "           " << "Dystans od node zrodlowego:" << std::endl;
    for (int l = 0; l < L.lNodow; ++l) {
        std::cout << l <<  "          -----        " << dystans[l] << std::endl;
    }

    std::cout << std::endl << "Szukanie najkrotszej drogi zakonczono w " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl << std::endl << std::endl;
}
