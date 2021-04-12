#include "../headers/GerenciadorColisoes.h"
#include <iostream>

GerenciadorColisoes::GerenciadorColisoes()
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
}

void GerenciadorColisoes::inserirColidivel(std::string tipoEntidade, EntidadeColidivel* ec)
{
    colidiveis.emplace(tipoEntidade, ec);
    std::cout << "ENTROU CARALHO" << std::endl;
}

void GerenciadorColisoes::removerColidivel(std::multimap<std::string, EntidadeColidivel*>::iterator posicao)
{
    colidiveis.erase(posicao);
}

void GerenciadorColisoes::verificaColisoes()
{
    std::multimap<std::string, EntidadeColidivel*>::iterator itr, itrOutro;
    itrOutro= colidiveis.begin();
    itr = itrOutro++;
    


    while(itr != colidiveis.end())
    {
        while(itrOutro != colidiveis.end())
        {
            if(itr->first != itrOutro->first)
            {
                if(estaoColidindo(itr->second, itrOutro->second))
                {
                    itr->second->colidir(itrOutro->second, itrOutro->first);
                    itrOutro->second->colidir(itr->second,itr->first);
                }
            }
            itrOutro++;
        }
        itr++;
        itrOutro = itr;
        itrOutro++;
    }
    //std::cout <<"vamos com calma ae"<<std::endl;
}   

bool GerenciadorColisoes::estaoColidindo(EntidadeColidivel* este, EntidadeColidivel* outro)
{
   
    Vetor2F posicaoEste = este->getPosicao();
    Vetor2F tamanhoEste = este->getTamanho();

    Vetor2F posicaoOutro = outro->getPosicao();
    Vetor2F tamanhoOutro = outro->getTamanho();

    Vetor2F offsetEste, offsetOutro;
    offsetEste.x = tamanhoEste.x*0.5;
    offsetOutro.x = tamanhoOutro.x*0.5;
    offsetEste.y = tamanhoEste.y*0.5;
    offsetOutro.y = tamanhoOutro.y*0.5;


    Vetor2F distanciaCentros;
    distanciaCentros.x = abs(posicaoEste.x - posicaoOutro.x);
    distanciaCentros.y = abs(posicaoEste.y - posicaoOutro.y);
    if(distanciaCentros <= (offsetEste + offsetOutro))
    {
       // std::cout << "colidiu :3" << std::endl;
        return true;
    }else{
        std::cout << "n colidiu :(" << std::endl;
        return false;
    }

}