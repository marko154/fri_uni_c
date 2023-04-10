#include <stdbool.h>
#include <stdio.h>

int main() {
  int n, first, next;
  scanf("%d", &n);
  scanf("%d", &first);
  next = first;
  for (int i = 0; i < n - 1 && next == first; i++) {
    scanf("%d", &next);
  }
  bool areEqual = next == first;
  printf("%d\n", areEqual);
  return 0;
}