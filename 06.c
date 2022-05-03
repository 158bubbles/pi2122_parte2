int removeOneOrd (LInt *l, int x){
    LInt current = *l;
    LInt ant;
    
    if(current==NULL) return 1;  //se for vazia

    else if(current->prox==NULL && current->valor==x){  //se só tiver um elemento e esse for o x
        free(*l);
        *l = NULL;
        return 0;
    }
    
    while(current != NULL && x > current->valor){   //sai quando chegarmos ao valor a remover
        ant = current;
        current = ant->prox;
    }
    
    if(current==NULL) {   //se chegar ao fim e nao encontrar nada
        return 1;
    }
    else if(x==current->valor) {   //se encontrar
        ant->prox = current->prox;
        free(current);
        return 0;
    } else 
        return 1;
}
