#pragma once
#include "GerenciadorGrafico.h"

class GerenciadorTeclado
{
private:
	GerenciadorTeclado();

	static GerenciadorTeclado* g;
public:
	~GerenciadorTeclado();

	static GerenciadorTeclado* getTeclado();

	enum Teclas
	{
		comeco, andarEsquerdaP1, andarDireitaP1, pularP1,andarEsquerdaP2, andarDireitaP2, pularP2, 
		adicionarP2, removerP2, pausar, resumir,teleporte, menuop1, menuop2, menuop3, menuop4
		
	};

	Teclas tecladoJogador();
	Teclas tecladoUtilidade();
};