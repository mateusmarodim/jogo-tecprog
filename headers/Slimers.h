#pragma once
#include "../headers/Selva.h"
#include "../headers/Caverna.h"
#include "../headers/Menu.h"

class Slimers
{
protected:
	GerenciadorGrafico gerenciadorGrafico;
	sf::Clock relogio;
	Fase* fase;
	Menu* menu;

public:
	Slimers();
	~Slimers();

	int executar();
};

