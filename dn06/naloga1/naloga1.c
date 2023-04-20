
#include "naloga1.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* zdruzi(char** nizi, char* locilo) {
  int total_size = 0;
  int size = 0;

  while (*(nizi + size)) {
    total_size += strlen(*(nizi + size));
    size++;
  }

  int mem_size = total_size + (size - 1) * strlen(locilo) + 1;
  char* joined = (char*)malloc(mem_size);
  total_size = 0;

  for (int i = 0; i < size; i++) {
    char* word = nizi[i];
    strncpy(joined + total_size, word, strlen(word));
    total_size += strlen(word);
    if (i != size - 1) {
      strncpy(joined + total_size, locilo, strlen(locilo));
      total_size += strlen(locilo);
    }
  }

  joined[mem_size - 1] = '\0';
  return joined;
}

char* NIZI[] = {"Radko", "Milena", "Boris", NULL};

int main() {
  char* niz = zdruzi(NIZI, ", ");
  printf("<%s>\n", niz);

  return 0;
}
