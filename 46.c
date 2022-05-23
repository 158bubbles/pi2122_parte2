int depthOrd (ABin a, int x) {
    int nivel = 1;
    
    if(a == NULL){
        return -1;
    }
    
    ABin current = a;
    
    while(current != NULL){
        if(x == current->valor){
            return nivel;
        }
        
        if(x < current->valor){
            current = current->esq;
            nivel++;
        } else {
            current = current->dir;
            nivel++;
        }
        
    }
    
    return -1;
}
