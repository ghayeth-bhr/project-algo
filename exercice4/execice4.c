#include <stdio.h>

int main()
{
    FILE *inputFile, *expectedFile;
    int c, i, j, max, min, inc = 1, expectedOutput, actualOutput;
    int caseNumber = 1;

    // Open the input and expected files
    inputFile = fopen("input.txt", "r");
    expectedFile = fopen("expected.txt", "r");
    if (inputFile == NULL || expectedFile == NULL)
    {
        printf("Error: Unable to open input or expected file.\n");
        return 1;
    }

    // Process each test case
    while (fscanf(inputFile, "%d", &c) == 1)
    {
        if (fscanf(expectedFile, "%d", &expectedOutput) != 1)
        {
            printf("Error: Mismatch in number of test cases between input.txt and expected.txt.\n");
            break;
        }

        // Check for valid number of contests
        if ((c < 1) || (c > 1000))
        {
            printf("erreur : %d out of range\n", c);
            return 0;
        }

        int ts[c];
        for (i = 0; i < c; i++)
        {
            fscanf(inputFile, "%d", &ts[i]);
            if (ts[i] > 10000)
            {
                printf("score : %d out of range\n", ts[i]);
                return 0;
            }
        }

        max = ts[0];
        min = ts[0];

        if (c == 1)
        {
            actualOutput = 0;
        }
        else if (c == 2)
        {
            actualOutput = 1;
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
                    }
                    if (ts[j] > max)
                    {
                        max = ts[j];
                    }
                }
                if (ts[i] < min || ts[i] > max)
                {
                    inc++;
                }
            }
            actualOutput = inc;
        }

        // Compare the actual output with the expected output
        if (actualOutput == expectedOutput)
        {
            printf("Case %d matched\n", caseNumber);
        }
        else
        {
            printf("Case %d mismatched (Expected: %d, Got: %d)\n", caseNumber, expectedOutput, actualOutput);
        }

        caseNumber++;
        inc = 1; // Reset incrementer for next case
    }

    // Close the files
    fclose(inputFile);
    fclose(expectedFile);
    return 0;
}
