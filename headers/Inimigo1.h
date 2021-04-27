#pragma once
#include "Inimigo.h"

class Inimigo1 : public Inimigo
{
private:
	int posxInicial;
	bool teste;
public:
	Inimigo1(Vetor2F pos = (0.0, 0.0), Vetor2F vel = (0.0, 0.0), Vetor2F tam = (0.0,0.0));
	~Inimigo1();

	//void desenhar(GerenciadorGrafico& g);
	void atualizar(float t);
	void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
};

