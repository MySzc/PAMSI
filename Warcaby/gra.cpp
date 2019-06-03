//
// Created by msz on 6/2/19.
//

#include "gra.h"
#include <iostream>

turaGry graWarcaby::zwrocTure(typPionka typ) {

    if(typ == BIALY || typ == BIALY_DAMA)
        return TURA_BIALE;
    else if(typ == CZARNY || typ == CZARNY_DAMA)
        return TURA_CZARNE;
    else
        return BRAK;

}

turaGry graWarcaby::zmienTure(turaGry tura) {

    if(tura == TURA_CZARNE)
        return TURA_BIALE;
    else if(tura == TURA_BIALE)
        return TURA_CZARNE;
    else
        return BRAK;
}

void graWarcaby::odznaczWszystkiePozaJednym(int x, int y) {

    this->odznaczWszystkie();
    this->planszaDoGry.zwrocPole(x,y).zaznaczPionka();

    /*
     * this->planszaDoGry.zwrocPole(y,x).zaznaczPionka();
    std::cout << "Zaznaczono pionek: " << x << " " << y << std::endl;

    for (int i = 0; i < WIELKOSC_PLANSZY; ++i) {
        for (int j = 0; j < WIELKOSC_PLANSZY; ++j) {

            if(i != x && j != y){

                this->planszaDoGry.zwrocPole(i,j).odznaczPionka();


            }

        }
    }
     */

}


void graWarcaby::odznaczWszystkie() {

    for (int i = 0; i < WIELKOSC_PLANSZY; ++i) {
        for (int j = 0; j < WIELKOSC_PLANSZY; ++j) {

            this->planszaDoGry.zwrocPole(i,j).odznaczPionka();

        }
    }

}



int graWarcaby::zwrocZaznaczoneX() {

    for (int i = 0; i < WIELKOSC_PLANSZY; ++i) {
        for (int j = 0; j < WIELKOSC_PLANSZY; ++j) {

            if(this->planszaDoGry.zwrocPole(i,j).czyZaznaczonyPionek() == true)
                return this->planszaDoGry.zwrocPole(i,j).retPozX();
            else
                return 0;

        }
    }

    return 0;
}

int graWarcaby::zwrocZaznaczoneY() {

    for (int i = 0; i < WIELKOSC_PLANSZY; ++i) {
        for (int j = 0; j < WIELKOSC_PLANSZY; ++j) {

            if(this->planszaDoGry.zwrocPole(i,j).czyZaznaczonyPionek()) {
                return this->planszaDoGry.zwrocPole(i, j).retPozY();
            }else
                return 0;
        }
    }

    return 0;
}

bool graWarcaby::czyCosJestZaznaczone() {

    for (int i = 0; i < WIELKOSC_PLANSZY; ++i) {
        for (int j = 0; j < WIELKOSC_PLANSZY; ++j) {

            if(this->planszaDoGry.zwrocPole(i,j).czyZaznaczonyPionek()){
                std::cout << "Zaznaczono pionek: " << i << " " << j << std::endl;
                return true;

            }

        }
    }
    return false;

}







