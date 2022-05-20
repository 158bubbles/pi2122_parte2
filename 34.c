int depth (ABin a, int x) {
    if(a == NULL){
        return -1;
    }
    if(a->valor == x){
        return 1;
    }
    
    if(depth(a->dir, x) == -1 && depth(a->esq, x) == -1){
        return -1;    //caso em que nao existe o x nem na esq nem na dir
    }
    else if(depth(a->dir, x) == -1){  //nao existe na dir
        return depth(a->esq, x) +1;
    }
    else if(depth(a->esq, x) == -1){   //nao existe na esq
        return depth(a->dir, x) +1;
    }
    else {  //pode existir ou na dir ou na esq
        if(depth(a->dir, x) < depth(a->esq, x)){
            return depth(a->dir, x) +1;
        } else {
            return depth(a->esq, x) +1;
        }
    }
}
