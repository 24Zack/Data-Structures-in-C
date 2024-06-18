//Code done by: Zackaria
//When you see in a comment "-->HM" that means Homework
//------------------------------------------

#include <stdio.h>
#include <string.h>
#define MAX_CHAR 20
#define NO_STUDENTS 35
typedef struct 
{
   char name[MAX_CHAR];
   int ID;
   int a_p_ext;
}A_info;

typedef struct 
{
   int   ID,
         Credits;
   char name[MAX_CHAR];
   A_info x;
}S_info;

//Functions prototypes
void menu(void); 
void fill_arrays(S_info*x,int n);
void print_arrays_content(const S_info*x,int n);
double search_student_earned_credits(S_info *x,int id, int n);
void sort_students_by_credits(S_info *x, int n);
void swap(S_info *x,S_info *y);
void sort_by_name(S_info *x, int n);




/*         Main Function        */
int main(void){
   //I am assuming that I have 35 students
   //For testing, we will work with n_students	 
   S_info x[NO_STUDENTS];
   int n,choice,id;
   double credits;
   do{
   	  //call menu function 
      menu();
      scanf("%d",&choice);
      switch(choice){
	    case 1:

            printf("\n\t\tInput the number of students>");
		      scanf("%d",&n);
			   //Call fill array
            fill_arrays(x,n);
		       break;
	    case 2:
            // call print array content 
            print_arrays_content(x,n);
		       break;
	    case 3:
            // call sort_students_by_credits
            sort_students_by_credits(x,n);
		       break;
	    case 4:
            // call search_student_earned_credits
            printf("\nEnter the student's ID> ");
            scanf("%d",&id);
            credits=search_student_earned_credits(x,id,n);
            if (credits==0)
            {
               printf("\nThe student id %d does not exist",id);
               break;
            }
            printf("\n%d has %.2lf credits earned",id,credits);
		       break;
	    case 5:
            sort_by_name(&x,n);
      
               break;
      case 6:
            printf("\n\t\tYou decided to QUIT\n\n\t\tBYE!\n\n\t\t");
		       break;
	    default:
            printf("\n\t\tThat was an INVALID CHOICE!\n");

	  }

   }while(choice!=6);    

   return 0;
}
/*  Functions Definitions */
void menu(void){
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\t1. Fill Arrays\n");
  printf("\n\t\t2. Display Array Content\n");
  printf("\n\t\t3. Sort Students By Credits\n");
  printf("\n\t\t4. Get a Student's Number of Credits\n");
  printf("\n\t\t5. Sort students by name\n");
  printf("\n\t\t6. Quit\n");
  printf("\n\t\t----------------------------------------\n");
  printf("\n\t\tYour choice please:");
}

/*       Defining functions         */

void fill_arrays(S_info*x,int n)
{
   //local declarations
   unsigned short i;
   char c;
   //filling the arrays
   printf("\n\t\t----------------------------------------\n");
   printf("\n\t\t\tFilling the array");
   printf("\n\t\t----------------------------------------\n");
   scanf("%c",&c);
   for ( i = 0; i < n; i++)
   {
      printf("\nEnter the name of the student> ");
      gets(x[i].name);
      printf("\nEnter the ID of %s: ",x[i].name);
      scanf("%d",&x[i].ID);
      printf("\nEnter the the number of credits of %s: ",x[i].name);
      scanf("%d",&x[i].Credits);
      scanf("%c",&c);
      
      
   }
   printf("\n\t\t----------------------------------------\n");
}

//ADD NAME
void print_arrays_content(const S_info*x,int n)
{
   //local declarations
   unsigned short i;
   printf("\n\t\t----------------------------------------\n");
   for ( i = 0; i < n; i++)
   {
      printf("\n------------------");
      printf("\nStudent %d: ",i+1);
      printf("\nName: %s",x[i].name);
      printf("\nID: %d",x[i].ID);
      printf("\nCredits: %d",x[i].Credits);
   }
   
   
}


void sort_students_by_credits(S_info *x, int n)
{
   //local declarations
   unsigned short i,j,min_in;
   //selection sort
   for ( i = 0; i < n-1; i++)
   {
      min_in=i;
      for ( j = i+1; j < n; j++)
      {
         if (x[j].Credits<x[min_in].Credits)
         {
            min_in=j;
         }
         
      }
      if (min_in!=i)
      {
         swap(&x[min_in],&x[i]);
      }
   }
   
}

double search_student_earned_credits(S_info *x,int id, int n)
{
   //local declarations
   unsigned short i,j;

   for ( i = 0; i < n; i++)
   {
      if (x[i].ID==id)
      {
         return x[i].Credits;
      }
      
   }
   return 0;
}

void swap(S_info *x,S_info *y)
{
   //local declarations
   S_info temp=*x;
   *x=*y;
   *y=temp;
}

void sort_by_name(S_info *x, int n)
{
   //Local declarations
   int i,j;
   for ( i = 0; i < n-1; i++)
   {
      for ( j = n-1; j >i; j--)
      {
         if (strcmp(x[j].name,x[j-1].name)<0)
         {
            swap(&x[j-1],&x[j]);
         }
         
      }
      
   }
   
}