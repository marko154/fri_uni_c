#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int get_friend(int n) {
  int friend = 1;

  for (int divisor = 2; divisor < sqrt(n) + 1; divisor++) {
    if (n % divisor == 0) {
      friend += divisor;
      friend += n / divisor;
    }
  }

  return friend;
}

int main() {
  int n;
  scanf("%d", &n);
  int friend = get_friend(n);
  if (get_friend(friend) == n) {
    printf("%d\n", friend);
  } else {
    printf("NIMA\n");
  }
  return 0;
}