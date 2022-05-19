LInt rotateL (LInt l){
    
    if(l == NULL){
        return l;
    }
    
    if(l->prox == NULL){
        return l;
    }
    
    LInt primeiro = l;
    l = l->prox;
    LInt current = l;
    
    while(current->prox != NULL){
        current = current->prox;
    }
    
    current->prox = primeiro;
    primeiro->prox = NULL;

    return l;
}
