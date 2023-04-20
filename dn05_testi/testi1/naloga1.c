
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga1.c
./a.out

*/

#include "naloga1.h"

#include <stdio.h>
#include <stdlib.h>

int* poisci(int* t, int* dolzina, int** konec) {
  int* first;
  *dolzina = 0;

  while (*(t - 1) != 0) {
    t--;
  }
  first = t;
  while (*(t + 1) != 0) {
    t++;
    (*dolzina)++;
  }
  (*dolzina)++;

  *konec = t;
  return first;
}

#ifndef test

int main() {
  // koda za ro"cno testiranje (po "zelji)
  return 0;
}

#endif
