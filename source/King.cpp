#include "King.h"
#include <iostream>

King::King(Caverna* pc, Jogador* pj, Vetor2F pos, Vetor2F vel, Vetor2F tam) :
    Inimigo(pos, vel, tam, "texture/king.png"),
    pCaverna(pc), pJogador(pj)
{
    podePular = true;
   // velocidade.y = 100.0f;
   // velocidade.x = 50.0f;
}

King::~King()
{
}

void King::atualizar(float t)
{
    if (abs(getPosicao().x - pJogador->getPosicao().x) <= 250)
    {
        mover();
    }
    velocidade.y += 700.0f * t;
    posicao += velocidade * t;

   // std::cout << abs(posicao.x - pJogador->getPosicao().x) << std::endl;
}

void King::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
    Vetor2F distancia = posicao - outro->getPosicao();
    Vetor2F distanciaCentros = (tamanho + outro->getTamanho()) * 0.5;
    float intersectaX = abs(distancia.x) - distanciaCentros.x;
    float intersectaY = abs(distancia.y) - distanciaCentros.y;

    if (tipoEntidade == "tile")
    {

        if (intersectaX > intersectaY)
        {
            podePular = true;
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
            podePular = true;
            velocidade.y = 0.0f;
        }

    }

}

void King::mover()
{
    float tempo = cooldownPulo.getElapsedTime().asSeconds();
    if (tempo >= 1 && podePular)
    {
        podePular = false;
        velocidade.y = -sqrt(2.0f * 981.0f * 150.0f);
        cooldownPulo.restart();
    }
    velocidade.x = (((pJogador->getPosicao().x) - (getPosicao().x)))*0.5;
}