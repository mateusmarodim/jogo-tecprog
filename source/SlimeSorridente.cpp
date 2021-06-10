#include "SlimeSorridente.h"

namespace jogador
{
    SlimeSorridente::SlimeSorridente(const Vetor2F Pos, const Vetor2F Vel, const Vetor2F Tam) :
        Jogador(Pos, Vel, Tam, "texture/Jogador.png")
    {
    }

    SlimeSorridente::~SlimeSorridente()
    {
    }

    void SlimeSorridente::atualizar(float t)
    {
        GerenciadorTeclado* gt = GerenciadorTeclado::getTeclado();

        if (vida == 0 || posicao.y > 7000.0f)
        {
            posicao = Vetor2F(-150.0f, 350.0f);
            vida = 3;
        }

        if (gt->tecladoJogador() == 0)
        {
            velocidade.x = (0.0f);
        }

        if (gt->tecladoJogador() == 1)
        {
            velocidade.x = -150.0f;
        }
        if (gt->tecladoJogador() == 2)
        {
            velocidade.x = 150.0f;
        }


        if (gt->tecladoJogador() == 3 && podePular)
        {
            podePular = false;
            velocidade.y = -sqrt(2.0f * 981.0f * 150.0f);

        }

        velocidade.y += 900.0f * t;

        posicao.x += velocidade.x * t;
        posicao.y += velocidade.y * t;
    }
}
