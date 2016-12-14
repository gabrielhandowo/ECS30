//  conversions.c
//  convert between distance units and convert between temperature units
//  Created by Gabriel Handowo on 10/6/16.


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//functions
void DataProcessing ();
void TemperatureConvert();
void DistanceConvert();
void assert_formatting(int num_args_read, int num_args_needed);
int temperature_units_formatting(char unit);
int distance_units_formatting(char unit);

int main (){
    //call out other functions
    DataProcessing ();
}

void DataProcessing ()
{
    //variables
    char temperatureDistance = '?';
    int num_args_read;
    
    //userinput
    printf("Pick the type of conversion that you would like to do.\n");
    printf("T or t for temperature\n");
    printf("D or d for distance\n");
    printf("Enter your choice: ");
    num_args_read = scanf ("%c", &temperatureDistance);
    assert_formatting (num_args_read, 1);
    
    //make sure user only input t or d char
    if (temperatureDistance == 't' || temperatureDistance =='T'){
        TemperatureConvert();
    }
    else if (temperatureDistance == 'd' || temperatureDistance == 'D'){
        DistanceConvert();
    }
    else{
        printf("Unknown conversion type %c chosen. Ending Program.\n", temperatureDistance);
        exit(0);
    }
}
void TemperatureConvert(){
    //variables
    double tempValue;
    char tempUnits, tempUnitsConversion;
    double finalConversionsValue;
    int num_args_read;
    
    //user inputs
    printf("Enter the temperature followed by its suffix (F, C, or K): ");
    num_args_read = scanf(" %lf %c", &tempValue, &tempUnits);
    assert_formatting(num_args_read, 2); //formating the number of input
    tempUnits = toupper(tempUnits); //make it uppercase
    temperature_units_formatting(tempUnits); // validate units input
    
    printf("Enter the new unit type (F, C, or K): ");
    num_args_read = scanf(" %c", &tempUnitsConversion); //scan user input
    assert_formatting(num_args_read, 1);
    tempUnitsConversion = toupper(tempUnitsConversion); //make all the input to uppercase
    temperature_units_formatting(tempUnitsConversion); //validate the units
    
    
    //calculation
    //from farenheit
    if (tempUnits == 'F'){
        if (tempUnitsConversion == 'F'){
            finalConversionsValue = tempValue;
            printf("%.2f%c is %.2f%c\n",tempValue,tempUnits, finalConversionsValue, tempUnitsConversion);
        }
        else if (tempUnitsConversion == 'C'){
            finalConversionsValue = (tempValue -32) * 5/9; //(tempValue - 32) * 5/9;
            printf ("%.2f%c is %.2f%c\n",tempValue,tempUnits, finalConversionsValue, tempUnitsConversion);
        }
        else if(tempUnitsConversion =='K'){
            finalConversionsValue = (tempValue - 32) * 5/9 + 273.15;
            printf ("%.2f%c is %.2f%c\n",tempValue,tempUnits, finalConversionsValue, tempUnitsConversion);
        }
        else {
            printf("Invalid formatting. Ending program.(if)\n");
        }
    }
    //from celcius
    else if (tempUnits == 'C'){
        if (tempUnitsConversion == 'C'){
            finalConversionsValue = tempValue;
            printf("%.2f%c is %.2f%c\n",tempValue,tempUnits, finalConversionsValue, tempUnitsConversion);
        }
        else if (tempUnitsConversion == 'F'){
            finalConversionsValue = (tempValue * 9/5) + 32;
            printf ("%.2f%c is %.2f%c\n",tempValue,tempUnits, finalConversionsValue, tempUnitsConversion);
        }
        else if(tempUnitsConversion =='K'){
            finalConversionsValue = tempValue + 273.15;
            printf ("%.2f%c is %.2f%c\n",tempValue,tempUnits, finalConversionsValue, tempUnitsConversion);
        }
        else {
            printf("Invalid formatting. Ending program.(if)\n");
        }
    }
    //from kelvin
    else if (tempUnits == 'K'){
        if (tempUnitsConversion == 'K'){
            finalConversionsValue = tempValue;
            printf("%.2f%c is %.2f%c\n",tempValue,tempUnits, finalConversionsValue, tempUnitsConversion);
        }
        else if (tempUnitsConversion == 'F'){
            finalConversionsValue = (tempValue - 273.15) * 9/5 + 32;
            printf ("%.2f%c is %.2f%c\n",tempValue,tempUnits, finalConversionsValue, tempUnitsConversion);
        }
        else if(tempUnitsConversion == 'C'){
            finalConversionsValue = tempValue - 273.15;
            printf ("%.2f%c is %.2f%c\n",tempValue,tempUnits, finalConversionsValue, tempUnitsConversion);
        }
        else {
            printf("Invalid formatting. Ending program.(if)\n");
        }
    }
    else{
        printf("%c is not a valid temperature type. Ending program.\n", tempUnits);
        exit(0);
    }
}

