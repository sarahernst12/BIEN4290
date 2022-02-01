/* 
* date created: 1/25/22
* creator: sarah ernst
* title: lab 0 part V
* description: opening file created in previous section, read contents, sum numbers, and output summation into new file
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    FILE *output;
    int numarray[20];
    char chararray[1000];
    int i = 0;
    int j = 0;
    int sum = 0;

    fp = fopen("randomnum.txt", "r");

    //check if reading file correctly, exit if read operation unsuccessful
    if (fp == NULL) {
        printf("error reading randomnumber text file\n");
        exit(EXIT_FAILURE);
    }

    //reading in numbers & summing all together
    while(fscanf(fp, "%d", &numarray[i]) != EOF){
        sum = sum + numarray[i];
        //printf("sum now equals: %d\n", sum);
    }

    //opening new file to write to
    output = fopen("summationoutput.txt", "w");

    //check if reading file correctly, exit if write operation unsuccessful
    if (output == NULL) {
        printf("error creating summationoutput text file\n");
        exit(EXIT_FAILURE);
    }

    //print out sum of all numbers into output file executable
    fprintf(output, "Sum of all numbers is: %d\n\n", sum);

    //print out contents of output file    
    printf("Sum of all numbers is: %d\n\n", sum);

    fclose(fp);
    fclose(output);
    return 0;
}

