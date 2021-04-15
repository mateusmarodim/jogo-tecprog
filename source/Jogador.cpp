#include "Jogador.h"
#include <iostream>

Jogador::Jogador(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	EntidadeColidivel(pos,vel,tam,"texture/blue.png")
{
	//posicao = Vetor2F(200.0, 400.0);
    vida = 3;
    bool pular = false;
    
    //colidindo = false;
}

Jogador::~Jogador()
{
}

void Jogador::desenhar(GerenciadorGrafico& gg)
{
	gg.desenhar(caminho, posicao);
}


void Jogador::atualizar(float t)
{

    GerenciadorEventos* g = GerenciadorEventos::getInstance();

    velocidade.y = 55;
    if (vida == 0)
    {
        posicao = Vetor2F(200.0f, 400.0f);
        vida = 3;
    }

    if(g->eventos() == 0 )
    {
        velocidade.x = (0.0f);
    }

    if (g->eventos() == 1)
    {
        velocidade.x = -100.0f;
    }
    if (g->eventos() == 2)
    {
        velocidade.x = 100.0f;
    }
    

    if (g->eventos() == 3)
    {
        if (pular) 
        {
            velocidade.y = - 30000;
            pular = false;
        }    
    }
    std::cout << pular << endl;

    
    posicao.x += velocidade.x * t;
    posicao.y += velocidade.y * t;



   std::cout << posicao.x<<std::endl;
    
}


void Jogador::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
    float cooldown = cooldownDano.getElapsedTime().asSeconds();

	if(tipoEntidade == "inimigo")
	{
        if(cooldown >= 2.0)
        {
            vida--;
            cooldownDano.restart();
            std::cout << "Doeu >.< " << " " << vida << std::endl;
        }
        if(this->posicao.x < outro->getPosicao().x)   
            posicao.x = posicao.x -.3f;
        else
            posicao.x = posicao.x +.3f;
        if (this->posicao.y < outro->getPosicao().y)
        {
            posicao.y = posicao.y - .3f;
        }
        else
        {
            posicao.y = posicao.y + .3f;
        }
	}

    if (tipoEntidade == "tile")
    {
        //std::cout << pular << endl;
        pular = true;
        if (this->posicao.y < outro->getPosicao().y)
        {
            posicao.y = posicao.y - .3f;
        }
        else
        {
            posicao.y = posicao.y + .3f;
        }

    }

    if (tipoEntidade == "plataformamovedica")
    {
        if (this->posicao.y < outro->getPosicao().y)
        {
            posicao.y = posicao.y - .3f;
        }
        else
        {
            posicao.y = posicao.y + .3f;
        }
    }

    if (tipoEntidade == "caixote")
    {
        if (this->posicao.y < outro->getPosicao().y)
        {
            posicao.y = posicao.y - .3f;
            pular = true;
        }
        else
        {
            posicao.y = posicao.y + .3f;
            pular = true;
        }
    }
}