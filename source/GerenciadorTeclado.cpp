#include "GerenciadorTeclado.h"
#include <iostream>

GerenciadorTeclado::GerenciadorTeclado()
{

}

GerenciadorTeclado* GerenciadorTeclado::getTeclado()
{
	if (g == nullptr)
	{
		g = new GerenciadorTeclado();
	}
	return g;
}

GerenciadorTeclado::~GerenciadorTeclado()
{
}

GerenciadorTeclado::Teclas  GerenciadorTeclado::tecladoUtilidade()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::M))
	{
		return adicionarP2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::N))
	{
		return removerP2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P))
	{
		return pausar;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::R))
	{
		return resumir;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num1))
	{
		return menuop1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num2))
	{
		return menuop2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num3))
	{
		return menuop3;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Num4))
	{
		return menuop4;
	}
}


GerenciadorTeclado::Teclas GerenciadorTeclado::tecladoJogador()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		return andarEsquerdaP1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		return andarDireitaP1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		return pularP1;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
	{
		return andarEsquerdaP2;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
	{
		return andarDireitaP2;
	}	
	if(sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))
	{
		return pularP2;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T))
	{
		return teleporte;
	}

}

GerenciadorTeclado* GerenciadorTeclado::g = nullptr;