//
// Created by msz on 6/1/19.
//

#include "akcesoriaDoGry.h"
#include "wielkosci.h"
#include "usprawnienia.h"

void akcesoriaGry::setTeksturaPlanszy(std::string tekstura) {

    this->teksturaPlanszy.loadFromFile(tekstura);

    this->spritePlanszy.setTexture(this->teksturaPlanszy);
}
