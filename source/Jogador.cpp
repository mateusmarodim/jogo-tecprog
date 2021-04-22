#include "Jogador.h"
#include <iostream>

Jogador::Jogador(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	EntidadeColidivel(pos,vel,tam,"texture/blue.png")
{
	//posicao = Vetor2F(200.0, 400.0);
    vida = 3;
    bool pular = false;
    bool podepular = true;
    
    //colidindo = false;
}

Jogador::~Jogador()
{
}

/*void Jogador::desenhar(GerenciadorGrafico& gg)
{
	gg.desenhar(caminho, posicao);
}*/


void Jogador::atualizar(float t)
{

    GerenciadorEventos* g = GerenciadorEventos::getInstance();

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
    

    if (g->eventos() == 3 && podepular)
    {
        podepular = false;
        velocidade.y = -sqrt(2.0f * 981.0f * 100.0f );

    }
    
    velocidade.y += 900.0f * t;

    posicao.x += velocidade.x * t;
    posicao.y += velocidade.y * t;

   //std::cout << posicao.x<<std::endl;
    
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

        if (this->posicao.y < outro->getPosicao().y)
        {
            pular = true;
            podepular = true;
            posicao.y = posicao.y - .3f;
            velocidade.y = 0.0f;
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
            podepular = true;
            velocidade.y = 0;
        }
        else
        {
            posicao.y = posicao.y + .3f;
            pular = true;
        }
    }

    if (tipoEntidade == "caixote")
    {
        if (this->posicao.y < outro->getPosicao().y)
        {
            posicao.y = posicao.y -.5f;
            velocidade.y = 0;
            podepular = true;
        }
        else
        {
            posicao.y = posicao.y + .3f;
            pular = true;
        }
    }

    if (tipoEntidade == "armadilha")
    {
       // if (cooldown >= 2.0)
       // {
            if (this->posicao.y < outro->getPosicao().y)
            {
                posicao.x = posicao.x - 100.f;
            }
            else
            {
                posicao.x = posicao.x - 100.f;
            }
           // cooldownDano.restart();
      //  }

    }
}