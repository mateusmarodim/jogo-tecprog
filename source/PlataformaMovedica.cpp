#include "PlataformaMovedica.h"
#include <iostream>

PlataformaMovedica::PlataformaMovedica(const Vetor2F Pos,const Vetor2F Vel,const Vetor2F Tam):
	Obstaculo(Pos, Vel, Tam, "texture/movingplat.png")
{
	velfix = 50.0;
	posiniY = Pos.y;
    velocidade.y = 50.0f;
}

PlataformaMovedica::~PlataformaMovedica()
{
}

void PlataformaMovedica::atualizar(float t)
{

    if (posicao.y >= posiniY)
    {
        velocidade.y = -velfix;
    }
    else if (posicao.y <= posiniY-85)
    {
        velocidade.y = velfix;
    }

    posicao.y += velocidade.y * t;
    posicao.x += velocidade.x * t;


}

void PlataformaMovedica::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{

}
