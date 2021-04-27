#pragma once
#include "Inimigo.h"

class King : public Inimigo
{
private:

public:
	King(Vetor2F pos = (0.0, 0.0), Vetor2F vel = (0.0, 0.0), Vetor2F tam = (0.0, 0.0));
	~King();
	void atualizar(float t);
	void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
};

