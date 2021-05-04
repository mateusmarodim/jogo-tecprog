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
    float x = abs(distancia.x) - distanciaCentros.x;
    float y = abs(distancia.y) - distanciaCentros.y;

    if (tipoEntidade == "jogador" || tipoEntidade == "jogador2")
    {

        if (x > y)
        {
            if (distancia.x > 0)
            {
                posicao.x += -1 * x;
            }
            else
            {
                posicao.x += 1 * x;
            }
        }

        else
        {
           // podepular = true;
            velocidade.y = 0;
           /* if (distancia.y > 0)
            {
                posicao.y += -1 * y;
            }
            else
            {
                posicao.y += 1 * y;
            }*/
        }
       /* colidindo = true;
        if (this->posicao.x < outro->getPosicao().x)
        {
             //posicao.x = posicao.x - .3f;
            this->velocidade.x = outro->getVelocidade().x;
        }
        else if (this->posicao.x > outro->getPosicao().x)
        {
            // posicao.x = posicao.x + .3f;
            this->velocidade.x = outro->getVelocidade().x;
        }*/
  
    }

    if (tipoEntidade == "tile")
    {
        velocidade.y = 0;
    }
}