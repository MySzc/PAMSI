//
// Created by msz on 5/4/19.
//

#ifndef GRAFY_DIJKSTRA_H
#define GRAFY_DIJKSTRA_H

#include "MacierzSasiedztwa.h"
#include "ListaSasiedztwa.h"

int ZwrocMinIndeks_M (int wagi[], bool najkrotsza_droga[], MacierzSasiedztwa M);

void Dijkstra_M(MacierzSasiedztwa M, int Node_Start);

void Dijkstra_L(ListaSasiedztwa L, int Node_Start);





#endif //GRAFY_DIJKSTRA_H
