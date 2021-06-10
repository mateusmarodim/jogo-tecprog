#include "SlimeRei.h"
#include <iostream>

namespace inimigo
{
    SlimeRei::SlimeRei(Jogador* pj, const  Vetor2F Pos, const  Vetor2F Vel, const  Vetor2F Tam) :
        Inimigo(Pos, Vel, Tam, "texture/king.png"),
        pJogador(pj)
    {
        podePular = true;

    }

    SlimeRei::~SlimeRei()
    {
    }

    void SlimeRei::atualizar(float t)
    {
        float tempo = relogio.getElapsedTime().asSeconds();
        if (abs(getPosicao().x - pJogador->getPosicao().x) <= 250)
        {
            if (tempo >= 1 && podePular)
            {
                podePular = false;
                velocidade.y = -sqrt(2.0f * 981.0f * 150.0f);
                relogio.restart();
            }
            velocidade.x = (((pJogador->getPosicao().x) - (getPosicao().x))) * 0.5;
        }

        velocidade.y += 700.0f * t;
        posicao += velocidade * t;

    }

    void SlimeRei::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
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

}

