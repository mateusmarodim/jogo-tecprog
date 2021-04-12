#pragma once
#include "EntidadeColidivel.h"
#include "Singleton.h"

class Jogador : public EntidadeColidivel
{
private:
	//GerenciadorEventos ge;
public:
	Jogador(Vetor2F pos = (0.0,0.0), Vetor2F vel = (0.0,0.0), Vetor2F tam = (0.0,0.0));
	~Jogador();

	void desenhar(GerenciadorGrafico& gg);
	void atualizar(float t);
	void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
	//controle
	//tratar
};

