void mirror (ABin *a) {
    
    ABin aux;
    
    if(*a == NULL){
        return;
    } else {
        
        aux = (*a)->esq;   //o aux guarda a esq
        (*a)->esq = (*a)->dir;  //para a esq poder ir para a dir
        (*a)->dir = aux;   //e assim a dir pode ir para a esq, que é onde está o aux
        
        mirror(&((*a)->dir));
        mirror(&((*a)->esq));
        
    }
}
