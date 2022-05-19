LInt somasAcL (LInt l) {
    
    if(l == NULL){
        return NULL;
    }
    
    LInt novaL = newLInt(l->valor, NULL);
    LInt currNova = novaL;
    int soma = l->valor;

    l = l->prox;
    
    while(l != NULL){
        soma += l->valor;
        currNova->prox = newLInt(soma, NULL);
        currNova = currNova->prox;
        l = l->prox;
    }
    
    
    return novaL;
}
