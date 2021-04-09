#pragma once
#include "ListaPersonagem.h"
#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"
#include "Jogador.h"
#include "Inimigo1.h"


class Principal
{
private:
	GerenciadorGrafico gerenciadorGrafico;
	GerenciadorEventos gerenciadorEventos;
	sf::Clock relogio;
	ListaPersonagem listaboneco;
	Jogador jogador1;

public:
	Principal();
	~Principal();

	int executar();
};

