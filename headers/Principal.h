#pragma once
#include "Selva.h"
#include "Caverna.h"

//class Fase;

class Principal
{
protected:
	GerenciadorGrafico gerenciadorGrafico;
	sf::Clock relogio;
	Selva fase1;
	Caverna fase2;

public:
	Principal();
	~Principal();

	int executar();
};

