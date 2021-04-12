#include "../headers/Entidade.h"
#include <iostream>

Entidade::Entidade(Vetor2F pos, const char* caminhoText) :
	posicao{ pos }, caminho{ caminhoText }
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

