#include "Caixote.h"

Caixote::Caixote(Vetor2F pos, Vetor2F vel , Vetor2F tam) :
    Obstaculo(pos, vel, tam, "texture/yellow.png")
{
    colidindo = false;
}

Caixote::~Caixote()
{

}

void Caixote::desenhar(GerenciadorGrafico& g)
{
    g.desenhar(caminho,posicao);
}

void Caixote::atualizar(float t)
{
    if(colidindo)
        posicao.x += velocidade.x * t;
    colidindo = false;
}

void Caixote::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
    if (tipoEntidade == "jogador")
    {
            this->velocidade = outro->getVelocidade();
            colidindo = true;
    }
}