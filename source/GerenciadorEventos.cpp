#include "GerenciadorEventos.h"
#include <iostream>

GerenciadorEventos::GerenciadorEventos()
{

}

GerenciadorEventos* GerenciadorEventos::getTeclado()
{
	if (g == nullptr)
	{
		g = new GerenciadorEventos();
	}
	return g;
}

GerenciadorEventos::~GerenciadorEventos()
{
}


GerenciadorEventos::Teclas GerenciadorEventos::Teclado()
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
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::T))
	{
		return teleporte;
	}
	
	//return comeco;
}

GerenciadorEventos* GerenciadorEventos::g = nullptr;