#include "Entidade.h"

Entidade::Entidade(Vetor2F Pos, const char* caminhoText) :
	posicao{ Pos }, caminho{ caminhoText }
{
}

Entidade::~Entidade()
{
}

void Entidade::inicializar(GerenciadorGrafico& g)
{
	g.carregarTextura(caminho);
}

void Entidade::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(caminho, posicao);
}
