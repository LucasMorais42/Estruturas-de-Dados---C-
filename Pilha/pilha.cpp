#include <iostream>
#include <stdexcept>
#include "pilha.h"
#include "node.h"

using namespace std;


        pilha::pilha(){
            //ao construir a pilha, nós iremos apontar pra uma posição nula o nosso topo
            //e o tamanho será 0
            topo = nullptr;
            tamanho = 0;
        }

        //destrutora
        pilha::~pilha(){
            while(!estaVazia()){
                //enquanto a pilha não estiver vazia eu vou removendo tudo
                pop();
            }
        }

        //funcoes da pilha:
        void pilha::push(TipoItem elemento){
            No* novoNo = new No(elemento, topo);
            topo = novoNo; // o topo virá o novoNo
            tamanho++;
        }

        TipoItem pilha::pop(){
            if(estaVazia()){
                throw runtime_error("Pilha vazia!");
            }
            else{
                No* noRemovido = topo; //o noRemovido será o topo sempre
                TipoItem valor = noRemovido -> valor; //nós estamos acessando o atributo valor do nó Removido

                topo = topo -> proximo; //A partir daqui o topo será o atributo próximo do noRemovido, que por consequencia
                //fica naquela lógica de estar sempre apontando pra baixo

                delete noRemovido; //estamos apagando da memória o noRemovido
                tamanho--; //diminuindo o tamanho da pilha
                return valor;
            }
        }

        void pilha::imprimir_pilha(){
            No* atual = topo;

            while(atual!=nullptr){
                cout << atual->valor << "\n";
                atual = atual -> proximo;
            }
            cout << "\n";

        }

        int pilha::imprime_tamanho(){
            return tamanho;
        }

       

        bool pilha::estaVazia(){
            
            return topo==nullptr;
        }

