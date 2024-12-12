#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE 100000

// Fonction pour vérifier si les parenthèses correspondent
int isMatchingPair(char open, char close)
{
    return (open == '(' && close == ')') ||
           (open == '[' && close == ']') ||
           (open == '{' && close == '}');
}

// Fonction pour vérifier si une chaîne est équilibrée
const char *isBalanced(const char *s)
{
    char stack[MAX_SIZE];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++)
    {
        char current = s[i];

        // Si c'est une parenthèse ouvrante, on l'empile
        if (current == '(' || current == '[' || current == '{')
        {
            stack[++top] = current;
        }
        // Si c'est une parenthèse fermante
        else if (current == ')' || current == ']' || current == '}')
        {
            if (top == -1 || !isMatchingPair(stack[top], current))
            {
                return "NO";
            }
            top--;
        }
        else
        {
            // Si un caractère invalide est trouvé
            return "NO";
        }
    }

    return (top == -1) ? "YES" : "NO";
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

    char inputLine[MAX_SIZE];
    char expectedLine[10];
    int testCase = 1;

    while (fgets(inputLine, sizeof(inputLine), inputFile) != NULL &&
           fgets(expectedLine, sizeof(expectedLine), expectedFile) != NULL)
    {

        // Retirer les sauts de ligne
        inputLine[strcspn(inputLine, "\n")] = '\0';
        expectedLine[strcspn(expectedLine, "\n")] = '\0';

        // Calculer le résultat obtenu
        const char *result = isBalanced(inputLine);

        // Comparer avec le résultat attendu
        if (strcmp(result, expectedLine) == 0)
        {
            printf("Test Case %d: OK\n", testCase);
        }
        else
        {
            printf("Test Case %d: Mismatch - Expected: %s, Got: %s\n", testCase, expectedLine, result);
        }

        testCase++;
    }

    fclose(inputFile);
    fclose(expectedFile);

    return 0;
}
