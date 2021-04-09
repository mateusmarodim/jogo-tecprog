#include "Jogador.h"
#include <iostream>>

Jogador::Jogador(Vetor2F pos, Vetor2F vel):
	Personagem(pos,vel, "sorvetao.jpg")
{
	posicao = Vetor2F(400.0, 400.0);
}

Jogador::~Jogador()
{
}

void Jogador::inicializar(GerenciadorGrafico& gg)
{
	gg.carregarTextura(caminho);
}

void Jogador::desenhar(GerenciadorGrafico& gg)
{
	gg.desenhar(caminho, posicao);
}

void Jogador::atualizar(GerenciadorEventos& ge, float t)
{
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

}
