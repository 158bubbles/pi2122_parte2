ABin cloneAB (ABin a) {
    ABin clone = NULL;
    
    if(a == NULL){
        return NULL;
    } else {
        
        clone = malloc(sizeof(struct nodo));
        clone->valor = a->valor;  //nodo, o primeiro elemento da arvore
        clone->dir = cloneAB(a->dir);
        clone->esq = cloneAB(a->esq);
        
    }

    return clone;
}
