int removeAll (LInt *l, int x){
    int count = 0;
    LInt current = *l, prev = newLInt(0, *l);
    *l = prev;
    
    while(current != NULL){
        
        if(current->valor == x){
            count++;
            prev->prox = current->prox;
            free(current);
            current = prev->prox;
            
            
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
