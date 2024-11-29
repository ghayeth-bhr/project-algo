#include <stdio.h>

int max_subarray_sum_with_limit(int n, int k, int a[])
{
    int max_sum = 0;

    // Cas normal : vérifier tous les sous-tableaux contigus
    for (int start = 0; start < n; start++)
    {
        int current_sum = 0;
        for (int end = start; end < n; end++)
        {
            current_sum += a[end];
            if (current_sum <= k)
            {
                if (current_sum > max_sum)
                {
                    max_sum = current_sum;
                }
            }
            else
            {
                break;
            }
        }
    }

    // Cas spécial : sous-tableau constitué par le premier et le dernier élément
    int wrap_sum = a[0] + a[n - 1];
    if (wrap_sum <= k && wrap_sum > max_sum)
    {
        max_sum = wrap_sum;
    }

    return max_sum;
}

int main()
{
    int n, k;

    // Entrée de la taille du tableau et de la valeur de k
    printf("Entrez la taille du tableau (n) : ");
    scanf("%d", &n);
    printf("Entrez la valeur maximale (k) : ");
    scanf("%d", &k);

    int a[n];

    // Entrée des éléments du tableau
    printf("Entrez les éléments du tableau :\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    if (k == 0)
    {
        printf("La somme maximale du sous-tableau est : %d\n", 0);
        return 0;
    }

    // Appel de la fonction et affichage du résultat
    int result = max_subarray_sum_with_limit(n, k, a);
    printf("La somme maximale du sous-tableau est : %d\n", result);

    return 0;
}