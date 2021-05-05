#include "Inimigo.h"

namespace inimigo
{
	Inimigo::Inimigo(const Vetor2F Pos, const Vetor2F Vel, const Vetor2F Tam, const string CaminhoText) :
		Personagem(Pos, Vel, Tam, CaminhoText)
	{
	}

	Inimigo::~Inimigo()
	{
	}
}


