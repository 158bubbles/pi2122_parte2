LInt cloneL (LInt l){
    LInt novo, prev = newLInt(0, NULL), auxPrev = prev;
    
    while(l != NULL){
         novo = newLInt (l->valor, NULL);
         auxPrev->prox = novo;
         auxPrev = auxPrev->prox;
         l = l->prox;  //anda para o próximo nodo de l
    }
    
    return prev->prox;
}
