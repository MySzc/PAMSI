//
// Created by msz on 5/21/19.
//

#include "plansza.h"
#include <iostream>

Plansza::Plansza() {

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {
            this->_Plansza[i][j].first = 0;
            this->_Plansza[i][j].second = 0;
        }
    }
}

void Plansza::inicPlanszyStart() {

    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {

            if( ((i%2 != 0 && j%2 == 0) || (i%2 == 0 && j%2 != 0)) && i<3 )
                this->_Plansza[i][j].first = 1;
            else if( ((i%2 != 0 && j%2 == 0) || (i%2 == 0 && j%2 != 0)) && i>4 )
                this->_Plansza[i][j].second = 1;
        }
    }

}

void Plansza::wyswietlPlansze() {


    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j) {

            if(this->_Plansza[i][j].first != 0)
                std::cout << "B" << " ";
            else if (this->_Plansza[i][j].second != 0)
                std::cout << "C" << " ";
            else
                std::cout << "O" << " ";
        }

        std::cout << std::endl;
    }
}
