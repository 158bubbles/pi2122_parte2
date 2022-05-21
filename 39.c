int insereNoVetor(ABin a, int n, int v[], int i){
    
    if(a==NULL)
        return i;
    
    if(n == 1){
        v[i] = a->valor;
        i++;
    } else {
        
        i = insereNoVetor(a->esq, n-1, v, i);
        i = insereNoVetor(a->dir, n-1, v, i);
    }
    
    return i;
}
 

 
int nivelV (ABin a, int n, int v[]) {
    
    int i = 0;
    
    return insereNoVetor(a, n, v, i);
}
