#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

// Static queues 
//NOTA: no primeiro elemento de uma queue, front está em 0 e o length está em 1.
//      no segundo elemento de uma queue, front está em 0 e o length está em 2.
//      etc etc

void SinitQueue (SQueue q){
    
    q->front = -1;  //o front é o inicio da fila, de onde se retiram os elementos
	q->length = 0;
}

int  SisEmptyQ (SQueue q){
    
	return (q->length == 0);
}

int  Senqueue (SQueue q, int x){
	int res = 0;
	
	if(q->length == Max){
	    res = 1;
	} else {
	    if(SisEmpty(q)){  //se estiver vazia, antes de acrescentarmos temos de passar o front para 0
	        q->front = 0;
	    }
	    
	    q->length++;
	    q->values[q->length] = x;
	}
	
	return res;
}


int  Sdequeue (SQueue q, int *x) {
	int res = 0;
	
	if(SisEmpty(q)){
	    res = 1;
	} else {
	    *x = q->values[q->front];
	    q->front++;
	    q->length--;
	    
	    if(SisEmpty(q)){ //se depois de removermos, ficarmos com queue vazia
	        q->front = -1;
	    }
	}
	
	return res;
}


int  Sfront (SQueue q, int *x) {
	int res = 0;
	
	if(SisEmpty(q)){
	    res = 1;
	} else {
	    *x = q->values[q->front];
	}
	
	return res;
}


void ShowSQueue (SQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%Max;
    }
    putchar ('\n');
}



// Queues with dynamic arrays

int dupQueue (DQueue q) {
	int res = 0;
	
	q->size *= 2;
	q->values = realloc(q->values,q->size);
	if(q->values == NULL) res = 1;
	
	return res;
}

int metadeQueue (DQueue q){
	int res = 0;
	
	q->size /= 2;
	q->values = realloc(q->values,q->size);
	if(q->values == NULL) res = 1;
	
	return res;
}


void DinitQueue (DQueue q) {
	q = malloc(sizeof(struct dinQueue));
	q->size = 1;
	q->front = -1;
	q->length = 0;
	q->values = malloc(sizeof(int));
}


int  DisEmptyQ (DQueue s) {
    
	return (q->length == 0);
}


int  Denqueue (DQueue q, int x){
	int res = 0;
	
	if((q->length == q->size) && (dupQueue(q) != 0)){
	    res = 1;
	} else {
	    if(DisEmpty(q)){  //se estiver vazia, antes de acrescentarmos temos de passar o front para 0
	        q->front = 0;
	    }
	    
	    q->length++;
	    q->values[q->length] = x;
	}
	
	return res;
}


int  Ddequeue (DQueue q, int *x){
	int res = 0;
	
	if(DisEmptyQ(q) && (metadeQueue(q) != 0)){
	    res = 1;
	} else {
	    *x = q->values[q->front];
	    q->front++;
	    q->length--;
	}
	
	if(DisEmptyQ(q)){
	    q->front = -1;
	}
	
	return res;
}


int  Dfront (DQueue q, int *x){
	int res = 0;
	
	if(DisEmptyQ(q)){
	    res = 1;
	} else {
	    *x = q->values[q->front];
	}
	
	return res;
}

void ShowDQueue (DQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%q->size;
    }
    putchar ('\n');
}
