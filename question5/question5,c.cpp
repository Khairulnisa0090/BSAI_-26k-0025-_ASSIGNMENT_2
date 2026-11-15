// name:  khairulnisa
// roll#: 26K-0025
// department: BAI_1A
// subject task: Programming Fundamnetals theory assignment_2
// question 5.c


#include <stdio.h>
#include <string.h>

void displayMenu()
{
    printf("\n===== LIBRARY MANAGEMENT SYSTEM =====\n");
    printf("1. Register Member\n");
    printf("2. Display Available Books\n");
    printf("3. Borrow a Book\n");
    printf("4. Return a Book\n");
    printf("5. Display Member Record\n");
    printf("6. Exit\n");
    printf("Enter your choice: ");
}

void registerMember(char name[], int *studentID, int *memberType)
{
    int type;

    printf("Enter member name: ");
    scanf(" %49[^\n]", name);

    printf("Enter student ID: ");
    scanf("%d", studentID);

    do
    {
        printf("Enter membership type (1=Student, 2=Faculty): ");
        scanf("%d", &type);

        if (type != 1 && type != 2)
        {
            printf("Invalid membership type.\n");
        }

    } while (type != 1 && type != 2);

    *memberType = type;

    printf("Registration successful!\n");
}

void displayBooks(int bookIDs[], char bookTitles[][50],
                  int availableCopies[], int totalBooks)
{
    int i;

    printf("\nBook ID\tBook Title\t\tAvailable Copies\n");

    for (i = 0; i < totalBooks; i++)
    {
        printf("%d\t%-25s\t%d\n",
               bookIDs[i], bookTitles[i], availableCopies[i]);
    }
}

