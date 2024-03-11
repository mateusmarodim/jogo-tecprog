#pragma once
#include "../headers/Selva.h"
#include "../headers/Caverna.h"

//class Fase;

class Principal
{
protected:
	GerenciadorGrafico gerenciadorGrafico;
	sf::Clock relogio;
	Fase* fase;

public:
	Principal();
	~Principal();

	int executar();
};

