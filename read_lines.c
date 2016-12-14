#include <stdio.h>
#include <stdlib.h>
#include "read_lines.h"

void read_lines(FILE* fp, char*** lines, int* num_lines){
    char c;
    int i = 0;
    int length = 0, index = 0;
    *num_lines = 0;
    int String_Length[1000] = {};
    
    //find line numberss and length
   	while(!feof(fp)){
        c = fgetc(fp);
        length++;
 
    // Enters here at the end of each line 
        if(c == '\n'){
        // This array stores the length of characters of each line
            String_Length[index] = length;
            index++;
        // Reset the number of characters for next iteration
            length = 0;
        // Increment the number of lines read so far
            (*num_lines)++;
        }
    }

    ///allocates memory
    (*lines) = (char**)malloc(*num_lines *sizeof(char*));
    
    //allocates memory for the strings
    for(i = 0; i < *num_lines; i++){
        (*lines)[i] = (char*) malloc (String_Length[i]+1 * sizeof(char));
    }
    
    //read from the beginning
    fseek(fp, 0, SEEK_SET);

	//put string into arrays
    i = 0;
    for (;i < *num_lines; i++){
        fgets((*lines)[i],(String_Length[i] + 1),fp);
    }
}