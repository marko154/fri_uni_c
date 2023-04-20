
/*

Prevajanje in poganjanje skupaj z datoteko test01.c:

gcc -D=test test01.c naloga2.c
./a.out


*/

#include "naloga2.h"

#include <stdio.h>

void zamenjaj(int** a, int** b) {
  int* temp = *a;
  *a = *b;
  *b = temp;
}

void swap(int** a, int** b) {
  int* temp = *a;
  *a = *b;
  *b = temp;
}

struct State;
typedef void state_func(struct State* state);
struct State {
  state_func* next;
};

void uredi(int** a, int** b, int** c) {
  if (**a > **b) {
    swap(a, b);
  }
  if (**b > **c) {
    swap(b, c);
  }
  if (**a > **b) {
    swap(a, b);
  }
}

#ifndef test

int main() {
  // koda za ro"cno testiranje (po "zelji)
  return 0;
}

#endif
