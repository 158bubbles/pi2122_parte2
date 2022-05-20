int freeAB (ABin a) {
    
    if(a == NULL){
        return 0;
    } 
    
    int res = 1 + freeAB(a->esq) + freeAB(a->dir);
    
    free(a);

    return res;
}
