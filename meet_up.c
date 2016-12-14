//
//  meet_up.c
//  
//
//  Created by Gabriel Handowo on 10/21/16.
//
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

//functions
void userInput();
void Input_Calculation (int rows, int columns, int itteration);
bool assert_formatting(double num_args_read, double num_args_needed);
int move_closer(int val1, int val2);
bool comparison(int row1, int col1, int row2, int col2);

int main()
{
    userInput();
    return 0;
}

void userInput()
{
    //variables
    double seed;
    int rows, columns, itteration;
    int num_args_read;
    
    //userInput of the seed to generate the random number
    do{
        printf("Enter the seed for the random number generator: ");
        num_args_read = scanf("%lf", &seed);
    }while(!(assert_formatting(num_args_read, 1)));
    srand(seed);// generate random number
    
    //user input of the rows
    do{
        do {
            printf("Enter the number of rows on the board: ");
            num_args_read = scanf("%d", &rows);
        }while(!(assert_formatting(num_args_read, 1)));
    }while(rows <= 0);
    
    //use input of columns
    do{
        do{
            printf("Enter the number of columns on the board: ");
            num_args_read =  scanf("%d", &columns);
        }while(!(assert_formatting(num_args_read, 1)));
    }while(columns <= 0);
    
    //itteration user input
    do{
        do{
            printf("Enter the number of simulations to run: ");
            num_args_read = scanf("%d", &itteration);
        }while(!(assert_formatting(num_args_read, 1)));
    }while(itteration <= 0);
    Input_Calculation(rows, columns, itteration);
}

//calculation
void Input_Calculation (int rows, int columns, int itteration)
{
    //variables
    int rows1, rows2, columns1, columns2;
    int tempRows1, tempscolumns1, tempsRows2, tempscolumns2;
    int i;
    double count = 0, finalCount = 0;
    double averageCount;
    
    //here comes the worst part, calculation
    for(i = 0; i < itteration; i++)
    {
        //determine the innitial values
        rows1 = rand() % (rows);
        columns1 = rand() % (columns);
        rows2 = rand() % (rows);
        columns2 = rand() % (columns);
        
        //print the number of simulations
        if(itteration <20){
        printf("Simulation %d\n",i);
        }
        
        //printout the first values of rows and columns
        if(itteration < 20) {
            printf("Piece one starts at: %d, %d\n",rows1, columns1);
            printf("Piece two starts at: %d, %d\n",rows2, columns2);
        }
        
        while(!(comparison(rows1,columns1, rows2, columns2))){
            //get new rows1 & col1
            tempRows1 = move_closer(rows1,rows2);
            tempscolumns1 =move_closer(columns1,columns2);
            
            //get new rows2 & col2
            tempsRows2= move_closer(rows2,rows1);
            tempscolumns2 =move_closer(columns2,columns1);
            
            //printout the simulation if it's lower than 20
            if (itteration < 20){
                printf("First piece moves from %d,%d to %d,%d\n", rows1, columns1, tempRows1, tempscolumns1);
                printf("Second piece moves from %d,%d to %d,%d\n", rows2, columns2, tempsRows2, tempscolumns2);
            }
            
            //initialize the old values to the new values
            rows1 = tempRows1; columns1 = tempscolumns1;
            rows2 = tempsRows2; columns2 = tempscolumns2;
            count++;
        }
        
        // track the sum of the count
        printf("\n");
        finalCount += count;
        
        //initilize the count to 0 so it won't added while it goes to the next loops
        count = 0;
    }
    
    //calculate the average values
    averageCount = finalCount/i;
    
    //printout average of rounds
    printf("On average it takes %.2f rounds on a board %d X %d for the pieces to meet.\n",averageCount, rows, columns);
}

//check user input
bool assert_formatting(double num_args_read, double num_args_needed)
{
    char new_line = '\n';
    bool is_valid = true; //assume the format is correct
    if(num_args_read != num_args_needed){ //didn't fill in all the format specifiers
        is_valid = false;//format is not correct
    }
    
    
    do{
        scanf("%c", &new_line); //read the next character from the standard input
        if(!isspace(new_line)){ //if it isn't white space
            is_valid = false; //extra stuff there so format isn't valid
        }
    }while(new_line != '\n'); //keep reading characters until you reach the new line character
    return is_valid;
}

//check the condition if it in the same rows or columns
bool comparison(int row1, int col1, int row2, int col2){
    return row1 == row2 && col1 == col2;
}

//move the rows and the columns
int move_closer(int val1, int val2){
    //if the min value less than max value
    if (val1 < val2){
       return val1 + rand() % (val2 - val1 + 1);
    }
    // if the min value is bigger than max value
    else if (val1 > val2){
        return val1 - rand() % (val1 - val2+ 1);
    }
    // if it's equal
    else{
        return val1;
    }
}
//I'm done yeay finally
