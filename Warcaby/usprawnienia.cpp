//
// Created by msz on 5/30/19.
//

#include "usprawnienia.h"
#include "plansza.h"

kierunkiRuchu sprawdzKierunekRuchu(int start_x, int start_y, int end_x, int end_y) {

    if(( end_x - start_x < 0) && ( end_y - start_y < 0))
        return GORA_LEWO;
    else if(( end_x - start_x < 0) && ( end_y - start_y > 0))
        return GORA_PRAWO;
    else if(( end_x - start_x > 0) && ( end_y - start_y < 0))
        return DOL_LEWO;
    else if(( end_x - start_x > 0) && ( end_y - start_y > 0))
        return DOL_PRAWO;
    else
        return BLAD;
}

int kierunekZbityPionka_X(int end_x, kierunkiRuchu kier) {

    switch(kier) {
        case GORA_LEWO:
            return end_x + 1;
        case GORA_PRAWO:
            return end_x + 1;
        case DOL_LEWO:
            return end_x - 1;
        case DOL_PRAWO:
            return end_x - 1;
        default:
            return 0;
    }
}

int kierunekZbityPionka_Y(int end_y, kierunkiRuchu kier) {

    switch(kier) {
        case GORA_LEWO:
            return end_y + 1;
        case GORA_PRAWO:
            return end_y - 1;
        case DOL_LEWO:
            return end_y + 1;
        case DOL_PRAWO:
            return end_y - 1;
        default:
            return 0;
    }
}


