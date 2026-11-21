#include <stdio.h>

int main()
{
    int year, days, startDay;
    int month, i, j;
    int monthDays[] = {31, 28, 31, 30, 31, 30,
                       31, 31, 30, 31, 30, 31};

    char *months[] = {"January", "February", "March",
                      "April", "May", "June",
                      "July", "August", "September",
                      "October", "November", "December"};

    printf("Enter year: ");
    scanf("%d", &year);

    if((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
        monthDays[1] = 29;

    startDay = (year - 1 + (year - 1)/4 -
                (year - 1)/100 + (year - 1)/400) % 7;

    for(month = 0; month < 12; month++)
    {
        printf("\n\n       %s %d\n", months[month], year);
        printf(" Sun Mon Tue Wed Thu Fri Sat\n");

        for(i = 0; i < startDay; i++)
            printf("    ");

        days = monthDays[month];

        for(j = 1; j <= days; j++)
        {
            printf("%4d", j);
            startDay++;

            if(startDay == 7)
            {
                startDay = 0;
                printf("\n");
            }
        }
    }

    return 0;
}
