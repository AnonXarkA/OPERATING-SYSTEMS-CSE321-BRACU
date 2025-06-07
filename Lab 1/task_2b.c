#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SENTENCE_MAX_LENGHT 1500

int main() {
    char line[SENTENCE_MAX_LENGHT + 1]; 
    FILE *input;
    FILE *output;

    input = fopen("input.txt","r");
    output = fopen("output.txt","w");

    fgets(line, sizeof(line), input);

    fclose(input);


    char *token = strtok(line, " ");
    if (token != NULL) {
        fputs(token, output);
        while ((token = strtok(NULL, " ")) != NULL) {
            fputs(" ", output);
            fputs(token, output);
        }
    }
    

    
    fclose(output);




}   



