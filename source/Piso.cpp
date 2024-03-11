#include "../headers/Piso.h"
#include <iostream>

Piso::Piso(const Vetor2F Pos,const  Vetor2F Vel,const  Vetor2F Tam):
	Obstaculo(Pos, Vel, Tam, "texture/tile.jpeg")
{

}

Piso::Piso()
{

}

void Piso::atualizar(float t)
{

}

void Piso::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{

}
