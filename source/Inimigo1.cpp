#include "Inimigo1.h"
#include <iostream>

Inimigo1::Inimigo1(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	Inimigo(pos, vel, tam, "texture/jungleslime.png")
{
	velocidade.y = 100.0f;
	velocidade.x = 100.0f;
	posxInicial = pos.x;
}

Inimigo1::~Inimigo1()
{
}

/*void Inimigo1::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(caminho, posicao);
}*/

void Inimigo1::atualizar(float t)
{
	
	if (posxInicial +100 >= posicao.x)
	{
		velocidade.x *= -1;
	}
	if (posxInicial -100 <= posicao.x)
	{
		velocidade.x *=-1;
	}

	posicao += velocidade * t;
	//std::cout << posicao.x << endl;
}

void Inimigo1::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
	//std::cout << "Toma essa haha!" << std::endl;
	//outro->setVelocidade(Vetor2F(-0.2,0.0));
	if (tipoEntidade == "tile")
	{
		velocidade.y = 0;
	}
	
}