#include <stdio.h>

int calculate(int year, int month, int day, int Century[]);
void finalDay(int remainder);
int main(){

    int year, month, day, dayOfTheWeek;
    int Century20th[] = {1,4,4,0,2,5,0,3,6,1,4,6};
    int Century21st[] = {0,3,3,6,1,4,6,2,5,0,3,5};
    int remainder;
    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the number of the month: ");
    scanf("%d", &month);
    printf("Enter the day: ");
    scanf("%d", &day);

    if(year >= 2001 && year <= 2100){
        year = year - 2000;
        remainder = calculate(year, month, day, Century21st);
    } else if(year >= 1901 && year <= 2000){
        year = year - 1900;
        remainder = calculate(year, month, day, Century20th);
    }else{
        printf("The year you entered is not in the range of accepted values(20th and 21st century)");
    }
    
    finalDay(remainder);

    return 0;
}
int calculate(int year, int month, int day, int Century[]){
    int sum;
    sum = year;

    year = year / 4;
    sum += year;
    sum += Century[month-1];
    sum+= day;

    sum = sum % 7;

    return sum;
}
void finalDay(int remainder){
    switch (remainder){
        case 0:
            printf("The day for the date provided is Saturday!");
            break;
        case 1:
            printf("The day for the date provided is Sunday!");
            break;
        case 2:
            printf("The day for the date provided is Monday!");
            break;
        case 3:
            printf("The day for the date provided is Tuesday!");
            break;
        case 4:
            printf("The day for the date provided is Wednesday!");
            break;
        case 5:
            printf("The day for the date provided is Thursday!");
            break;
        case 6:
            printf("The day for the date provided is Friday!");
            break;
        default:
            printf("There was an error along the way.");
            break;
    }
}
