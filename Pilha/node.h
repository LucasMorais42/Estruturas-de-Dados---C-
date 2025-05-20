#ifndef NODE_H
#define NODE_H
typedef int TipoItem; 

class No{

    public:
        TipoItem valor;
        No* proximo;


        No(TipoItem v, No* prox = nullptr) : valor(v), proximo(prox){}

};

#endif