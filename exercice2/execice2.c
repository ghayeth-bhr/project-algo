#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void compareOutputs(int actual[], int expected[], int count)
{
    for (int i = 0; i < count; i++)
    {
        if (actual[i] == expected[i])
        {
            printf("Test Case %d: OK\n", i + 1);
        }
        else
        {
            printf("Test Case %d: Mismatch - Expected: %d, Got: %d\n", i + 1, expected[i], actual[i]);
        }
    }
}

int main()
{
    FILE *inputFile = fopen("input.txt", "r");
    FILE *expectedFile = fopen("expected.txt", "r");
    if (inputFile == NULL || expectedFile == NULL)
    {
        printf("Could not open input or expected file\n");
        return 1;
    }

    char line[1000];
    int actualOutputs[1000];
    int expectedOutputs[1000];
    int count = 0;

    while (fgets(line, sizeof(line), inputFile))
    {
        int n, k;
        sscanf(line, "%d %d", &n, &k);

        int a[n];
        fgets(line, sizeof(line), inputFile);
        char *token = strtok(line, " ");
        for (int i = 0; i < n; i++)
        {
            a[i] = atoi(token);
            token = strtok(NULL, " ");
        }

        int result = max_subarray_sum_with_limit(n, k, a);
        actualOutputs[count] = result;
        count++;
    }

    count = 0;
    while (fgets(line, sizeof(line), expectedFile))
    {
        expectedOutputs[count] = atoi(line);
        count++;
    }

    compareOutputs(actualOutputs, expectedOutputs, count);

    fclose(inputFile);
    fclose(expectedFile);
    return 0;
}
