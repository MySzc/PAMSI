//
// Created by msz on 5/4/19.
//

#include "Dijkstra.h"
#include <climits>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

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

int Dijkstra_M(MacierzSasiedztwa M, int Node_Start) {

    //int dystans[M.lKrawedzi];
    int *dystans = new int [M.lKrawedzi];
    //bool najkrotsza_droga[M.lKrawedzi];
    bool *najkrotsza_droga = new bool [M.lKrawedzi];


    for (int i = 0; i < M.lKrawedzi; ++i) {
        dystans[i] = INT_MAX;
        najkrotsza_droga[i] = false;
    };

    dystans[Node_Start-1] = 0;

    for (int j = 0; j < M.lKrawedzi-1 ; ++j) {

        int u;

        u = ZwrocMinIndeks_M(dystans, najkrotsza_droga, M);

        najkrotsza_droga[u] = true;

        for (int k = 0; k < M.lKrawedzi; ++k)
            if(!najkrotsza_droga[k] && M.Macierz[u][k] && dystans[u] != INT_MAX && dystans[u]+M.Macierz[u][k] < dystans[k])
                dystans[k] = dystans[u]+M.Macierz[u][k];

    }

    std::cout << "Node koncowy:" << "           " << "Dystans od node zrodlowego:" << std::endl;
    for (int l = 0; l < M.lKrawedzi; ++l) {
        std::cout << l+1 <<  "          -----        " << dystans[l] << std::endl;
    }


    return 0;
}

typedef std::pair<int,int> int_pair;

int Dijkstra_L(ListaSasiedztwa L, int Node_Start) {

    //TODO Jak zainicjowac drugi argument tablica/wskaznikiem a nie vectorem
    std::priority_queue< int_pair, std::vector<int_pair>, std::greater<int_pair> > pq;

    int *dystans = new int [L.lKrawedzi];

    for (int i = 0; i < L.lKrawedzi; ++i) {
        dystans[i] = INT_MAX;
    };

    pq.push(std::make_pair(0,Node_Start-1));

    dystans[Node_Start-1] = 0;

    while(!pq.empty()){

        int u = pq.top().second;
        pq.pop();

        for () {


            
        }




    }

    return 0;
}
