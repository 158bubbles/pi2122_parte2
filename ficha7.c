#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

void libertaLista (Palavras);
int quantasP (Palavras);
void listaPal (Palavras);
char * ultima (Palavras);
Palavras acrescentaInicio (Palavras, char *);
Palavras acrescentaFim (Palavras, char *);
Palavras acrescenta (Palavras, char *);
struct celula * maisFreq (Palavras);

//verifica se a l está sem nodos ou tem nodos mas a ocorrencia é 0
int isEmpty(Palavras l){
    int res = 0;
    
    if(l == NULL || l->ocorr == 0){
        res = 1;
    }
    return res;
}


//liberta o espaço ocupado pela lista de palavras
void libertaLista (Palavras l){
    Palavras temporario = l;
    
    if(l == NULL){
        return;
    } 
    
    while(l != NULL){
        l = l->prox;
        free(temporario->palavra);
        free(temporario);
        temporario = l;
    }
}


//auxiliar da quantasP
int isDifferent(char *pal, Palavras lista){
    int count = 0;
    
    while(lista != NULL){
        if(strcmp(pal, lista->palavra) == 0){
            count++;
        }
        
    }
    
    return count>1;
}


//diz quantas palavras diferentes existem no total em l
int quantasP (Palavras l){
    int res = 0;
    Palavras lista = l;
    
    if(isEmpty(l)) return 0;
    
    while(l != NULL){
        if(isDifferent(l->palavra, lista) == 1){
            res++;
        }
    }
    
    return res;
}


//lista uma por linha todas as palavras e as suas ocorr
void listaPal (Palavras l){
    
    if(l == NULL){
        return;
    }
    
    while(l != NULL){
        printf("%s\n", l->palavra);
        printf("%d\n\n", l->ocorr);
        l = l->prox;
    }
}


//diz nos a ultima palavra da lista
char * ultima (Palavras l){
    
    if(l == NULL){
        return NULL;
    }
    
    while(l->prox != NULL){
        l = l->prox;
    }
    
    return l->palavra;
}


//acrescenta uma palavra no inicio da lista
Palavras acrescentaInicio (Palavras l, char *p){
    Palavras nova = malloc(sizeof(struct celula));
    
    nova->palavra = malloc(sizeof(char) * (strlen(p)+1) );
    strcpy(nova->palavra, p);
    nova->ocorr = 1;
    nova->prox = l;

    return nova;
}


//acrescenta uma palavra do fim da lista
Palavras acrescentaFim (Palavras l, char *p){
    Palavras nova = malloc(sizeof(struct celula));
    nova->palavra = malloc(sizeof(char)*(strlen(p)+1));
    strcpy(nova->palavra, p);
    nova->ocorr = 1;
    nova->prox = NULL;
    
    Palavras current = l;
    
    if(current == NULL){
        return nova;
    }
    
    while(current->prox != NULL){
        current = current->prox;
    }
    
    current->prox = nova;
    
    return l;
}


//regista mais uma ocorrencia de p ou acrescenta nodo com p
Palavras acrescenta (Palavras l, char *p){
    Palavras current = l;
    
    if(isEmpty(l)){  //se for lista vazia, criamos o nodo e a nova lista é esse nodo
        Palavras nova = malloc(sizeof(struct celula));
        nova->palavra = malloc(sizeof(char)*(strlen(p)+1));
        nova->ocorr = 1;
        nova->prox = NULL;
        
    } else {
        //criar um temp antes do l
        Palavras temp = malloc(sizeof(struct celula));
        temp->palavra = malloc(sizeof(char)*(strlen(p)+1));
        temp->ocorr = 0;
        temp->prox = l;
        
        while(current->prox != NULL && strcmp(current->palavra, p) < 0){
            temp = current;
            current = current->prox;
        }
        
        //este ciclo acaba se:
        //1. encontrarmos a palavra em questao
        //2. passarmos a ter >0, temos de meter antes desse nodo
        //2.2 se antes desse nodo, for o inicio da lista
        //3. chegarmos ao fim da lista com ultimo nodo <0
        //4. chegarmos ao fim da lista com ultimo nodo >0
        
        if(strcmp(current->palavra, p) == 0){
            
            current->ocorr = current->ocorr +1;
            
        } else if(strcmp(current->palavra, p) > 0){
            
            if(current == l){
                Palavras nodo = malloc(sizeof(struct celula));
                nodo->palavra = malloc(sizeof(char)*(strlen(p)+1));
                strcpy(nodo->palavra, p);
                nodo->ocorr = 1;
                nodo->prox = current;
                l = nodo;
            }
            
            Palavras nodo = malloc(sizeof(struct celula));
            nodo->palavra = malloc(sizeof(char)*(strlen(p)+1));
            strcpy(nodo->palavra, p);
            nodo->ocorr = 1;
            nodo->prox = current;
            temp->prox = nodo;
            
        } else if(current->prox == NULL && strcmp(current->palavra, p) > 0){
            
            Palavras nodo = malloc(sizeof(struct celula));
            nodo->palavra = malloc(sizeof(char)*(strlen(p)+1));
            strcpy(nodo->palavra, p);
            nodo->ocorr = 1;
            nodo->prox = current;
            temp->prox = nodo;
            
        } else if(current->prox == NULL && strcmp(current->palavra, p) < 0){
            
            Palavras nodo = malloc(sizeof(struct celula));
            nodo->palavra = malloc(sizeof(char)*(strlen(p)+1));
            strcpy(nodo->palavra, p);
            nodo->ocorr = 1;
            nodo->prox = NULL;
            current->prox = nodo;
            
        }
    }
    
    return l;
}



struct celula * maisFreq (Palavras l){
    Palavras res;
    int max = 0;
    
    if(isEmpty(l)){
        return NULL;
    }
    
    while(l != NULL){
        if(l->ocorr > max){
            max = l->ocorr;
            res = malloc(sizeof(struct celula));
            res->palavra = malloc(sizeof(char)*(strlen(l->palavra)+1));
            strcpy(res->palavra, l->palavra);
            res->ocorr = max;
            res->prox = NULL;
        }
        
        l = l->prox;
    }
    
    return res;
}

int main () {
    Palavras dic = NULL;

    char * canto1 [44] = {"as", "armas", "e", "os", "baroes", "assinalados",
                          "que", "da", "ocidental", "praia", "lusitana", 
                          "por", "mares", "nunca", "de", "antes", "navegados",
                          "passaram", "ainda", "alem", "da", "taprobana",
                          "em", "perigos", "e", "guerras", "esforcados",
                          "mais", "do", "que", "prometia", "a", "forca", "humana",
                          "e", "entre", "gente", "remota", "edificaram", 
                          "novo", "reino", "que", "tanto", "sublimaram"};

    printf ("\n_____________ Testes _____________\n\n");

    int i; struct celula *p;
    for (i=0;i<44;i++);
        dic = acrescentaInicio (dic, canto1[i]);

    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    //listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));

    //libertaLista (dic);

    dic = NULL;

    srand(42);
    
    for (i=0; i<1000; i++);
        //dic = acrescenta (dic, canto1 [rand() % 44]);
    
    printf ("Foram inseridas %d palavras\n", quantasP (dic));
    printf ("palavras existentes:\n");
    //listaPal (dic);
    printf ("última palavra inserida: %s\n", ultima (dic));
    
    //p = maisFreq (dic);
    //printf ("Palavra mais frequente: %s (%d)\n", p->palavra, p->ocorr);
    
    printf ("\n_________ Fim dos testes _________\n\n");

    return 0;
}
