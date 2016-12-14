//  crated by Gabriel handowo vony
//  Calculate the amount of loan.
//

#include <stdio.h>
#include <math.h>

int main(void)
{
    //variables
    double amount;
    double interestRate;
    double numPayments;
    
    
    //user input
    printf("Please enter the amount of money you borrowed: $");
    scanf(" %lf", &amount);
    printf("Please enter the annual interest rate: ");
    scanf(" %lf", &interestRate);
    printf("Please enter the number of payments to be made: ");
    scanf(" %lf", &numPayments);
    
    //loan calculation
    double interestRateMonthly = interestRate/12; // get a monthly interest rate
    double loanCost = (interestRateMonthly * amount)/(1 - (pow((1 + interestRateMonthly),-numPayments))); //calculate the laon cost
    double totalAmount = loanCost * numPayments; //calculate the total amount of loan that user need to pay
    double amountDiff = totalAmount - amount; // the amount interest that user need to pay
    
    //user output
    printf( "A loan of $%.2f with an annual interest of %.2f payed off over %.0f months will have monthly payments of $%.2f. In total you will pay $%.2f, making the cost of your loan $%.2f.\n", amount, interestRate, numPayments, loanCost, totalAmount, amountDiff);
}
