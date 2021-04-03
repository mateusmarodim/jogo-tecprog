#pragma once
#include "ListaPersonagem.h"
#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"


class Principal
{
private:
	GerenciadorGrafico gerenciadorGrafico;
	GerenciadorEventos gerenciadorEventos;
	sf::Clock relogio;
	ListaPersonagem listaboneco;

public:
	Principal();
	~Principal();

	int executar();
};

