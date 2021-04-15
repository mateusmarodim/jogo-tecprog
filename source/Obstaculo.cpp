#include "Obstaculo.h"
#include <iostream>

Obstaculo::Obstaculo(Vetor2F pos, Vetor2F vel, Vetor2F tam, const char* caminhoText) :
    EntidadeColidivel(pos, vel, tam, caminhoText)
{
}

Obstaculo::~Obstaculo()
{
}

/*void Obstaculo::desenhar(GerenciadorGrafico& g)
{
    g.desenhar(caminho, posicao);
}*/