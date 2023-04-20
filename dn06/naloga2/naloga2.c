
#include "naloga2.h"

#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int** ap2pp(int (*kazalec)[N], int izvornoStVrstic, int ciljnoStVrstic) {
  int** rezultat = (int**)malloc(ciljnoStVrstic * sizeof(int**));
  int row_size = (izvornoStVrstic * N) / ciljnoStVrstic;

  for (int i = 0; i < ciljnoStVrstic; i++) {
    rezultat[i] = (int*)calloc(row_size + 1, sizeof(int*));
    for (int j = 0; j < row_size; j++) {
      rezultat[i][j] = kazalec[(i * row_size + j) / N][(i * row_size + j) % N];
    }
  }

  return rezultat;
}

int (*pp2ap(int** kazalec, int izvornoStVrstic, int* ciljnoStVrstic))[N] {
  int(*arr)[N] = (int(*)[N])calloc(izvornoStVrstic, sizeof(int[N]));
  int index = 0;

  for (int i = 0; i < izvornoStVrstic; i++) {
    for (int j = 0; kazalec[i][j] != 0; j++) {
      arr[index / N][index % N] = kazalec[i][j];
      index++;
    }
  }

  *ciljnoStVrstic = ceil((double)index / N);
  return arr;
}
