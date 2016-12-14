//  anagram.c
//  Created by Gabriel Handowo on 10/27/16.
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

//functions
void User_Input();
bool input_validation(char input[]);
char lowercase_converter(char input[]);
void my_strcpy(char dest[], char src[]);
bool anagram(char a[], char b[]);

//main programs
int main(){
    User_Input();
}

void User_Input(){
    //variables
    char input1[20], input2[20], oldInput1[20], oldInput2[20];
    bool results;

        do{
            printf("Please enter the first word: \n");
            scanf("%s", input1);
        }while(!(input_validation(input1) == true));
        my_strcpy(oldInput1, input1);
        lowercase_converter(input1);

        do{
            printf("Please enter the second word: \n");
            scanf("%s", input2);
        }while (!(input_validation(input2) == true));
        my_strcpy(oldInput2, input2);
        lowercase_converter(input2);

        results = anagram(input1, input2);

        if (results == false){
            printf("%s is NOT an anagram of %s\n", oldInput1, oldInput2);
        }
        else if ( results == true){
            printf("%s is an anagram of %s\n", oldInput1, oldInput2);
        }
}

char lowercase_converter(char input[]){
    for(int i = 0; input[i] != '\0'; i++){
        input[i] = tolower(input[i]);
    }
     return *input;
}

void my_strcpy(char dest[], char src[]){
  //copy src into dest
  //it is up to the caller to make sure that there is enough room in
  //dest to fit all of src. If there isn't bad things can happen
  int i;
  
  for(i = 0; src[i] != '\0'; i++){//while we haven't found the null character
    dest[i] = src[i];// copy the current character from source to dest
  }
  dest[i] = src[i]; //copy the null character to dest
}

bool input_validation(char input[]){
    bool is_valid;

    for(int i = 0; input[i] != '\0'; i++){
        if ((input[i] > 'a' && input[i] < 'z') || (input[i] > 'A' && input[i] < 'Z')){
            is_valid = true;
        }
        else{
            is_valid = false;
        }
    }
    return is_valid;
}
bool anagram(char i1[], char i2[])
{
    bool results = true;
   int val1[26] = {0}, val2[26] = {0}, i = 0;
 
   for (;i1[i] != '\0'; i++){
      val1[i1[i]-'a']++;
   }
 
   i = 0;
 
   for (;i2[i] != '\0'; i++){
      val2[i2[i]-'a']++;
   }
 
   for (i = 0; i < 26; i++){
      if (val1[i] != val2[i])
        results = false;
   }
 
   return results;
}