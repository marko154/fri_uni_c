#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int arr[1000000];

int main() {
  int n;
  scanf("%d", &n);

  for (int i = 0; i < n; i++) {
    scanf("%d", &arr[i]);
  }

  int bestSoFar = arr[0], current = 0;

  for (int i = 0; i < n; i++) {
    current += arr[i];
    if (current > bestSoFar) bestSoFar = current;
    if (current < 0) {
      current = 0;
    }
  }

  printf("%d\n", bestSoFar);

  return 0;
}