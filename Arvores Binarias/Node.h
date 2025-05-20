#ifndef NODE_H
#define NODE_H

typedef int tipoItem;

class No
{

    public:
        tipoItem valor;
        No *esquerda;
        No *direita;

        No(tipoItem elemento, No *left = nullptr, No *right = nullptr) : valor(elemento), esquerda(left), direita(right) {}
};
#endif