#pragma once
#include "GerenciadorGrafico.h"
class GerenciadorEventos
{
private:
	sf::Event event;
	//Jogador* pj;
	//GerenciadorGrafico gerenciadorGrafico;

public:

	enum Evento
	{
		comeco,andarEsquerda, andarDireita
	};

	GerenciadorEventos();
	~GerenciadorEventos();

	Evento eventos();


};

