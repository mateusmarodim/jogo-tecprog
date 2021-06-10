#include "Espinho.h"
#include <iostream>

Espinho::Espinho(const Vetor2F Pos,const Vetor2F Vel,const Vetor2F Tam):
EntidadeColidivel(Pos, Vel, Tam, "texture/projetil.png")
{

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

}
