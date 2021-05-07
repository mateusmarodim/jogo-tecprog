#include "GerenciadorColisoes.h"
#include <iostream>
#include <stdlib.h>

GerenciadorColisoes::GerenciadorColisoes()
{
}

GerenciadorColisoes::~GerenciadorColisoes()
{
    /*std::multimap<std::string, EntidadeColidivel*>::iterator itr;
    itr = colidiveis.end();

    while (itr != colidiveis.begin())
    {
        colidiveis.erase(itr);
        itr--;
    }*/
}

void GerenciadorColisoes::inserirColidivel(std::string tipoEntidade, EntidadeColidivel* ec)
{
    colidiveis.emplace(tipoEntidade, ec);
}

void GerenciadorColisoes::removerColidivel(std::multimap<std::string, EntidadeColidivel*>::iterator posicao)
{
    colidiveis.erase(posicao);
}

void GerenciadorColisoes::esvaziarColidiveis()
{
    std::multimap<std::string, EntidadeColidivel*>::iterator itr;
    itr = colidiveis.end();

    while (itr != colidiveis.begin())
    {
        colidiveis.erase(itr);
        itr--;
    }
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
                    //system("cls");
                    itr->second->colidir(itrOutro->second, itrOutro->first);
                    itrOutro->second->colidir(itr->second,itr->first);
                }
            }
            itrOutro++;
        }
        itr++;
        itrOutro = itr;
        if(itrOutro!=colidiveis.end())
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
    distanciaCentros.x = posicaoEste.x - posicaoOutro.x;
    distanciaCentros.y = posicaoEste.y - posicaoOutro.y;

    float intersectaX = abs(distanciaCentros.x) - (offsetEste.x + offsetOutro.x);
    float intersectaY = abs(distanciaCentros.y) - (offsetEste.y + offsetOutro.y);

   
    if(intersectaX < 0.0f && intersectaY < 0.0f)
    {
        return true;
    }else{
       // system("cls");
        return false;
    }

}

std::multimap <std::string, EntidadeColidivel*>::iterator GerenciadorColisoes::encontrar(std::string tipoEntidade)
{
    std::multimap<std::string, EntidadeColidivel*>::iterator itr, itrend;
    itr = colidiveis.find(tipoEntidade);
    //itrend=colidiveis.end();

   /* while (itr != colidiveis.find(tipoEntidade))
    {
        itr++;
    }*/
    return itr;
}

void GerenciadorColisoes::imprimir()
{
    std::multimap<std::string, EntidadeColidivel*>::iterator itr;
    itr = colidiveis.begin();

    for (itr; itr != colidiveis.end(); itr++)
    {
        cout << itr->first
            << '\t' << itr->second << endl;
    }
    std:: cout << endl;
}
