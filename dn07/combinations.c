#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char combination[101];
char rows[100][50];
int n;

void print_combination() { printf("%s\n", combination); }

void print_combs(int row) {
  if (row == n) {
    print_combination(row);
  }
  for (char* c = rows[row]; *c != '\0'; c++) {
    combination[row] = *c;
    print_combs(row + 1);
  }
}

int main() {
  scanf("%d", &n);
  getchar();
  for (int i = 0; i < n; i++) {
    scanf("%s", rows[i]);
  }
  combination[n] = '\0';
  print_combs(0);

  return 0;
}