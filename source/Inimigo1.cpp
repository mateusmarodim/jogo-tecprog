#include "../headers/Inimigo1.h"
#include <iostream>

Inimigo1::Inimigo1(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	Inimigo(pos, vel, tam, "texture/red.png")
{
}

Inimigo1::~Inimigo1()
{
}

void Inimigo1::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(caminho, posicao);
}

void Inimigo1::atualizar(float t)
{
	if (fmod(t,100000000))
	{
		//std::cout << "salve" << endl;
	}
	posicao += velocidade * t;
}

void Inimigo1::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
	std::cout << "Toma essa haha!" << std::endl;
	//outro->setVelocidade(Vetor2F(-0.2,0.0));
	
}