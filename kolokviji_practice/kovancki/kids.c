#include <stdio.h>

int coin_sizes[] = {1, 2, 5, 10, 20, 50, 100, 200};

int coins(int cents, int idx)
{
  if (cents < 0 || idx < 0)
    return 0;
  if (cents == 0)
    return 1;

  return coins(cents, idx - 1) +
         coins(cents - coin_sizes[idx], idx);
}

int main()
{
  int euros;
  scanf("%d", &euros);
  printf("%d\n", coins(euros * 100, 7));
  return 0;
}