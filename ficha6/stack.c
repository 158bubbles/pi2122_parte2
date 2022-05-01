#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

// Static stacks 

void SinitStack (SStack s){
	
	s->sp = -1;   //para uma stack estar vazia, o stack pointer está a -1
}


int  SisEmpty (SStack s){
    int res = 0;
    
    if(s->sp == -1){
	    res = 1;
    }    
    
    return res;
}


int  Spush (SStack s, int x){
	int res = 0;
	
	if(s->sp +1 == Max){  //se estiver cheia, dá return 1
	    res = 1;   
	} else {
	    s->sp++;   //o sp aumenta e colocamos nessa posição o x
	    s->values[s->sp] = x;
	}
	
	return res;
}



int  Spop (SStack s, int *x) {
	int res = 0;
	
	if(SisEmpty(s)){
	    res = 1;
	} else {
	    *x = s->values[s->sp];
	    s->sp--;
	}
	
	return res;
}



int  Stop (SStack s, int *x) {
	int res = 0;
	
	if(SisEmpty(s)){
	    res = 1;
	} else {
	    *x = s->values[s->sp];
	}
	
	return res;
}



void ShowSStack (SStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}




// Stacks with dynamic arrays

int dupStack (DStack s) {  //é feito quando é preciso mais espaço para novos elementos
	int res = 0;
	
	s->size *= 2;
	s->values = realloc(s->values,s->size);
	if(s->values == NULL) res = 1;
	
	return res;
}

int metadeStack (DStack s) {   //é feito quando n é preciso tanto espaço, entao poupa-se memoria
	int res = 0;
	
	s->size /= 2;
	s->values = realloc(s->values,s->size);
	if(s->values == NULL) res = 1;
	
	return res;
}


void DinitStack (DStack s) {
	
	s = malloc(sizeof(struct dinStack));
	s->size = 1;
	s->sp = -1;
	s->values = malloc(sizeof(int));  //espaço alocado para os elementos int
}


int  DisEmpty (DStack s) {
    
	return (s->sp = -1);
}


int  Dpush (DStack s, int x){
	int res = 0;
	
	if((s->sp == (s->size -1)) && (dupStack(s) != 0)){  //está cheio e a duplicação n é feita
	    res = 1;
	} else {
	    s->sp++;   //o sp aumenta e colocamos nessa posição o x
	    s->values[s->sp] = x;
	}
	
	return res;
}


int  Dpop (DStack s, int *x){
	int res = 0;
	
	if(DisEmpty(s) && metadeStack(s) != 0){
	    res = 1;
	} else {
	    *x = s->values[s->sp];
	    s->sp--;
	}
	
	return res;
}


int  Dtop (DStack s, int *x){
	int res = 0;
	
	if(DisEmpty(s)){
	    res = 1;
	} else {
	    *x = s->values[s->sp];
	}
	
	return res;
}


void ShowDStack (DStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}
