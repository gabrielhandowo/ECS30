//  complex_mult.c
//  calculate the complex multivariable equation
//  Created by Gabriel Handowo on 9/26/16.
//  ECS 20

#include <stdio.h>

int main(){
    //variables
    int complexNum1a,complexNum1b,complexNum2a,complexNum2b,results1,result2;
    
    //user input
    printf("Enter the first complex number in the form ai + b: ");
    scanf(" %d i + %d", &complexNum1a, &complexNum1b);// first input
    printf("Enter the second complex number in the form ai + b: ");
    scanf(" %d i + %d", &complexNum2a, &complexNum2b);//second input
    
    //calculation
    results1 = (complexNum1a * complexNum2b) + (complexNum1b * complexNum2a); //integer with i
    result2 = (complexNum1b * complexNum2b) - (complexNum1a * complexNum2a); //right side after +
    
    //output
    printf("(%di + %d) * (%di + %d) = %di + %d\n", complexNum1a, complexNum1b, complexNum2a,complexNum2b, results1,result2);
    
    return 0;
}
