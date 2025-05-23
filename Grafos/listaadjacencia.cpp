#include <iostream>
#include "listaadjacencia.hpp"
using namespace std;

  Grafo::Grafo(int v):vertices(v), arestas(0), adj(new Vertice[v]){}
  	//criando um grafo, recebe um numero de vertices
	//atribui para vertices = v, arestas = 0, adj = new Vertice(v)
	//adj tem o endereço de um vetor do tipo VERTICE de V elementos
    
  //método construtor
  Vertice::Vertice(): cab(nullptr){	
    //ao ser inicializado o cab aponta pra nullptr

  }
  


  Adjacencia::Adjacencia():vertice(0), peso(0), prox(nullptr){}


