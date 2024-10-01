#pragma once
#include<SFML/Graphics.hpp>
#include"Helper.h"
#include<iostream>
#include<string>
using namespace std;
using namespace sf;



class Cards
{
private:
	bool faceUp = true;
	color Color;
	Suit suit;
	char rank;
	string path;
	Texture cardTexture_background;
	Sprite cardSprite_background;
	Texture cardTexture_front;
	Sprite cardSprite_front;

public:


	//constructor for the card
	Cards(Suit s, char r, color c, string p)
	{
		suit = s;
		rank = r;
		Color = c;
		path = p;
		cardTexture_background.loadFromFile("empty.png");
		cardSprite_background.setTexture(cardTexture_background);
		load_set_front(path);
	}

	char get_rank() {
		return rank;
	}
	char get_nextrank() {
		return rank+1 ;
	}
	Suit get_suit() {
		return suit;
	}
	bool if_faceUp() {
		return faceUp;
	}
	void set_rank(char _rank) {
		this->rank = _rank;
	}
	void set_suit(Suit suit) {
		this->suit = suit;
	}
	void set_faceUp(bool faceup) {
		this->faceUp = faceup;
	}
	void set_color(color c) {
		this->Color = c;
	}
	Sprite& getSprite() {

		if(faceUp)
		    return  cardSprite_front;
		else
			return cardSprite_background;
	}

	void setspritesize(int x, int y) {
		cardSprite_front.setScale(x, y);
		cardSprite_background.setScale(x, y);
	}



	void set_position(int x, int y) {
		cardSprite_front.setPosition(x, y);
		cardSprite_background.setPosition(x, y);
	}

	bool operator==(const Cards& c) const {
		return (rank == c.rank && suit == c.suit && Color == c.Color);
	}
	bool operator!=(const Cards& c) const {
		return !operator==(c);
	}

	void load_set_front(string path)
	{
		cardTexture_front.loadFromFile(path);
		cardSprite_front.setTexture(cardTexture_front);
	}


	void draw(RenderWindow& window, int x, int y)
	{
		if (faceUp)
		{
			window.draw(cardSprite_front);
		}
		else
		{
			window.draw(cardSprite_background);
		}
	}


};

