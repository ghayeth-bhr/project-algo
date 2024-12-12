#include <stdio.h>
#include <math.h>
#include <stdlib.h>

// Function to find the smallest divisor greater than 1
int smallest_divisor(int n)
{
    if (n <= 1)
        return -1; // No valid divisors
    if (n % 2 == 0)
        return 2; // Fast check for even numbers
    for (int i = 3; i * i <= n; i += 2)
    {
        if (n % i == 0)
        {
            return i;
        }
    }
    return n; // If no divisor found, n is prime
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
    FILE *inputFile, *expectedFile;
    long long l, r;
    int caseNumber = 1;
    int actualOutput[1000], expectedOutput[1000];
    int count = 0;

    // Open the input and expected files
    inputFile = fopen("input.txt", "r");
    expectedFile = fopen("expected.txt", "r");
    if (inputFile == NULL || expectedFile == NULL)
    {
        printf("Error: Unable to open input or expected file.\n");
        return 1;
    }

    // Process each test case
    while (fscanf(inputFile, "%lld %lld", &l, &r) == 2)
    {
        if (fscanf(expectedFile, "%d", &expectedOutput[count]) != 1)
        {
            printf("Error: Mismatch in number of test cases between input.txt and expected.txt.\n");
            break;
        }

        // Compute the actual output
        if (l == r)
        {
            actualOutput[count] = smallest_divisor(l);
        }
        else
        {
            if (l % 2 == 0 || r % 2 == 0)
            {
                actualOutput[count] = 2; // If one of the numbers is even, the smallest divisor is 2
            }
            else
            {
                actualOutput[count] = 2; // Smallest divisor > 1 in odd ranges is 2
            }
        }

        count++;
        caseNumber++;
    }

    // Compare outputs
    compareOutputs(actualOutput, expectedOutput, count);

    // Close the files
    fclose(inputFile);
    fclose(expectedFile);
    return 0;
}
