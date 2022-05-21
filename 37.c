int iguaisAB (ABin a, ABin b) {
    
    if(a == NULL && b == NULL){
        return 1;
    }
    else if(a == NULL){
        return 0;
    }
    else if(b == NULL){
        return 0;
    }
    else if(a->valor != b->valor){
        return 0;
    }
    else {  //se os dois primeiros nodos forem iguais temos de testar p o resto
        int resEsq = iguaisAB(a->esq, b->esq);
        int resDir = iguaisAB(a->dir, b->dir);
        
        return resEsq * resDir;
    }
}
