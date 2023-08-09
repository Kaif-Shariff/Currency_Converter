#include <stdio.h>
#include <windows.h>
#include <conio.h>

char c1[15] = "BJP", c2[15] = "AAP", c3[15] = "SHIVSENA", c4[15] = "CONGRESS";

int choice, votesCount1 = 0, votesCount2 = 0, votesCount3 = 0, votesCount4 = 0, spoiledtvotes = 0, age;

void ageValidation();
void mainMenu();
void shortmenu();
void castVote();
int votesCount();
int getWinnerCandidate();

int main()
{
    mainMenu();

    return 0;
}
void mainMenu()
{
    system("cls");

    ageValidation();

    system("cls");

    printf("\n***************************************************************************");
    printf("\n************                                                   ************ ");
    printf("\n************                 VOTING SYSTEM                     ************ ");
    printf("\n************                                                   ************ ");
    printf("\n***************************************************************************\n\n");

    if (age >= 18)
    {
        printf("\n1.Cast Vote");
        printf("\t\t\t\t2.Find Vote Count\n");
        printf("\n3.Find Leading Candidate");
        printf("\t\t4.Exit\n\n");

    start:
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            castVote();
            shortmenu();
            break;

        case 2:
            votesCount();
            getch();
            break;

        case 3:
            getWinnerCandidate();
            getch();
            break;
        default:
            if (choice == 4)
            {
                printf("\nThanks for Your Time ");
            }
            else
            {
                printf("\n\nIncorrect response\nPlease try again !!\n");
                goto start;
                getch();
            }
        }
    }
    else
    {
        printf("\nYou're not eligible to vote\n");
    }
}

void ageValidation()
{
    int day, month, year, cYear = 2022;

    printf("\n***************************************************************************");
    printf("\n************                                                   ************ ");
    printf("\n************                   Verify Your Age                 ************ ");
    printf("\n************                                                   ************ ");
    printf("\n***************************************************************************\n\n");

    printf("\nVerify Date of birth\n");

    do
    {
        printf("\nEnter day: ");
        scanf(" %d", &day);
    } while (day > 31 || day < 1);

    do
    {
        printf("\nEnter month: ");
        scanf("%d", &month);

    } while (month > 12 || month < 1);

    printf("\nEnter year: ");
    scanf("%d", &year);

    age = cYear - year;
}

void shortmenu()
{
    system("cls");
    int choice;
    printf("\n***************************************************************************");
    printf("\n************                                                   ************ ");
    printf("\n************                 VOTING SYSTEM                     ************ ");
    printf("\n************                                                   ************ ");
    printf("\n***************************************************************************\n\n");

    printf("\n1.Find Vote Count");
    printf("\n2.Find Leading Candidate");
    printf("\n3.Go to Main menu");
    printf("\n4.Exit");

    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        votesCount();
        getch();
        break;

    case 2:
        getWinnerCandidate();
        getch();
        break;
    case 3:
        mainMenu();
        getch();
        break;
    default:
        if (choice == 4)
        {
            printf("\nThanks for Your Time ");
        }
        else
        {
            printf("\n\nIncorrect Response\nPlease try again\n");
            getch();
        }
    }
}
void castVote()
{
    system("cls");
    int choice;

    FILE *fp1 = fopen("Vote.txt", "a");
    printf("\n***************************************************************************");
    printf("\n************                                                   ************ ");
    printf("\n************                    CAST VOTE                      ************ ");
    printf("\n************                                                   ************ ");
    printf("\n***************************************************************************\n\n");

    printf("\n1. %s ", c1);
    printf("\t\t\t2. %s\n ", c2);
    printf("\n3. %s ", c3);
    printf("\t\t4. %s\n", c4);
    printf("\n\t5. %s", "None of These");

    printf("\n\nInput your choice (1 - 5) : ");
    scanf(" %d", &choice);

    switch (choice)
    {
    case 1:
        votesCount1++;
        break;
    case 2:
        votesCount2++;
        break;
    case 3:
        votesCount3++;
        break;
    case 4:
        votesCount4++;
        break;
    case 5:
        spoiledtvotes++;
        break;
    default:
        printf("\n Error: Wrong Choice !! Please retry");
    }

    printf("\nYour vote has been recorded!\n");
    fprintf(fp1, "%s = %d | %s = %d | %s = %d | %s = %d | Spoiled Votes = %d\n", c1, votesCount1, c2, votesCount2, c3, votesCount3, c4, votesCount4, spoiledtvotes);
    fclose(fp1);
    choice = 0;
}

