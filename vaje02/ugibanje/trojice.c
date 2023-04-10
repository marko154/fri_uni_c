#include <math.h>
#include <stdbool.h>
#include <stdio.h>

bool is_pytagorean(int c) {
  for (int a = 1; a < c; a++) {
    int possible_b = (int)sqrt(c * c - a * a);
    if (possible_b * possible_b + a * a == c * c) {
      return true;
    }
  }
  return false;
}

int main() {
  int m, n;
  scanf("%d %d", &m, &n);

  int ans = 0;

  for (int c = m; c <= n; c++) {
    if (is_pytagorean(c)) {
      ans++;
    }
  }

  printf("%d\n", ans);
  return 0;
}