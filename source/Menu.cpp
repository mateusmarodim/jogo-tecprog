/*#include "Menu.h"
#include <iostream>

Menu::Menu(float altura, float largura, GerenciadorGrafico& g)
{
	if (!font.loadFromFile("arial.ttf"))
	{
		std::cout << "sem menu pra vc hj" << endl;
	}

	menu[0].setFont(font);
	menu[0].setColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(Vetor2F(altura/2,largura/4)*1);

	menu[1].setFont(font);
	menu[1].setColor(sf::Color::White);
	menu[1].setString("Options");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(font);
	menu[2].setColor(sf::Color::White);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(width / 2, height / (MAX_NUMBER_OF_ITEMS + 1) * 3));

}

Menu::~Menu()
{
}

void Menu::desenhar(GerenciadorGrafico& g)
{
	for (int i = 0; i < 3; i++)
	{
		g.desenhar(menu[i]);
	}
}

void Menu::Up()
{
}

void Menu::Down()
{
}
*/