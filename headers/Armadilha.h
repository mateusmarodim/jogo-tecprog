#pragma once
#include "Obstaculo.h"

class Armadilha : public Obstaculo
{
public:
	Armadilha(const Vetor2F Pos = (0.0, 0.0), const  Vetor2F Vel = (0.0, 0.0),const  Vetor2F Tam = (0.0, 0.0));
	~Armadilha();

	void atualizar(float t);
	void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
};

