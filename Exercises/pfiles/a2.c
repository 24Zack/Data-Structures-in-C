/**
 * 1. Write a program in C to create and store information in a text file.
Test Data :
Input a sentence for the file : This is the content of the file test.txt.
Expected Output :

 The file test.txt created successfully...!! 
*/
#include <stdio.h>

int main(void)
{
    //declarations
    FILE *p;
    char str[50];
    p=fopen("test.txt","w");
    printf("\nEnter any string/sentence> ");
    fgets(str,50,stdin);
    fprintf(p,"%s\n",str);
    fclose(p);
    printf("The file test.txt created successfully...!!\n");
}