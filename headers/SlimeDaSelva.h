#pragma once
#include "Inimigo.h"

namespace inimigo
{
	class SlimeDaSelva : public Inimigo
	{
	private:
		int posxInicial;
		float velo;
	public:
		SlimeDaSelva(const Vetor2F Pos = (0.0, 0.0), const Vetor2F Vel = (0.0, 0.0), const Vetor2F Tam = (0.0, 0.0));
		~SlimeDaSelva();

		//void desenhar(GerenciadorGrafico& g);
		void atualizar(float t);
		void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
	};

}

