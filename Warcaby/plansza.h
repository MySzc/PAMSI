//
// Created by msz on 5/21/19.
//

#ifndef WARCABY_PLANSZA_H
#define WARCABY_PLANSZA_H

#include "wielkosci.h"
#include "usprawnienia.h"



class Pole{
private:

    typPionka Typ;
    int poz_x;
    int poz_y;
    bool zaznacz;

public:

    Pole()= default;

    void setPozX(int poz);
    void setPozY(int poz);
    void setPozXY(int x, int y);
    void setTyp(typPionka typ);
    void zaznaczPionka();
    void odznaczPionka();
    bool czyZaznaczonyPionek();

    int retPozX();
    int retPozY();
    typPionka retTyp();

};


class Plansza{
private:

    Pole plansza_do_gry[WIELKOSC_PLANSZY][WIELKOSC_PLANSZY];

public:

    Plansza()= default;

    void inicjalizujPlansze();
    void inicjalizujPlanszeStart();
    void wyswietlPlansze();

    void zmienTyp(int x, int y, typPionka typ);
    void ruchPionka(int start_x, int start_y, int end_x, int end_y);
    void biciePionka(int start_x, int start_y, int end_x, int end_y);

    Pole zwrocPole(int x,int y);
    typPionka zwrocTypPionka(int x, int y);
};




#endif //WARCABY_PLANSZA_H
