//
// Created by msz on 5/30/19.
//

#ifndef WARCABY_USPRAWNIENIA_H
#define WARCABY_USPRAWNIENIA_H

enum typPionka{

    CZARNY,
    BIALY,
    CZARNY_DAMA,
    BIALY_DAMA,
    PUSTE,
    NIEDOZWOLONE_POLE,
};

bool czyTenSamKolor(typPionka typ1, typPionka typ2);
bool czyPrzeciwnyKolor(typPionka typ1, typPionka typ2);

enum kierunkiRuchu{

    GORA_LEWO,
    GORA_PRAWO,
    DOL_LEWO,
    DOL_PRAWO,
    BRAK_RUCHU,
};

kierunkiRuchu sprawdzKierunekRuchu(int start_x, int start_y, int end_x, int end_y);

int kierunekZbityPionka_X(int end_x, kierunkiRuchu kier);

int kierunekZbityPionka_Y(int end_y, kierunkiRuchu kier);


enum turaGry{

    TURA_BIALE,
    TURA_CZARNE,
    BRAK,
};

struct liczniki{
public:

    int pole_x;
    int pole_y;
    int licznik_kierunku;

    liczniki(){
        pole_x=0;
        pole_y=0;
        licznik_kierunku=0;
    };
};

#endif //WARCABY_USPRAWNIENIA_H
