int removeAll (LInt *l, int x){
    int count = 0;
    LInt current = *l, prev = newLInt(0, *l), eliminado;
    *l = prev;
    
    while(current != NULL){
        
        if(current->valor == x){
            count++;
            prev->prox = current->prox;
            eliminado = current;
            current = current->prox;
            free(eliminado);
            
        }else{
            prev = prev->prox;
            current = current->prox;
            
        }
    }
    
    current = *l;
	*l = current->prox;
	free (current);
    
    
    return count;
}
