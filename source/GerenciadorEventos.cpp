#include "GerenciadorEventos.h"
#include <iostream>

GerenciadorEventos::GerenciadorEventos()
{

}

GerenciadorEventos* GerenciadorEventos::getInstance()
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


GerenciadorEventos::Evento GerenciadorEventos::eventos()
{
	
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
	{
		return andarEsquerda;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
	{
		return andarDireita;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space))
	{
		return pular;
	}
	
	return comeco;
}

GerenciadorEventos* GerenciadorEventos::g = nullptr;