#include "EntidadeColidivel.h"
#include <iostream>

EntidadeColidivel::EntidadeColidivel(Vetor2F pos, Vetor2F vel, Vetor2F tam, const char* caminhoText):
	velocidade{vel},posicao{pos},tamanho{tam},caminho{caminhoText}
{
}

EntidadeColidivel::~EntidadeColidivel()
{
}

void EntidadeColidivel::inicializar(GerenciadorGrafico& g)
{
	g.carregarTextura(caminho);
	tamanho = g.getTamanho(caminho);
}

void EntidadeColidivel::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(caminho, posicao);
}

const Vetor2F EntidadeColidivel::getPosicao()const
{
	return posicao;
}

const Vetor2F EntidadeColidivel::getTamanho()const
{
	return tamanho;
}

const Vetor2F EntidadeColidivel::getVelocidade() const
{
	return velocidade;
}
