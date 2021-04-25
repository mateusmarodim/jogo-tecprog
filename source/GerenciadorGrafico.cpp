#include "GerenciadorGrafico.h"
#include <iostream>

GerenciadorGrafico::GerenciadorGrafico():
	janela{ new sf::RenderWindow(sf::VideoMode(1080, 600), "Jogo")},//arrumar com os vetores que foram criados dps 1080,600
	camera(sf::Vector2f(400,300),sf::Vector2f(800,600))//800,600
{
	janela->setView(camera);
}

GerenciadorGrafico::~GerenciadorGrafico()
{
	delete janela;

	for (auto i = texturas.begin(); i != texturas.end(); ++i)
	{
		delete i->second;
	}
}

void GerenciadorGrafico::mostrar()
{
	janela->display();
}

void GerenciadorGrafico::limpar(int r, int g, int b)
{
	janela->clear(sf::Color(r, g, b));
}

/*void GerenciadorGrafico::limpar(const string caminho)
{
	janela->clear(caminho);
}*/


void GerenciadorGrafico::desenhar(string caminho, Vetor2F posicao)
{
	if (texturas.count(caminho) == 0)
	{
		std::cout << "imagem em  " << caminho << " nao encontrada!" << std::endl;
		exit(20);
	}
	text = texturas[caminho];

	
	sprite.setTexture(*text, true);
	sprite.setOrigin(text->getSize().x*0.5,text->getSize().y*0.5);
	sprite.setPosition(posicao.x, posicao.y);
	janela->draw(sprite);

}

bool GerenciadorGrafico::carregarTextura(string caminho)
{
	if (texturas.count(caminho) == 1)
		return true;
	else
	{
		sf::Texture* text = new sf::Texture();
		if (!text->loadFromFile(caminho))
		{
			std::cout << "imagem em " << caminho << "nao carregada!" << std::endl;
			exit(10);
		}

		texturas.emplace(caminho, text);

		return true;
	}
}

void GerenciadorGrafico::centralizar(Vetor2F centro)
{
	camera.setCenter(sf::Vector2f(centro.x, centro.y));
	janela->setView(camera);
}

sf::RenderWindow* GerenciadorGrafico::getJanela()
{
	return janela;
}

const Vetor2F GerenciadorGrafico::getTamanho(const std::string& caminho) const {

	if (texturas.count(caminho) == 0) {
		std::cout << "Atencao! Imagem em " << caminho << " nao carregada!" << std::endl;
		exit(121);
	}

	sf::Vector2u dimensoes = (texturas.at(caminho))->getSize();

	return Vetor2F(dimensoes.x, dimensoes.y);
}

/*void GerenciadorGrafico::desenharRetanguloSolido(const Vetor2F centro, const Vetor2F dimensao, const Cor cor) const {
	sf::RectangleShape retangulo = sf::RectangleShape({ dimensao.x, dimensao.y });
	retangulo.setFillColor({ cor.r, cor.g, cor.b, cor.a });
	retangulo.setOrigin(dimensao.x / 2, dimensao.y / 2);
	retangulo.setPosition(centro.x, centro.y);
	janela->draw(retangulo);
}*/