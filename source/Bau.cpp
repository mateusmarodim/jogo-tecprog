#include "Bau.h"

Bau::Bau(const Vetor2F Pos,const  Vetor2F Vel ,const  Vetor2F Tam) :
    Obstaculo(Pos, Vel, Tam, "texture/caixote.png")
{
    colidindo = false;
    velocidade.y = 50;
}

Bau::~Bau()
{

}

void Bau::atualizar(float t)
{
    posicao.y += velocidade.y * t;
    if(colidindo)
        posicao.x += velocidade.x * t;
    colidindo = false;
}

void Bau::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
    Vetor2F distancia = posicao - outro->getPosicao();
    Vetor2F distanciaCentros = (tamanho + outro->getTamanho()) * 0.5;
    float intersectaX = abs(distancia.x) - distanciaCentros.x;
    float intersectaY = abs(distancia.y) - distanciaCentros.y;

    if (tipoEntidade == "jogador" || tipoEntidade == "jogador2")
    {

        if (intersectaX > intersectaY)
        {
            if (distancia.x > 0)
            {
                posicao.x += -1 * intersectaX;
            }
            else
            {
                posicao.x += 1 * intersectaX;
            }
        }

        else
        {
          
            velocidade.y = 0;
        }
       
  
    }

    if (tipoEntidade == "tile")
    {
        if (intersectaX > intersectaY)
			{
				if (distancia.x > 0)
				{
					posicao.x += -1 * intersectaX;
				}
				else
				{
					posicao.x += 1 * intersectaX;
				}
				velocidade.y = 0.0f;
			}
			else
			{
				if (distancia.y > 0)
				{
					posicao.y += -1 * intersectaY;
				}
				else
				{
					posicao.y += 1 * intersectaY;
				}
			}
    }
}