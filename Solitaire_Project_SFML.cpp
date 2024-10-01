#include<SFML/Graphics.hpp>
#include<iostream>
#include"Helper.h"
#include"Cards.h"
#include"Deck.h"
#include"Tableau.h"
#include"Suitdeck.h"

using namespace std;
using namespace sf;

void setupTableau(Deck& deck, std::vector<Tableau>& tableaus) {
    
    Vector2f startingPosition(165.0f, 285.0f);

    
    for (int i = 0; i < 7; ++i) {
        Tableau tableau(startingPosition + Vector2f((i*1.01f) * 210.0f, 0));
        
        for (int j = 0; j <= i; ++j) {
            Cards* card = deck.drawCard();
            tableau.insertCard(card, j == i);  
        }
        tableaus.push_back(tableau);
    }
}


void renderTableaus(RenderWindow& window, const std::vector<Tableau>& tableaus) {
    for (const Tableau& tableau : tableaus) {
        tableau.display(window);  
    }
}



int main()
{

    sf::RenderWindow window(sf::VideoMode(1920, 1080), " Tut SFML", sf::Style::Close | sf::Style::Resize);
    window.setPosition(Vector2i(-10, 0));

    int screen = 0; // 0 - main screen, 1 - rules, 2 - mode, 3 - game
    Texture B;
    B.loadFromFile("2.png");


    Deck deck;
    vector<Tableau> tableaus;

    


 /*   Tableau t1(Vector2f(175,291),30);
    Tableau t2(Vector2f(385, 291), 30);
    Tableau t3(Vector2f(592, 291), 30);
    Tableau t4(Vector2f(800, 291), 30);
    Tableau t5(Vector2f(1006, 291), 30);
    Tableau t6(Vector2f(1216, 291), 30);
    Tableau t7(Vector2f(1425, 291), 30);*/



    SuitDeck s1(SPADES,Vector2f(1028,50));
    SuitDeck s2(HEARTS, Vector2f(1205,50));
    SuitDeck s3(CLUBS, Vector2f(1387,50));
    SuitDeck s4(DIAMONDS, Vector2f(1568,50));




    Sprite Card(B);
    Card.setPosition(100, 50);
    Card.setScale(0.45f, 0.45f);
    Texture C;

    Texture A;
    A.loadFromFile("Background.png");

    Sprite Backg(A);
    Backg.setPosition(0, -80);
    Font Lato;
    Lato.loadFromFile("BillyArgelFont-vZ8Z.otf");

    Text NG("NEW GAME", Lato, 50);
    NG.setPosition(540, 60);
    NG.setFillColor(sf::Color::Black);
    Text LG("LOAD GAME", Lato, 50);
    LG.setPosition(535, 170);
    LG.setFillColor(sf::Color::Black);
    bool isSpriteSelected = false;
    Cards* selectedCard = nullptr;
    bool deagCard = false;
    float max_x = 500;
    //--------------
    while (window.isOpen())
    {
        sf::Event evnt;

        while (window.pollEvent(evnt))
        {
            if (evnt.type == sf::Event::Closed)
                window.close();

            if (evnt.type == sf::Event::MouseButtonPressed)
            {
                if (evnt.mouseButton.button == sf::Mouse::Left)
                {
                    cout << Mouse::getPosition(window).x << " " << Mouse::getPosition(window).y << endl;
                    // Check if the mouse click is inside the sprite
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
                    sf::Vector2i mousePosition2 = sf::Mouse::getPosition(window);
                  
                    if (Card.getGlobalBounds().contains(static_cast<float>(mousePosition.x), static_cast<float>(mousePosition.y)))
                    {
                        isSpriteSelected = true;
                    }
                    if (mousePosition2.x > 705 && mousePosition2.x < 1103 && mousePosition2.y > 379 && mousePosition2.y < 481 && screen == 0)  // start main screen to mode
                    {
                        A.loadFromFile("mode.png");
                        Sprite Backg(A);
                        Backg.setPosition(0, -80);
                        screen = 2;
                    } 
                    if (mousePosition2.x > 1455 && mousePosition2.x < 1841 && mousePosition2.y > 41 && mousePosition2.y < 215 && screen == 2)  // mode to start main screen 
                    {
                        A.loadFromFile("Background.png");
                        Sprite Backg(A);
                        Backg.setPosition(0, -80);
                        screen = 0;
                    }
                    if (mousePosition2.x > 640 && mousePosition2.x < 1190 && mousePosition2.y > 180 && mousePosition2.y < 375 && screen == 2)  //  mode to game start easy
                    {
                        A.loadFromFile("Board.png");
                        Sprite Backg(A);
                        Backg.setPosition(0, -80);
                        screen = 3;
                        //Set up the tableau and deal cards
                        setupTableau(deck, tableaus);

                    }
                    //if (mousePosition2.x > 705 && mousePosition2.x < 1103 && mousePosition2.y > 379 && mousePosition2.y < 481 && screen == 0)  // mode to game start hard
                    //{
                    //    A.loadFromFile("textures/mode.png");
                    //    Sprite Backg(A);
                    //    Backg.setPosition(0, -80);
                    //    screen = 2;
                    //}
                    

                    if (mousePosition2.x > 1430 && mousePosition2.x < 1730 && mousePosition2.y > 5 && mousePosition2.y < 84 && screen == 0)  // start main screen to rules 
                     {
                        A.loadFromFile("Rules.png");
                        Sprite Backg(A);
                        Backg.setPosition(0, -80);
                        screen = 1;
                    }
                    if (mousePosition2.x > 1360 && mousePosition2.x < 1736 && mousePosition2.y > 114 && mousePosition2.y < 265 && screen == 1)  // rules to main screen
                    {
                        A.loadFromFile("Background.png");
                        Sprite Backg(A);
                        Backg.setPosition(0, -80);
                        screen = 0;
                    }

                    


                 

                }
               
                else if (evnt.mouseButton.button == sf::Mouse::Right)
                {
                    deagCard = true;
                }
            }

            
            
            if (evnt.type == sf::Event::MouseButtonReleased)
            {
                if (evnt.mouseButton.button == sf::Mouse::Left)
                {
                    isSpriteSelected = false;
                }
            }
        }

        

        if (isSpriteSelected)
        {
            sf::Vector2i mousePosition = sf::Mouse::getPosition(window);
            Card.setPosition(static_cast<float>(mousePosition.x) - 50, static_cast<float>(mousePosition.y) - 65);
        }
       
        if (deagCard)
        {
            sf::Vector2f position = Card.getPosition();
            position.x += 5;
            Card.setPosition(position);
            if (position.x >= max_x)
                deagCard = false;
        }

        window.clear();

        window.draw(Backg);

        if (screen == 3) {
            renderTableaus(window, tableaus);  // Display the tableau columns
        }
        window.display();
    }

    return 0;
}
