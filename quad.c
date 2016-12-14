//
//  quad1.c
//  
//
//  Created by Gabriel Handowo on 10/6/16.
//
//

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
void UserInput();
void FinalOutput();

int main()
{
    //variables
    double var1 = 0.0,var2 = 0.0,var3 = 0.0;
    UserInput(var1,var2,var3);
}

//userinput
void UserInput(double x,double y,double z)
{
    printf("Given a quadratic equation of the form a*x^2 + b * x + c\n");
    printf("Please enter a: ");
    scanf("%lf",&x);
    printf("Please enter b: ");
    scanf("%lf",&y);
    printf("Please enter c: ");
    scanf("%lf",&z);
    //check if user input is not 0
    if (x == 0.0 || y == 0.0 || z == 0.0){
        printf("There are no real solutions\n");
        exit(0);
    }
    FinalOutput(x,y,z);
}

//data calculation and output
void FinalOutput(double a, double b, double c){
    //variables
    double determinant, sol1,sol2,solution;
    determinant = b*b-4.0*a*c;
    
    //calculate the determinant & results
    if (determinant == 0){
        solution =-b/(2.0*a);//calculation
        //output
        printf("There is one real solution: %.2f \n", solution);
    }
    
    else if( determinant > 0){
        sol1 = (-b + sqrt(determinant) ) / (2.0*a);// first results
        sol2 = (-b - sqrt(determinant) ) / (2.0*a);//second results
        //results output
        printf("There are 2 real solutions\n");
        printf("Solution 1: %.2f\n",sol1);
        printf("Solution 2: %.2f\n", sol2);
    }
    else{
        printf("There are no real solutions\n");
    }
}
