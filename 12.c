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
    LInt current = *l, prev = newLInt(0, *l), eliminado;
    int max = descobreMaior(l);
    int flag = 0;
    
    *l = prev;   
    
    while(current != NULL && flag == 0){
        if(current->valor == max){
            flag = 1;
            prev->prox = current->prox;
            eliminado = current;
            free(eliminado);
            current = current->prox;
            
            
        } else {
            prev = prev->prox;
            current = current->prox;
        }
    }
    
    current = *l;
    *l = current->prox;
    free(current);
    
    return max;
}
