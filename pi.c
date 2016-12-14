//
//  pi.c
//  
//
//  Created by Gabriel Handowo on 10/20/16.
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

//functions
bool is_valid_formatting(int num_args_read, int num_args_needed);
void PiCalculation();
double rand_double(double low, double high);
void calculation (double iterations);

int main()
{
    PiCalculation();
}

//callculation and user input
void PiCalculation()
{
    //variables
    double iterations;
    int seed, num_args_read;
    
    //seed generator
    do {
        printf("Enter the seed for the random number generator: ");
        num_args_read = scanf("%d",&seed);
        srand(seed);//random numbers
    } while (!(is_valid_formatting(num_args_read,1)));
    
    //iterations needed
    do{
        do{
            printf("Enter the number of iterations to run: ");
            scanf("%lf",&iterations);
        } while (!(is_valid_formatting(num_args_read,1)));
    } while (iterations < 0);
    
    calculation(iterations);
}

//pi calculation
void calculation (double iterations){
    //variables
    double x,y,z,pi;
    int i,Probability = 0;
    
    // initialize random numbers
    for ( i=0; i < iterations; i++){
        
        //determine the points between -1 to 1
        x = rand_double(-1,1);
        y = rand_double(-1,1);
        
        //determine the distance of the vals
        z = (x*x) + (y*y);
        z = sqrt(z);
        
        if (z < 1) Probability++;
        pi = (double)Probability/iterations*4;
    }
    printf("The value of pi is %.5f.\n", pi);
}

//invalid formatting
bool is_valid_formatting(int num_args_read, int num_args_needed)
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

//random numbers
double rand_double(double low, double high){
    
    return low +  ( (double) rand()) /
    ( ((double)RAND_MAX)/(high-low));
}

