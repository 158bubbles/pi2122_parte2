ABin somasAcA (ABin a) {
    int resEsq, resDir; 
    if(a == NULL) return NULL;
    
    ABin novo = malloc(sizeof(struct nodo)); //crio o novo nodo
    ABin novaEsq = somasAcA(a->esq);   //cria a nova arvore da esq
    ABin novaDir = somasAcA(a->dir);   //cria a nova arvore da dir
    novo->esq = novaEsq;
    novo->dir = novaDir;
    
    if(novaEsq == NULL){
        resEsq = 0;
    } else {
        resEsq = novaEsq->valor;  //estamos a ir buscar o valor do primeiro nodo esq
    }
    
    if(novaDir == NULL){
        resDir = 0;
    } else {
        resDir = novaDir->valor;   //estamos a ir buscar o valor do primeiro nodo dir
    }

    novo->valor = a->valor + resEsq + resDir;  //no fim, calculamos a soma total
    
    return novo;
}
