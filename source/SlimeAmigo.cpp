#include "SlimeAmigo.h"


SlimeAmigo::SlimeAmigo(const Vetor2F Pos, const Vetor2F Vel, const Vetor2F Tam):
	Jogador(Pos,Vel,Tam,"texture/Jogador2.PNG")
{
}

SlimeAmigo::~SlimeAmigo()
{
}

void SlimeAmigo::atualizar(float t)
{
    GerenciadorEventos* g = GerenciadorEventos::getTeclado();

    if (vida == 0)
    {
        posicao = Vetor2F(-150.0f, 350.0f);
        vida = 3;
    }

    if (g->Teclado() == 0)
    {
        velocidade.x = (0.0f);
    }

    if (g->Teclado() == 4)
    {
        velocidade.x = -150.0f;
    }
    if (g->Teclado() == 5)
    {
        velocidade.x = 150.0f;
    }


    if (g->Teclado() == 6 && podepular)
    {
        podepular = false;
        velocidade.y = -sqrt(2.0f * 981.0f * 150.0f);

    }

    if (posicao.y > 7000.0f)
    {
        posicao = Vetor2F(-150.0f, 350.0f);
    }
    velocidade.y += 900.0f * t;

    posicao.x += velocidade.x * t;
    posicao.y += velocidade.y * t;

    // std::cout << posicao.x<<std::endl;
}
