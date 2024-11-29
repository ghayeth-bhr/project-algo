#include <stdio.h>

int main()
{
    int e, i, j, inc = 0;
    printf("Donner le nombre d'evenement: ");
    scanf("%d", &e);

    if (e > 1000000)
    {
        printf("Erreur : %d out of range\n", e);
        return 0;
    }

    int te[e];
    printf("Donner les evenements: ");

    for (i = 0; i < e; i++)
    {
        scanf("%d", &te[i]);
        if ((te[i] > 10) && (te[i] != -1))
        {
            printf("Evenement %d non disponible\n", te[i]);
            return 0;
        }
    }

    // Find the first non -1 element
    if (te[0] == -1)
    {
        while (te[inc] == -1 && inc < e)
        {
            inc++;
        }
    }

    // Handle special cases for all events being -1
    if (inc == e || inc == e - 1)
    {
        printf("%d\n", inc);
        return 0;
    }

    // Process the events
    for (i = inc; i < e; i++)
    {
        j = i + 1;
        while (te[i] > 0 && j < e)
        {
            if (te[j] == -1)
            {
                te[j] = te[j] + 1;
                te[i] = te[i] - 1;
                j++; // Move to the next event
            }
            j++;
        }
    }

    int count = 0;
    for (i = 0; i < e; i++)
    {
        if (te[i] == -1)
        {
            count++;
        }
    }

    printf("%d\n", count);
    return 0;
}
