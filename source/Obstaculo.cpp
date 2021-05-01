#include "Obstaculo.h"
#include <iostream>

Obstaculo::Obstaculo(const Vetor2F Pos,const  Vetor2F Vel,const  Vetor2F Tam,const string CaminhoText) :
    EntidadeColidivel(Pos, Vel, Tam, CaminhoText)
{
}

Obstaculo::~Obstaculo()
{
}

void Obstaculo::colidir(EntidadeColidivel* outro, string tipoEntidade)
{
}
