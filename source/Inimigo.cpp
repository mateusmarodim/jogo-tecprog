#include "../headers/Inimigo.h"

Inimigo::Inimigo(Vetor2F pos, Vetor2F vel, Vetor2F tam, const char* caminhoText):
	EntidadeColidivel(pos,vel,tam,caminhoText)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(caminho, posicao);
}


