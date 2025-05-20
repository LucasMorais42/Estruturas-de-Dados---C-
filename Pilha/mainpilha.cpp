#include <iostream>
#include "pilha.h"

using namespace std;

int main(){

    pilha p1;

    p1.push(10);
    p1.push(20);
    p1.estaCheia();
    p1.imprimir_pilha();

    return 0;

}