#ifndef LISTAADJACENCIA_HPP
#define LISTAADJACENCIA_HPP

class Adjacencia{
  
  public:
    int vertice; //numero do vertice
    int peso; //peso da aresta
    Adjacencia *prox; //endereço da proxima adjacencia
    
    Adjacencia();

    static Adjacencia *cria_Adjacencia(int v, int peso);
    
};

class Vertice{
  
  public:
    //ponteiro pro primeiro elemento da lista encadeada;
    Adjacencia *cab;
    string nome;
    
    //método construtor
    Vertice();
        //ao ser inicializado o cab aponta pra nullptr
  
};



class Grafo{
  
  public:
    int arestas, vertices;
    Vertice *adj;
    
    Grafo(int v);

    bool criaAresta(int vi, int vf, int peso);
    void imprimeGrafo();
    void buscaEmProfundidade(int chave);
    void visitaP(int u, int *cor, int chave);
};


#endif

