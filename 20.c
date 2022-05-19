int drop (int n, LInt *l){
    LInt current = *l, prev = NULL;
    int nrEliminados = 0;

    
    while(current != NULL && n > 0){  //quando sair do ciclo, nao faz nada
        prev = current;
        current = current->prox;
        free(prev);
        n--;
        nrEliminados++;
    }
    
    *l = current;
    
    return nrEliminados;
}
