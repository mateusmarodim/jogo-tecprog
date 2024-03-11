#pragma once
#include "../headers/GerenciadorGrafico.h"
class GerenciadorEventos
{
private:
	sf::Event event;
	//Jogador* pj;
	//GerenciadorGrafico gerenciadorGrafico;
	GerenciadorEventos();

	static GerenciadorEventos* g;
public:

	static GerenciadorEventos* getTeclado();

	enum Teclas
	{
		comeco, andarEsquerdaP1, andarDireitaP1, pularP1,andarEsquerdaP2, andarDireitaP2, pularP2, adicionarP2, removerP2, pausar, resumir,teleporte
	};

	~GerenciadorEventos();

	Teclas Teclado();
};