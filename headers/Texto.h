#pragma once
#include "SFML/Graphics.hpp"

class Texto
{
private:
	sf::Font fonte;
	sf::Text texto;

public:
	Texto();
	~Texto();

	void setFonte(sf::Font f);
	sf::Font getFonte();

	void setTexto(sf::Text t);
	sf::Text getTexto();


};

