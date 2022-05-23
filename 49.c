int quantosMaiores (ABin a, int x) {
	int count = 0;
  
	if (a != NULL) {
		if (a->valor > x)
			count = 1;
		  count += quantosMaiores (a->esq, x) + quantosMaiores (a->dir, x);
	}
	return count;
}
