void remreps (LInt l){
    
    if(l == NULL){
        return;
    }
    
    if(l->prox == NULL){
        return;
    }
    
    LInt prev = l;
    LInt current = prev->prox;
    
    while(current != NULL){
        
        if(prev->valor == current->valor){
            prev->prox = current->prox;
            free(current);
            current = prev->prox;
        } else {
            prev = prev->prox;
            current = current->prox;
        }
    }
}
