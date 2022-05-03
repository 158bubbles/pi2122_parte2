LInt reverseL (LInt l){
    LInt current = l;
    LInt ant = NULL;
    LInt next;
    
    while(current!=NULL){
        next = current->prox;
        current->prox = ant;  //muda a direção da primeira seta
        ant = current;   //alteraçao das tres caixas ant, current e next
        current = next;
    }
    
    l = ant; //p a lista começar no fim, o current e o next estao no NULL
    
    return l;
}
