LInt parte (LInt l){
    if(l == NULL || l->prox == NULL){
        return NULL;
    }
    
    LInt par = l->prox;
    LInt current = l;
    LInt currentPar = par;
    
    while(current != NULL && currentPar != NULL){
        if(current->prox != NULL){
            current->prox = current->prox->prox;
        }
        
        if(currentPar->prox != NULL){
            currentPar->prox = currentPar->prox->prox;
        }
        
        current = current->prox;
        currentPar = currentPar->prox;
    }
    
    return par;
}
*/
