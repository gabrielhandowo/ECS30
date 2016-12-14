//  ECS 20
//  grade_need.c
//  estimate how much final grade do you need for achieve certain grade in your class
//  Created by Gabriel Handowo on 10/5/16.


#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
//functions
double UserInputRangeValidation(double valueValidation);
void DataProcessing(char grade, double currentGrade, double finalWeight);
void GradeCalculation(char gradeCalc, double finalWeightCalc, double gradePercentNeededCalc, double currentGradeCalc);
void assertFormating();

int main()
{
    //variable
    char Lettergrades = '?';
    double currentGradeInput= 0.0, finalWeightInput= 0.0;
    
    DataProcessing(Lettergrades, currentGradeInput, finalWeightInput);
}
void DataProcessing(char grade, double currentGrade, double finalWeight)
{
    //Variable
    double gradePercentNeeded = 0.0;
    int num_args_read;
    //get user input
    printf ("Enter the grade you want in the class: ");//get what grade Letter user wants
    num_args_read = scanf ("%c", &grade);
    //validate user grade input
    assertFormating (num_args_read, 1); //checking user input
    switch (grade){
        case 'A':
        case 'a':
        case 'B':
        case 'b':
        case 'C':
        case 'c':
        case 'd':
        case 'D':
        case 'f':
        case 'F':
            break;
        default:
            printf("Unknown Grade Received: %c. Ending program.\n", grade);
            exit(0);
    }
    printf ("Enter your current percent in the class: ");//user's current percentage
    num_args_read = scanf ("%lf", &currentGrade);
    assertFormating (num_args_read, 1); // checking user input
    UserInputRangeValidation(currentGrade);// checking user input to be greater than 0 and less than 100
    
    printf("Enter the weight of the final: ");//percentage of user finals
    num_args_read = scanf("%lf", &finalWeight);
    assertFormating (num_args_read, 1);// checking user input
    UserInputRangeValidation(finalWeight);// checking user input to be greater than 0 and less than 100
    
    //grade estimation by letter grade
    switch(grade){
        case 'A':
        case 'a':
            gradePercentNeeded = 90;
            break;
        case 'B':
        case'b':
            gradePercentNeeded = 80;
            break;
        case 'C':
        case 'c':
            gradePercentNeeded = 70;
            break;
        case 'd':
        case 'D':
            gradePercentNeeded = 60;
            break;
        case 'f':
        case 'F':
            gradePercentNeeded = 0;
            break;
        default:
            printf("Invalid formatting. Ending program.\n");
    }
    GradeCalculation (grade ,finalWeight, gradePercentNeeded, currentGrade);
}
                      
void GradeCalculation(char gradeCalc, double finalWeightCalc, double gradePercentNeededCalc, double currentGradeCalc)
{
    //calculation
    double percentage = finalWeightCalc/100;//make everything in %
    double finalGrade = (gradePercentNeededCalc - (currentGradeCalc * (1-percentage)))/percentage;
    
    //if the program give more than 100% or less than 100% and user output
    if (finalGrade > 100){
        printf(" You cannot get a %c in the class because you would need to score at least %.2f%% on the final.\n",gradeCalc, finalGrade);//output
    }
    else if (finalGrade < 0){
        printf("You cannot score low enough on the final to get a %c in the class.\n",gradeCalc);//output
    }
    else {
        printf("You need a grade of at least  %.2f%% on the final to get a %c in the class.\n",finalGrade, gradeCalc); //output
    }
}

//input validation based on value
double UserInputRangeValidation(double valueValidation){
        if (valueValidation > -1 && valueValidation < 101){
            return valueValidation;
        }
        else if (valueValidation < 0){
            printf("The number you last entered should have been positive. Ending program.\n");
            exit(0);
        }
        else{
            printf("Invalid formatting. Ending program.\n");
            exit(0);
        }
 }
//validation function
void assertFormating (int num_args_read, int num_args_needed){
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
