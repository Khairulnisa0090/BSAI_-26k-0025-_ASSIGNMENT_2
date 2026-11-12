// name:  khairulnisa
// roll#: 26K-0025
// department: BAI_1A
// subject task: Programming Fundamnetals theory assignment_2
//Question3.c

#include <stdio.h>

void inputReadings(int sensors, int hours, float temp[sensors][hours])
{
	int i;
    for (i = 0; i < sensors; i++)
    {
        printf("\nEnter readings for Sensor %d:\n", i + 1);
         int j;
        for (j = 0; j < hours; j++)
        {
            printf("Hour %d: ", j + 1);
            scanf("%f", &temp[i][j]);
        }
    }
}

void analyzeSensor(float readings[], int hours)
{
    float total = 0;
    float highest = readings[0];
    float lowest = readings[0];

    int critical = 0;
    int warning = 0;
    int currentStreak = 0;
    int longestStreak = 0;
  int i;
    for ( i = 0; i < hours; i++)
    {
        total += readings[i];

        if (readings[i] > highest)
            highest = readings[i];

        if (readings[i] < lowest)
            lowest = readings[i];

        if (readings[i] >= 40)
            critical++;

        if (readings[i] >= 35 && readings[i] <= 39)
            warning++;

        if (readings[i] >= 35)
        {
            currentStreak++;

            if (currentStreak > longestStreak)
                longestStreak = currentStreak;
        }
        else
        {
            currentStreak = 0;
        }
    }

    float average = total / hours;

    printf("\nTotal Temperature: %.2f\n", total);
    printf("Average Temperature: %.2f\n", average);
    printf("Highest Temperature: %.2f\n", highest);
    printf("Lowest Temperature: %.2f\n", lowest);
    printf("Critical Readings: %d\n", critical);
    printf("Warning Readings: %d\n", warning);
    printf("Longest Streak: %d hours\n", longestStreak);
}

int findHighestAverage(int sensors, int hours,
                       float temp[sensors][hours])
{
    float highestAverage = 0;
    int highestSensor = 0;
         int i;
    for ( i = 0; i < sensors; i++)
    {
        float total = 0;
int j;
        for ( j = 0; j < hours; j++)
            total += temp[i][j];

        float average = total / hours;

        if (i == 0 || average > highestAverage)
        {
            highestAverage = average;
            highestSensor = i;
        }
    }

    return highestSensor;
}

int main()
{
    int sensors, hours;

    printf("Enter number of sensors: ");
    scanf("%d", &sensors);

    printf("Enter number of hourly readings: ");
    scanf("%d", &hours);

    if (sensors <= 0 || hours <= 0)
    {
        printf("Invalid input.\n");
        return 0;
    }

    float temp[sensors][hours];

    inputReadings(sensors, hours, temp);
int i;
    for ( i = 0; i < sensors; i++)
    {
        printf("\n===== Sensor %d Report =====\n", i + 1);
        analyzeSensor(temp[i], hours);
    }

    int highestSensor = findHighestAverage(sensors, hours, temp);

    float total = 0;
int j;
    for ( j = 0; j < hours; j++)
        total += temp[highestSensor][j];

    printf("\nSensor with Highest Average: %d\n", highestSensor + 1);
    printf("Highest Average: %.2f\n", total / hours);

    return 0;
}

