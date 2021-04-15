#include "PlataformaMovedica.h"

PlataformaMovedica::PlataformaMovedica(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	Obstaculo(pos, vel, tam, "texture/green.png")
{
}

PlataformaMovedica::~PlataformaMovedica()
{
}

void PlataformaMovedica::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(caminho, posicao);
}

void PlataformaMovedica::atualizar(float t)
{
	float tempo = teste.getElapsedTime().asSeconds();

	if (tempo >= 2.0)
	{
		velocidade.y *=-1;
		teste.restart();
	}
	posicao.y += velocidade.y * t;
	posicao.x += velocidade.x * t;

	velocidade.y = 30.0f;

}

void PlataformaMovedica::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
}
