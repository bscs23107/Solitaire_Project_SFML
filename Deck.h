#pragma once
#include<SFML/Graphics.hpp>
#include"Helper.h"
#include"Cards.h"
#include"Tableau.h"
#include<vector>
#include<iostream>
#include<string>
#include <stack>
#include<ctime>
#include<algorithm> 
using namespace std;
using namespace sf;

class Deck
{
private:
    vector<Cards*> deck; 
    int size = 52;

public:

    Deck() {

        char ranks[] = { 'A','2','3','4','5','6','7','8','9','T','J','Q','K' };
		Suit suits[] = { HEARTS, DIAMONDS, CLUBS, SPADES };
		color colors[] = { RED, BLACK };
		string paths[] = { "Final_deck/hearts/", "Final_deck/diamonds/", "Final_deck/clubs/", "Final_deck/spades/" };

        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 13; j++) {
				deck.push_back(new Cards(suits[i], ranks[j], colors[i % 2], paths[i] + ranks[j] + ".png"));
			}
		}

        shuffle();
    }

    
    void shuffle() {
        
        srand(std::time(0));
        std::random_shuffle(deck.begin(), deck.end());
    }

    
    void addCard(Cards* card) {
        deck.push_back(card);
    }

    Cards* getCard(int index) {
        if (index >= 0 && index < deck.size()) {
            return deck[index];  
        }
        return nullptr;  
    }

    
    
    Cards* drawCard() {
        if (!deck.empty()) {
            Cards* drawnCard = deck.back();
            deck.pop_back();
            return drawnCard;
        }
        return nullptr;
    }

    Cards* getCardAtPosition(float x, float y)
    {
        for (Cards* card : deck)  
        {
            if (card->getSprite().getGlobalBounds().contains(x, y))
            {
                return card;
            }
        }
        return nullptr;
    }
  
    //void display(RenderWindow& window) {
    //    const int numColumns = 7; 
    //    const float cardWidth = 125.0f;
    //    const float cardHeight = 192.0f;
    //    const float spacingX = 83.0f;
    //    const float spacingY = 30.0f; 
    //    const float startX = 175.0f; //
    //    const float startY = 288.0f;

    //   
    //    vector<int> cardsInColumn = { 1, 2, 3, 4, 5, 6, 7 };

    //    // Index to track where in the deck we are
    //    int cardIndex = 0;

    //    for (int col = 0; col < numColumns; ++col) {
    //
    //        float currentX = startX + col * (cardWidth + spacingX);

    //        // Draw each card in the column
    //        for (int row = 0; row < cardsInColumn[col]; ++row) {
    //           
    //            float currentY = startY + row * (spacingY);

    //           
    //            Cards* card = deck[cardIndex];
    //            card->setspritesize(1,1);
    //            
    //            card->set_position(currentX, currentY);

    //           
    //            if (row == cardsInColumn[col] - 1) {
    //               
    //                card->set_faceUp(true);
    //            }
    //            else {
    //              
    //                card->set_faceUp(false);
    //            }

    //            
    //            card->draw(window, currentX, currentY);

    //            
    //            cardIndex++;
    //        }
    //    }
    //}
};

