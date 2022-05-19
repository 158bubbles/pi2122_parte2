LInt arrayToList (int v[], int N){
    LInt l = newLInt(v[0], NULL), current = l;
    int i;
    
    if(N == 0) return NULL;
    
    for(i=1; i < N; i++){
        LInt novo = newLInt(v[i], NULL);
        current->prox = novo;
        current = current->prox;
    }
    
    
    return l;
}
