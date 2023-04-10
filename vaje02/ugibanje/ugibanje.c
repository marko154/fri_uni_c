#include <stdio.h>

enum { HIGHER = 1, LOWER = -1 };

int main() {
  int a, b;
  scanf("%d %d", &a, &b);

  int feedback;
  do {
    scanf("%d", &feedback);
    int mid = (a + b) / 2;

    if (feedback == HIGHER) {
      a = mid + 1;
    } else if (feedback == LOWER) {
      b = mid - 1;
    }
  } while (feedback != 0);

  if (a == b) {
    printf("%d\n", a);
  } else if (a < b) {
    printf("%d %d\n", a, b);
  } else {
    printf("PROTISLOVJE\n");
  }

  return 0;
}