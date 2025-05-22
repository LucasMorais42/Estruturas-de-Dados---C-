#include "BinaryTree.h"
#include <iostream>
using namespace std;

BinaryTree::BinaryTree() : raiz(nullptr) {}
BinaryTree::~BinaryTree() {destruirRecursivo(raiz);}

void destruirRecursivo(No* no) {
        if (no) {
            destruirRecursivo(no->esquerda);
            destruirRecursivo(no->direita);
            delete no;
        }
    }



void BinaryTree::inserir(tipoItem valor)
{
  inserirRecursiva(raiz, valor);
}


/*usamos *& porque eu quero um ponteiro do tipo no porem eu quero que o meu codigo altere diretamente o ponteiro, ou seja,
se raiz = nullptr, como eu passei a raiz pro no, eu quero que raiz = new No(valor);
raiz terá um novo endereço alocado, referenciando um Nó. O que vai acontecer com isso é:

No* = recebe um ponteiro
& -> é um ponteiro e é uma referência direta a variável passada

no*& = raiz (raiz é um ponteiro e está sendo referenciada diretamente)
se eu fizesse
no = "batata"; (se fosse possível, é o endereço de raiz que está sendo mudado para "batata").
*/


void BinaryTree::inserirRecursiva(No *&no, tipoItem valor)
{
  /*Vamos lá, aqui estamos passando RAIZ para o "No" e valor para o valor, lembrando que a chamada dessa inserirRecursiva
  Vai vir da função inserir acima, logo veja que ali em inserir sempre é passado a raiz e o valor que o usuário
  quer adicionar*/

  // caso base da nossa recursão
  if (no == nullptr)
  {
    // ser o no (ou seja, a raiz) for um ponteiro nulo, significa que precisamos criar um primeiro no e passar o valor inicial
    no = new No(valor);
  }
  else if (valor < no->valor)
  {
    /*caso o valor que queremos adicionar seja menor que o valor do no (ou seja, seja menor que o valor da raiz)
      nós iremos fazer uma chamada recursiva, lembrando do conceito de arvores, se for menor fica a esquerda
      logo vamos passar pra inserirRecursiva o ponteiro pro elemento esquerdo do nó atual, e o valor continua o que
      o usuario passou na função inserir
    */

    inserirRecursiva(no->esquerda, valor);
  }
  else if (valor > no->valor)
  {
    inserirRecursiva(no->direita, valor);
  }
  /*A ideia dessa recursão é sempre ir atualizando qual é esse "Nó", ou seja, sempre que o valor que eu quero adicionar
    seja menor que o valor do nó atual, começando pela raiz, eu vou pegar o ponteiro do nó a direita do nó atual.
    Caso seja maior que o valor do nó atual, pego o elemento a esquerda.

    Esse jogo de pegar o a esquerda ou a direita só vai acabar quando eu encontrar o caso-base da recursão que é
    ver se o meu nó é um ponteiro nulo, ou seja, não há elementos pra verificar se é maior ou menor, ali iremos criar o nó
  */
}

  int tamanho(No* no)
  {
    if (no == nullptr)
      return 0;
    
    else
      return 1 + tamanho(no -> esquerda) + tamanho (no -> direita);
    
  }

  /* A impressao pré-ordem imprime RAIZ - ESQUERDA - DIREITA, ou seja, no nosso código
  irá imprimir logo de cara a RAIZ, depois todos os elementos a esquerda (incluindo dos nós-filhos),
  depois imprimir todos os elementos a direita (incluindo os dos nós filhos)
  
  Dada a arvore:

         10
       /  \
      1    11
     / \   / \
    0   2 4   12
  
Travessia	| Ordem de Nós Visitados
Pré-ordem	| 10, 1, 0, 2, 11, 4, 12
Em-ordem	| 0, 1, 2, 10, 4, 11, 12
Pós-ordem	| 0, 2, 1, 4, 12, 11, 10

Pré-ordem: Raiz primeiro ("PRÉ" = antes dos filhos)
Em-ordem: Raiz no meio (para BST, sai em ordem crescente)
Pós-ordem: Raiz por último ("PÓS" = depois dos filhos)

  */

  void imprimir_preOrdem(No* no){
      
        if(no != nullptr){

            cout << no -> conteudo << " ";
            imprimir_preOrdem(no -> esquerda);
            imprimir_preOrdem(no -> direita);
        }
  }

  void imprimir_emOrdem(No* no) {
    if (no != nullptr) {
        imprimirEmOrdem(no->esquerda);
        cout << no->conteudo << " ";
        imprimirEmOrdem(no->direita);
    }
}

void imprimir_posOrdem(No* no) {
    if (no != nullptr) {
        imprimirPosOrdem(no->esquerda);  
        imprimirPosOrdem(no->direita);   
        cout << no->conteudo << " ";     
    }
}

//Função que avalia se um árvore está vazia ou não
bool BinaryTree::estaVazia() const {
    return raiz == nullptr;
}

//Retorna o valor da nossa Raiz
tipoItem BinaryTree::valorRaiz() const {
    if (raiz == nullptr)
        throw std::runtime_error("Árvore vazia");
    return raiz->valor;
}

//Função pública da nossa árvore, que irá chamar a recursiva
bool BinaryTree::buscar(tipoItem valor) const {
    return buscarRecursivo(raiz, valor);
}

//A função busca recursiva, basicamente faz:
/*
CASO BASE 1: Se o nó for nullptr, significa que passamos todos os nós e ele não existe
CASO BASE 2: Se o valor do nó que estamos passando foi igual o valor que queremos, retorna true (achamos o valor)
CASO RECURSIVO 1: Se o valor do nó que buscamos, for menor que o valor do nó atual, chamamos recursivamente a função
passando o valor a esquerda do nó atual
CASO RECURSIVO 2: Caso os 3 casos acima não sejam concluidos, nós vamos chamar a função recursiva passando os valores a direita
do nó (caso do valor for maior que o nó atual) 


*/
bool BinaryTree::buscarRecursivo(No* no, tipoItem valor) const {
    if (no == nullptr) return false;
    if (valor == no->valor) return true;
    if (valor < no->valor) return buscarRecursivo(no->esquerda, valor);
    return buscarRecursivo(no->direita, valor);
}