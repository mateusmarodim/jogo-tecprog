#include "../headers/Jogador.h"
#include <iostream>

namespace jogador
{
    Jogador::Jogador(const Vetor2F Pos, const Vetor2F Vel, const Vetor2F Tam, const string CaminhoText) :
    Personagem(Pos,Vel,Tam,CaminhoText)
{
    velocidade.y = 0;
    vida = 5;
    bool podePular = true;
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

    if (tipoEntidade == "inimigo")
    {
        if (cooldown >= 2.0)
        {
            vida--;
            relogio.restart();
            std::cout << "Vidas :" << vida << std::endl;
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
                podePular = true;
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
            podePular = true;
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
             if (this->posicao.y < outro->getPosicao().y)
             {
                 posicao.x = posicao.x - 100.f;
             }
             else
             {
                 posicao.x = posicao.x - 100.f;
             }

      }

      if (tipoEntidade == "tile")
      {

          if (intersectaX > intersectaY)
          {
              podePular = true;
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
                  podePular = true;
                  posicao.y += 1 * intersectaY;
              }

              velocidade.y = 0.0f;
          }

      }

      if (tipoEntidade == "king")
      {
          if (cooldown >= 2.0)
          {
              vida--;
              relogio.restart();
              std::cout <<"Vidas :" << vida << std::endl;
          }

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
      }

      if (tipoEntidade == "espinho")
      {
          if (cooldown >= 2.0)
          {
              vida--;
              relogio.restart();
              std::cout << "Vidas :" << vida << std::endl;
          }
      }
  }
}
