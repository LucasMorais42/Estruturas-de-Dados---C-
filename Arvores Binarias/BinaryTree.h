#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "Node.h"

class BinaryTree
{
    public:
        No *raiz;

        BinaryTree();
        ~BinaryTree();

        void inserir(tipoItem valor);
        int tamanho(No *raiz);
        void imprimir_preOrdem(No *raiz);
        void imprimir_emOrdem(No* no)
        void imprimir_posOrdem(No* no)

    private:
        void inserirRecursiva(No *&no, tipoItem valor);
};
#endif