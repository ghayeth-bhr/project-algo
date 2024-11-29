#include <stdio.h>
#include <stdlib.h>

#define MAX_N 10000
#define MAX_M 100000

// Liste d'adjacence
int adj[MAX_N][MAX_N]; // Graph representation (Adjacency Matrix)
int visited[MAX_N];    // Tableau de visites
int n, m;              // Nombre de sommets et arêtes

// Fonction DFS pour détecter un cycle
int dfs(int u)
{
    // Si le sommet est en cours de visite, un cycle est trouvé
    if (visited[u] == 1)
    {
        return 1;
    }

    // Si le sommet est complètement visité, on retourne faux
    if (visited[u] == 2)
    {
        return 0;
    }

    // Marquer le sommet comme en cours de visite (1)
    visited[u] = 1;

    // Explorer tous les voisins
    for (int v = 0; v < n; v++)
    {
        if (adj[u][v] == 1)
        {
            if (dfs(v))
            {
                return 1;
            }
        }
    }

    // Marquer le sommet comme complètement visité (2)
    visited[u] = 2;
    return 0;
}

int main()
{
    // Lecture des entrées
    scanf("%d %d", &n, &m);

    // Initialiser la liste d'adjacence et les visites
    for (int i = 0; i < n; i++)
    {
        visited[i] = 0; // 0 = Non visité, 1 = En cours de visite, 2 = Complètement visité
        for (int j = 0; j < n; j++)
        {
            adj[i][j] = 0; // Pas d'arêtes initialement
        }
    }

    // Lecture des arêtes
    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u - 1][v - 1] = 1; // Convertir en indices 0-basés
    }

    // Vérifier chaque sommet
    for (int i = 0; i < n; i++)
    {
        if (visited[i] == 0)
        {
            if (dfs(i))
            {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}
