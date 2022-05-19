void appendL (LInt *l, int x){
    LInt current = *l;
    LInt novo = newLInt(x, NULL);  //criamos um novo com o valor de x para ser posto antes do NULL
    
    if(current == NULL){
        *l = novo;
    } else {
        
        while(current->prox != NULL){
        current = current->prox;
        }
        
        current->prox = novo;    }

}
