#include "Personagem.h"

Personagem::Personagem(const Vetor2F Pos, const Vetor2F Vel, const Vetor2F Tam, const string CaminhoText):
	EntidadeColidivel(Pos,Vel,Tam,CaminhoText)
{
}

Personagem::~Personagem()
{
}
