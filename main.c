#include <stdio.h>
#include <math.h>

void typeOfVehicle(char vehicleType);
void processOutput(int hourEntered, int minuteEntered, int hourLeft, int minuteLeft, char vehicleType);
int main()
{
    char vehicleType;
    int hourEntered, minuteEntered, hourLeft, minuteLeft;
    printf("Type of vehicle? ");
    scanf("%c", &vehicleType);
    printf("Hour vehicle entered lot\t(0 - 24)? ");
    scanf("%d", &hourEntered);
    printf("Minute vehicle entered lot\t(0 - 60)? ");
    scanf("%d", &minuteEntered);
    printf("Hour vehicle left lot\t\t(0 - 24)? ");
    scanf("%d", &hourLeft);
    printf("Minute vehicle left lot\t\t(0 - 60)? ");
    scanf("%d", &minuteLeft);

    if(hourEntered >  24  || hourLeft > 24)
        printf("You are getting towed. ");
    else{
        typeOfVehicle(vehicleType);
        processOutput(hourEntered, minuteEntered, hourLeft, minuteLeft, vehicleType);
    }
    return 0;
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
            printf("Invalid Type of vehicle.\n");
            break;
    }
}
void processOutput(int hourEntered, int minuteEntered, int hourLeft, int minuteLeft, char vehicleType){
    int minute, hour;
    double totalCharge;
    char type = toupper(vehicleType);

    if(minuteLeft < minuteEntered){
        minuteLeft += 60;
        hourLeft--;
    }
    hour = hourLeft - hourEntered;
    minute = minuteLeft - minuteEntered;
    printf("\t\tPARKING LOT CHARGE\t\n");
    printf("\tTIME-IN\t\t\t\t%d:%d\n",hourEntered,minuteEntered);
    printf("\tTIME-OUT\t\t\t%d:%d\n",hourLeft, minuteLeft);
    printf("\t---------\n");
    printf("\tPARKING TIME\t\t\t%d:%d\n",hour, minute);
    minute > 30 ? hour++: hour;
    printf("\tROUNDED TOTAL\t\t\t%d\n", hour);

    if (type == 'C' && hour <= 3)
        totalCharge = 0.0;
    else if (type == 'B' && hour <= 1)
        totalCharge = 2.0;
    else if (type == 'T' && hour <= 2)
        totalCharge = 1.0;
    else
        totalCharge = (double)((hour - 3.0) * 1.5);

    printf("\t\t\t\t----------\n");
    printf("\tTOTAL CHARGE\t\t\t$%.2lf\n",totalCharge);
}
