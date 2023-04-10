#include <stdio.h>

void print_bytes(void* ptr, size_t n_bytes) {
  for (size_t i = 0; i < n_bytes; i++) {
    printf(" %.16x", *((char*)ptr + i));
  }
}

int main() {
  long long num = -1231231232132;
  print_bytes(&num, sizeof(long long));
  return 0;
  int n, largest, sLargest = -1;
  scanf("%d", &n);
  scanf("%d", &largest);

  for (int i = 0; i < n - 1; i++) {
    int next;
    scanf("%d", &next);
    if (next >= largest) {
      sLargest = largest;
      largest = next;
    } else if (next >= sLargest) {
      sLargest = next;
    }
  }

  printf("%d", sLargest);

  return 0;
}