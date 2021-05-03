#include "Espinho.h"
#include <iostream>

Espinho::Espinho(Vetor2F Pos, Vetor2F Vel, Vetor2F Tam):
EntidadeColidivel(Pos, Vel, Tam, "texture/projetil.png")
{
    //deletar = false;
}

Espinho::~Espinho()
{

}

void Espinho::atualizar(float t)
{
    velocidade.x -= 30*t;
    posicao.x += velocidade.x * t;
}

void Espinho::colidir(EntidadeColidivel* outro, string tipoEntidade)
{
    if (tipoEntidade == "jogador") 
    {
        //std::cout << "hasta la vista baby ;)" << std::endl;
    }
}
