ABin cloneMirror (ABin a) {
    if(a == NULL){
        return NULL;
    }
    
    ABin nova = (ABin) malloc(sizeof(struct nodo));
    ABin novaEsq = cloneMirror(a->esq);
    ABin novaDir = cloneMirror(a->dir);
    
    nova->valor = a->valor;
    nova->esq = novaEsq;
    nova->dir = novaDir;
    
    
    return nova;
}
