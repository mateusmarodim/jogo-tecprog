#pragma once
#include "Selva.h"
#include "Caverna.h"
#include "Menu.h"

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

