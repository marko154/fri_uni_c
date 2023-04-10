#include <stdbool.h>
#include <stdio.h>

long get_reversed(long n, long reversed) {
  if (n == 0) return reversed;
  return get_reversed(n / 10, reversed * 10 + n % 10);
}

bool is_palindrome(long n) { return n == get_reversed(n, 0); }

long next(long n) { return n + get_reversed(n, 0); }

int main() {
  int k, a, b, ans = 0;
  scanf("%d %d %d", &k, &a, &b);

  for (long n = a; n <= b; n++) {
    bool isLyscrel = true;
    long num = n;
    for (int i = 0; i < k; i++) {
      num = next(num);

      if (is_palindrome(num)) {
        isLyscrel = false;
        break;
      }

      if (num > 10e17) {
        break;
      }
    }

    if (isLyscrel) {
      ans++;
    }
  }

  printf("%d\n", ans);

  return 0;
}