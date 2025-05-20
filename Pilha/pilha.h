#ifndef PILHA_H
#define PILHA_H
#include "node.h"

class pilha{

    private:
        No* topo;
        int tamanho;

    public:

        //construtora
        pilha();
        //destrutora
        ~pilha();

        //funcoes da pilha:
        bool estaCheia();
        bool estaVazia();
        void push(TipoItem elemento);
        TipoItem pop();
        void imprimir_pilha();
        int imprime_tamanho();

        /*lembrando que o arquivo header é como se fosse um condensador, é pra facilitar pro compilador, ou seja, é uma
        maneira de informar ao compilador tudo que tem na estrutura, sem necessariamente o compilador precisar acessar o
        arquivo.cpp
        */
};
#endif