#pragma once
#include <vector>
#include "Cards.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

class Tableau {
private:
    vector<Cards*> cards;     // Cards in the tableau
    Vector2f position;         // Position of the tableau pile
    float cardOffset;              // Offset to stack cards visually

public:
 
    Tableau(sf::Vector2f pos, float offset = 30.0f) : position(pos), cardOffset(offset) {}

   
    void insertCard(Cards* card, bool faceUp = false) {
       
        card->set_faceUp(faceUp); 
        card->getSprite().setPosition(position.x, position.y + cards.size() * cardOffset);
        cards.push_back(card);
    }

    void addCard(Cards* card) {
        cards.push_back(card);  
    }

    Vector2f getPosition() const {
        return position;
    }

    //// Function to remove the top card from the tableau
    //Cards* removeTopCard() {
    //    if (!cards.empty()) {
    //        Cards* topCard = cards.back();
    //        cards.pop_back();
    //        return topCard;
    //    }
    //    return nullptr; // If tableau is empty
    //}

    //// Function to get the top card
    //Cards* getTopCard() {
    //    if (!cards.empty()) {
    //        return cards.back();
    //    }
    //    return nullptr;
    //}


    void display(RenderWindow& window) const { 
        float currentY = position.y;
        for (Cards* card : cards) {
            card->getSprite().setPosition(position.x, currentY);
            window.draw(card->getSprite());
            currentY += cardOffset;  
        }
    }


    //// Function to check if the card can be moved (implement Solitaire rules here)
    //bool canMoveCard(Cards* card) {
    //    // Implement game rules, e.g., check if card color and rank are correct for a valid move
    //    // This can be customized based on the game logic you're following.
    //    return true; // Simplified for now
    //}

    //// Function to move multiple cards from this tableau to another tableau
    //void moveCardsTo(Tableau& destination, int startIndex) {
    //    for (size_t i = startIndex; i < cards.size(); i++) {
    //        destination.insertCard(cards[i]);
    //    }
    //    cards.erase(cards.begin() + startIndex, cards.end());
    //}
};