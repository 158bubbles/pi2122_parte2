void insereNaLInt(LInt *l, ABin a, int n){
    
    if(a==NULL) {
        return;
    }
    
    if(n == 1){
        LInt current = *l;
        
        while(current->prox != NULL) {
            current = current->prox;
        }
        
        LInt nodo = mynewLInt(a->valor, NULL);
        current->prox = nodo;
        nodo->prox = NULL;
    
        
    } else {
        
        insereNaLInt(l, a->esq, n-1);
        insereNaLInt(l, a->dir, n-1);
        
    }
}




LInt nivelL (ABin a, int n) {
    
    LInt l = mynewLInt(0, NULL);
    
    insereNaLInt(&l, a, n);
    
    LInt current = l;
    l = current->prox;
    free(current);
    
    return l;
}
