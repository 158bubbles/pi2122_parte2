void insertOrd (LInt *l, int x){
    LInt current = *l;
    LInt ant;
    
    if(current == NULL){   //caso esteja vazia
        *l = newLInt(x, NULL);
        return;
    } 
    
    if(x <= (*l)->valor){   //caso o x seja menor ou igual, tem de ir para uma primeira caixa antes do resto da lista
        *l = newLInt(x, *l);
        return;
    }
    
    while(current != NULL && x > (current->valor)){   //anda sempre, só para quando chegar ao fim ou for para inserir o x entre o ant e o curr
        ant = current;
        current = ant->prox;
    }
    
    ant->prox = newLInt(x, current);   //e aqui insere no sitio onde saiu do loop
    
}
