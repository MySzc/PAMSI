//
// Created by msz on 6/2/19.
//

#ifndef WARCABY_GRA_H
#define WARCABY_GRA_H

#include "akcesoriaDoGry.h"
#include "plansza.h"
#include "wielkosci.h"
#include "usprawnienia.h"
#include <SFML/Graphics.hpp>


class graWarcaby{
public:

    Plansza planszaDoGry;
    akcesoriaGry akcesoriaDoGry;


    turaGry Tura;


    void odznaczWszystkiePozaJednym(int x, int y);
    void odznaczWszystkie();
    bool czyCosJestZaznaczone();

    int zwrocZaznaczoneX();
    int zwrocZaznaczoneY();

    turaGry zwrocTure(typPionka typ);

    turaGry zmienTure(turaGry tura);






};


#endif //WARCABY_GRA_H