int votesCount()
{
    system("cls");
    char ans;

    printf("\n***************************************************************************");
    printf("\n************                                                   ************ ");
    printf("\n************                    VOTE COUNTS                    ************ ");
    printf("\n************                                                   ************ ");
    printf("\n***************************************************************************\n\n");

    printf("\n %s - %d ", c1, votesCount1);
    printf("\n %s - %d ", c2, votesCount2);
    printf("\n %s - %d ", c3, votesCount3);
    printf("\n %s - %d ", c4, votesCount4);
    printf("\n %s - %d \n", "Spoiled Votes", spoiledtvotes);

B:
    printf("\nWould you like to go back (Y/N) -> ");
    scanf(" %c", &ans);

    if (ans == 'Y' || ans == 'y')
    {
        shortmenu();
    }
    else if (ans == 'N' || ans == 'n')
    {
        return 0;
    }
    else
    {
        printf("\nPlease try again!\n");
        goto B;
    }
}

int getWinnerCandidate()
{
    system("cls");
    char answer;
    printf("\n***************************************************************************");
    printf("\n************                                                   ************ ");
    printf("\n************                 Winning Candidate                 ************ ");
    printf("\n************                                                   ************ ");
    printf("\n***************************************************************************\n\n");

    if (votesCount1 > votesCount2 && votesCount1 > votesCount3 && votesCount1 > votesCount4)

    {
        printf("\n***************************************************************************");
        printf("\n************                                                   ************ ");
        printf("\n************                       %s                         ************", c1);
        printf("\n************                                                   ************ ");
        printf("\n***************************************************************************\n\n");
    }
    else if (votesCount2 > votesCount3 && votesCount2 > votesCount4 && votesCount2 > votesCount1)

    {
        printf("\n***************************************************************************");
        printf("\n************                                                   ************ ");
        printf("\n************                       %s                         ************", c2);
        printf("\n************                                                   ************ ");
        printf("\n***************************************************************************\n\n");
    }

    else if (votesCount3 > votesCount4 && votesCount3 > votesCount2 && votesCount3 > votesCount1)

    {
        printf("\n***************************************************************************");
        printf("\n************                                                   ************ ");
        printf("\n************                       %s                    ************", c3);
        printf("\n************                                                   ************ ");
        printf("\n***************************************************************************\n\n");
    }
    else if (votesCount4 > votesCount1 && votesCount4 > votesCount2 && votesCount4 > votesCount3)

    {
        printf("\n***************************************************************************");
        printf("\n************                                                   ************ ");
        printf("\n************                       %s                    ************", c4);
        printf("\n************                                                   ************ ");
        printf("\n***************************************************************************\n\n");
    }
    else
    {
        printf("\n***************************************************************************");
        printf("\n************                                                   ************ ");
        printf("\n************                      No Winner                    ************");
        printf("\n************                                                   ************ ");
        printf("\n***************************************************************************\n\n");
    }

A:
    printf("\nWould you like to go back (Y/N) -> ");
    scanf(" %c", &answer);

    if (answer == 'Y' || answer == 'y')
    {
        shortmenu();
    }
    else if (answer == 'N' || answer == 'n')
    {
        return 0;
    }
    else
    {
        printf("\nPlease try again!\n");
        goto A;
    }
}
