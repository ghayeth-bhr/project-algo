#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NODES 10000
#define MAX_EDGES 100000

int n, m;                      // Nombre de sommets et d'arêtes
int adj[MAX_NODES][MAX_NODES]; // Liste d'adjacence
int visited[MAX_NODES];        // État de chaque sommet : 0 = non visité, 1 = en cours de visite, 2 = exploré

// Fonction DFS pour détecter les cycles
int dfs(int node)
{
    // Marquer le sommet comme en cours de visite
    visited[node] = 1;

    // Explorer tous les voisins
    for (int i = 0; i < n; i++)
    {
        if (adj[node][i])
        {
            if (visited[i] == 1)
            {
                // Si le voisin est en cours de visite, il y a un cycle
                return 1;
            }
            if (visited[i] == 0 && dfs(i))
            {
                // Si le voisin n'est pas encore exploré, faire un DFS récursif
                return 1;
            }
        }
    }

    // Marquer le sommet comme exploré
    visited[node] = 2;
    return 0;
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

    int testCase = 1;
    while (fscanf(inputFile, "%d %d", &n, &m) == 2)
    {
        // Réinitialisation de la liste d'adjacence et des états
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                adj[i][j] = 0;
            }
            visited[i] = 0;
        }

        // Lecture des arêtes
        for (int i = 0; i < m; i++)
        {
            int u, v;
            fscanf(inputFile, "%d %d", &u, &v);
            adj[u - 1][v - 1] = 1; // Arête du sommet u au sommet v
        }

        // Vérifier les cycles pour chaque sommet
        int hasCycle = 0;
        for (int i = 0; i < n; i++)
        {
            if (visited[i] == 0 && dfs(i))
            {
                hasCycle = 1;
                break;
            }
        }

        // Lire la sortie attendue
        char expectedOutput[10];
        fscanf(expectedFile, "%s", expectedOutput);

        // Afficher le résultat du test
        if ((hasCycle && strcmp(expectedOutput, "YES") == 0) || (!hasCycle && strcmp(expectedOutput, "NO") == 0))
        {
            printf("Test Case %d: OK\n", testCase);
        }
        else
        {
            printf("Test Case %d: Mismatch - Expected: %s, Got: %s\n", testCase, expectedOutput, hasCycle ? "YES" : "NO");
        }

        testCase++;
    }

    fclose(inputFile);
    fclose(expectedFile);

    return 0;
}
