LInt NForward (LInt l, int N){
    
    while(N > 0){
        l = l->prox;
        N--;
    }
  
    return l;
}
