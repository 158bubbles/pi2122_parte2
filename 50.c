int length(LInt l){
    int count = 1;
    while(l->prox != NULL){
        l = l->prox;
        count++;
    }
    return count;
}

LInt parte(LInt l, int *x){
    
    if(l == NULL) return NULL;
    
    int meio = length(l)/2;
    LInt current = l, prev, l2;
    
    while(meio>0){
        prev = current;
        current = current->prox;
        meio--;
    }
    
    *x = current->valor;
    l2 = current->prox;
    prev->prox = NULL;
    
    return l2;
}



void listToBTree (LInt l, ABin *a) {
    if(l == NULL){
        *a = NULL;
        return;
    }
    
    //se l só tem um elemento
    if(l->prox == NULL){
        ABin novo = malloc(sizeof(struct nodo));
        *a = novo;
        (*a)->valor = l->valor;
        (*a)->esq = NULL;
        (*a)->dir = NULL;
        return;
    }
    
    //criar duas listas, uma para cada parte da arvore
    LInt l1 = l, l2;
    int x; //vai ser o valor da root, ainda a definir na funçao parte
    //vamos partir a l deixando a primeira parte p l1, criando a segunda parte p l2 e descobrindo a root x
    l2 = parte(l, &x);
    
    
    //criar a arvore
    ABin novo = malloc(sizeof(struct nodo));
    *a = novo;
    (*a)->valor = x;
    (*a)->esq = NULL;
    (*a)->dir = NULL;
    
    listToBTree(l1,  &(*a)->esq);
    listToBTree(l2,  &(*a)->dir);
    
}
