#include "../headers/SlimeAmigo.h"

namespace jogador
{
    SlimeAmigo::SlimeAmigo(const Vetor2F Pos, const Vetor2F Vel, const Vetor2F Tam) :
        Jogador(Pos, Vel, Tam, "texture/Jogador2.png")
    {
        teleporte = true;
    }

    SlimeAmigo::~SlimeAmigo()
    {
    }

    void SlimeAmigo::atualizar(float t)
    {
        float teste = relogio.getElapsedTime().asSeconds();
        GerenciadorTeclado* gt = GerenciadorTeclado::getTeclado();

        if (vida == 0)
        {
            posicao = Vetor2F(-150.0f, 350.0f);
            vida = 3;
        }

        if (gt->tecladoJogador() == 0)
        {
            velocidade.x = (0.0f);
        }

        if (gt->tecladoJogador() == 4)
        {
            velocidade.x = -150.0f;
        }
        if (gt->tecladoJogador() == 5)
        {
            velocidade.x = 150.0f;
        }
        if (gt->tecladoJogador() == 11 && teleporte)
        {
            posicao.x += 100.0f;
            teleporte = false;
        }
        if (teste >= 3)
        {
            teleporte = true;
            relogio.restart();
        }

        if (gt->tecladoJogador() == 6 && podePular)
        {
            podePular = false;
            velocidade.y = -sqrt(2.0f * 981.0f * 150.0f);

        }

        if (posicao.y > 7000.0f)
        {
            posicao = Vetor2F(-150.0f, 350.0f);
        }
        velocidade.y += 900.0f * t;

        posicao.x += velocidade.x * t;
        posicao.y += velocidade.y * t;

    }

}
