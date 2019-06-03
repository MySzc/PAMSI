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


#endif //WARCABY_USPRAWNIENIA_H
