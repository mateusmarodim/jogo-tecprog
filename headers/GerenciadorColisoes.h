#pragma once
#include "EntidadeColidivel.h"
#include <map>
#include <iterator>
#include <string>

class GerenciadorColisoes
{
private:
    std::multimap<std::string, EntidadeColidivel*> colidiveis;
    
public:
    GerenciadorColisoes();
    ~GerenciadorColisoes();

    void inserirColidivel(std::string chave, EntidadeColidivel* ec); //as chaves corresponderão aos tipos das entidades (e.g. jogador, inimigo, tile)
    void removerColidivel(std::multimap <std::string, EntidadeColidivel*>::iterator posicao); //remove o elemento da posicao fornecida do multimapa
    void esvaziarColidiveis();
    void verificaColisoes();
    bool estaoColidindo(EntidadeColidivel* este, EntidadeColidivel* outro/*, float empurrar*/);
    std::multimap <std::string, EntidadeColidivel*>::iterator encontrar(std::string tipoEnt);
    void imprimir();

};
