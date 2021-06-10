#pragma once
#include "Jogador.h"

namespace jogador
{
	class SlimeSorridente : public Jogador
	{
	public:
		SlimeSorridente(const Vetor2F Pos = (0.0, 0.0), const Vetor2F Vel = (0.0, 0.0), const Vetor2F Tam = (0.0, 0.0));
		~SlimeSorridente();

		void atualizar(float t);
	};
}


