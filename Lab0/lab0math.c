// date created: 1/25/22
// creator: sarah ernst
// title: lab 0 part V
// description: opening file created in previous section, read contents, sum numbers, and output summation into new file
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    FILE *fp;
    FILE *output;
    int numarray[20];
    int i;
    int sum = 0;

    fp = fopen("randomnum.txt", "r");

    //check if reading file correctly
    if (fp != NULL) {
        //printf("YAY!\n\n);
        //exit(1);
    }
    else printf("error reading randomnumber text file");

    //reading in numbers
    for (i = 0; i < 20; i++){
        fscanf(fp, "%d", &numarray[i]);
    }

    for (i = 0; i < 20; i++){
        sum = sum + numarray[i];
    }

    //printf("Sum of all numbers is: %d\n\n", sum);
    //for (i = 0; i < 20; i++){
    //    printf("Number is: %d\n\n", numarray[i]);
    //}

    output = fopen("summationoutput.txt", "w");

    //check if reading file correctly
    if (output != NULL) {
        //printf("YAY!\n\n);
        //exit(1);
    }
    else printf("error creating summationoutput text file");

    fprintf(output, "Sum of all numbers is: %d\n\n", sum);

    fclose(fp);
    fclose(output);
}

