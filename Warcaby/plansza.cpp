//
// Created by msz on 5/21/19.
//

#include "plansza.h"
#include "wielkosci.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>


Pole::Pole() {

    this->ustawTyp(PUSTE);

    this->odznaczPionka();

    for (int indeks = 0; indeks < ILOSC_RUCHOW; ++indeks) {
        this->ustawBrakRuchu(indeks);
    }
}

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

bool Pole::czyBialy() {

    return (this->zwrocTyp() == BIALY || this->zwrocTyp() == BIALY_DAMA);
}

bool Pole::czyCzarny() {

    return (this->zwrocTyp() == CZARNY || this->zwrocTyp() == CZARNY_DAMA);
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


/*
Pole Plansza::zwrocPole(int x, int y) {

    return this->plansza_do_gry[x][y];
}
*/

void Plansza::inicjalizujPlansze() {

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            this->plansza_do_gry[x][y].odznaczPionka();

            this->plansza_do_gry[x][y].ustawTyp(PUSTE);

        }
    }

}

void Plansza::inicjalizujPlanszeStart() {

    this->inicjalizujPlansze();

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            if( ((y%2 == 0) && (x%2 ==0)) || ((y%2 != 0) && (x%2 != 0)))
                this->plansza_do_gry[x][y].ustawTyp(NIEDOZWOLONE_POLE);
            else if ( ( ((x%2 != 0) && (y%2 ==0)) || ((x%2 == 0) && (y%2 != 0)) ) && (x < 3) )
                this->plansza_do_gry[x][y].ustawTyp(CZARNY);
            else if ( (((x%2 != 0) && (y%2 ==0)) || ((x%2 == 0) && (y%2 != 0)) ) && (x > 4) )
                this->plansza_do_gry[x][y].ustawTyp(BIALY);
        }
    }
}

void Plansza::wyswietlPlanszeTerminal() {

    for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {
        for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {

            if (this->plansza_do_gry[x][y].zwrocTyp() == NIEDOZWOLONE_POLE)
                std::cout << "|||" << " ";
            else
            if (this->plansza_do_gry[x][y].zwrocTyp() == PUSTE)
                std::cout << "___" << " ";
            else
            if (this->plansza_do_gry[x][y].zwrocTyp() == BIALY)
                std::cout << " b " << " ";
            else
            if (this->plansza_do_gry[x][y].zwrocTyp() == CZARNY)
                std::cout << " c " << " ";
            else
            if (this->plansza_do_gry[x][y].zwrocTyp() == BIALY_DAMA)
                std::cout << " B " << " ";
            else
            if (this->plansza_do_gry[x][y].zwrocTyp() == CZARNY_DAMA)
                std::cout << " C " << " ";

        }
                std::cout << std::endl;
    }

}


void Plansza::ruchPionkaKoordynaty(int start_x, int start_y, int end_x, int end_y) {

    this->plansza_do_gry[end_x][end_y].ustawTyp( this->plansza_do_gry[start_x][start_y].zwrocTyp() );

    this->plansza_do_gry[start_x][start_y].ustawTyp(PUSTE);

}

void Plansza::ruchPionkaZaznaczenie(int end_x, int end_y) {

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

           if(this->plansza_do_gry[y][x].czyZaznaczonyPionek())
               this->ruchPionkaKoordynaty(y,x,end_y,end_x);

        }
    }
}

void Plansza::biciePionkaKoordynaty(int start_x, int start_y, int end_x, int end_y) {

    kierunkiRuchu kier;
    int bity_x=0, bity_y=0;

    this->plansza_do_gry[end_x][end_y].ustawTyp( this->plansza_do_gry[start_x][start_y].zwrocTyp() );

    this->plansza_do_gry[start_x][start_y].ustawTyp(PUSTE);

    kier = sprawdzKierunekRuchu(start_x,start_y,end_x,end_y);
    bity_x = kierunekZbityPionka_X(end_y, kier);
    bity_y = kierunekZbityPionka_Y(end_x, kier);

    this->plansza_do_gry[bity_y][bity_x].ustawTyp(PUSTE);

}


