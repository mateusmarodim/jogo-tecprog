#pragma once
#include"Personagem.h"
#include"GerenciadorTeclado.h"
#include <math.h>

namespace jogador
{
	class Jogador : public Personagem
	{
	protected:
		unsigned int vida;

	public:
		Jogador(const Vetor2F Pos = (0.0, 0.0), const Vetor2F Vel = (0.0, 0.0), const Vetor2F Tam = (0.0, 0.0), const string CaminhoText = nullptr);
		virtual ~Jogador();

		virtual void atualizar(float t) = 0;
		virtual void colidir(EntidadeColidivel* outro, std::string tipoEntidade);
	};
}


