int minValor(ABin a){
    
    while(a->esq != NULL){
        a = a->esq;
    }

    return a->valor;
} 
 
 
int maxValor(ABin a){
    
    while(a->dir != NULL){
        a = a->dir;
    }

    return a->valor;
} 
 
 
 
int deProcura (ABin a) {
    
    if(a ==  NULL){
        return 1;
    }
    
    if(a->esq != NULL && maxValor(a->esq) > a->valor) return 0;
    
    else if (a->dir != NULL && minValor(a->dir) < a->valor) return 0;
    
    else if(deProcura(a->esq)==0 || deProcura(a->dir)==0) return 0;
    
    
    return 1;
}
