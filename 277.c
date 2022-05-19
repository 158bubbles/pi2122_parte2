LInt parte (LInt l){
    
    if(l == NULL || l->prox == NULL){
        return NULL;
    }
    
    LInt prev = l, current = prev->prox;
    LInt listaPares = newLInt(0, NULL);
    LInt currNovo = listaPares;
    int i;
    
    for(i=2; current != NULL; i++){
        if(i % 2 == 0){
            prev->prox = current->prox;

            currNovo->prox = current;
            currNovo = currNovo->prox;
            currNovo->prox = NULL;
            
            current = prev->prox;
        } else {
            prev = prev->prox;
            current = current->prox;
        }
        
    }
    
    currNovo = listaPares;
    listaPares = listaPares->prox;
    free(currNovo);
    
    return listaPares;
}
