int descobreMaior(LInt *l){
    LInt current = *l;
    int max = current->valor;  //fixamos como maior o primeiro elemento
     
    while(current != NULL){
         if(current->valor > max){
             max = current->valor;
         }
         
         current = current->prox;
    }
    
    return max;
}


int removeMaiorL (LInt *l){
    LInt current = *l, prev = newLInt(0, *l);
    int max = descobreMaior(l);
    
    *l = prev;   
    
    while(current != NULL && current->valor != max){
        prev = current;
        current = current->prox;
    }
    
    prev->prox = current->prox;
    free(current);
    current = prev->prox;
    
    current = *l;
    *l = current->prox;
    free(current);
    
    return max;
}
