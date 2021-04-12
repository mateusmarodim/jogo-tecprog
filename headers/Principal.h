#pragma once
#include "ListaEntidade.h"
#include "GerenciadorEventos.h"
#include "GerenciadorGrafico.h"
#include "GerenciadorColisoes.h"
#include "Jogador.h"
#include "Inimigo1.h"


class Principal
{
private:
	GerenciadorGrafico gerenciadorGrafico;
	GerenciadorColisoes gerenciadorColisoes;
	sf::Clock relogio;
	ListaEntidade listaboneco;
	Jogador jogador;

public:
	Principal();
	~Principal();

	int executar();
};

