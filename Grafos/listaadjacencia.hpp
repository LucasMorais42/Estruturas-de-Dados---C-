#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

class Vertice{
  
  public:
    //ponteiro pro primeiro elemento da lista encadeada;
    Adjacencia *cab;
    
    //método construtor
    Vertice(){	
        //ao ser inicializado o cab aponta pra nullptr

    }
  
};

class Adjacencia{
  
  public:
    int vertice; //numero do vertice
    int peso; //peso da aresta
    Adjacencia *prox; //endereço da proxima adjacencia
    
    Adjacencia(){}
};


class Grafo{
  
  public:
    int arestas, vertices;
    Vertice *adj;
    
    Grafo(int v){
    
    }
  
};


#endif

