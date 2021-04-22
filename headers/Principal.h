#pragma once
#include "Fase.h"

class Fase;

class Principal
{
protected:
	GerenciadorGrafico gerenciadorGrafico;
	sf::Clock relogio;
	Fase teste;

public:
	Principal();
	~Principal();

	int executar();
	//void adicionaEntidade(EntidadeColidivel* entidade, string tipoEntidade);
};

