//Code done by: Zackaria

//------------------------------------------

#include<stdio.h>
#include <string.h>

#define no_students 10

typedef struct 
{
    int ID;
    float gpa;
    char name[100];
}S_info;


/*       User Defined Functions       */
//For each function declaration, fill in the arguments data types
void menu(void); 
void fill_arrays(S_info *,FILE *infp);
void print_arrays_content(S_info *); 
void sort_students_by_gpa(S_info*);
void sort_students_by_name(S_info*);
void swap(S_info *d, S_info*s);
void update_file(S_info *x,FILE*outfp);

/*         Main Function        */
int main(void){
   
   int choice,filled=0;
   S_info x[10];
   FILE *infp;
   infp=fopen("data.txt","r+");
   if (infp==NULL)
    {
        printf("\nThis file is not found!");
        return 1;
    }

   do{
   	  //call menu function 
      menu();
      scanf("%d",&choice);
      switch(choice){
	    case 1:
            if (!filled)
            {
                fill_arrays(x,infp);
                filled=1;
            }else
            {
                printf("\nThe array is already filled");
            }
		       break;
	    case 2:
            if (!filled)
            {
                printf("\nSorry, you first need to fill the array before printing its content");
            }else
            {
                print_arrays_content(x);   
            }
		       break;
	    case 3:
            if (!filled)
            {
                printf("\nSorry, you first need to fill the array before sorting its content");
            }else
            {
                sort_students_by_gpa(x);
            }
            
		       break;
	    case 4:
            if (!filled)
            {
                printf("\nSorry, you first need to fill the array before sorting its content");
            }else
            {
                sort_students_by_name(x);
            }
		       break;
        case 5:
            if (!filled)
            {
                printf("\nSorry, you first need to fill the arrays before updating the original file");
            }else
            {
                update_file(x,infp);
            }
		       break;
	    case 6:
            printf("\n\t\tYou decided to QUIT\n\n\t\tBYE!\n\n\t\t");
               break;
	    default:
            printf("\n\t\tThat was an INVALID CHOICE!\n");
	  }//end of switch
   }while(choice!=6);    

   fclose(infp);
   return 0;
}
/*  Functions Definitions */
void menu(void){
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\t1. Fill Arrays using text files (data)\n");
  printf("\n\t\t2. Display Array Content\n");
  printf("\n\t\t3. Sort Students By GPA\n");
  printf("\n\t\t4. Sort Students By name\n");
  printf("\n\t\t5. Update original file\n");
  printf("\n\t\t6. Quit\n");
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\tYour choice please: ");
}

void fill_arrays(S_info *x, FILE *infp)
{
    //local declarations
    int i=0;
    char line[60];
    char temp;
 
    while (!feof(infp))
    {
        fgets(x[i].name,100,infp);
        fscanf(infp,"%f",&x[i].gpa);
        fgetc(infp);//get the newline char 
        fscanf(infp,"%d",&x[i].ID);
        fgetc(infp);
        fgetc(infp);
        i++;
    }
     
}

void print_arrays_content(S_info *x)
{
    //local declarations
    int i;

    for ( i = 0; i < no_students; i++)
    {
        printf("\nName: %s",x[i].name);
        printf("\nGPA: %.2f\n",x[i].gpa);
        printf("\nID: %d\n",x[i].ID);
        printf("\n--------------------------");
    }    
}

void sort_students_by_gpa(S_info*x)
{
    //local declarations
    int i,j,min_v=0;
    for ( i = 0; i < no_students-1; i++)
    {
        min_v=i;
        for ( j = i+1; j < no_students; j++)
        {
            if (x[j].gpa<x[min_v].gpa)
            {
                min_v=j;
            }
        }
        if (min_v!=i)
        {
            swap(&x[min_v],&x[i]);
        }   
    }
}

void swap(S_info *d, S_info*s)
{
    S_info temp;
    temp=*d;
    *d=*s;
    *s=temp;
}

void update_file(S_info *x,FILE*outfp)
{
    //local declarations
    int i=0;
    fseek(outfp,0,0);
    for ( i = 0; i < no_students; i++)
    {
        fprintf(outfp,"%s",x[i].name);
        fprintf(outfp,"%.2f\n",x[i].gpa);
        fprintf(outfp,"%d\n",x[i].ID);
        fprintf(outfp,"-------------------------------\n");
    }

}

void sort_students_by_name(S_info*x)
{
    //local declarations
    int i,j,min;
    //selection sort
    for ( i = 0; i < no_students-1; i++)
    {
        min=i;
        for ( j = i+1; j <no_students ; j++)
        {
            if (strcmp(x[i].name,x[j].name)>0)
            {
                min=j;
            }
            
        }
        if (min!=i)
        {
            swap(&x[min],&x[i]);
        }
        
    }
    
}