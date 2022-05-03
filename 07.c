void merge (LInt *r, LInt l1, LInt l2){
    *r = newLInt(0, NULL);   //caixa com um 0 para começar a lista *r
    LInt currR = *r;
    
    while(l1 != NULL && l2 != NULL){  //enquanto tiverem o mesmo numero de elementos
        
        if(l1->valor <= l2->valor){
            currR->prox = l1;
            currR = currR->prox;
            l1 = l1->prox;
        } else {
            currR->prox = l2;
            currR = currR->prox;
            l2 = l2->prox;
        }
    }
    
    if(l1 == NULL){   //se l1 chegar ao fim, mete-se da l2
        currR->prox = l2;
    } 
    else if(l2 == NULL){  //se l2 chegar ao fim, mete-se da l1
        currR->prox = l1;
    }
    
    currR = *r;  //o currR  vai para o inicio, que é onde está o *r
    *r =(*r)->prox;   //o *r passa a estar no primeiro elemento da lista
    free(currR);    //damos free da caixa criada inicialmente com o 0
    
}
