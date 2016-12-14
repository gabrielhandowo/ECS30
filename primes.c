#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

//functions
void user_input();
void prime_calculation(int n);
bool is_valid_formatting(int num_args_read, int num_args_needed);

//main excecute
int main ()
{
	user_input();
    return 0;
}
void user_input(){
	int range;
    int num_args_read;

    do{
	    do{
	    	printf("Enter a number greater than 1: ");
    		num_args_read = scanf("%d", &range);
	    }while(!(is_valid_formatting(num_args_read, 1)));
    }while(range < 2);

	prime_calculation(range);
}

void prime_calculation(int val){
    int i;
    int j;
    int n = val + 1;
    int *primes;

    primes = malloc((n) *sizeof(int));
     for (i=2;i<n;i++)
        primes[i]=1;

    for (i=2;i<n;i++)
        if (primes[i])
            for (j=i;i*j<n;j++)
                primes[i*j]=0;
            printf("The primes between 2 and %d are:\n", val);
    for (i=2;i<n;i++)
        if (primes[i]){
            printf("%d\n",i);
        }
}

bool is_valid_formatting(int num_args_read, int num_args_needed){
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