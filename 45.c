int lookupAB (ABin a, int x) {
    
    if(a == NULL){
        return 0;  //falso
    }
    
    ABin current = a;
    
    while(current != NULL){
        if(current-> valor == x){
            return 1;  //verdadeiro
        }
        
        if(x < current->valor){
            current = current->dir;
        } else {
            current = current->dir;
        }
    }
    
    return 0;  //se chegarmos ao fim, e nao encontrar, é pq nao tem
}
