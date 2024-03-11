#pragma once
#include "../headers/Inimigo.h"
#include "../headers/Espinho.h"

class Fase;

namespace inimigo
{
	class SlimeEspinhoso : public Inimigo
	{
	private:
		Fase* fase;
		int posxInicial;
		Espinho* proj;

	public:
		SlimeEspinhoso(Fase* fs = nullptr, const  Vetor2F Pos = (0.0, 0.0), const  Vetor2F Vel = (0.0, 0.0), const  Vetor2F Tam = (0.0, 0.0));
		~SlimeEspinhoso();

		void atualizar(float t);
		void atirar();
	};
}
