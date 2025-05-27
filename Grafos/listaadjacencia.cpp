#include <iostream>
#include "listaadjacencia.hpp"
using namespace std;

  Grafo::Grafo(int v):vertices(v), arestas(0){
    adj = new Vertice[v];
  }
  	//criando um grafo, recebe um numero de vertices
	//atribui para vertices = v, arestas = 0, adj = new Vertice(v)
	//adj tem o endereço de um vetor do tipo VERTICE de V elementos
    
void Grafo::imprimeGrafo(){
    

    for(int i=0; i<vertices; i++){
        //imprime o vértice de referencia, por exemplo v1:
        cout << "v" << i << ": ";

        //vamos pegar a lista encadeada de vértices relacionados a v1, começamos pelo head da lista
        Adjacencia* ad = adj[i].cab;
        //aqui eu tenho por exemplo o endereço para vf2 das explicações anteriores
        
        while(ad){
          //enquanto o ad não for um nullptr, vai imprimir
          //a impressão vai ser por exemplo vf2(10), significa que v1 se conecta a v2 com peso 10
          cout << "v" << ad->vertice << "(" <<  ad->peso  << ")";
          if(ad->prox){
          	cout << "->";
		  }

          //após imprimir vf2, chamamos a próxima conexão, no caso o vf1
          ad = ad->prox;

        }
        cout << "\n";
    }
}



  //método construtor
  Vertice::Vertice(): cab(nullptr){	
    //ao ser inicializado o cab aponta pra nullptr

  }
  


  Adjacencia::Adjacencia():vertice(0), peso(0), prox(nullptr){}
  Adjacencia* Adjacencia::cria_Adjacencia(int v, int peso){
    
      //ao chamar o método de criar lista de adjacencias, crio um temp
      Adjacencia *temp = new Adjacencia();

      //passo que o vertice desse temp é o v
      temp ->vertice = v;

      //o peso entre v do array e o v da lista é o peso da aresta que liga ambos
      temp -> peso = peso;

      //temp prox aponta pra nulo
      temp -> prox = nullptr;

      return temp; //retorna o ponteiro para temp
  }

bool Grafo::criaAresta(int vi, int vf, int peso){

  //faz testes pra garantir que o grafo é valido e que
  //os vértices sejam válidos, ou seja, -1<vértice<grafo.vertices
  if((vf<0) || (vf>=vertices)) return false;
  if((vi<0) || (vi>=vertices)) return false;

  //crio um objeto adjacencia, ele chama o método cria_ADJACENCIA
  //nesse momento tenho um novo com {vertice: vf, peso: peso, prox: nullptr}
  Adjacencia *novo = Adjacencia::cria_Adjacencia(vf, peso);
  //essa adjacencia é apenas um vértice com uma aresta solta
  //tipo vf ---> (está assim, tem um destino final que é o vf e a aresta com o peso)
  

  // esse código abaixo vai fazer a ligação
  // aquela ligação acima é colocada no começo da lista encadeada
  //pense numa lista que comece com v1 -> nullptr (ou seja, v1 nn se conecta com ngm)
  //vf---> nullptr; vamos conectar vf ao nullptr (colocar no começo)
  novo -> prox = adj[vi].cab;

  //aqui nós fazemos a conexão entre a lista encadeada e o vértice
  //antes estava v1 --> nullptr, mesmo após acrescentar o vf
 
  //após esse código eu faço: v1 --> vf ---> nullptr

  /*Acrescentando um vf2 ficaria como?:
  Adjacencia *novo = Adjacencia::cria_Adjacenc gr->adj[vi].cab = novo;ia(vf, peso);
  vf2----> (solta, sem conexão com ngm)

  novo -> prox = gr-> adj[vi].cab;
  //vf2---->vf--->nullptr (vf2 se conecta com o primeiro elemento da lista encadeada)*/
  adj[vi].cab = novo;	
  
  
  //atualiza qual vai ser o primeiro elemento da lista, ficando:adj
  //v1 --> vf2 --> vf --> nullptr
  
  	
  arestas++;
  return true;
} 



