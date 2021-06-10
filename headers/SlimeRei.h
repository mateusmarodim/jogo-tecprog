#pragma once
#include "Inimigo.h"
#include "Jogador.h"

using namespace jogador;

namespace inimigo
{
	class SlimeRei : public Inimigo
	{
	private:
		Jogador* pJogador;

	public:
		SlimeRei(Jogador* pj = nullptr, const  Vetor2F Pos = (0.0, 0.0), const  Vetor2F Vel = (0.0, 0.0), const  Vetor2F Tam = (0.0, 0.0));
		~SlimeRei();

		void atualizar(float t);
		void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
	};
}

