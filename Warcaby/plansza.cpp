//
// Created by msz on 5/21/19.
//

#include "plansza.h"
#include "wielkosci.h"
#include <iostream>
#include <cmath>


void Pole::ustawTyp(typPionka typ) {

    this->Typ = typ;
}

typPionka Pole::zwrocTyp() {

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

bool Pole::czyPuste() {

    return this->zwrocTyp() == PUSTE;
}

bool Pole::czyNiedozwolonePole() {

    return this->zwrocTyp() == NIEDOZWOLONE_POLE;
}

bool Pole::czyBialyPionek() {

    return this->zwrocTyp() == BIALY;
}

bool Pole::czyCzarnyPionek() {

    return this->zwrocTyp() == CZARNY;
}

bool Pole::czyBialyDama() {

    return this->zwrocTyp() == BIALY_DAMA;
}

bool Pole::czyCzarnyDama() {

    return this->zwrocTyp() == CZARNY_DAMA;
}

void Pole::ustawKierunekGL() {

    this->kierunki[0] = GORA_LEWO;
}

void Pole::ustawKierunekGP() {

    this->kierunki[1] = GORA_PRAWO;
}

void Pole::ustawKierunekDP() {

    this->kierunki[2] = DOL_PRAWO;
}

void Pole::ustawKierunekDL() {

    this->kierunki[3] = DOL_LEWO;
}

void Pole::ustawBrakRuchu(int indeks) {

    this->kierunki[indeks] = BRAK_RUCHU;
}



Pole Plansza::zwrocPole(int x, int y) {
    return this->plansza_do_gry[x][y];
}

void Plansza::inicjalizujPlansze() {

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            this->zwrocPole(x,y).odznaczPionka();

            this->zwrocPole(x,y).ustawTyp(PUSTE);

        }
    }

}

void Plansza::inicjalizujPlanszeStart() {

    this->inicjalizujPlansze();

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            if( ((y%2 == 0) && (x%2 ==0)) || ((y%2 != 0) && (x%2 != 0)))
                this->zwrocPole(x,y).ustawTyp(NIEDOZWOLONE_POLE);
            else if ( ( ((x%2 != 0) && (y%2 ==0)) || ((x%2 == 0) && (y%2 != 0)) ) && (y < 3) )
                this->zwrocPole(x,y).ustawTyp(CZARNY);
            else if ( (((x%2 != 0) && (y%2 ==0)) || ((x%2 == 0) && (y%2 != 0)) ) && (y > 4) )
                this->zwrocPole(x,y).ustawTyp(BIALY);
        }
    }
}

void Plansza::wyswietlPlanszeTerminal() {

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            if (this->zwrocPole(x,y).zwrocTyp() == NIEDOZWOLONE_POLE)
                std::cout << "|||" << " ";
            else
            if (this->zwrocPole(x,y).zwrocTyp() == PUSTE)
                std::cout << "___" << " ";
            else
            if (this->zwrocPole(x,y).zwrocTyp() == BIALY)
                std::cout << " b " << " ";
            else
            if (this->zwrocPole(x,y).zwrocTyp() == CZARNY)
                std::cout << " c " << " ";
            else
            if (this->zwrocPole(x,y).zwrocTyp() == BIALY_DAMA)
                std::cout << " B " << " ";
            else
            if (this->zwrocPole(x,y).zwrocTyp() == CZARNY_DAMA)
                std::cout << " C " << " ";

        }
                std::cout << std::endl;
    }

}


void Plansza::ruchPionka(int start_x, int start_y, int end_x, int end_y) {

    this->zwrocPole(end_x,end_y).ustawTyp( this->zwrocPole(start_x,start_y).zwrocTyp() );

    this->zwrocPole(start_x,start_y).ustawTyp(PUSTE);

}

