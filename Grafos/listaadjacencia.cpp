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
 

enum cores{
    WHITE, //valor 0, nao processado
    YELLOW, //valor 1, nós em processamento
    RED // valor 2, todos nós já processados
  };

void Grafo::buscaEmProfundidade(){
 

  int cor[vertices]; //crio um vetor que salvará o estado de cada vertice, qual cor cada um está
  
  
  int u;

  for(u=0; u<vertices; u++){
    cor[u] = WHITE; //defino todos os vértices como BRANCO (não processados)
  }

  for(u=0; u<vertices; u++){
    if(cor[u]==WHITE){
        visitaP(u, cor);
    }
  }
}

void Grafo::visitaP(int u, int *cor){
    cor[u] = YELLOW; //acabou de receber por exemplo o vertice 0, seta ele em amarelo (em processamento)
    Adjacencia *v = adj[u].cab; //pega o primeiro elemento da lista de adjacencias do vertice 0

    while(v){ //enquanto a lista encadeada nao chegar em nullptr
      if(cor[v->vertice]==WHITE){ //se a cor do elemento do vértice da lista encadeada for branco (não processado)
        visitaP(v->vertice, cor); //faço uma chamada recursiva passando ele mesmo
      } 
      v = v ->prox; //sai do if e passa pro próximo elemento da lista encadeada
    }
    cor[u] = RED; //quando eu passei por todos da lista encadeada, significa que o vertice inicial fica vermelho

  /*Suponha o grafo:
  v0 → [v1, v2, v3]
  v1 → [v2]
  v2 → []
  v3 → []
  
  1ª Chamada inicial: visitaP(0, cor)

      cor[0] = YELLOW
      v = adj[0].cab → aponta pro nó da lista com v1
      entra no while(v)
          v = v1;
          cor[1] == WHITE → chama visitaP(1, cor)

  2ª chamada: visitaP(1, cor)
      cor[1] = YELLOW
      v = adj[1].cab → aponta pro nó com v2
      entra no while(v)
          v = v2
          cor[2] == WHITE → chama visitaP(2, cor)
  
  3ªchamada: visitaP(2, cor)
      cor[2] = YELLOW
      v = adj[2].cab → nullptr, pois v2 não tem adjacentes
      while(v) não entra
      cor[2] = RED
      retorna para visitaP(1) (ou chamada 2ª)

  2ªchamada DESEMPILHADA:
      v = v->prox → agora v = nullptr (pois v1 só tinha v2)
      sai do loop
      cor[1] = RED
      retorna para visitaP(0)

  1ª chamada DESEMPILHADA:
      v = v->prox → agora v = v2 (próximo da lista de v0)
      cor[2] == RED, não entra no if, só avança
      v = v->prox → v3
      cor[3] == WHITE → chama visitaP(3)
  
  4ª chamda visitaP(3, cor)
      cor[3] = YELLOW, lista vazia 
      v = v->prox → agora nullptr
      sai do loop
      cor[3] = RED

  Volta pra 1ª chamada novamente:
      cor[0] =RED

  */
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



