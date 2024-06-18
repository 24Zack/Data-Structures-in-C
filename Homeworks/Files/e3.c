/**
 * Change the content of the file you used in exercise 2. Next to
 * each course code, write down the expected grade letter (A, B+, C-, D…).
 * Without loading the data to an array, define a function that will compute
 * the expected GPA.
 * You can use some additional user defined functions to solve the problem.
*/

#include <stdio.h>
#include <string.h>
float find_gpa(FILE *outfp);
float check_grade(char *grade);

int main(void)
{
    //declarations
    FILE *outfp;
    float gpa;
    outfp=fopen("courses1.txt","r");
    if (outfp==NULL)
    {
        printf("\nThe file doesnt exist or has not been found");
        return 1;
    }
    gpa=find_gpa(outfp);
    //output gpa
    printf("\nYour estimated gpa should be: %.2f",gpa);
    fclose(outfp);
    return 0;
}

float find_gpa(FILE *outfp)
{
    //local declarations
    char str[50],grade[4];
    int c=0;
    float t_gpa=0,t;
    while (!feof(outfp))
    {
        fscanf(outfp,"%s",str);
        fscanf(outfp,"%s",grade);
        t=check_grade(grade);
        if (t>=0)
        {
            t_gpa+=t;
            c++;
        }
    }
    //compute average gpa
    t_gpa/=c;
    return t_gpa;
}

float check_grade(char *grade)
{

    if (strcmp(grade,"A+")==0 || strcmp(grade,"A")==0)
    {
        return 4;
    }else if (strcmp(grade,"A-")==0)
    {
        return 3.67;
    }else if (strcmp(grade,"B+")==0)
    {
        return 3.33;
    }else if (strcmp(grade,"B")==0)
    {
        return 3;
    }else if (strcmp(grade,"B-")==0)
    {
        return 2.67;
    }else if (strcmp(grade,"C+")==0)
    {
        return 1.67;
    }else if (strcmp(grade,"C")==0)
    {
        return 2.0;
    }else if (strcmp(grade,"C-")==0)
    {
        return 1.67;
    }else if (strcmp(grade,"D+")==0)
    {
        return 1.33;
    }else if (strcmp(grade,"D")==0)
    {
        return 1;
    }else if (strcmp(grade,"F")==0)
    {
        return 0;
    }
    return -1;
    
}