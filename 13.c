void init (LInt *l){
    LInt current = *l, prev = newLInt(0, *l);
    
    *l = prev;
    
    while(current->prox != NULL){
        current = current->prox;
        prev = prev->prox;
    }
    
    prev->prox = NULL;
    free(current);
    current = *l;
    *l = current->prox;
    free(current);
}
