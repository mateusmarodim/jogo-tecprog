#include "GerenciadorEventos.h"
#include <iostream>

GerenciadorEventos::GerenciadorEventos()
{

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
	return comeco;
}