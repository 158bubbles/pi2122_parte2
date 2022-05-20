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



void preorder (ABin a, LInt * l) {
    
    if(a == NULL){
        return;
        
    } else {
        insereNaLInt(a->valor, l);  //vai inserir o nodo da root na LInt 
        preorder(a->esq, l);
        preorder(a->dir, l);
    }
}
