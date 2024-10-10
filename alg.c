#include "alg.h"
#include <time.h>


void troca(int* v, int i, int j){

	int aux = v[i];
	v[i] = v[j];
	v[j] = aux;

}

int  minimo(int* v, int chave, int i){
	if(v[chave] > v[i])
		return i;
	return chave;
		
}

void printv(int* v, int n){

	int i = 0;
	printf("\nO vetor é:");
	for(i = 0; i < n; i++)
		printf(" %d", v[i]);
	printf("\n");

}

void bubble(int* v, int n){

	int i, j;

	for(i = 0; i < n - 1; i++)

		for(j = 0; j < n - i; j++)

			if(v[j] > v[j+1])

				troca(v, j, j+1);
				

}


void selection(int* v, int n){

	int i, j, chave;

	for(i = 0; i < n; i++){
		chave = i;
		for(j = i; j <= n; j++)
			chave = minimo(v, chave, j);
		troca(v, i, chave);
	}

}


void insertion(int* v, int n){

	int i, j, chave, continua;

	for( i = 1; i <= n; i++){
		chave = i;
		continua = 1;
		for(j = i-1; (j >= 0) && continua; j--){
			if(v[j] > v[chave]){
			       troca(v, chave, j);
			       chave = j;
			}
			else
				continua = 0;
		}
	}
}


int particiona(int* v, int inf, int sup){

	int i, pos_pivo = inf, pivo = v[sup];

    for(i = inf; i < sup; i++)
        if(v[i] <= pivo)
            troca(v, i, pos_pivo++);

    troca(v, pos_pivo, sup);

    return pos_pivo;

}


int random_particiona(int* v, int inf, int sup){

    srand(time(NULL));

    int pos_pivo = (rand()%(sup - inf + 1))+inf;

    troca(v, pos_pivo, sup);

    return particiona(v, inf, sup);


}


void quick(int* v, int inf, int sup){
		
    if(inf < sup){
	    int pos_pivo = random_particiona(v, inf, sup);
	    quick(v, inf, pos_pivo-1);
		quick(v, pos_pivo+1, sup);

    }

}



void merge(int* v, int inf, int sup){

    int m = (inf + sup)/2;

    int l = (m - inf) +1;
    int r = (sup - m);

    int i, j, k;

    int* right = (int*) malloc(sizeof(int)*r);
    int* left = (int*) malloc(sizeof(int)*l);

    for(i = 0; i < l; i++)
        left[i] = v[inf + i];

    for(i = 0; i < r; i++)
        right[i] = v[m + 1 + i];

    i = 0;
    j = 0;
    k = inf;

    while(i < l && j < r){
        if(left[i] > right[j])
            v[k++] = right[j++];

        else
            v[k++] = left[i++];
    }

    while(i < l)
       v[k++] = left[i++];

    while(j < r)
       v[k++] = right[j++];

    free(left);
    free(right);



}



void mergeSort(int* v, int inf, int sup){

	if( inf < sup){
		int m = (inf + sup)/2;

		mergeSort(v, inf, m);
		mergeSort(v, m+1, sup);

		merge(v, inf, sup);

	}

}


