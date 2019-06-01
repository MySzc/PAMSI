//
// Created by msz on 5/21/19.
//

#ifndef WARCABY_PLANSZA_H
#define WARCABY_PLANSZA_H

#include "wielkosci.h"
#include "usprawnienia.h"

enum typPionka{
    CZARNY,
    BIALY,
    CZARNY_DAMA,
    BIALY_DAMA,
    PUSTE,
    NIEDOZWOLONE_POLE,
};

class Pole{
private:

    typPionka Typ;
    int poz_x;
    int poz_y;

public:

    Pole()= default;

    void setPozX(int poz);
    void setPozY(int poz);
    void setPozXY(int x, int y);
    void setTyp(typPionka typ);

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
};




#endif //WARCABY_PLANSZA_H