void Plansza::biciePionkaZaznaczenie(int end_x, int end_y) {

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            if(this->plansza_do_gry[y][x].czyZaznaczonyPionek())
                this->biciePionkaKoordynaty(y,x,end_y,end_x);

        }
    }
}


void Plansza::odznaczWszystkie() {

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            this->plansza_do_gry[x][y].odznaczPionka();
        }
    }
}

bool Plansza::czyCosJestZaznaczone() {

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            if(this->plansza_do_gry[x][y].czyZaznaczonyPionek())
                return true;
        }
    }

    return false;
}


int Plansza::zwrocZaznaczoneX() {

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            if(this->plansza_do_gry[y][x].czyZaznaczonyPionek())
                return x;
        }
    }
    return 0;
}

int Plansza::zwrocZaznaczoneY() {

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            if(this->plansza_do_gry[y][x].czyZaznaczonyPionek())
                return y;
        }
    }
    return 0;
}


int Plansza::ileBialychPionkow() {

    int licznik = 0;

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            if(this->plansza_do_gry[x][y].zwrocTyp() == BIALY || this->plansza_do_gry[x][y].zwrocTyp() == BIALY_DAMA)
                licznik++;
        }
    }

    return licznik;
}

int Plansza::ileCzarnychPionkow() {

    int licznik = 0;

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            if(this->plansza_do_gry[x][y].zwrocTyp() == CZARNY || this->plansza_do_gry[x][y].zwrocTyp() == CZARNY_DAMA)
                licznik++;
        }
    }

    return licznik;
}

bool Plansza::czyRuchJestDozwolonyGracz(int end_x, int end_y) {

    int start_x=0, start_y=0;

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            if(this->plansza_do_gry[x][y].czyZaznaczonyPionek()) {
                start_x = y;
                start_y = x;
            }
        }
    }

    //RUCH DAMKI
    if(plansza_do_gry[start_y][start_x].zwrocTyp() == BIALY_DAMA){

        return (abs(end_x - start_x)  == abs(end_y - start_y));

    }//RUCH PIONKA
    else if( ((abs(end_x - start_x) == 1) && (abs(end_y - start_y) == 1)) && (plansza_do_gry[start_y][start_x].zwrocTyp() == BIALY) ) {

        return true;

    };

    return false;
}

bool Plansza::czyBicieJestDozwoloneGracz(int end_x, int end_y) {

    int start_x=0, start_y=0;
    int bity_x=0, bity_y=0;
    kierunkiRuchu kier;

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

            if(this->plansza_do_gry[x][y].czyZaznaczonyPionek()) {
                start_x = x;
                start_y = y;
            }
        }
    }

    if( ((abs(end_x - start_y) == 2) && (abs(end_y - start_x) == 2))  && (plansza_do_gry[start_x][start_y].zwrocTyp() == BIALY) ){

        kier = sprawdzKierunekRuchu(start_x,start_y,end_y,end_x);

        bity_x = kierunekZbityPionka_X(end_x, kier);
        bity_y = kierunekZbityPionka_Y(end_y, kier);

        return (plansza_do_gry[bity_y][bity_x].zwrocTyp() == CZARNY || plansza_do_gry[bity_x][bity_y].zwrocTyp() == CZARNY_DAMA);
    };

    return false;
}

