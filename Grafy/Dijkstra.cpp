//
// Created by msz on 5/4/19.
//

#include "Dijkstra.h"
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
#include <chrono>

#define INT_MAX 1000000000

int ZwrocMinIndeks_M (int dystans[], bool najkrotsza_droga[], MacierzSasiedztwa M){

    int min = INT_MAX;
    int min_indeks;


    for (int i = 0; i < M.lKrawedzi ; ++i) {
        if( najkrotsza_droga[i] == false && dystans[i] <= min) {
            min = dystans[i];
            min_indeks = i;
        };
    };

    return min_indeks;
}

void Dijkstra_M(MacierzSasiedztwa M, int Node_Start) {

    int *dystans = new int [M.lNodow];
    bool *najkrotsza_droga = new bool [M.lNodow];

    std::cout << "DIJKSTRA_MACIERZ:" << std::endl;

    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < M.lNodow; ++i) {
        dystans[i] = INT_MAX;
        najkrotsza_droga[i] = false;
    };

    dystans[Node_Start] = 0;

    for (int j = 0; j < M.lKrawedzi-1 ; ++j) {

        int u;

        u = ZwrocMinIndeks_M(dystans, najkrotsza_droga, M);

        najkrotsza_droga[u] = true;

        for (int k = 0; k < M.lKrawedzi; ++k)
            if(!najkrotsza_droga[k] && M.Macierz[u][k]  && dystans[u]+M.Macierz[u][k] < dystans[k] && dystans[u] != INT_MAX)
                dystans[k] = dystans[u] + M.Macierz[u][k];

    }

    auto end = std::chrono::steady_clock::now();

    auto diff = end - start;

    std::cout << "Node koncowy:" << "           " << "Dystans od node zrodlowego:" << std::endl;
    for (int l = 0; l < M.lNodow; ++l) {
        std::cout << l <<  "          -----        " << dystans[l] << std::endl;
    }

    std::cout << std::endl << "Szukanie najkrotszej drogi zakonczono w " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl << std::endl << std::endl;

}

typedef std::pair<int,int> int_pair;

void Dijkstra_L(ListaSasiedztwa L, int Node_Start) {

    //TODO Jak zainicjowac drugi argument tablica/wskaznikiem a nie vectorem
    std::priority_queue< int_pair, std::vector<int_pair>, std::greater<int_pair> > pq;

    int *dystans = new int [L.lNodow];

    std::cout << "DIJKSTRA_LISTA:" << std::endl;

    auto start = std::chrono::steady_clock::now();

    for (int i = 0; i < L.lNodow; ++i) {
        dystans[i] = INT_MAX;
    };

    pq.push(std::make_pair(0,Node_Start));

    dystans[Node_Start] = 0;

    int i;
    int v;
    int waga;
    int u;

    while(!pq.empty()) {

        u = pq.top().second;
        pq.pop();

        i = 0;

        while (L.Lista[u][i].second != 0) {


            v = L.Lista[u][i].first;
            waga = L.Lista[u][i].second;

            i++;

            if (dystans[v] > dystans[u] + waga) {

                dystans[v] = dystans[u] + waga;
                pq.push(std::make_pair(dystans[v], v));
            };
        };
    };

    auto end = std::chrono::steady_clock::now();

    auto diff = end - start;



    std::cout << "Node koncowy:" << "           " << "Dystans od node zrodlowego:" << std::endl;
    for (int l = 0; l < L.lNodow; ++l) {
        std::cout << l <<  "          -----        " << dystans[l] << std::endl;
    }

    std::cout << std::endl << "Szukanie najkrotszej drogi zakonczono w " << std::chrono::duration <double, std::milli> (diff).count() << " ms" << std::endl << std::endl << std::endl;

}
