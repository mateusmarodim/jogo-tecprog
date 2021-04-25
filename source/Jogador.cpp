#include "Jogador.h"
#include <iostream>

Jogador::Jogador(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	EntidadeColidivel(pos,vel,tam,"texture/Jogador.png")
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
        velocidade.y = -sqrt(2.0f * 981.0f * 150.0f );

    }
    
    velocidade.y += 900.0f * t;

    posicao.x += velocidade.x * t;
    posicao.y += velocidade.y * t;

   //std::cout << posicao.x<<std::endl;
    
}


void Jogador::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{

    float cooldown = cooldownDano.getElapsedTime().asSeconds();

    Vetor2F distancia = posicao - outro->getPosicao();
    Vetor2F distanciaCentros = (tamanho + outro->getTamanho()) * 0.5; 
    float intersectaX = abs(distancia.x) - distanciaCentros.x;
    float intersectaY = abs(distancia.y) - distanciaCentros.y;

	if(tipoEntidade == "inimigo")
	{
        if(cooldown >= 2.0)
        {
            //vida--;
            cooldownDano.restart();
            std::cout << "Doeu >.< " << " " << vida << std::endl;
        }

        if (intersectaX > intersectaY)
        {
            if (distancia.x > 0)
            {
                posicao.x += -1 * intersectaX;
            }
            else
                posicao.x += 1 * intersectaX;
        }
        else
        {
            velocidade.y = 0;
            if (distancia.y > 0)
            {
                posicao.y += -1 * intersectaY;
            }
            else
                posicao.y += 1 * intersectaY;
        }
	}

    /*if (tipoEntidade == "tile")
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

    }*/

    if (tipoEntidade == "plataformamovedica")
    {
        if (intersectaX > intersectaY)
        {
            if (distancia.x > 0)
            {
                posicao.x += -1 * intersectaX;
            }
            else
                posicao.x += 1 * intersectaX;
        }
        else
        {
            velocidade.y = 0;
            if (distancia.y > 0)
            {
                posicao.y += -1 * intersectaY;
            }
            else
            {
                podepular = true;
                posicao.y += 1 * intersectaY;
            }

 
        }

    }

    if (tipoEntidade == "caixote")
    {
        if (intersectaX > intersectaY)
        {
            if (distancia.x > 0)
            {
                posicao.x += -1 * intersectaX;
            }
            else
            {
                posicao.x += 1 * intersectaX;
            }
        }

        else
        {
            podepular = true;
            if (distancia.y > 0)
            {

                posicao.y += -1 * intersectaY;
            }
            else
            {
                posicao.y += 1 * intersectaY;
            }
            velocidade.y = 0;
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

    if (tipoEntidade == "tile")
    {

        if (intersectaX > intersectaY)
        {
            podepular = true;
            if (distancia.x > 0)
            {
                posicao.x += -1 * intersectaX;
            }
            else
            {
                posicao.x += 1 * intersectaX;
            }
            velocidade.y = 0.0f;
        }
        else
        {
            if (distancia.y > 0)
            {
                posicao.y += -1 * intersectaY;
            }
            else
            {
                posicao.y += 1 * intersectaY;
            }
            podepular = true;
            velocidade.y = 0.0f;
        }

    }
}