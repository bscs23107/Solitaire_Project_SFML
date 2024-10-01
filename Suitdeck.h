#pragma once
#include <stack>
#include "Cards.h"
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;


class SuitDeck {
private:
    std::stack<Cards*> cards;       // Stack of cards in the suit deck (foundation)
    sf::Vector2f position;          // Position of the suit deck on screen
    Suit suit;                      // Suit of this foundation pile

public:
    // Constructor: Set position and suit for the suit deck
    SuitDeck(Suit s, sf::Vector2f pos) : suit(s), position(pos) {}

    // Function to insert a card into the suit deck
    //bool insertCard(Cards* card) {
    //    if (canPlaceCard(card)) {
    //        // Adjust position of the card to fit in the suit deck
    //        card->getSprite().setPosition(position);
    //        cards.push(card);  // Push card onto the stack
    //        return true;
    //    }
    //    return false;
    //}

    // Function to remove the top card (if needed)
    //Cards* removeTopCard() {
    //    if (!cards.empty()) {
    //        Cards* topCard = cards.top();
    //        cards.pop();  // Pop the card from the stack
    //        return topCard;
    //    }
    //    return nullptr;
    //}

    // Function to get the top card
    //Cards* getTopCard() const {
    //    if (!cards.empty()) {
    //        return cards.top();  // Return the top card of the stack
    //    }
    //    return nullptr;
    //}

    // Function to check if a card can be placed on this suit deck (foundation)
    //bool canPlaceCard(Cards* card) const {
    //    // Ensure the card is of the same suit
    //    if (card->get_suit() != suit) {
    //        return false;
    //    }

    //    // Check if it's the first card (must be an Ace)
    //    if (cards.empty()) {
    //        return card->get_rank() == 'A';
    //    }

    //    // Otherwise, ensure the rank is the next in sequence
    //    Cards* topCard = getTopCard();
    //    if (topCard) {
    //        return (card->get_rank() == topCard->get_nextrank());
    //    }

    //    return false;
    //}

    // Function to draw the suit deck and its cards
    //void draw(sf::RenderWindow& window) {
    //    if (cards.empty()) {
    //        // Draw an empty pile representation (if needed)
    //        sf::RectangleShape emptyPile(sf::Vector2f(100.0f, 150.0f)); // Example dimensions for an empty pile
    //        emptyPile.setPosition(position);
    //        emptyPile.setOutlineColor(sf::Color::White);
    //        emptyPile.setOutlineThickness(2);
    //        emptyPile.setFillColor(sf::Color(0, 0, 0, 0)); // Transparent
    //        window.draw(emptyPile);
    //    }
    //    else {
    //        // Draw the top card only (since the stack hides other cards)
    //        Cards* topCard = getTopCard();
    //        if (topCard != nullptr) {
    //            window.draw(topCard->getSprite());
    //        }
    //    }
    //}
};