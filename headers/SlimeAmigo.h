#pragma once
#include "Jogador.h"

namespace jogador
{
	class SlimeAmigo : public Jogador
	{
	private:
		bool teleporte;

	public:
		SlimeAmigo(const Vetor2F Pos = (0.0, 0.0), const Vetor2F Vel = (0.0, 0.0), const Vetor2F Tam = (0.0, 0.0));
		~SlimeAmigo();

		void atualizar(float t);
	};
}


