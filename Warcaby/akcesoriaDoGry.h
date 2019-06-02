//
// Created by msz on 6/1/19.
//

#ifndef WARCABY_AKCESORIADOGRY_H
#define WARCABY_AKCESORIADOGRY_H

#include "wielkosci.h"
#include "usprawnienia.h"
#include <SFML/Graphics.hpp>
#include <string>


class akcesoriaGry{
public:

    sf::Texture teksturaPlanszy;
    sf::Texture teksturaPionkaBialy;
    sf::Texture teksturaPionkaCzarny;
    sf::Texture teksturaDamyBialy;
    sf::Texture teksturaDamyCzarny;


    sf::Sprite spritePlanszy;



    void setTeksturaPlanszy(std::string tekstura);






};


#endif //WARCABY_AKCESORIADOGRY_H
