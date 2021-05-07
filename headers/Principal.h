#pragma once
#include "Selva.h"
#include "Caverna.h"

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

