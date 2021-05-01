#pragma once
#include "EntidadeColidivel.h"

class Personagem : public EntidadeColidivel
{
protected:
	//colcoar o bool pular dps!
public:
	Personagem(const Vetor2F Pos = (0.0, 0.0), const Vetor2F Vel = (0.0, 0.0), const Vetor2F Tam = (0.0, 0.0), const string CaminhoText = nullptr);
	//Personagem();
	virtual ~Personagem();
};