void Plansza::wypelnijMozliweKierunkiRuch() {

    int tmp_x = 0, tmp_y = 0;
    int tmp_x_2 =0, tmp_y_2;

    for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
        for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {


            if(this->plansza_do_gry[y][x].zwrocTyp() != PUSTE && this->plansza_do_gry[y][x].zwrocTyp() != NIEDOZWOLONE_POLE) {

                //RUCH GORA LEWO
                tmp_x = x - 1;
                tmp_y = y - 1;

                if (tmp_x < 0 || tmp_y < 0 || tmp_x > 7 || tmp_y > 7) {
                    this->plansza_do_gry[y][x].ustawBrakRuchu(0);
                } else {

                    if (czyTenSamKolor(this->plansza_do_gry[y][x].zwrocTyp(), this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp()) )
                        this->plansza_do_gry[y][x].ustawBrakRuchu(0);

                    else if (this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp() == PUSTE) {

                        if(this->plansza_do_gry[y][x].czyBialy())
                            this->plansza_do_gry[y][x].ustawKierunekGL();
                        else
                            this->plansza_do_gry[y][x].ustawBrakRuchu(0);

                    }
                    else if( czyPrzeciwnyKolor( this->plansza_do_gry[y][x].zwrocTyp(), this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp() ) ){

                        tmp_x_2 = tmp_x - 1;
                        tmp_y_2 = tmp_y - 1;

                        if(tmp_x_2 < 0 || tmp_y_2 < 0 || tmp_x_2 > 7 || tmp_y_2 > 7)
                            this->plansza_do_gry[y][x].ustawBrakRuchu(0);
                        else{

                            if(this->plansza_do_gry[tmp_y_2][tmp_x_2].zwrocTyp() == PUSTE)
                                this->plansza_do_gry[y][x].ustawKierunekGL();
                        }
                    }
                }

                //RUCH GORA PRAWO
                tmp_x = x + 1;
                tmp_y = y - 1;

                if (tmp_x < 0 || tmp_y < 0 || tmp_x > 7 || tmp_y > 7) {
                    this->plansza_do_gry[y][x].ustawBrakRuchu(1);
                } else {

                    if (czyTenSamKolor(this->plansza_do_gry[y][x].zwrocTyp(), this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp()) )
                        this->plansza_do_gry[y][x].ustawBrakRuchu(1);

                    else if (this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp() == PUSTE) {

                        if(this->plansza_do_gry[y][x].czyBialy())
                            this->plansza_do_gry[y][x].ustawKierunekGP();
                        else
                            this->plansza_do_gry[y][x].ustawBrakRuchu(1);

                    }else if( czyPrzeciwnyKolor( this->plansza_do_gry[y][x].zwrocTyp(), this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp() ) ){

                        tmp_x_2 = tmp_x + 1;
                        tmp_y_2 = tmp_y - 1;

                        if(tmp_x_2 < 0 || tmp_y_2 < 0 || tmp_x_2 > 7 || tmp_y_2 > 7)
                            this->plansza_do_gry[y][x].ustawBrakRuchu(1);
                        else{

                            if(this->plansza_do_gry[tmp_y_2][tmp_x_2].zwrocTyp() == PUSTE)
                                this->plansza_do_gry[y][x].ustawKierunekGP();
                        }
                    }
                }


                //RUCH DOL PRAWO
                tmp_x = x + 1;
                tmp_y = y + 1;

                if (tmp_x < 0 || tmp_y < 0 || tmp_x > 7 || tmp_y > 7) {
                    this->plansza_do_gry[y][x].ustawBrakRuchu(2);
                } else {

                    if (czyTenSamKolor(this->plansza_do_gry[y][x].zwrocTyp(), this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp()) )
                        this->plansza_do_gry[y][x].ustawBrakRuchu(2);

                    else if (this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp() == PUSTE) {

                        if(this->plansza_do_gry[y][x].czyCzarny())
                            this->plansza_do_gry[y][x].ustawKierunekDP();
                        else
                            this->plansza_do_gry[y][x].ustawBrakRuchu(2);

                    }else if( czyPrzeciwnyKolor( this->plansza_do_gry[y][x].zwrocTyp(), this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp() ) ){

                        tmp_x_2 = tmp_x + 1;
                        tmp_y_2 = tmp_y + 1;

                        if(tmp_x_2 < 0 || tmp_y_2 < 0 || tmp_x_2 > 7 || tmp_y_2 > 7)
                            this->plansza_do_gry[y][x].ustawBrakRuchu(2);
                        else{

                            if(this->plansza_do_gry[tmp_y_2][tmp_x_2].zwrocTyp() == PUSTE)
                                this->plansza_do_gry[y][x].ustawKierunekDP();
                        }
                    }
                }


                //RUCH DOL LEWO
                tmp_x = x - 1;
                tmp_y = y + 1;

                if (tmp_x < 0 || tmp_y < 0 || tmp_x > 7 || tmp_y > 7) {
                    this->plansza_do_gry[y][x].ustawBrakRuchu(3);
                } else {

                    if (czyTenSamKolor(this->plansza_do_gry[y][x].zwrocTyp(),
                                       this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp()))
                        this->plansza_do_gry[y][x].ustawBrakRuchu(3);

                    else if (this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp() == PUSTE) {

                        if(this->plansza_do_gry[y][x].czyCzarny())
                            this->plansza_do_gry[y][x].ustawKierunekDL();
                        else
                            this->plansza_do_gry[y][x].ustawBrakRuchu(3);

                    } else if( czyPrzeciwnyKolor( this->plansza_do_gry[y][x].zwrocTyp(), this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp() ) ){

                        tmp_x_2 = tmp_x - 1;
                        tmp_y_2 = tmp_y + 1;

                        if(tmp_x_2 < 0 || tmp_y_2 < 0 || tmp_x_2 > 7 || tmp_y_2 > 7)
                            this->plansza_do_gry[y][x].ustawBrakRuchu(3);
                        else{

                            if(this->plansza_do_gry[tmp_y_2][tmp_x_2].zwrocTyp() == PUSTE)
                                this->plansza_do_gry[y][x].ustawKierunekDL();
                        }
                    }
                }


            }
        }
    }
}

