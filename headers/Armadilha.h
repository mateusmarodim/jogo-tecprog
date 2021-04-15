#pragma once
#include "Obstaculo.h"
class Armadilha : public Obstaculo
{
public:
	Armadilha(Vetor2F pos = (0.0, 0.0), Vetor2F vel = (0.0, 0.0), Vetor2F tam = (0.0, 0.0));
	~Armadilha();

	void atualizar(float t);
	void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
};

