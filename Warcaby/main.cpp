#include <SFML/Graphics.hpp>

#include "wielkosci.h"
#include "plansza.h"
#include "usprawnienia.h"
#include "akcesoriaDoGry.h"
#include "gra.h"
#include <iostream>

int main() {

    graWarcaby GRA;

    GRA.planszaDoGry.inicjalizujPlanszeStart();

    GRA.planszaDoGry.ruchPionka(5,2,4,3);

    GRA.akcesoriaDoGry.setTeksturaPlanszy("board.png");
    GRA.akcesoriaDoGry.setTeksturaDamy("bialyKrolowa.png","czarnyKrolowa.png");
    GRA.akcesoriaDoGry.setTeksturaPionka("bialyPionek.png", "czarnyPionek.png");


    sf::RenderWindow window(sf::VideoMode(8*WIELKOSC_POLA,8*WIELKOSC_POLA,32),"Warcaby");

    sf::Vector2i mysz;

    while(window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left ){
                mysz = sf::Mouse::getPosition( window );
                std::cout << "L " << mysz.y/100 << " ; " << mysz.x/100<< std::endl;

                if (GRA.planszaDoGry.zwrocTypPionka(mysz.y/100, mysz.x/100)!= PUSTE ||
                    GRA.planszaDoGry.zwrocTypPionka(mysz.y/100, mysz.x/100) != NIEDOZWOLONE_POLE){

                    GRA.odznaczWszystkiePozaJednym(mysz.y/100, mysz.x/100);
                }
            }

            if(event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left ){
                mysz = sf::Mouse::getPosition( window );
                std::cout << "L " << mysz.x/100 << " ; " << mysz.y/100<< std::endl;

                if (GRA.planszaDoGry.zwrocTypPionka(mysz.y/100, mysz.x/100)!= PUSTE ||
                    GRA.planszaDoGry.zwrocTypPionka(mysz.y/100, mysz.x/100) != NIEDOZWOLONE_POLE){

                    GRA.planszaDoGry.ruchPionka(GRA.zwrocZaznaczoneX(), GRA.zwrocZaznaczoneY(),  mysz.y/100, mysz.x/100);

                    GRA.odznaczWszystkie();
                }
            }




            window.draw(GRA.akcesoriaDoGry.spritePlanszy);

            for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {
                for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {

                    GRA.akcesoriaDoGry.spritePionkaBialy.setPosition(y*WIELKOSC_POLA,x*WIELKOSC_POLA);
                    GRA.akcesoriaDoGry.spritePionkaCzarny.setPosition(y*WIELKOSC_POLA,x*WIELKOSC_POLA);
                    GRA.akcesoriaDoGry.spriteDamyBialy.setPosition(y*WIELKOSC_POLA,x*WIELKOSC_POLA);
                    GRA.akcesoriaDoGry.spriteDamyCzarny.setPosition(y*WIELKOSC_POLA,x*WIELKOSC_POLA);

                    if(GRA.planszaDoGry.zwrocTypPionka(x,y) == BIALY)
                        window.draw(GRA.akcesoriaDoGry.spritePionkaBialy);
                    else if(GRA.planszaDoGry.zwrocTypPionka(x,y) == CZARNY)
                        window.draw(GRA.akcesoriaDoGry.spritePionkaCzarny);
                    else if(GRA.planszaDoGry.zwrocTypPionka(x,y) == CZARNY_DAMA)
                        window.draw(GRA.akcesoriaDoGry.spriteDamyCzarny);
                    else if(GRA.planszaDoGry.zwrocTypPionka(x,y) == BIALY_DAMA)
                        window.draw(GRA.akcesoriaDoGry.spriteDamyBialy);

                    if(x == 7 && y == 7) {
                        std::cout << "********************************************" << std::endl;
                        GRA.planszaDoGry.wyswietlPlansze();
                    }
                }
            }

            window.display();
        }

    }



/*
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