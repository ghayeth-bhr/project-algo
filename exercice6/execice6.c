#include <stdio.h>
#include <gmp.h>

// Fonction pour calculer le PGCD
int diviseurCommunMaximal(int l, int m)
{
    int min = l, i;
    if (l > m)
    {
        min = m;
    }

    for (i = min; i > 0; i--)
    {
        if (l % i == 0 && m % i == 0)
        {
            return i;
        }
    }
    return 1;
}

int main()
{
    mpz_t a, b;
    int result;

    // Initialiser les variables GMP
    mpz_init(a);
    mpz_init(b);

    // Demander à l'utilisateur de saisir les valeurs de a et b
    printf("Entrez a et b : \n");
    gmp_scanf("%Zd %Zd", a, b);

    // Vérifier si a et b sont égaux
    if (mpz_cmp(a, b) == 0)
    {
        // Si a == b, alors le PGCD est a (ou b)
        gmp_printf("%Zd\n", a);
    }
    else
    {
        // Si a != b, le PGCD de tous les entiers entre a et b est 1
        printf("1\n");
    }

    // Libérer la mémoire allouée aux variables GMP
    mpz_clear(a);
    mpz_clear(b);

    return 0;
}
