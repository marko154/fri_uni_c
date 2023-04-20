#include <stdio.h>

int summands[30];

void print_sum(int n) {
  for (int i = 0; i < n; i++) {
    printf("%d", summands[i]);
    if (i < n - 1) {
      printf(" + ");
    }
  }
  printf("\n");
}

void num_of_ways(int n, int k, int idx) {
  if (n == 0) {
    print_sum(idx);
    return;
  }
  if (n < 0 || k <= 0) {
    return;
  }
  summands[idx] = k;
  num_of_ways(n - k, k, idx + 1);
  num_of_ways(n, k - 1, idx);
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  num_of_ways(n, k, 0);
  return 0;
}