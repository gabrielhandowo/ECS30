//created 10/28/2016
//by Gabriel Handowo Vony

//library
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdlib.h>
#include <ctype.h>

//functions
void User_Input();
bool assert_formatting();
int Get_User_Input(char prompt[]);
void matrix_calculation(int m1[100][100], int m2[100][100], int rows, int columns);

//main execution
int main()
{
   User_Input();
}

void User_Input()
{
   int rows, columns;
   int matrix1[100][100], matrix2[100][100];

   rows = Get_User_Input("Please enter the number of rows: ");
   columns = Get_User_Input("Please enter the number of columns: ");

   printf("Enter Matrix A \n"); 
   for (int i = 0; i < rows; i++){
      for (int j = 0; j < columns; j++){
         scanf("%d", &matrix1[i][j]);
      }
   }

   printf("Enter Matrix B \n");
   for (int i = 0; i < rows; i++){
      for (int j = 0; j < columns; j++){
         scanf("%d", &matrix2[i][j]);
      }
   }
   matrix_calculation(matrix1, matrix2, rows, columns);
}
   

int Get_User_Input(char prompt[])
{
   int input;
   int num_args_read;
   do{
      printf("%s\n", prompt);
      num_args_read = scanf("%d", &input);
   }while((!(assert_formatting(num_args_read, 1))) && (input < 0 && input < 100));
   return input;
}

void matrix_calculation(int m1[100][100], int m2[100][100], int rows, int columns)
{
   int sum[100][100];
   printf("A + B =\n");
   for(int i =0; i < rows; i++){
      for(int j = 0; j < columns; j++){
         sum[i][j] = m1[i][j] + m2[i][j];
         printf("%d ", sum [i][j]);
      }
      printf("\n");
   }
}

bool assert_formatting(int num_args_read, int num_args_needed)
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