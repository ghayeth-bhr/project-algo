#include <stdio.h>

int main()
{
    FILE *inputFile, *expectedFile;
    int e, i, j, inc, expectedOutput, actualOutput;
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
    while (fscanf(inputFile, "%d", &e) == 1)
    {
        if (fscanf(expectedFile, "%d", &expectedOutput) != 1)
        {
            printf("Error: Mismatch in number of test cases between input.txt and expected.txt.\n");
            break;
        }

        if (e > 1000000)
        {
            printf("Erreur : %d out of range\n", e);
            continue; // Skip this test case and continue with the next one
        }

        int te[e];
        for (i = 0; i < e; i++)
        {
            fscanf(inputFile, "%d", &te[i]);
            if ((te[i] > 10) && (te[i] != -1)) // Check for invalid event numbers
            {
                printf("Evenement %d non disponible\n", te[i]);
                continue; // Skip the invalid event and go to the next test case
            }
        }

        // Find the first non -1 element
        inc = 0;
        while (inc < e && te[inc] == -1) // Ensure that we find the first non -1 element
        {
            inc++;
        }

        // Handle special cases for all events being -1
        if (inc == e || inc == e - 1) // If all events are -1
        {
            actualOutput = inc;
        }
        else
        {
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

            // Count the number of -1 elements remaining
            int count = 0;
            for (i = 0; i < e; i++)
            {
                if (te[i] == -1)
                {
                    count++;
                }
            }
            actualOutput = count;
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
    }

    // Close the files
    fclose(inputFile);
    fclose(expectedFile);
    return 0;
}
