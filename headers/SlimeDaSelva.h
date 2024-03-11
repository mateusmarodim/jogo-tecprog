#pragma once
#include "../headers/Inimigo.h"

namespace inimigo
{
	class SlimeDaSelva : public Inimigo
	{
	private:
		const float posxInicial;
		const float veloX;

	public:
		SlimeDaSelva(const Vetor2F Pos = (0.0, 0.0), const Vetor2F Vel = (0.0, 0.0), const Vetor2F Tam = (0.0, 0.0));
		~SlimeDaSelva();

		void atualizar(float t);
	};
}

