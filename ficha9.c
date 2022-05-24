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


//altura da arvore
int altura (ABin a){
    
    if(a==NULL){
        return 0;
    }
    
    int alturaEsq = altura(a->esq);
    int alturaDir = altura(a->dir);
    
    if(alturaEsq > alturaDir){
        return (alturaEsq + 1);
    } else {
        return (alturaDir + 1);
    }
}


//numero de folhas da arvore
int nFolhas (ABin a){
    int count=0;
    
    if(a == NULL){
        return 0;
    }
    
    if(a->esq == NULL && a->dir == NULL){
        return 1;
    }
    
    return nFolhas(a->esq) + nFolhas(a->dir);
}


//nodo mais à esquerda
ABin maisEsquerda (ABin a){
    ABin current = a;
    
    while(current->esq != NULL){
        current = current->esq;
    }

    return current;
}


//dá print de todos os elementos do nivel l
void imprimeNivel (ABin a, int l){
    
    if(a == NULL){
        return;
    }
    
    if(l == 0){
        printf("%d\n", a->valor);
    } else {
        imprimeNivel(a->esq, l-1);
        imprimeNivel(a->dir, l-1);    
    }
}


//testa se x está na arvore
int procuraE (ABin a, int x){
    
    if(a == NULL){
        return 0;
    }
    
    if(a->valor == x){
        return 1;
    }
    
    int esq = procuraE(a->esq, x);
    int dir = procuraE(a->dir, x);
    
    
    return (esq || dir);
}

//---------------------------------------------------------------

//dá-nos o nodo onde está x
struct nodo *procura (ABin a, int x){
    
    if(a == NULL){
        return NULL;
    }
    
    ABin current = a;
    
    while(current != NULL){
        
        if(current->valor == x){
            return current;
        }
        
        if(x < current->valor){
            current = current->esq;
        } else {
            current = current->dir;
        }
        
    }
    
    return NULL;
}


//diz-nos o nível onde está o x na arvore
int nivel (ABin a, int x){
    int nivel = 1;
    
    if(a == NULL) return -1;
    
    ABin current = a;
    while(current != NULL){
        
        if(current->valor == x){
            return nivel;
        }
        
        if(x < current->valor){
            current = current->esq;
            nivel++;
        } else {
            current = current->dir;
            nivel++;
        }
    }
    
    return (-1);
}


//imprime por ordem crescente todos os elementos < x
void imprimeAte (ABin a, int x){
    
    if(a == NULL) return;
     
    ABin current = a; 
        
    if(current->valor == x){  //os menores sao os da esq
        imprimeAte(current->esq, x);
        printf("%d\n", current->valor);
    } 
    else if(x < current->valor){
        imprimeAte(current->esq, x);
    }
    else if(x > current->valor) {
        imprimeAte(current->esq, x);
        printf("%d\n", current->valor);
        imprimeAte(current->dir, x);
    }
}
