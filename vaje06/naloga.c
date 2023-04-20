
#include "naloga.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int steviloZnakov(char* niz, char znak) {
  int occurances = 0;
  while (*niz) {
    if (*niz == znak) {
      occurances++;
    }
    niz++;
  }
  return occurances;
}

char* kopirajDoZnaka(char* niz, char znak) {
  char* znak_ptr = strchr(niz, znak);
  int length = znak_ptr == NULL ? strlen(niz) : znak_ptr - niz;
  char* shorter = (char*)malloc(length + 1);
  strncpy(shorter, niz, length);
  *(shorter + length) = '\0';
  return shorter;
}

char** razcleni(char* niz, char locilo, int* stOdsekov) {
  *stOdsekov = steviloZnakov(niz, locilo) + 1;
  char** segments = (char**)calloc(*stOdsekov, sizeof(char*));

  for (int i = 0; i < *stOdsekov; i++) {
    segments[i] = kopirajDoZnaka(niz, locilo);
    niz += strlen(segments[i]) + 1;
  }

  return segments;
}

#ifndef test

int main() {
  // koda za ro"cno testiranje (po "zelji)
  int num_of_segments;
  razcleni("prijazen niz z enim samim presledkom med besedami", ' ',
           &num_of_segments);
  return 0;
}

#endif
