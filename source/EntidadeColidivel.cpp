#include "../headers/EntidadeColidivel.h"
#include <iostream>

EntidadeColidivel::EntidadeColidivel(const Vetor2F Pos,const Vetor2F Vel,const Vetor2F Tam, const string CaminhoText):
	posicao{Pos},
	velocidade{Vel},
	tamanho{Tam},
	caminho{CaminhoText}
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

const Vetor2F EntidadeColidivel::getVelocidade()const
{
	return velocidade;
}

const sf::Clock* EntidadeColidivel::getTempo()const
{
	return &relogio;
}

void EntidadeColidivel::reiniciaRelogio()
{
	relogio.restart();
}
