#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if (argc != 3) return -1;
    int n = atoi(argv[1]);
    int m = atoi(argv[2]);
    int r1 = 4;
    if (n < m) {
        int t = n;
        n = m;
        m = t;
    }
    for (int i = 1; i < m; i++) {
        r1 += 6 + (i-1) * 4;
    }
    int r2 = r1;
    for (int i = m; i < n; i++) {
        r2 += 6 + (i-1) * 4;
    }
    printf("%d %d\n", r1, r2);
    return 0;
}