void borrowBook(int bookIDs[], char bookTitles[][50],
                int availableCopies[], int totalBooks,
                int borrowedBookIDs[], int *borrowedCount,
                int memberType)
{
    int id, days;
    int index = -1;
    int i;
    int allowedDays;

    if (*borrowedCount >= 3)
    {
        printf("You cannot borrow more than 3 books.\n");
        return;
    }

    printf("Enter book ID: ");
    scanf("%d", &id);

    for (i = 0; i < totalBooks; i++)
    {
        if (bookIDs[i] == id)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
    {
        printf("Invalid book ID.\n");
        return;
    }

    if (availableCopies[index] <= 0)
    {
        printf("No copies available.\n");
        return;
    }

    printf("Enter number of days you want to keep the book: ");
    scanf("%d", &days);

    if (days <= 0)
    {
        printf("Number of days must be positive.\n");
        return;
    }

    if (memberType == 1)
        allowedDays = 14;
    else
        allowedDays = 30;

    if (days > allowedDays)
    {
        printf("Maximum allowed days are %d.\n", allowedDays);
        return;
    }

    borrowedBookIDs[*borrowedCount] = id;
    (*borrowedCount)++;

    availableCopies[index]--;

    printf("Book borrowed successfully!\n");
    printf("Book Name: %s\n", bookTitles[index]);
}

float returnBook(int bookIDs[], int availableCopies[],
                 int totalBooks, int borrowedBookIDs[],
                 int *borrowedCount, int memberType,
                 float *totalFine)
{
    int id, actualDays;
    int bookIndex = -1;
    int borrowedIndex = -1;
    int allowedDays;
    int lateDays;
    int i;

    float currentFine = 0;

    char code[30];

    printf("Enter book ID to return: ");
    scanf("%d", &id);

    /* Check borrowing record */
    for (i = 0; i < *borrowedCount; i++)
    {
        if (borrowedBookIDs[i] == id)
        {
            borrowedIndex = i;
            break;
        }
    }

    if (borrowedIndex == -1)
    {
        printf("You have not borrowed this book.\n");
        return 0;
    }

    /* Find book in inventory */
    for (i = 0; i < totalBooks; i++)
    {
        if (bookIDs[i] == id)
        {
            bookIndex = i;
            break;
        }
    }

    if (bookIndex == -1)
    {
        printf("Book record not found.\n");
        return 0;
    }

    printf("Enter actual number of days kept: ");
    scanf("%d", &actualDays);

    if (actualDays <= 0)
    {
        printf("Number of days must be positive.\n");
        return 0;
    }

    if (memberType == 1)
        allowedDays = 14;
    else
        allowedDays = 30;

    lateDays = actualDays - allowedDays;

    if (lateDays > 0)
    {
        if (memberType == 1)
            currentFine = lateDays * 20;
        else
            currentFine = lateDays * 10;
    }

    /* Fine before waiver */
    *totalFine = *totalFine + currentFine;

    /* Membership code and waiver */
    printf("Enter membership code (LIB2026 for 50%% waiver): ");
    scanf("%29s", code);

    if (strcmp(code, "LIB2026") == 0)
    {
        currentFine = currentFine * 0.50;
        printf("50%% waiver applied.\n");
    }
    else
    {
        printf("No waiver applied.\n");
    }

    /* Remove returned book from borrowed array */
    for (i = borrowedIndex; i < *borrowedCount - 1; i++)
    {
        borrowedBookIDs[i] = borrowedBookIDs[i + 1];
    }

    (*borrowedCount)--;

    /* Increase available copies */
    availableCopies[bookIndex]++;

    printf("Book returned successfully!\n");
    printf("Fine for this return: Rs. %.2f\n", currentFine);

    return currentFine;
}

void displayMemberRecord(char name[], int studentID,
                         int memberType, int borrowedBookIDs[],
                         int borrowedCount, float totalFine,
                         float fineAfterWaiver)
{
    int i;

    printf("\n===== MEMBER RECORD =====\n");

    printf("Name: %s\n", name);
    printf("Student ID: %d\n", studentID);

    if (memberType == 1)
        printf("Membership Type: Student\n");
    else
        printf("Membership Type: Faculty\n");

    printf("Currently Borrowed Books: ");

    if (borrowedCount == 0)
    {
        printf("None");
    }
    else
    {
        for (i = 0; i < borrowedCount; i++)
        {
            printf("%d ", borrowedBookIDs[i]);
        }
    }

    printf("\nTotal Fine Before Waiver: Rs. %.2f\n", totalFine);
    printf("Final Fine Payable: Rs. %.2f\n", fineAfterWaiver);
}

int main()
{
    int bookIDs[5] = {101, 102, 103, 104, 105};

    char bookTitles[5][50] = {
        "C Programming",
        "Mathematics",
        "Artificial Intelligence",
        "Physics",
        "English"
    };

    int availableCopies[5] = {3, 4, 2, 5, 3};

    int totalBooks = 5;

    char name[50] = "";

    int studentID = 0;
    int memberType = 0;

    int borrowedBookIDs[3];
    int borrowedCount = 0;

    int choice;
    int registered = 0;

    float totalFine = 0;
    float fineAfterWaiver = 0;
    float returnedFine;

    do
    {
        displayMenu();
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                registerMember(name, &studentID, &memberType);
                registered = 1;
                break;

            case 2:
                displayBooks(bookIDs, bookTitles,
                             availableCopies, totalBooks);
                break;

            case 3:
                if (registered == 1)
                {
                    borrowBook(bookIDs, bookTitles,
                               availableCopies, totalBooks,
                               borrowedBookIDs, &borrowedCount,
                               memberType);
                }
                else
                {
                    printf("Please register first.\n");
                }
                break;

            case 4:
                if (registered == 1)
                {
                    returnedFine = returnBook(
                        bookIDs, availableCopies, totalBooks,
                        borrowedBookIDs, &borrowedCount,
                        memberType, &totalFine
                    );

                    fineAfterWaiver =
                        fineAfterWaiver + returnedFine;
                }
                else
                {
                    printf("Please register first.\n");
                }
                break;

            case 5:
                if (registered == 1)
                {
                    displayMemberRecord(
                        name, studentID, memberType,
                        borrowedBookIDs, borrowedCount,
                        totalFine, fineAfterWaiver
                    );
                }
                else
                {
                    printf("Please register first.\n");
                }
                break;

            case 6:
                printf("Thank you for using the Library System.\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }

    } while (choice != 6);

    return 0;
}

