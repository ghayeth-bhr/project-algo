#include <stdio.h>

int main()
{
    int c, i, j, max, min, inc = 1;
    printf("donner le nombre de concourt\n");
    scanf("%d", &c);
    if ((c < 1) || (c > 1000))
    {
        printf("erreur : %d out of range\n", c);
        return 0;
    };

    int ts[c];
    printf("donner les scores obtenue pour les %d concourt\n", c);

    for (i = 0; i < c; i++)
    {
        scanf("%d", &ts[i]);
        if (ts[i] > 10000)
        {
            printf("score : %d out of range\n", ts[i]);
            return 0;
        }
    };
    max = ts[0];
    min = ts[0];
    if (c == 1)
    {
        printf("incroyable est : 0\n");
        return 0;
    }
    else if (c == 2)
    {
        printf("incroyable est : 1\n");
        return 0;
    }
    else
    {

        for (i = 2; i < c; i++)
        {

            for (j = 0; j < i; j++)
            {
                if (ts[j] < min)
                {
                    min = ts[j];
                };
                if (ts[j] > max)
                {
                    max = ts[j];
                };
            };
            if (ts[i] < min || ts[i] > max)
            {
                inc++;
            };
        }
    }
    printf("incroyable est : %d\t:", inc);
    return 0;
}