#include "Inimigo.h"

Inimigo::Inimigo(Vetor2F pos, Vetor2F vel, const char* caminhoText):
	Personagem(pos,vel,caminhoText)
{
}

Inimigo::~Inimigo()
{
}

void Inimigo::inicializar(GerenciadorGrafico& g)
{
	g.carregarTextura(caminho);
}

void Inimigo::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(caminho, posicao);
}

void Inimigo::atualizar(float t)
{
	posicao += velocidade * t;
}
