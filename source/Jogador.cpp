#include "../headers/Jogador.h"
#include <iostream>

Jogador::Jogador(Vetor2F pos, Vetor2F vel, Vetor2F tam):
	EntidadeColidivel(pos,vel,tam,"texture/blue.png")
{
	//posicao = Vetor2F(200.0, 400.0);
    vida = 10;
    
    //colidindo = false;
}

Jogador::~Jogador()
{
}

void Jogador::desenhar(GerenciadorGrafico& gg)
{
	gg.desenhar(caminho, posicao);
}

/*void Jogador::atualizar(float t)
{
	Singleton* s = Singleton::getInstance(ge);

	//std::cout << "oi " << endl;
	velocidade.x = 0.0f;
	if (ge.eventos() == 1)
	{
		//std::cout << "tras" << endl;
		velocidade.x = -100.0f;
	}
	if (ge.eventos() == 2)
	{
		//std::cout << "frente" << endl;
		velocidade.x = 100.0f;
		//std::cout << velocidade.x << endl;
	}

	posicao.x += velocidade.x * t;

}*/

void Jogador::atualizar(float t)
{
    if(vida == 0)
    {
        posicao = Vetor2F(600.0f,400.0f);
        vida = 10;
    }
    GerenciadorEventos* g = GerenciadorEventos::getInstance();

    if(g->eventos() == 0 )
    {
        velocidade = Vetor2F(0.0f,0.0f);

    }

    if (g->eventos() == 1)
    {
        velocidade.x = -100.0f;
    }
    if (g->eventos() == 2)
    {
        velocidade.x = 100.0f;
    }
    if (pular == true)
    {
        if (g->eventos() == 1 && g->eventos() == 3)
        {
            velocidade.x = -100.0f;
            velocidade.y = -50.0f;
            pular = false;
        }
        else if (g->eventos() == 2 && g->eventos() == 3)
        {
            velocidade.x = 100.0f;
            velocidade.y = -50.0f;
            pular = false;
        }
        else if (g->eventos() == 3)
        {
            velocidade.y = -50.0f;
            pular = false;
        }
    }
    std::cout << velocidade.x << " " << vida << std::endl;

    posicao.x += velocidade.x * t;
    posicao.y += velocidade.y * t;
    pular = true;
    
}


void Jogador::colidir(EntidadeColidivel* outro, std::string tipoEntidade)
{
    float cooldown = cooldownDano.getElapsedTime().asSeconds();
	if(tipoEntidade == "inimigo")
	{
       // colidindo = true;
        if(cooldown >= 2.0)
        {
            vida--;
            cooldownDano.restart();
        }
        if(this->posicao.x < outro->getPosicao().x)   
            posicao.x = posicao.x -.3f;
        else
            posicao.x = posicao.x +.3f;
        //velocidade.x = 0.0;
		std::cout << "Doeu >.< "<< std::endl; 
	}
}