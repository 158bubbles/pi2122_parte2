int removeRep (LInt *l, int x){
    int count = 0;
    LInt current = *l, prev = newLInt(0, *l), eliminado;
    *l = prev;
    
    while(current != NULL){
        
        if(current->valor == x){
            count++;
            if(count>1){
                prev->prox = current->prox;
                eliminado = current;
                current = current->prox;
                free(eliminado);  
            } else {
                prev = current;
                current = current->prox;
            }
        }else{
            prev = prev->prox;
            current = current->prox;
        }
    }
    
    current = *l;
	*l = current->prox;
	free (current);
    
    return count - 1;
}


int removeDups (LInt* l){
    int count = 0;
    LInt current = *l;
    
    while(current != NULL){
        count += removeRep(l, current->valor);
        current = current->prox;
    }
    
    return count;
}
