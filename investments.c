//
//  investments.c
//  
//
//  Created by Gabriel Handowo on 10/15/16.
//
//

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

//functions
void userInput();
bool is_valid_formatting(int num_args_read, int num_args_needed);
void TotalSaving(double amountAddedMonthly, double Period, double investmentRate, double owedAmount, double monthlyLoansRate, double minumPayment);
void OutPut(double investmentSum, double paymentAfter);


//main program
int main ()
{
    userInput();
}

void userInput()
{
    //variables
    double addedEachMonths, loansYouOwe, annualLoansRate, minLoanPayment, currentAge,retireAge, annualInvestmentsRate;
    int num_args_read;
    
    //inputs and input checks
    //amount added monthly
    do{
        do{
        printf ("Enter how much money you will be putting towards\n");
          printf("loans/retirement each month: ");
          num_args_read = scanf("%lf", &addedEachMonths);
        }while(!(is_valid_formatting(num_args_read,1)));
    }while(addedEachMonths < 0);
    
    //owed amount
    do{
      do {
          printf("Enter how much you owe in loans: ");
          num_args_read = scanf("%lf",&loansYouOwe);
      } while (!(is_valid_formatting(num_args_read,1)));
    }while(loansYouOwe < 0);
    
    //annual interest
    do{
        do {
            printf("Enter the annual interest rate of the loans: ");
            num_args_read = scanf("%lf",&annualLoansRate);
        } while (!(is_valid_formatting(num_args_read,1)));
    }while (annualLoansRate < 0);

    //minimum monthlu amount
    do{
        do {
            printf("Enter your minimum monthly loan payment: ");
            num_args_read = scanf("%lf",&minLoanPayment);
        } while (!(is_valid_formatting(num_args_read,1)));
    }while(minLoanPayment < 0);
    if (minLoanPayment > addedEachMonths){
        printf("You didn't set aside enough money to pay off our loans. Ending program.");
        exit(0);
    }
    
    //current age
    do{
      do {
          printf("Enter your current age: ");
          num_args_read = scanf("%lf",&currentAge);
      } while (!(is_valid_formatting(num_args_read,1)));
    }while(currentAge < 0 && currentAge < 100);
    
    //retire age
    do{
        do{
            do {
                printf("Enter the age you plan to retire at: ");
                num_args_read = scanf("%lf",&retireAge);
            } while ((!(is_valid_formatting(num_args_read,1)) && (retireAge < currentAge)));
        }while(retireAge < 0);
    }while(retireAge < currentAge);
    
    //investment rate
    do{
      do {
          printf("Enter the annual rate of return you predict for your investments: ");
          num_args_read = scanf("%lf",&annualInvestmentsRate);
      } while (!(is_valid_formatting(num_args_read,1)));
    }while(annualInvestmentsRate < 0 && annualInvestmentsRate < 100);
    
    //terms in month
    int monthlyAgeRange = (retireAge - currentAge)*12;
    
    TotalSaving(addedEachMonths, monthlyAgeRange, annualInvestmentsRate/12.0, loansYouOwe, annualLoansRate/12.0, minLoanPayment);
    
}

//amount calcualtion
void TotalSaving(double amountAddedMonthly, double Period, double investmentRate, double owedAmount, double monthlyLoansRate, double minumPayment){
    //variables
    double totalLoans = owedAmount;
    double tempLoans = owedAmount;
    double totalInvestment = 0.0,minPay = 0.0;
    
    //if the amount payed using the minimum amount
    for (int i = 0; i < Period; i++){
       if (totalLoans > 0 ){
           totalLoans = totalLoans + (totalLoans * monthlyLoansRate);
           totalLoans -= minumPayment;
           totalInvestment = totalInvestment + (totalInvestment * investmentRate);
           totalInvestment = totalInvestment + (amountAddedMonthly -minumPayment);
           minPay = totalInvestment;
        }
        
        else {
            totalInvestment -= totalLoans;
            totalLoans = 0;
            totalInvestment = totalInvestment + (totalInvestment * investmentRate);
            totalInvestment += amountAddedMonthly;
            minPay = totalInvestment;
        }
    }
    
    totalInvestment = 0;
    
    //if the amount payed using whole amount
    for (int i = 0; i < Period; i++) {
        if (tempLoans > 0){
            tempLoans = tempLoans + (tempLoans * monthlyLoansRate);
            tempLoans -= amountAddedMonthly;
        }
        else{
            totalInvestment -= tempLoans;
            tempLoans = 0;
            totalInvestment = totalInvestment + (totalInvestment * investmentRate);
            totalInvestment += amountAddedMonthly;
        }
    }
    
    
    //condition output
    //still owed some money
    if (totalLoans > 0){
        printf("Warning! After you retire you will still have $%.2f in loans left.\n", totalLoans);
        printf("You should apply all $%.2f towards your loan before making any investments.\n",amountAddedMonthly);
        OutPut(minPay, totalInvestment);
    }
    //if payed using minimum amount is enough
    else if (totalInvestment < minPay){
        printf("You should only make the minimum payments on your loan and apply the rest towards retirement.\n");
        printf ("If you do you will have $%.2f when you retire as opposed to $%.2f if you payed off your loan before investing.\n",minPay, totalInvestment);
    }
    //when it need to payed with the full amount
    else{
         printf("You should apply all $%.2f towards your loan before making any investments.\n",amountAddedMonthly);
        OutPut(minPay, totalInvestment);
    }
}

//general output
void OutPut(double investmentSum, double paymentAfter){
    printf ("If you do you will have $%.2f when you retire as opposed to $%.2f if you only made minimum payments.\n",paymentAfter,  investmentSum);
}
//check the user input if it's valid or not
bool is_valid_formatting(int num_args_read, int num_args_needed)
{
    char new_line ='\n';
    bool is_valid = true;
    if (num_args_read != num_args_needed){
        is_valid =false;
    }
    
    do {
        scanf("%c", &new_line);
        if (!isspace(new_line)){
            is_valid =false;
        }
    }while(new_line != '\n');
    return is_valid;
}
