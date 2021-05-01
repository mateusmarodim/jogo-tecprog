#pragma once
//#include "Fase.h"
#include "Selva.h"
#include "Caverna.h"

//class Fase;

class Principal
{
protected:
	GerenciadorGrafico gerenciadorGrafico;
	sf::Clock relogio;
	//Fase teste;
	Selva fase1;
	Caverna fase2;

public:
	Principal();
	~Principal();

	int executar();
};

