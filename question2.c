// name:  khairulnisa
// roll#: 26K-0025
// department: BAI_1A
// subject task: Programming Fundamnetals theory assignment_2
//Question1_c Code



#include <stdio.h>

// Function to calculate sum of proper divisors
int sumProperDivisors(int number)
{
    int sum = 0;
   int i;
    for ( i = 1; i <= number / 2; i++)
    {
        if (number % i == 0)
        {
            sum += i;
        }
    }

    return sum;
}

int main()
{
    int n;
    int pairCount = 0;

    printf("Enter the upper limit: ");
    scanf("%d", &n);
      int first;
    for ( first = 1; first <= n; first++)
    {
        int second = sumProperDivisors(first);

        if (second > first && second <= n)
        {
            int reverseSum = sumProperDivisors(second);

            if (reverseSum == first)
            {
                printf("Amicable pair: (%d, %d)\n", first, second);
                pairCount++;
            }
        }
    }

    if (pairCount == 0)
        printf("No amicable pairs found.\n");
    else
        printf("Total pairs found: %d\n", pairCount);

    return 0;
}

