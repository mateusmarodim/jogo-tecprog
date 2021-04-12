#include "../headers/Jogador.h"
#include <iostream>

Jogador::Jogador(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	EntidadeColidivel(pos,vel,tam,"texture/sorvetao.png")
{
	posicao = Vetor2F(200.0, 400.0);
}

Jogador::~Jogador()
{
}

void Jogador::desenhar(GerenciadorGrafico& gg)
{
	gg.desenhar(caminho, posicao);
}

/*void Jogador::atualizar(float t)
{
	Singleton* s = Singleton::getInstance(ge);

	//std::cout << "oi " << endl;
	velocidade.x = 0.0f;
	if (ge.eventos() == 1)
	{
		//std::cout << "tras" << endl;
		velocidade.x = -100.0f;
	}
	if (ge.eventos() == 2)
	{
		//std::cout << "frente" << endl;
		velocidade.x = 100.0f;
		//std::cout << velocidade.x << endl;
	}

	posicao.x += velocidade.x * t;

}*/

void Jogador::atualizar(float t)
{
    GerenciadorEventos* g = GerenciadorEventos::getInstance();

    //std::cout << "oi " << endl;
    velocidade.x = 0.0f;
    if (g->eventos() == 1)
    {
        //std::cout << "tras" << endl;
        velocidade.x = -100.0f;
    }
    if (g->eventos() == 2)
    {
        //std::cout << "frente" << endl;
        velocidade.x = 100.0f;
        //std::cout << velocidade.x << endl;
    }

    posicao.x += velocidade.x * t;

}


void Jogador::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
	if(tipoEntidade == "inimigo")
	{
		std::cout << "Doeu >.<" << std::endl; 
	}
}