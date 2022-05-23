void removeMaiorA (ABin *a) {
   
   if(*a == NULL){
       return;
   }
   
   ABin current = *a, prev;
   
   if((*a)->dir == NULL){
       (*a) = (*a)->esq;
       free(current);
       return;
   }
   
   while(current->dir != NULL){
       prev = current;
       current = current->dir;
   }
   
   prev->dir = current->esq;  // o prev->dir passa a apontar para o elemento à esq do curr, 
   free(current);             //quando este é eliminado, sobe para o lugar dele. Se nao houver, é o NULL
}
