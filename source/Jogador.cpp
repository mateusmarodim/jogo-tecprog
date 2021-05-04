#include "Jogador.h"
#include <iostream>

Jogador::Jogador(const Vetor2F Pos, const Vetor2F Vel, const Vetor2F Tam, const string CaminhoText ):
	Personagem(Pos,Vel,Tam,CaminhoText)
{
    vida = 3;
    bool pular = false;
    bool podepular = true;
}

Jogador::~Jogador()
{
}


void Jogador::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{

    float cooldown = relogio.getElapsedTime().asSeconds();

    Vetor2F distancia = posicao - outro->getPosicao();
    Vetor2F distanciaCentros = (tamanho + outro->getTamanho()) * 0.5; 
    float intersectaX = abs(distancia.x) - distanciaCentros.x;
    float intersectaY = abs(distancia.y) - distanciaCentros.y;

	if(tipoEntidade == "inimigo")
	{
        if(cooldown >= 2.0)
        {
            vida--;
            relogio.restart();
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
                //podepular = true;
                posicao.y += -1 * intersectaY;
            }
            else
            {
                podepular = true;
                posicao.y += 1 * intersectaY;
            }
            
            velocidade.y = 0.0f;
        }

    }

    if (tipoEntidade == "king")
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
        //else
        //{
        //    if (distancia.y > 0)
        //    {
        //        posicao.y += -1 * intersectaY;
        //    }
        //    else
        //    {
        //        posicao.y += 1 * intersectaY;
        //    }
        //}
    }
}