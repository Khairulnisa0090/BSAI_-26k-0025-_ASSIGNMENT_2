// name:  khairulnisa
// roll#: 26K-0025
// department: BAI_1A
// subject task: Programming Fundamnetals theory assignment_2
// question 4: Bakery Festival Sales Management System


#include <stdio.h>

int getValidDays()
{
    int days;

    do
    {
        printf("Enter number of festival days (1-7): ");
        scanf("%d", &days);

        if (days < 1 || days > 7)
        {
            printf("Invalid days. Please enter 1 to 7.\n");
        }

    } while (days < 1 || days > 7);

    return days;
}

float calculateDailySales(int dayNumber)
{
    int orders;
    int i;

    float amount;
    float total = 0;
    float highest = 0;
    float average;

    printf("\nDay %d - Number of orders: ", dayNumber);
    scanf("%d", &orders);

    while (orders < 1)
    {
        printf("Number of orders must be at least 1: ");
        scanf("%d", &orders);
    }

    for (i = 1; i <= orders; i++)
    {
        do
        {
            printf("Enter amount of order %d: ", i);
            scanf("%f", &amount);

            if (amount <= 0)
            {
                printf("Amount must be greater than zero.\n");
            }

        } while (amount <= 0);

        total = total + amount;

        if (i == 1 || amount > highest)
        {
            highest = amount;
        }
    }

    average = total / orders;

    printf("\nDay %d Sales Report:\n", dayNumber);
    printf("Total Sales: Rs. %.2f\n", total);
    printf("Average Order: Rs. %.2f\n", average);
    printf("Highest Order: Rs. %.2f\n", highest);

    return total;
}

int findHighestSalesDay(float dailySales[], int numberOfDays)
{
    int i;
    int highestDay = 1;

    for (i = 1; i < numberOfDays; i++)
    {
        if (dailySales[i] > dailySales[highestDay - 1])
        {
            highestDay = i + 1;
        }
    }

    return highestDay;
}

void displayBarChart(float dailySales[], int numberOfDays)
{
    int i, j;
    int stars;

    printf("\n===== DAILY SALES BAR CHART =====\n");

    for (i = 0; i < numberOfDays; i++)
    {
        stars = (int)(dailySales[i] / 100);

        printf("Day %d: ", i + 1);

        for (j = 0; j < stars; j++)
        {
            printf("*");
        }

        printf("\n");
    }
}

int main()
{
    int days;
    int i;
    int highestDay;

    float dailySales[7];
    float festivalTotal = 0;

    days = getValidDays();

    for (i = 0; i < days; i++)
    {
        dailySales[i] = calculateDailySales(i + 1);

        festivalTotal = festivalTotal + dailySales[i];
    }

    highestDay = findHighestSalesDay(dailySales, days);

    printf("\n===== FESTIVAL SUMMARY =====\n");
    printf("Total Festival Sales: Rs. %.2f\n", festivalTotal);
    printf("Day with Highest Sales: Day %d\n", highestDay);

    displayBarChart(dailySales, days);

    return 0;
}

