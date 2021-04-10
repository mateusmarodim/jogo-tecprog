#pragma once
#include "EntidadeColidivel.h"
#include "Singleton.h"

class Jogador : public EntidadeColidivel
{
private:
	//GerenciadorEventos ge;
public:
	Jogador(Vetor2F Pos = (0.0,0.0), Vetor2F Vel = (0.0,0.0));
	~Jogador();

	void inicializar(GerenciadorGrafico& gg);
	void desenhar(GerenciadorGrafico& gg);
	void atualizar(float t);
	//controle
	//tratar
};

