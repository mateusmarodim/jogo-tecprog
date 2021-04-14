#pragma once
#include "GerenciadorGrafico.h"
class GerenciadorEventos
{
private:
	sf::Event event;
	//Jogador* pj;
	//GerenciadorGrafico gerenciadorGrafico;
	GerenciadorEventos();

	static GerenciadorEventos* g;
public:

	static GerenciadorEventos* getInstance();

	enum Evento
	{
		comeco,andarEsquerda,andarDireita,pular
	};

	~GerenciadorEventos();

	Evento eventos();
};