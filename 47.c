int maiorAB (ABin a) {
    ABin current = a;
    
    while(current->dir != NULL){
        
        current = current->dir;
    }
    
    return current->valor;
}
