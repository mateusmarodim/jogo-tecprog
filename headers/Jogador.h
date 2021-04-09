#pragma once
#include "Personagem.h"

class Jogador : public Personagem
{
//private:

public:
	Jogador(Vetor2F Pos = (0.0,0.0), Vetor2F Vel = (0.0,0.0));
	~Jogador();

	void inicializar(GerenciadorGrafico& gg);
	void desenhar(GerenciadorGrafico& gg);
	void atualizar(GerenciadorEventos& ge,float t);
	//controle
	//tratar
};

