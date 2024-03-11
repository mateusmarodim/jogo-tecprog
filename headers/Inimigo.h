#pragma once
#include "../headers/Personagem.h"

namespace inimigo
{
	class Inimigo : public Personagem
	{
	public:
		Inimigo(const Vetor2F Pos = (0.0, 0.0), const Vetor2F Vel = (0.0, 0.0), const Vetor2F Tam = (0.0, 0.0), const string CaminhoText = nullptr);
		virtual ~Inimigo();

		virtual void atualizar(float t) = 0;
		virtual void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
	};

}

