#include <stdio.h>
#include <math.h>
int ans = 0;

int f(int n, int k)
{
  if (k < n)
    return 1;
  int total = 0;
  for (int i = 0; i < k; i++)
  {
    total += f(n - i - 1, k);
    ans++;
  }
  return total;
}

int g(int n, int k)
{
  if (n < k)
    return 0;
  int total = 0;

  for (int i = 0; i < k; i++)
  {
    total += g(n - i - 1, k);
  }
  return k - 1 + total;
}
int g1(int n, int k)
{
  return (k - 1) * (n - k) * (pow(2, n - k) - 2);
}

int main()
{
  int n = 5, k = 3;
  printf("%d %d\n", g(n, k), g1(n, k));
  return 0;
}