bool Plansza::czyJestKierunekNaLiscie(int x, int y, kierunkiRuchu kier) {

    for (int indeks = 0; indeks < ILOSC_RUCHOW ; ++indeks) {

        if (this->plansza_do_gry[y][x].kierunki[indeks] == kier)
            return true;
    }
    return false;

}

void Plansza::losowyRuchCzarny() {

    bool ruch = false;
    int y, x;
    int tmp_y, tmp_x;

    srand (time(NULL));

    while(!ruch){

        x = rand() % 8;
        y = rand() % 8;

        if(this->plansza_do_gry[y][x].czyCzarny()){

            for (int i = 0; i < ILOSC_RUCHOW; ++i) {

                if(this->plansza_do_gry[y][x].kierunki[i] == GORA_LEWO){

                    tmp_y = y - 1;
                    tmp_x = x - 1;

                    if(this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp() == PUSTE) {
                        this->ruchPionkaKoordynaty(y, x, tmp_y, tmp_x);
                        ruch = true;
                    }
                    else {
                        this->biciePionkaKoordynaty(y, x, tmp_y - 1, tmp_x - 1);
                        ruch = true;
                    }

                } else if(this->plansza_do_gry[y][x].kierunki[i] == GORA_PRAWO){

                    tmp_y = y - 1;
                    tmp_x = x + 1;

                    if(this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp() == PUSTE){

                        this->ruchPionkaKoordynaty(y,x,tmp_y,tmp_x);
                        ruch = true;
                    }
                    else {
                        this->biciePionkaKoordynaty(y, x, tmp_y - 1, tmp_x + 1);
                        ruch = true;
                    }

                }else if(this->plansza_do_gry[y][x].kierunki[i] == DOL_PRAWO){

                    tmp_y = y + 1;
                    tmp_x = x + 1;

                    if(this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp() == PUSTE) {
                        this->ruchPionkaKoordynaty(y, x, tmp_y, tmp_x);
                        ruch = true;
                    }
                    else {
                        this->biciePionkaKoordynaty(y, x, tmp_y + 1, tmp_x + 1);
                        ruch = true;
                    }

                }else if(this->plansza_do_gry[y][x].kierunki[i] == DOL_LEWO){

                    tmp_y = y + 1;
                    tmp_x = x - 1;

                    if(this->plansza_do_gry[tmp_y][tmp_x].zwrocTyp() == PUSTE) {
                        this->ruchPionkaKoordynaty(y, x, tmp_y, tmp_x);
                        ruch = true;
                    }
                    else {
                        this->biciePionkaKoordynaty(y, x, tmp_y + 1, tmp_x - 1);
                        ruch = true;
                    }
                }
            }
        }
    }

}












