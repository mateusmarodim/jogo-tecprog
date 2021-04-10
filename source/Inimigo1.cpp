#include "Inimigo1.h"
#include <iostream>

Inimigo1::Inimigo1(Vetor2F pos, Vetor2F vel):
	Inimigo(pos, vel, "possivel inimigo.png")
{
}

Inimigo1::~Inimigo1()
{
}

void Inimigo1::inicializar(GerenciadorGrafico& g)
{
	g.carregarTextura(caminho);
}

void Inimigo1::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(caminho, posicao);
}

void Inimigo1::atualizar(float t)
{
	if (fmod(t,100000000))
	{
		std::cout << "salve" << endl;
	}
	posicao += velocidade * t;
}
