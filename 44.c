int addOrd (ABin *a, int x) {
    
    ABin novo = malloc(sizeof(struct nodo));
    novo->valor = x;
    novo->esq = NULL;
    novo->dir = NULL;
    
    
    if(*a == NULL){
        *a = novo;
        return 0;
    }
    
    ABin current = *a, prev;
    
    while(current != NULL){
        
        if(x == current->valor){
            return 1;
        }
        
        prev = current;
        
        if(x < current->valor){
            current = current->esq;
        } else {
            current = current->dir;
        }
    }
    
    //quando chgamos ao fim da arvore, é para adicionar
    if(x < prev->valor){
        prev->esq = novo;
    } else {
        prev->dir = novo;
    }
    
    return 0;
}
