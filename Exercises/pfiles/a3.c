/**
 * 2. Write a program in C to read an existing file.
Test Data :
Input the file name to be opened : test.txt
Expected Output :

 The content of the file test.txt is  :                                                                       
This is the content of the file test.txt.
*/
#include <stdio.h>
#define file "test.txt"
int main(void)
{
    //declarations
    FILE *p;
    char str[150];
    
    p=fopen(file,"r");
    if (p==NULL)
    {
        printf("\nFile doesn't exist");
        return 1;
    }
    
    printf("\nThis is the content of the file test.txt: ");
    while (!feof(p))
    {
        fgets(str,50,p);
        printf("\n%s",str);
    }
    fclose(p);
    
}