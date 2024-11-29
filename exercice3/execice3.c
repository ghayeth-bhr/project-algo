#include <stdio.h>

int main()

{
    int i, j, s = 0, k, q, x = 0, l, r, f;
    int maxCount = 0;
    int mostFrequent;

    scanf("donner le deux bornes %d %d", &l, &r);
    if ((l < r) && (l >= 2) && (r <= 10e9))
    {

        for (i = l; i <= r; i++)
        {
            for (j = 2; j <= i; j++)
            {
                if (i % j == 0)
                {
                    s++;
                }
            }
        };

        int t[s];

        for (k = l; k <= r; k++)

        {
            for (q = 2; q <= k; q++)
            {
                if (k % q == 0)
                {
                    t[x] = q;
                    x++;
                }
            }
        };

        for (int i = 0; i < s; i++)
        {
            int count = 0;

            for (j = 0; j < s; j++)
            {
                if (t[j] == t[i])
                {
                    count++;
                }
            }

            if (count > maxCount)
            {
                maxCount = count;
                mostFrequent = t[i];
            }
        };

        printf("The most frequent diviseur between %d and %d is %d\n", l, r, mostFrequent);
        return 0;
    }
    else
        printf("erreur\n");
}
