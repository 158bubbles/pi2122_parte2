void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    *mx = newLInt(0, NULL);
    *Mx = newLInt(0, NULL);
    LInt auxmx = *mx, auxMx = *Mx;
    
    while(l!=NULL){
        
        if(l->valor < x){
            auxmx->prox = l;
            auxmx = auxmx->prox;
            l = l->prox;
            auxmx->prox = NULL;
            
        }else{
            auxMx->prox = l;
            auxMx = auxMx->prox;
            l = l->prox;
            auxMx->prox = NULL;
        }
    }
    
    auxmx = *mx;
    *mx = (*mx)->prox;
    free(auxmx);
    
    auxMx = *Mx;
    *Mx = (*Mx)->prox;
    free(auxMx);
    
}
