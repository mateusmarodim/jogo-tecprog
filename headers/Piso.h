#pragma once
#include "Obstaculo.h"

class Piso : public Obstaculo
{
public:
	Piso(const Vetor2F Pos = (0.0, 0.0),const  Vetor2F Vel = (0.0, 0.0),const  Vetor2F Tam = (0.0, 0.0));
	Piso();

	void atualizar(float t);
	void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
};