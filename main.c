#include <stdio.h>

int main(void)
{
    unsigned int n;
    scanf("%d", &n);
    unsigned int nFila[n];
    for (unsigned int x = 0; x < n; x++)
        scanf("%d", &nFila[x]);

    unsigned int m;
    scanf("%d", &m);
    unsigned int mFila[m];
    for (unsigned int x = 0; x < m; x++)
        scanf("%d", &mFila[x]);

    for (unsigned int x = 0; x < n; x++)
    {
        char flag = 1;
        for (unsigned int y = 0; y < m; y++)
            if (nFila[x] == mFila[y])
            {
                flag = 0;
                break;
            }
        if (flag)
            printf("%d ", nFila[x]);
    }
    printf("\n");

    return 0;
}
