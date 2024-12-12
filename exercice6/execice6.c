#include <stdio.h>
#include <string.h>

#define MAX_SIZE 1020

// Fonction pour lire et traiter chaque cas de test
void processTestCase(char *a, char *b, char *expected)
{
    char result[MAX_SIZE];

    // Vérifier si a et b sont égaux
    if (strcmp(a, b) == 0)
    {
        // Si a et b sont identiques, le PGCD est a (ou b)
        strcpy(result, a);
    }
    else
    {
        // Si a et b sont différents, le PGCD est 1
        strcpy(result, "1");
    }

    // Comparer le résultat obtenu avec le résultat attendu
    if (strcmp(result, expected) == 0)
    {
        printf("Test Case: OK\n");
    }
    else
    {
        printf("Test Case: Mismatch - Expected: %s, Got: %s\n", expected, result);
    }
}

int main()
{
    FILE *inputFile = fopen("input.txt", "r");
    FILE *expectedFile = fopen("expected.txt", "r");

    if (inputFile == NULL || expectedFile == NULL)
    {
        printf("Erreur: Impossible d'ouvrir les fichiers.\n");
        return 1;
    }

    char a[MAX_SIZE], b[MAX_SIZE], expected[MAX_SIZE];

    // Lire chaque ligne de input.txt et expected.txt
    while (fscanf(inputFile, "%s %s", a, b) != EOF && fgets(expected, sizeof(expected), expectedFile) != NULL)
    {
        // Retirer le saut de ligne de la ligne attendue
        expected[strcspn(expected, "\n")] = '\0';

        // Traiter le cas de test
        processTestCase(a, b, expected);
    }

    fclose(inputFile);
    fclose(expectedFile);

    return 0;
}
