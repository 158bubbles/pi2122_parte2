void insereNaLInt(int v, LInt *l){
    LInt current = *l;
    LInt nodo = newLInt(v, NULL);
    
    
    if(*l == NULL){
        *l = nodo;
        return;
    } else {
        
        while(current->prox != NULL){
            current = current->prox;
        }
        
        current->prox = nodo;
        nodo->prox = NULL;
    }
}



void posorder (ABin a, LInt * l) {
    
    if(a == NULL){
        return;
        
    } else {
        posorder(a->esq, l);
        posorder(a->dir, l);
        insereNaLInt(a->valor, l);  //vai inserir o nodo da root na LInt 
    }
}
