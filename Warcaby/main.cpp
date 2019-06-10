#include <SFML/Graphics.hpp>

#include "wielkosci.h"
#include "plansza.h"
#include "usprawnienia.h"
#include "akcesoriaDoGry.h"
#include <iostream>

int main() {

    Plansza GRA;
    akcesoriaGry tekstury;

    GRA.inicjalizujPlanszeStart();

    tekstury.setTeksturaPlanszy("board.png");
    tekstury.setTeksturaDamy("bialyKrolowa.png","czarnyKrolowa.png");
    tekstury.setTeksturaPionka("bialyPionek.png", "czarnyPionek.png");

    sf::RenderWindow window(sf::VideoMode(8*WIELKOSC_POLA,8*WIELKOSC_POLA,32),"Warcaby");

    sf::Vector2i mysz;
    kierunkiRuchu kierunek_pomocniczy;
    bool koniec_gry = false;
    turaGry TURA = TURA_BIALE;

    while(window.isOpen() && !koniec_gry) {
        sf::Event event{};

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }


            GRA.wypelnijMozliweKierunkiRuch();


            if(TURA == TURA_BIALE && GRA.czyMaRuchyBialy()) {

                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
                    mysz = sf::Mouse::getPosition(window);
                    GRA.odznaczWszystkie();
                }

                if ((GRA.plansza_do_gry[mysz.y / 100][mysz.x / 100].czyBialy()) &&
                    !GRA.czyCosJestZaznaczone()) {

                    GRA.odznaczWszystkie();
                    GRA.plansza_do_gry[mysz.y / 100][mysz.x / 100].zaznaczPionka();
                }


                if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Right) {

                    mysz = sf::Mouse::getPosition(window);

                    if (GRA.plansza_do_gry[mysz.y / 100][mysz.x / 100].czyPuste() &&
                        GRA.czyCosJestZaznaczone()) {

                        kierunek_pomocniczy = sprawdzKierunekRuchu(GRA.zwrocZaznaczoneY(), GRA.zwrocZaznaczoneX(), mysz.y / 100, mysz.x / 100);

                        if (GRA.czyRuchJestDozwolonyGracz(mysz.x / 100, mysz.y / 100) &&
                            GRA.czyJestKierunekNaLiscie(GRA.zwrocZaznaczoneX(), GRA.zwrocZaznaczoneY(), kierunek_pomocniczy)) {

                            GRA.ruchPionkaZaznaczenie(mysz.x / 100, mysz.y / 100);
                            TURA = TURA_CZARNE;
                        }
                        else if (GRA.czyBicieJestDozwoloneGracz(mysz.x / 100, mysz.y / 100) &&
                            GRA.czyJestKierunekNaLiscie(GRA.zwrocZaznaczoneX(), GRA.zwrocZaznaczoneY(), kierunek_pomocniczy)) {

                            GRA.biciePionkaZaznaczenie(mysz.x / 100, mysz.y / 100);
                            TURA = TURA_CZARNE;
                        }

                        GRA.odznaczWszystkie();
                    }
                }
            } else if(TURA == TURA_BIALE)
                koniec_gry = true;



            GRA.wypelnijMozliweKierunkiRuch();


            if(TURA == TURA_CZARNE && GRA.czyMaRuchyCzarny()){

                liczniki tmp_l = pierwszyPoziomAI(GRA);

                int tmp_x,tmp_y,tmp_k;

                GRA.ruchPoLiczniku(tmp_l);

                //GRA.losowyRuchCzarny();

                TURA = TURA_BIALE;
            } else if(TURA == TURA_CZARNE)
                koniec_gry = true;


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

            }
        }

        window.display();
    }

    while(window.isOpen()) {
        sf::Event event{};

        while (window.pollEvent(event)) {

            if (event.type == sf::Event::Closed) {
                window.close();
            }

            if (!GRA.czyMaRuchyCzarny() && !GRA.czyMaRuchyBialy() && window.isOpen()) {

                tekstury.setTeksturaPlanszy("remis.png");
                window.draw(tekstury.spritePlanszy);

            } else if (TURA == TURA_BIALE && window.isOpen()) {

                tekstury.setTeksturaPlanszy("wygranaczarne.png");
                window.draw(tekstury.spritePlanszy);

            } else if (TURA == TURA_CZARNE && window.isOpen()) {

                tekstury.setTeksturaPlanszy("wygranabiale.png");
                window.draw(tekstury.spritePlanszy);
            }
        }

        window.display();
    }


    return 0;
}

