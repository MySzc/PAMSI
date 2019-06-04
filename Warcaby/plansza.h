//
// Created by msz on 5/21/19.
//

#ifndef WARCABY_PLANSZA_H
#define WARCABY_PLANSZA_H

#include "wielkosci.h"
#include "usprawnienia.h"



class Pole{
public:

    typPionka Typ;
    bool zaznacz;
    kierunkiRuchu kierunki[ILOSC_RUCHOW];


    Pole();

    void ustawTyp(typPionka typ);
    typPionka zwrocTyp();

    bool czyPuste();
    bool czyNiedozwolonePole();
    bool czyBialyPionek();
    bool czyCzarnyPionek();
    bool czyBialyDama();
    bool czyCzarnyDama();

    void ustawKierunekGL();
    void ustawKierunekGP();
    void ustawKierunekDP();
    void ustawKierunekDL();
    void ustawBrakRuchu(int indeks);

    void zaznaczPionka();
    void odznaczPionka();
    bool czyZaznaczonyPionek();
};


class Plansza{
public:

    Pole plansza_do_gry[WIELKOSC_PLANSZY][WIELKOSC_PLANSZY];



    Plansza()= default;

    //Pole zwrocPole(int x,int y);

    void inicjalizujPlansze();
    void inicjalizujPlanszeStart();

    int ileBialychPionkow();
    int ileCzarnychPionkow();

    void wyswietlPlanszeTerminal();

    void ruchPionkaKoordynaty(int start_x, int start_y, int end_x, int end_y);
    void ruchPionkaZaznaczenie(int end_x, int end_y);
    void biciePionkaKoordynaty(int start_x, int start_y, int end_x, int end_y);
    void biciePionkaZaznaczenie(int end_x,int end_y);

    void odznaczWszystkie();
    bool czyCosJestZaznaczone();

    bool czyRuchJestDozwolonyGracz(int end_x, int end_y);
    bool czyBicieJestDozwoloneGracz(int end_x, int end_y);
};




#endif //WARCABY_PLANSZA_H
