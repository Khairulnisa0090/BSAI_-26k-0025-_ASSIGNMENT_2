// name:  khairulnisa
// roll#: 26K-0025
// department: BAI_1A
// subject task: Programming Fundamnetals theory assignment_2

#include <stdio.h>

int main()
{
    int rows, seats;

    printf("Enter number of rows: ");
    scanf("%d", &rows);

    printf("Enter seats per row: ");
    scanf("%d", &seats);

    int hall[rows][seats];

    int i, j;
    int totalAvailable = 0;

    // Input seating arrangement
    printf("\nEnter seat status (0 = Available, 1 = Booked):\n");

    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < seats; j++)
        {
            do
            {
                printf("Row %d, Seat %d: ", i, j);
                scanf("%d", &hall[i][j]);

                if (hall[i][j] != 0 && hall[i][j] != 1)
                    printf("Enter only 0 or 1.\n");

            } while (hall[i][j] != 0 && hall[i][j] != 1);
        }
    }

    // Display seating arrangement
    printf("\nSeating Arrangement:\n");
    printf("     ");

    for (j = 0; j < seats; j++)
        printf("%d ", j);

    printf("\n");

    for (i = 0; i < rows; i++)
    {
        printf("Row %d ", i);

        for (j = 0; j < seats; j++)
        {
            if (hall[i][j] == 0)
                printf("_ ");
            else
                printf("X ");
        }

        printf("\n");
    }

    // Available seats in each row
    printf("\nAvailable Seats Report:\n");

    for (i = 0; i < rows; i++)
    {
        int rowAvailable = 0;

        for (j = 0; j < seats; j++)
        {
            if (hall[i][j] == 0)
                rowAvailable++;
        }

        printf("Row %d: %d available seats\n", i, rowAvailable);
        totalAvailable += rowAvailable;
    }

    printf("Total available seats: %d\n", totalAvailable);

    // Input group size
    int k;

    printf("\nEnter number of customers: ");
    scanf("%d", &k);

    if (k <= 0 || k > seats)
    {
        printf("Invalid group size.\n");
        return 0;
    }

    // Search from middle row outwards
    int middle = rows / 2;
    int found = 0;
    int bookedRow = -1;
    int startSeat = -1;
int distance;
    for ( distance = 0; distance < rows && found == 0; distance++)
    {
        // Check smaller row number first
        int row1 = middle - distance;

        if (row1 >= 0)
        {
            int count = 0;

            for (j = 0; j < seats; j++)
            {
                if (hall[row1][j] == 0)
                    count++;
                else
                    count = 0;

                if (count == k)
                {
                    bookedRow = row1;
                    startSeat = j - k + 1;
                    found = 1;
                    break;
                }
            }
        }

        // Check larger row number
        if (distance > 0 && found == 0)
        {
            int row2 = middle + distance;

            if (row2 < rows)
            {
                int count = 0;

                for (j = 0; j < seats; j++)
                {
                    if (hall[row2][j] == 0)
                        count++;
                    else
                        count = 0;

                    if (count == k)
                    {
                        bookedRow = row2;
                        startSeat = j - k + 1;
                        found = 1;
                        break;
                    }
                }
            }
        }
    }

    // Confirm booking
    if (found == 1)
    {
        printf("\nBooking successful!\n");
        printf("Allocated row: %d\n", bookedRow);
        printf("Allocated seats: ");

        for (j = startSeat; j < startSeat + k; j++)
        {
            hall[bookedRow][j] = 1;
            printf("%d ", j);
        }

        // Display updated arrangement
        printf("\n\nUpdated Seating Arrangement:\n");

        for (i = 0; i < rows; i++)
        {
            printf("Row %d ", i);

            for (j = 0; j < seats; j++)
            {
                if (hall[i][j] == 0)
                    printf("_ ");
                else
                    printf("X ");
            }

            printf("\n");
        }

        totalAvailable -= k;

        printf("Remaining available seats: %d\n", totalAvailable);
    }
    else
    {
        printf("\nSorry! No consecutive seats are available.\n");
        printf("Seating plan remains unchanged.\n");
    }

    return 0;
}

