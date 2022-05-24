#include "abin.h"

ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}


// Questão 1
ABin removeMenor (ABin *a){
    ABin current = *a, prev;
    
    if(*a == NULL){
        return NULL;
    }
    
    while(current->esq != NULL){
        prev = current;
        current = current->esq;
    }
    
    ABin nodo = malloc(sizeof(struct nodo));
    nodo->valor = current->valor;
    nodo->esq = NULL;
    nodo->dir = NULL;

    prev->esq = current->dir;
    free(current);
    
    return nodo;
}



void removeRaiz (ABin *a){
    
    if(*a == NULL){
        return;
    }
    
    ABin current = *a;
    
    if((*a)->dir == NULL){
        current = (*a)->esq;
        free(*a);
        *a = current;
    }
    
    else if((*a)->esq == NULL){
        current = (*a)->dir;
        free(*a);
        *a = current;
    }
    else {
        ABin menorDir = removeMenor(&((*a)->dir));
        menorDir->esq = (*a)->esq;
        menorDir->dir = (*a)->dir;
        free(*a);
        *a = menorDir;
    }
}



int removeElem (ABin *a, int x){
    
    if(*a == NULL) return (-1);
    
    ABin current = *a;
    
    if(current->valor == x){
        removeRaiz(a);
        return 0;
    } 
    else if(x < current->valor) {
        removeElem(&(current->esq), x);
    }
    else if(x > current->valor) {
        removeElem(&(current->esq), x);
    }

    return (-1);
}
