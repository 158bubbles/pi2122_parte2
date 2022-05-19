void concatL (LInt *a, LInt b){
    LInt current = *a;
    
    if(current == NULL){
        *a = b;
    } else {
        
        while(current->prox != NULL){
        current = current->prox;
        }
        
        current->prox = b;
    }    
}
