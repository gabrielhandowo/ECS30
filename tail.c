#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//Function
void execution(int argc, char* argv[]);

//main execution
int main(int argc, char* argv[]){
    execution(argc,argv);
    return 0;
}

void execution(int argc, char* argv[]){
    int num_lines = atoi(argv[2]);
    int i = 0;
    char** lines;
    FILE* fp = NULL;
    //file
    fp = fopen(argv[1], "r");
    if(fp == NULL){
        printf("ERROR!\n");
        exit(0);
    }

    lines = (char**)malloc(num_lines* sizeof(char*));
    for(int i = 0; i < num_lines ; i++){
        lines[i] = (char*)malloc(10000 * sizeof(char));
    }
    
    while(fgets(lines[i],100,fp)){
        i++;
        if(i == num_lines){
            i = 0;
        }
    }

    for(int j = i; j < num_lines; j++){
        printf("%s", lines[j]);
    }
    for(int j = 0; j < i; j++){
        printf("%s", lines[j]);
    }
    
    //Free memory
    for(int i = 0; i < num_lines; i++){
        free(lines[i]);
    }
    free(lines);
}