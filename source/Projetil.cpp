#include "Projetil.h"
#include <iostream>

Projetil::Projetil(Vetor2F Pos, Vetor2F Vel, Vetor2F Tam):
EntidadeColidivel(Pos, Vel, Tam, "texture/projetil.png")
{

}

Projetil::~Projetil()
{

}

void Projetil::atualizar(float t)
{
    velocidade.x -= 30*t;
    posicao.x += velocidade.x * t;
}

void Projetil::colidir(EntidadeColidivel* outro, string tipoEntidade)
{
    if (tipoEntidade == "jogador") 
    {
        std::cout << "hasta la vista baby ;)" << std::endl;
    }
}