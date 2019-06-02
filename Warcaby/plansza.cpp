//
// Created by msz on 5/21/19.
//

#include "plansza.h"
#include "wielkosci.h"
#include <iostream>
#include <cmath>

#define WIELKOSC_PLANSZY 8

void Pole::setPozX(int poz) {

    this->poz_x = poz;
}


void Pole::setPozY(int poz) {

    this->poz_y = poz;
}


void Pole::setPozXY(int x, int y) {

    this->setPozX(x);
    this->setPozY(y);
}


void Pole::setTyp(typPionka typ) {

    this->Typ = typ;
}


int Pole::retPozX() {

    return this->poz_x;
}


int Pole::retPozY() {

    return this->poz_y;
}


typPionka Pole::retTyp() {

    return this->Typ;
}


void Pole::zaznaczPionka() {

    this->zaznacz = true;
}

void Pole::odznaczPionka() {

    this->zaznacz = false;

}

bool Pole::czyZaznaczonyPionek() {
    return this->zaznacz;
}


void Plansza::inicjalizujPlansze() {

    for (int i = 0; i < WIELKOSC_PLANSZY; ++i) {
        for (int j = 0; j < WIELKOSC_PLANSZY; ++j) {

            this->plansza_do_gry[i][j].setPozX(i);
            this->plansza_do_gry[i][j].setPozY(j);

            this->plansza_do_gry[i][j].setTyp(PUSTE);

        }
    }

}


void Plansza::inicjalizujPlanszeStart() {

    this->inicjalizujPlansze();

    for (int i = 0; i < WIELKOSC_PLANSZY; ++i) {
        for (int j = 0; j < WIELKOSC_PLANSZY; ++j) {

            if( ((i%2 == 0) && (j%2 ==0)) || ((i%2 != 0) && (j%2 != 0)))
                this->plansza_do_gry[i][j].setTyp(NIEDOZWOLONE_POLE);
            else if ( ( ((i%2 != 0) && (j%2 ==0)) || ((i%2 == 0) && (j%2 != 0)) ) && (i < 3) )
                this->plansza_do_gry[i][j].setTyp(CZARNY);
            else if ( (((i%2 != 0) && (j%2 ==0)) || ((i%2 == 0) && (j%2 != 0)) ) && (i > 4) )
                this->plansza_do_gry[i][j].setTyp(BIALY);
        }
    }

}

void Plansza::wyswietlPlansze() {

    for (int i = 0; i < WIELKOSC_PLANSZY; ++i) {
        for (int j = 0; j < WIELKOSC_PLANSZY; ++j) {

            if (this->plansza_do_gry[i][j].retTyp() == NIEDOZWOLONE_POLE)
                std::cout << "|||" << " ";
            else
            if (this->plansza_do_gry[i][j].retTyp() == PUSTE)
                std::cout << "___" << " ";
            else
            if (this->plansza_do_gry[i][j].retTyp() == BIALY)
                std::cout << " b " << " ";
            else
            if (this->plansza_do_gry[i][j].retTyp() == CZARNY)
                std::cout << " c " << " ";
            else
            if (this->plansza_do_gry[i][j].retTyp() == BIALY_DAMA)
                std::cout << " B " << " ";
            else
            if (this->plansza_do_gry[i][j].retTyp() == CZARNY_DAMA)
                std::cout << " C " << " ";

        }
                std::cout << std::endl;
    }

}


void Plansza::zmienTyp(int x, int y, typPionka typ) {

    this->plansza_do_gry[x][y].setTyp(typ);
}


void Plansza::ruchPionka(int start_x, int start_y, int end_x, int end_y) {

    this->zmienTyp(end_x,end_y, this->plansza_do_gry[start_x][start_y].retTyp() );
    this->zmienTyp(start_x, start_y, PUSTE);

}

void Plansza::biciePionka(int start_x, int start_y, int end_x, int end_y) {

    this->zmienTyp(end_x,end_y, this->plansza_do_gry[start_x][start_y].retTyp() );
    this->zmienTyp(start_x, start_y, PUSTE);

    kierunkiRuchu tmp;

    tmp = sprawdzKierunekRuchu(start_x, start_y, end_x, end_y);

    this->zmienTyp(kierunekZbityPionka_X(end_x, tmp), kierunekZbityPionka_Y(end_y, tmp), PUSTE);
}

Pole Plansza::zwrocPole(int x, int y) {
    return this->plansza_do_gry[x][y];
}

typPionka Plansza::zwrocTypPionka(int x, int y) {
    return this->zwrocPole(x,y).retTyp();
}



