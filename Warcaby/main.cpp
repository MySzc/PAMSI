#include <SFML/Graphics.hpp>

#include "wielkosci.h"
#include "plansza.h"
#include "usprawnienia.h"
#include <iostream>

int main() {


   Plansza test;

   test.inicjalizujPlanszeStart();
   test.wyswietlPlansze();

    test.ruchPionka(5,2,4,3);

    std::cout << "****************************************************************" << std::endl;

    test.wyswietlPlansze();

    test.ruchPionka(2,5,3,4);

    std::cout << "****************************************************************" << std::endl;

    test.wyswietlPlansze();

    test.biciePionka(4,3,2,5);

    std::cout << "****************************************************************" << std::endl;

    test.wyswietlPlansze();


/*
    sf::RenderWindow window(sf::VideoMode(sf::VideoMode::getDesktopMode()),"Hello SFML");



    sf::Font font;

    font.loadFromFile("OpenSans-Bold.ttf");


    sf::Text text("Hello World",font,11);

    text.setCharacterSize(32);

    text.setPosition(window.getSize().x/2 - text.getGlobalBounds().width/2,

                     window.getSize().y/2 - text.getGlobalBounds().height/2);



    while(window.isOpen()){



        sf::Event event;

        while(window.pollEvent(event)) {

            if(event.type == sf::Event::Closed){

                window.close();

            }

            window.clear(sf::Color::Black);

            window.draw(text);

            window.display();

        }

    }

    return 0;
*/
}