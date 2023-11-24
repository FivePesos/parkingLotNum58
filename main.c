#include <stdio.h>
#include <ctype.h>

void userInput(char *vehicleType, int *hourEntered, int *minuteEntered, int *hourLeft, int *minuteLeft);
void typeOfVehicle(char vehicleType);
void timeInTimeOut(int hourEntered, int minuteEntered, int hourLeft, int minuteLeft);
void calculations(int hourEntered, int minuteEntered, int hourLeft, int minuteLeft, char vehicleType);

int main()
{
    char vehicleType;
    int hourEntered, minuteEntered, hourLeft, minuteLeft;

    userInput(&vehicleType, &hourEntered, &minuteEntered, &hourLeft, &minuteLeft);
    timeInTimeOut(hourEntered,minuteEntered,hourLeft,minuteLeft);
    typeOfVehicle(vehicleType);
    calculations(hourEntered, minuteEntered, hourLeft, hourEntered, vehicleType);
    return 0;
}

void userInput(char *vehicleType, int *hourEntered, int *minuteEntered, int *hourLeft, int *minuteLeft){
    printf("Type of vehicle? ");
    scanf("%c", vehicleType);
    printf("Hour vehicle entered lot\t(0 - 24)? ");
    scanf("%d", hourEntered);
    printf("Minute vehicle entered lot\t(0 - 60)? ");
    scanf("%d", minuteEntered);
    printf("Hour vehicle left lot\t\t(0 - 24)? ");
    scanf("%d", hourLeft);
    printf("Minute vehicle left lot\t\t(0 - 60)? ");
    scanf("%d", minuteLeft);
}

void timeInTimeOut(int hourEntered, int minuteEntered, int hourLeft, int minuteLeft){
    printf("\t\tPARKING LOT CHARGE\t\n");
    printf("\tTIME-IN\t\t\t\t%d:%d\n",hourEntered,minuteEntered);
    printf("\tTIME-OUT\t\t\t%d:%d\n",hourLeft, minuteLeft);
    printf("\t---------\n");
}

void typeOfVehicle(char vehicleType){

    char type = toupper(vehicleType);

    switch(type){
        case 'C':
            printf("\n\tType of vehicle: Car\n");
            break;
        case 'B':
            printf("\n\tType of vehicle: Bus\n");
            break;

        case 'T':
            printf("\n\tType of vehicle: Truck\n");
            break;

        default:
            printf("Invalid.\n");
            break;
    }
}

void calculations(int hourEntered, int minuteEntered, int hourLeft, int minuteLeft, char vehicleType){
    int minute;
    int hour;
    int rate;
    double totalCharge;
    char type = toupper(vehicleType);

    if(minuteLeft < minuteEntered){
        minuteLeft += 60;
        hourLeft--;
    }

    hour = hourLeft - hourEntered;
    minute = minuteLeft - minuteEntered;

    if(minute > 0){
        hour++;
    }

    printf("\tPARKING TIME\t\t\t%d:%d\n",hour, minute);
    printf("\tROUNDED TOTAL\t\t\t%d\n", hour);

    switch(type){
        case 'C':
            if (hour <= 3) {
                rate = 0;
            } else {
                rate = 1.50;
            }
            break;
        case 'B':
             if (hour <= 1) {
                rate = 2;
            } else {
                rate = 3.70;
            }
            break;

        case 'T':
            if (hour <= 2) {
                rate = 1.00;
            } else {
                rate = 2.30;
            }
            break;

        default:
            printf("Invalid.\n");
            break;
    }
    totalCharge = hour * rate;
    printf("\t\t\t\t----------\n");
    printf("\tTOTAL CHARGE\t\t\t%.2lf\n",totalCharge);
}

