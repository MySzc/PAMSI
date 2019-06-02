//
// Created by msz on 6/1/19.
//

#include "akcesoriaDoGry.h"
#include "wielkosci.h"
#include "usprawnienia.h"
#include <SFML/Graphics.hpp>

void akcesoriaGry::setTeksturaPlanszy(std::string tekstura) {

    this->teksturaPlanszy.loadFromFile(tekstura);

    this->spritePlanszy.setTexture(this->teksturaPlanszy);
}

void akcesoriaGry::setTeksturaPionka(std::string bialy, std::string czarny) {

    this->teksturaPionkaBialy.loadFromFile(bialy);

    this->teksturaPionkaCzarny.loadFromFile(czarny);

    this->spritePionkaBialy.setTexture(this->teksturaPionkaBialy);

    this->spritePionkaCzarny.setTexture(this->teksturaPionkaCzarny);
}

void akcesoriaGry::setTeksturaDamy(std::string bialy, std::string czarny) {

    this->teksturaDamyBialy.loadFromFile(bialy);

    this->teksturaDamyCzarny.loadFromFile(czarny);

    this->spriteDamyBialy.setTexture(this->teksturaDamyBialy);

    this->spriteDamyCzarny.setTexture(this->teksturaDamyCzarny);

}
