#pragma once
#include "Personagem.h"

namespace inimigo
{
	class Inimigo : public Personagem
	{
	public:
		Inimigo(const Vetor2F Pos = (0.0, 0.0), const Vetor2F Vel = (0.0, 0.0), const Vetor2F Tam = (0.0, 0.0), const string CaminhoText = nullptr);
		virtual ~Inimigo();
	};

}

