#pragma once
#include "EntidadeColidivel.h"

class Personagem : public EntidadeColidivel
{
protected:
	bool podePular;

public:
	Personagem(const Vetor2F Pos = (0.0, 0.0), const Vetor2F Vel = (0.0, 0.0), const Vetor2F Tam = (0.0, 0.0), const string CaminhoText = nullptr);
	virtual ~Personagem();

	virtual void atualizar(float t) = 0;
	virtual void colidir(EntidadeColidivel* outro, std::string tipoEntidade) = 0;
};