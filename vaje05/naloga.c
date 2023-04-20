
#include "naloga.h"

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int vsota(int* zac, int* kon) {
  int sum = 0;
  while (zac != kon) {
    sum += *zac;
    zac++;
  }
  return sum;
}

void indeksInKazalec(int* t, int* indeks, int** kazalec) {
  if (*indeks == -1) {
    *indeks = *kazalec - t;
  } else {
    *kazalec = t + *indeks;
  }
}

void frekvenceCrk(char* niz, int** frekvence) {
  int len = 'z' - 'a' + 1;
  int* new_frequencies = calloc(len, sizeof(int));
  while (*niz) {
    int offset = tolower(*niz) - 'a';
    if (offset < len && offset >= 0) {
      new_frequencies[offset]++;
    }
    niz++;
  }

  *frekvence = new_frequencies;
}

#ifndef test

int main() {
  // koda za ro"cno testiranje (po "zelji)
  int* frekvence;
  frekvenceCrk("baNanA", &frekvence);
  free(frekvence);

  return 0;
}

#endif
