//  ECS 20
//  grade_need.c
//  estimate how much final grade do you need for achieve certain grade in your class
//  Created by Gabriel Handowo on 9/24/16.

#include <stdio.h>


int main()
{
    //variable
    char grade = '?';
    int gradePercentNeeded, currentGrade, finalWeight;
    double finalGrade;
    double percentage;
    
    //get user input
    printf ("Enter the grade you want in the class: ");//get what grade Letter user wants
    scanf ("%c", &grade);
    printf ("Enter the percent in the class you need in the class to get that grade: ");//percentage needed
    scanf ("%d", &gradePercentNeeded);
    printf ("Enter your current percent in the class: "); //user's current percentage
    scanf ("%d", &currentGrade);
    printf("Enter the weight of the final: "); //percentage of user finals
    scanf("%d", &finalWeight);
    
    //calculation
    percentage = (double)finalWeight/100;//make everything in %
    finalGrade = ((double)gradePercentNeeded - ((double)currentGrade * (1-percentage)))/percentage;
   
    //user output
    printf("You need to get at least %.2f%% on the final to get a %c in the class.\n",finalGrade, grade);
    return 0;
}
