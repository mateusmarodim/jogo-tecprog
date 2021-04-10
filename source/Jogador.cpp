#include "Jogador.h"
#include <iostream>>

Jogador::Jogador(Vetor2F pos, Vetor2F vel):
	EntidadeColidivel(pos,vel, "sorvetao.jpg")
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
	velocidade.x = 0;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		velocidade.x = -100.0f;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		velocidade.x = 100.0f;
	}
	posicao.x += velocidade.x * t;
	
}