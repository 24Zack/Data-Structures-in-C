/**
 * Program where you enter the name of the file and fill it
*/
#include <stdio.h>

int main(void)
{
    //declarations
    FILE *f;
    char name_str[30];
    char name[50];
    int age;

    printf("\nEnter the name of the file: ");
    scanf("%s",name_str);
    f=fopen(name_str,"a");
    getchar();
    printf("\nEnter your name> ");
    fgets(name,50,stdin);
    fprintf(f,"%s",name);
    printf("\nEnter your age> ");
    scanf("%d",&age);
    fprintf(f,"Age: %d\n",age);
    fprintf(f,"-----------------------------\n");

    fclose(f);
    return 0;
}