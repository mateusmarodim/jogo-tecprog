#include "Caixote.h"

Caixote::Caixote(Vetor2F pos, Vetor2F vel , Vetor2F tam) :
    Obstaculo(pos, vel, tam, "texture/caixote.png")
{
    colidindo = false;
    velocidade.y = 50;
}

Caixote::~Caixote()
{

}

void Caixote::atualizar(float t)
{
    posicao.y += velocidade.y * t;
    if(colidindo)
        posicao += velocidade * t;
    colidindo = false;
}

void Caixote::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
    if (tipoEntidade == "jogador")
    {
            this->velocidade = outro->getVelocidade();
            colidindo = true;
    }

    if (tipoEntidade == "tile")
    {
        velocidade.y = 0;
    }
}