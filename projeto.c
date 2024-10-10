#include "alg.h"
#define TAMANHO 100000
#define MAX 100000
#include <time.h>


int  main(){

    srand(time(NULL));

	int v1[TAMANHO], v2[TAMANHO], v3[TAMANHO], v4[TAMANHO], v5[TAMANHO], i;
    clock_t start, end;
    float tempo1, tempo2, tempo3, tempo4, tempo5;

    for(i = 0; i < TAMANHO; i++){
        v1[i] = rand()%(MAX+1);
        v2[i] = v1[i];
        v3[i] = v2[i];
        v4[i] = v3[i];
        v5[i] = v4[i];
    }


    //merge
    start = clock();

    mergeSort(v1, 0, TAMANHO-1);

    end = clock();

    tempo1 = (end - start)/(float)CLOCKS_PER_SEC;


    //quick
    start = clock();

    quick(v2, 0, TAMANHO-1);

    end = clock();

    tempo2 = (end - start)/(float)CLOCKS_PER_SEC;


    //bubble
    start = clock();

    bubble(v3, TAMANHO-1);

    end = clock();

    tempo3 = (end - start)/(float)CLOCKS_PER_SEC;


    //selection
    start = clock();

    selection(v4, TAMANHO-1);

    end = clock();

    tempo4 = (end - start)/(float)CLOCKS_PER_SEC;

    
    //insertion
    start = clock();

    insertion(v5, TAMANHO-1);

    end = clock();

    tempo5 = (end - start)/(float)CLOCKS_PER_SEC;


    

    printf("\nBubble: %.4f\n", tempo3);

    printf("\nSelection: %.4f\n", tempo4);

    printf("\nInsertion: %.4f\n", tempo5);

    printf("\nQuick: %.4f\n", tempo2);

    printf("\nMerge: %.4f\n", tempo1);



	return 0;

}
