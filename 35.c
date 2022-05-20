int freeAB (ABin a) {
    
    if(a == NULL){
        return 0;
    } 
    
    ABin aux = a;
    
    free(aux);

    return 1 + freeAB(a->esq) + freeAB(a->dir);
}
