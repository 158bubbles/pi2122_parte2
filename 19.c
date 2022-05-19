int take (int n, LInt *l){
    LInt current, prev = newLInt(0, *l);
    int tam = 0, count = 0, tamanhoFinal = 0;
    *l = prev;
    current = prev->prox;
    
    while(current != NULL && n > 0){
        prev = prev->prox;
        current = current->prox;
        n--;
        tamanhoFinal++;
    }
    
    if(n == 0){ //no caso em que é para eliminar os nodos
        prev->prox = NULL;
        
        while(current != NULL){
            prev = current;
            current = current->prox;
            free(prev);
        }
    }
    
    current = *l;
    *l = current->prox;
    free(current);
    
    return tamanhoFinal;
}
