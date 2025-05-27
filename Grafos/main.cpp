#include "listaadjacencia.hpp"
#include <iostream>
using namespace std;

int main(){

    Grafo *gr = new Grafo(3);

    gr->criaAresta(0, 2, 10);
    gr->criaAresta(0, 1, 5);
    gr->criaAresta(0, 1, 5);
    gr->imprimeGrafo();

}