void DistanceConvert(){
    //variables
    double distanceValue = 0.0, newDistanceValue;
    char distanceUnits, newDistanceUnits;
    int num_args_read;
    
    //user input
    printf("Enter the distance followed by its suffix (I,F,Y,M): ");
    num_args_read = scanf(" %lf %c", &distanceValue, &distanceUnits);
    assert_formatting(num_args_read, 2); //format user input
    distanceUnits = toupper(distanceUnits); //make it uppercase
    distance_units_formatting(distanceUnits); //validate the units
    
    printf("Enter the new unit type (I,F,Y,M): ");
    num_args_read = scanf(" %c", &newDistanceUnits);
    assert_formatting(num_args_read, 1);
    newDistanceUnits = toupper(newDistanceUnits); //make it upprcase
    distance_units_formatting(newDistanceUnits); //validate user units
    
    //calculation
    //from inches
    if ( distanceUnits == 'I'){
        if (newDistanceUnits == 'I'){
            newDistanceValue = distanceValue;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
        else if (newDistanceUnits =='F'){
            newDistanceValue = distanceValue /12;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
        else if( newDistanceUnits =='Y'){
            newDistanceValue = distanceValue /36;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
        else if( newDistanceUnits =='M'){
            newDistanceValue = distanceValue /63360;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
    }
    //from feet or foot
    else if ( distanceUnits == 'F'){
        if (newDistanceUnits == 'F'){
            newDistanceValue = distanceValue;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
        else if (newDistanceUnits =='I'){
            newDistanceValue = distanceValue * 12;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
        else if( newDistanceUnits =='Y'){
            newDistanceValue = distanceValue /3;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
        else if( newDistanceUnits =='M'){
            newDistanceValue = distanceValue /5280;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
    }
    //from yard
    else if ( distanceUnits == 'Y'){
        if (newDistanceUnits == 'Y'){
            newDistanceValue = distanceValue;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
        else if (newDistanceUnits =='I'){
            newDistanceValue = distanceValue * 36;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
        else if( newDistanceUnits =='F'){
            newDistanceValue = distanceValue *3;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
        else if( newDistanceUnits =='M'){
            newDistanceValue = distanceValue /1760;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
    }
    //from miles
    else if ( distanceUnits == 'M'){
        if (newDistanceUnits == 'M'){
            newDistanceValue = distanceValue;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
        else if (newDistanceUnits =='I'){
            newDistanceValue = distanceValue * 63360;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
        else if( newDistanceUnits =='F'){
            newDistanceValue = distanceValue * 5280;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
        else if( newDistanceUnits =='Y'){
            newDistanceValue = distanceValue * 1760;
            printf("%.2f%c is %.2f%c\n",distanceValue,distanceUnits, newDistanceValue,newDistanceUnits);
        }
    }
    else {
        printf("%c is not a valid distance type. Ending program.\n", distanceUnits);
        exit(0);
    }
}

//validate user input
void assert_formatting(int num_args_read, int num_args_needed)
{
    char new_line = '\n';
    if(num_args_read != num_args_needed){
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
    scanf("%c", &new_line);
    if(new_line != '\n'){
        printf("Invalid formatting. Ending program.\n");
        exit(0);
    }
}

//validate user input for distance
int distance_units_formatting(char unit)
{
    switch (unit){
        case 'I':
        case 'F':
        case 'Y':
        case 'M':
            return unit;
        default:
            printf("%c is not a valid distance type. Ending program.\n", unit);
            exit(0);
    }
}

//validate user input for temperature
int temperature_units_formatting(char unit){
    switch (unit){
        case 'C':
        case 'K':
        case 'F':
            return unit;
        default:
            printf("%c is not a valid temperature type. Ending program.\n", unit);
            exit(0);
    }
}
