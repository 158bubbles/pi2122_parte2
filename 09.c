LInt parteAmeio (LInt *l){
    LInt current = *l;
    LInt y, prev;
    int i, metade;
    
    for(i=0; current != NULL; i++){  // para termos o tamanho de *l
        current = current->prox;
    }
    
    metade = i/2;  //definimos onde está a metade
    current = *l;
    prev = NULL;
    
    for(i=0; i < metade ; i++){
        prev = current;
        current = current->prox;
    }
    
    if(prev == NULL)
        return NULL;
    
    prev->prox = NULL;
    
    y = *l;
    *l = current;
    
    return y;
}
