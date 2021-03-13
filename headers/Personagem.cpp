#include "Personagem.h"

Personagem::Personagem(sf::Vector2f pos, sf::Vector2f vel, const char* caminhoTextura) :
	posicao{pos}, velocidade{vel}, text{ nullptr }
{

	corpo.setSize(sf::Vector2f(200.0f, 200.0f));

	if (caminhoTextura) 
	{
	text = new sf::Texture;
	text->loadFromFile(caminhoTextura);
	}

	corpo.setTexture(text);
	corpo.setSize(sf::Vector2f(200.0f, 200.0f));
	corpo.setOrigin(corpo.getSize() / 2.0f);
	
}

Personagem::~Personagem()
{
	if(text)
		delete text;
}

void Personagem::atualizar(float t)
{
	/*if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
		corpo.move(-0.1f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
		corpo.move(0.1f, 0.0f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
		corpo.move(0.0f,-0.1f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
		corpo.move(0.01f,0.1f);*/
	posicao += velocidade*t;

	corpo.setPosition(posicao);
}

void Personagem::desenhar(sf::RenderWindow* janela)
{
	janela->draw(corpo);
}

