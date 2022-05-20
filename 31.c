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



void inorder (ABin a, LInt * l) {
    
    if(a == NULL){
        return;
        
    } else {
        inorder(a->esq, l);
        insereNaLInt(a->valor, l);   //vai inserir o nodo da root na LInt 
        inorder(a->dir, l);
    }
}
