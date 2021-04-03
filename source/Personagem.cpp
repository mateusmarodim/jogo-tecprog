#include "Personagem.h"
#include <iostream>

Personagem::Personagem(Vetor2F Pos, Vetor2F Vel, const char* caminhoText):
	posicao{Pos},velocidade{Vel},caminho{caminhoText}
{
}

Personagem::~Personagem()
{
}

void Personagem::inicializar(GerenciadorGrafico &g)
{
	g.carregarTextura(caminho);
}

void Personagem::atualizar(float t)
{
	posicao += velocidade * t;
}


void Personagem::desenhar(GerenciadorGrafico &g)
{
	g.desenhar(caminho, posicao);
}
