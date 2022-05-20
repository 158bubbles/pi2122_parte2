int altura (ABin a){
    int res = 0;
    
    if(a == NULL){
        return res;
    }
    
    int direita = altura(a->dir);
    int esquerda = altura(a->esq);
    
    
    if(direita > esquerda){
        return (direita + 1);
    } else {
        return (esquerda + 1);
    }
}
