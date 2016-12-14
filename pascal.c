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
bool assert_formatting(int num_args_read, int num_args_needed);
void Triagle_Simulation(int lines);
long Factor (int val);

//main functions
int main()
{
    User_Input();
    return 0;
}

void User_Input()
{
    int lines, num_args_read;

    do{
        printf("Please enter how many levels of Pascal's Triangle you would like to see: ");
        num_args_read = scanf("%d", &lines);
    }while((!(assert_formatting(num_args_read, 1))) && (lines < 0 || lines < 28));

    Triagle_Simulation(lines);
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

void Triagle_Simulation(int lines)
{
    int results = 1;

    for(int i=0; i<lines; i++)
    {
        for(int j=0; j <= i; j++)
        {
            if (j==0 || i==0)
                results = 1;
            else
                results = results*(i-j+1)/j;

            printf("%d ", results);
        }
        printf("\n");
    }
}