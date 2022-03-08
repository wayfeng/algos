#include <stdio.h>
#include <stdlib.h>

/*
 * You need to buy N chocolates from 6 types:
 * type I has only 1 available, type II 2, and type III 3.
 * the rest have unlimited supply, number of type IV can be any integer,
 * number of type V has to be an even number,
 * and number of type VI has to be multiple of 3.
 * calculate how many ways there are to buy N chocolates.
 */

#ifndef min
#define min(a, b) ((a) < (b)) ? (a) : (b)
#endif

int recur(int n, int idx)
{
  int res = 0;
  if (n == 0) return 1;
  switch (idx) {
  case 0:
  case 1:
  case 2:
    for (int i = min(idx+1, n); i >= 0; i--)
      res += recur(n-i, idx+1);
    break;
  case 3:
  case 4:
  case 5:
    for (int i = 0; i <= n; i+=idx-2)
      res += recur(n-i, idx+1);
    break;
  default:
    break;
  }
  return res;
}

int main(int argc, char **argv)
{
  for (int i = 1; i < argc; i++) {
    int n = atoi(argv[i]);
    if (n <= 0)
      continue;
    int r = recur(n, 0);
    printf("%d ", r);
  }
  printf("\n");
  return 0;
}
