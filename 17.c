LInt cloneRev (LInt l){
    LInt novo = NULL;
    
    while(l != NULL){
        novo = newLInt(l->valor, novo);
        //a cada iteração, temos uma caixinha 'novo' que tem o valor de l e coloca-se antes do 'novo' anterior
        l = l->prox;
    }
    
    
    return novo;
}
