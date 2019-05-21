//
// Created by msz on 5/21/19.
//

#ifndef WARCABY_PLANSZA_H
#define WARCABY_PLANSZA_H

#include <utility>

class Plansza{

    // Pierwszy element pary != 0 -> pionek bialy, Drugi element pary != 0 -> pionek czarny
    // wartość elementu: 0 - brak pionka, 1 - zwykly pionek, 2 - krolowa
    std::pair<int,int> _Plansza[8][8];

public:

    Plansza();

    void inicPlanszyStart();
    void wyswietlPlansze();



};




#endif //WARCABY_PLANSZA_H
