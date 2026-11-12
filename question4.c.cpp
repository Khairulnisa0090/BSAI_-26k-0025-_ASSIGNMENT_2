// name:  khairulnisa
// roll#: 26K-0025
// department: BAI_1A
// subject task: Programming Fundamnetals theory assignment_2
//Question3.c


#include <stdio.h>

int getValidDays()
{
    int days;

    do
    {
        printf("Enter festival days (1 to 7): ");
        scanf("%d", &days);

        if (days < 1 || days > 7)
            printf("Invalid days. Try again.\n");

    } while (days < 1 || days > 7);

    return days;
}

float calculateDailySales(int dayNumber)
{
    int orders;
    float amount;
    float total = 0;
    float highest = 0;

    printf("\nDay %d - Number of orders: ", dayNumber);
    scanf("%d", &orders);

    while (orders < 1)
    {
        printf("Enter at least one order: ");
        scanf("%d", &orders);
    }

    for (int i = 1; i <= orders; i++)
    {
        do
        {
            printf("Enter amount for order %d: ", i);
            scanf("%f", &amount);

            if (amount <= 0)
                printf("Amount must be greater than zero.\n");

        } while (amount <= 0);

        total += amount;

        if (i == 1 || amount > highest)
            highest = amount;
    }

    printf("Total sales: Rs. %.2f\n", total);
    printf("Average order: Rs. %.2f\n", total / orders);
    printf("Highest order: Rs. %.2f\n", highest);

    return total;
}

int findHighestSalesDay(float dailySales[], int numberOfDays)
{
    int highestDay = 1;

    for (int i = 1; i < numberOfDays; i++)
    {
        if (dailySales[i] > dailySales[highestDay - 1])
            highestDay = i + 1;
    }

    return highestDay;
}

void displayBarChart(float dailySales[], int numberOfDays)
{
    printf("\n===== DAILY SALES BAR CHART =====\n");

    for (int i = 0; i < numberOfDays; i++)
    {
        int stars = (int)(dailySales[i] / 100);

        printf("Day %d: ", i + 1);

        for (int j = 0; j < stars; j++)
            printf("*");

        printf("\n");
    }
}

int main()
{
    int days;
    float dailySales[7];
    float festivalTotal = 0;

    days = getValidDays();

    for (int i = 0; i < days; i++)
    {
        dailySales[i] = calculateDailySales(i + 1);
        festivalTotal += dailySales[i];
    }

    int highestDay = findHighestSalesDay(dailySales, days);

    printf("\n===== FESTIVAL SUMMARY =====\n");
    printf("Total Festival Sales: Rs. %.2f\n", festivalTotal);
    printf("Highest Sales Day: Day %d\n", highestDay);

    displayBarChart(dailySales, days);

    return 0;
}

