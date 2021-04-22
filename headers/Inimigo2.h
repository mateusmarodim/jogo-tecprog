#pragma once
#include "Inimigo.h"
class Inimigo2 : public Inimigo
{
private:
	bool atirar;
public:
	Inimigo2(Vetor2F pos = (0.0, 0.0), Vetor2F vel = (0.0, 0.0), Vetor2F tam = (0.0, 0.0));
	~Inimigo2();

	void atualizar(float t);
	void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
	//void atirar();
};

