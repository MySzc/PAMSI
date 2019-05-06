//
// Created by msz on 5/6/19.
//

#include "BellmanFord.h"
#include <climits>


void BellmanFord_M(MacierzSasiedztwa M, int Node_Start) {

    int *dystans = new int [M.lNodow];

    for (int i = 0; i < M.lNodow; ++i) {
        dystans[i] = INT_MAX;
    }

    for (int j = 0; j <  M.lKrawedzi-1 ; ++j) {
        for (int i = 0; i < M.lNodow; ++i) {



        }
    }


}
