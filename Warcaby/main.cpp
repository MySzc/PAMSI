#include <SFML/Graphics.hpp>

#include "wielkosci.h"
#include "plansza.h"
#include "usprawnienia.h"
#include "akcesoriaDoGry.h"
#include "gra.h"
#include <iostream>
#include <utility>

int main() {

    Plansza GRA;
    akcesoriaGry tekstury;

    GRA.inicjalizujPlanszeStart();

    tekstury.setTeksturaPlanszy("board.png");
    tekstury.setTeksturaDamy("bialyKrolowa.png","czarnyKrolowa.png");
    tekstury.setTeksturaPionka("bialyPionek.png", "czarnyPionek.png");

    sf::RenderWindow window(sf::VideoMode(8*WIELKOSC_POLA,8*WIELKOSC_POLA,32),"Warcaby");

    sf::Vector2i mysz;

    while(window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }


                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {

                    mysz = sf::Mouse::getPosition(window);

                    //if (((GRA.plansza_do_gry[mysz.y / 100][mysz.x / 100].zwrocTyp() != PUSTE) ||
                     //    (GRA.plansza_do_gry[mysz.y / 100][mysz.x / 100].zwrocTyp() != NIEDOZWOLONE_POLE)) &&
                     //   !GRA.czyCosJestZaznaczone()) {
                    if((GRA.plansza_do_gry[mysz.y / 100][mysz.x / 100].zwrocTyp() == BIALY)  &&
                       !GRA.czyCosJestZaznaczone()){

                        std::cout << "L " << mysz.y / 100 << " ; " << mysz.x / 100 << std::endl;

                        GRA.odznaczWszystkie();
                        GRA.plansza_do_gry[mysz.y / 100][mysz.x / 100].zaznaczPionka();
                    }
                }

                if (GRA.czyCosJestZaznaczone())
                    std::cout << "Cos jest zaznaczone" << std::endl;

                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {

                    mysz = sf::Mouse::getPosition(window);

                    if (GRA.plansza_do_gry[mysz.y / 100][mysz.x / 100].zwrocTyp() == PUSTE &&
                        GRA.czyCosJestZaznaczone() && GRA.czyRuchJestDozwolonyGracz(mysz.x / 100,mysz.y / 100)) {

                        std::cout << "P " << mysz.y / 100 << " ; " << mysz.x / 100 << std::endl;

                        GRA.ruchPionkaZaznaczenie(mysz.x / 100, mysz.y / 100);

                        GRA.odznaczWszystkie();
                    }
                }


            }


            window.draw(tekstury.spritePlanszy);

            for (int y = 0; y < WIELKOSC_PLANSZY; ++y) {
                for (int x = 0; x < WIELKOSC_PLANSZY; ++x) {

                    tekstury.spritePionkaBialy.setPosition(y*WIELKOSC_POLA,x*WIELKOSC_POLA);
                    tekstury.spritePionkaCzarny.setPosition(y*WIELKOSC_POLA,x*WIELKOSC_POLA);
                    tekstury.spriteDamyBialy.setPosition(y*WIELKOSC_POLA,x*WIELKOSC_POLA);
                    tekstury.spriteDamyCzarny.setPosition(y*WIELKOSC_POLA,x*WIELKOSC_POLA);

                    if(GRA.plansza_do_gry[x][y].zwrocTyp() == BIALY)
                        window.draw(tekstury.spritePionkaBialy);
                    else if(GRA.plansza_do_gry[x][y].zwrocTyp() == CZARNY)
                        window.draw(tekstury.spritePionkaCzarny);
                    else if(GRA.plansza_do_gry[x][y].zwrocTyp() == CZARNY_DAMA)
                        window.draw(tekstury.spriteDamyCzarny);
                    else if(GRA.plansza_do_gry[x][y].zwrocTyp() == BIALY_DAMA)
                        window.draw(tekstury.spriteDamyBialy);

                    if(x == 7 && y == 7) {
                        std::cout << "********************************************" << std::endl;
                        GRA.wyswietlPlanszeTerminal();
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
