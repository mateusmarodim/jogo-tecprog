#include "Fase.h"

Fase::Fase(sf::Clock* rf, GerenciadorGrafico* gg):
	relogiof(rf), gerenciadorGrafico(gg)
{
	listaboneco.inserir(new Jogador(Vetor2F(-100.0, 350.0)));
	listaboneco.inserir(new Inimigo1(Vetor2F(400.0, 400.0)));
	listaboneco.inserir(new Pistoleiro(Vetor2F(-150.0, 400.0)));
	listaboneco.inserir(new Tile(Vetor2F(300.0, 439.0)));
	listaboneco.inserir(new Caixote(Vetor2F(300, 400)));
	listaboneco.inserir(new PlataformaMovedica(Vetor2F(-240.0, 439.0)));
	listaboneco.inserir(new Armadilha(Vetor2F(150, 422)));

	listaboneco.iniciliazarEntidade(*gerenciadorGrafico);

	gerenciadorColisoes.inserirColidivel("jogador", static_cast<EntidadeColidivel*>(listaboneco.voltarInicio()));
	gerenciadorColisoes.inserirColidivel("inimigo", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
	gerenciadorColisoes.inserirColidivel("inimigo", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
	gerenciadorColisoes.inserirColidivel("tile", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
	gerenciadorColisoes.inserirColidivel("caixote", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
	gerenciadorColisoes.inserirColidivel("plataformamovedica", static_cast<EntidadeColidivel*>(listaboneco.irProx()));
	gerenciadorColisoes.inserirColidivel("armadilha", static_cast<EntidadeColidivel*>(listaboneco.irProx()));

	
}

Fase::Fase()
{
}

Fase::~Fase()
{
	listaboneco.excluir();
}

/*void Fase::adicionaEntidade(EntidadeColidivel* entidade, string tipoEntidade)
{
}*/

void Fase::atualizar(float t)
{
	//sf::Time t = relogiof->getElapsedTime();
	//relogiof->restart();

	gerenciadorGrafico->limpar();
	gerenciadorGrafico->centralizar(listaboneco.voltarInicio()->getPosicao());

	listaboneco.atualizar(t);
	
	listaboneco.desenharEntidade(*gerenciadorGrafico);
	gerenciadorColisoes.verificaColisoes();

	gerenciadorGrafico->mostrar();
}
