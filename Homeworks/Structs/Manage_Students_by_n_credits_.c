//Code done by: Zackaria 
//When you see in a comment "-->HM" that means Homework
//------------------------------------------

#include <stdio.h>
#include <string.h>
#define MAX_CHAR 20
/*       User Defined Functions       */
//-->HM: you will have to fill in these prototypes
//For each function declaration, fill in the arguments data types
void menu(void); 
void fill_arrays(int no,int *credits,int *ids, char names[][MAX_CHAR]);
void print_arrays_content(const int *ids, const int *credits, int no_students,const char names[][MAX_CHAR]);
double search_student_earned_credits(char *name,char names[][MAX_CHAR],int no_students,int *credits);
void sort_students_by_credits(int n,int *credits,int *ids,char names[][MAX_CHAR]);
void swap(int *credits, int *ids, int i,char names[][MAX_CHAR]);

/*         Main Function        */
int main(void){
   //I am assuming that I have 35 students
   //For testing, we will work with n_students	 
   int IDs[35],Credits[35];
   int choice,n_students; 
   char names[35][MAX_CHAR];
   char name[MAX_CHAR];
   double credit_s;
   char c;
   
   do{
   	  //call menu function 
      menu();
      scanf("%d",&choice);
      switch(choice){
	    case 1:

            printf("\n\t\tInput the number of students>");
		      scanf("%d",&n_students);
			   //-->HM: call fill function and check if it is working 
            fill_arrays(n_students,Credits,IDs,names);

		       break;
	    case 2:
            //-->HM Call the appropriate Function
            // call print array content 
            print_arrays_content(IDs,Credits,n_students,names);
		       break;
	    case 3:
            //-->HM Call the appropriate Function
            // call sort_students_by_credits
            // in sort_students_by_credits call swap();
            sort_students_by_credits(n_students,Credits,IDs,names);
		       break;
	    case 4:
            // call search_student_earned_credits
            // return double=credit of the student
            scanf("%c",&c);
            printf("\nEnter the student's name> ");
            gets(name);
            credit_s=search_student_earned_credits(name,names,n_students,Credits);
            if (credit_s==0)
            {
               printf("\nThe student %s doesn't exist",name);
               continue;
            }
            printf("\nThe student %s has earned %.2lf credits",name,credit_s);
		       break;
	    case 5:
            printf("\n\t\tYou decided to QUIT\n\n\t\tBYE!\n\n\t\t");
               break;
	    default:
            printf("\n\t\tThat was an INVALID CHOICE!\n");

	  }
      //end of switch
      //clear wbhitespace
      
      
   }while(choice!=5);    

   return 0;
}
/*  Functions Definitions */
void menu(void){
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\t1. Fill Arrays\n");
  printf("\n\t\t2. Display Array Content\n");
  printf("\n\t\t3. Sort Students By Credits\n");
  printf("\n\t\t4. Get a Student's Number of Credits\n");
  printf("\n\t\t5. Quit\n");
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\tYour choice please:");
}

//-->HM: Define the remaining functions

void fill_arrays(int no,int *credits,int *ids, char names[][MAX_CHAR])
{
   //local declarations
   unsigned short i;
   char c;
   //filling the arrays
   printf("\n\t\t----------------------------------------\n");
   printf("\n\t\t\tFilling the array");
   printf("\n\t\t----------------------------------------\n");
   scanf("%c",&c);
   for ( i = 0; i < no; i++)
   {
      printf("\n\t\tEnter the name for the %d student> ",i+1);
      gets(names[i]);
      
      printf("\n\t\tEnter the ID of %s> ",names[i]);
      scanf("%d",&ids[i]);
      printf("\n\t\tEnter the number of credits for %s> ",names[i]);
      scanf("%d",&credits[i]);
      scanf("%c",&c);

   }
   printf("\n\t\t----------------------------------------\n");
}

//ADD NAME
void print_arrays_content(const int *ids, const int *credits, int no_students,const char names[][MAX_CHAR])
{
   //local declarations
   unsigned short i;
   printf("\n\t\t----------------------------------------\n");
   printf("\n\t\tStudent\t\tID\t\tCredits");
   for ( i = 0; i < no_students; i++)
   {
      printf("\n\t\t%s\t\t%d\t\t%d",names[i],ids[i],credits[i]);
   }
   
}


void sort_students_by_credits(int n,int *credits,int *ids,char names[][MAX_CHAR])
{
   //local declarations
   unsigned short i,j;
   //Bubble sort
   for ( i = 0; i < n-1; i++)
   {
      for ( j = n-1; j >i; j--)
      {
         if (credits[j]<credits[j-1])
         {
            swap(credits,ids,j,names);
         }
         
      }
      
   }
   

}
//ADD NAME of studetns

double search_student_earned_credits(char *name,char names[][MAX_CHAR],int n,int *credits)
{
   //local declarations
   unsigned short i,j;
   double credits_no=0;
   //find at which 
   for ( i = 0; i < n; i++)
   {
      if (strcmp(name,names[i])==0)
      {
         credits_no=credits[i];
         break;
      }
   }
   
   return credits_no;
}

void swap(int *credits, int *ids, int i,char names[][MAX_CHAR])
{
   //local declarations
   unsigned short temp;
   char temp1[MAX_CHAR];
   //credits swap
   temp=credits[i];
   credits[i]=credits[i-1];
   credits[i-1]=temp;
   //ids swap
   temp=ids[i];
   ids[i]=ids[i-1];
   ids[i-1]=temp; 
   //name swap
   strcpy(temp1,names[i]);
   strcpy(names[i],names[i-1]);
   strcpy(names[i-1],temp1);

}