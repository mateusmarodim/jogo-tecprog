#include "PlataformaMovedica.h"

PlataformaMovedica::PlataformaMovedica(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	Obstaculo(pos, vel, tam, "texture/movingplat.png")
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
	velocidade.y -= 40.0f * t;

	if (tempo >= 2.0)
	{
		velocidade.y *=-1;
		teste.restart();
	}
	posicao.y += velocidade.y * t;
	posicao.x += velocidade.x * t;

	

}

void PlataformaMovedica::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{

}
