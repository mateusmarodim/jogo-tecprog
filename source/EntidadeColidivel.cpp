#include "EntidadeColidivel.h"
#include <iostream>

EntidadeColidivel::EntidadeColidivel(Vetor2F Pos, Vetor2F Vel, const char* caminhoText):
	posicao{Pos},velocidade{Vel},caminho{caminhoText}
{
}

EntidadeColidivel::~EntidadeColidivel()
{
}

void EntidadeColidivel::inicializar(GerenciadorGrafico& g)
{
	g.carregarTextura(caminho);
}

void EntidadeColidivel::desenhar(GerenciadorGrafico &g)
{
	g.desenhar(caminho, posicao);
}
