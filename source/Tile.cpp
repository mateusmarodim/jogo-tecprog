#include "../headers/Tile.h"
#include <iostream>

Tile::Tile(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	EntidadeColidivel(pos, vel, tam, "texture/purple.png")
{
	//tam = Vetor2F(1000.0, 1000.0);
}

Tile::Tile()
{
}

void Tile::desenhar(GerenciadorGrafico& g)
{
	g.desenhar(caminho, posicao);
}

void Tile::atualizar(float t)
{

}

void Tile::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
	//std::cout << "Harder daddy" << std::endl;
}
