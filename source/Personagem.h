#pragma once
#include "SFML/Graphics.hpp"

class Personagem
{
private:
	sf::Vector2f posicao;
	sf::Vector2f velocidade;
	sf::Texture* text;
	sf::RectangleShape corpo;
	
public:
	Personagem(sf::Vector2f pos = sf::Vector2f(0.0f,0.0f), sf::Vector2f vel = sf::Vector2f(0.0f, 0.0f), const char* caminhoTextura = nullptr);
	~Personagem();
	void atualizar(float t);
	void desenhar(sf::RenderWindow* janela);

};

