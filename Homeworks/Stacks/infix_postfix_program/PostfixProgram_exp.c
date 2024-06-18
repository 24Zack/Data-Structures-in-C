#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int push(char*stack,int*top,char ToPush,int size){

  if(*top==size-1)//Stack Overflow
    return(0);
  else{
    stack[++(*top)]=ToPush;
    return(1);
  }
}

char pop(char*stack,int*top){

 if(*top==-1)//Empty Stack
   return('$'); 
 else{
   return(stack[(*top)--]);  
 }
}

int check_balanced_expression(char *infix, char *stack, int top, int stack_size){
  //declarations
  int i;
  char ch_s;
  for ( i = 0; i < strlen(infix); i++)
  {
    if (infix[i]=='('||infix[i]=='[')
    {
      push(stack,top,infix[i],stack_size);
    }else if (infix[i]==')'||infix[i]==']')
    {
      ch_s=pop(stack,&top);
      if ((infix[i]==')' && ch_s!='(') || (infix[i]==']' && ch_s!='['))
      {
        return 0; // if what we read is a closing parenthesis and what we pop is 
      }
      
    }
  }
  //check if the stack is empty
  if (top==-1)
  {
    return 1;
  }else
  {
   return 0; 
  }
}
void Load_Expression_File_Array(FILE*infp, char*expression,int size){
  
  fseek(infp,0,0);
  fgets(expression,size,infp);
}
int Compute_Size_Infix(FILE*infp){
  int cnt=0;
  char ch;
  
  do{
    ch=getc(infp);
    cnt++;
  }while(ch!=EOF);
  
  return(cnt);//cnt is the size to use for the infix array
}
int check_expression_parentheses(char *infix){
  //declarations
  int i;
  for ( i = 0; i < strlen(infix); i++)
  {
    if (infix[i]=='('||infix[i]==')'||infix[i]=='['||infix[i]==']')
    {
      return 1;
    }
  }
  return 0;
}

int Compute_Size_Stack_p(char*infix_expression){
  int i=0,cnt=0; 
  char ch;
  while(infix_expression[i]!='\0')
  {
   ch=infix_expression[i++];	
   if(ch=='(' || ch=='[')
    cnt++;
   }
  return(cnt); 
}

void Menu(void){
   
   printf("\n\t\t------------------- MENU-------------------\n");
   printf("\n\t\t1.Check if a Math Expression is Balanced\n");
   printf("\n\t\t2.Convert infix to postfix (expression without()[])\n");
   printf("\n\t\t3.Convert infix to postfix (expression with()[])\n");
   printf("\n\t\t4.Execute Postfix Expression\n");
   printf("\n\t\t5.QUIT\n");
   printf("\n\t\t--------------------------------------------\n");
   printf("\n\t\tYour choice please:");
}
char check_top_stack(char*stack,int top){

if (top==-1)
  return('$'); 
else
  return(stack[top]);
}
int priority(char ch){
 
  if(ch=='*' || ch=='/')
    return(2);
  else if(ch=='+' || ch=='-')
    return(1);
  else
    return(0);
}
void convert_infix_postfix_no_parentheses(char*infix_expression,char*postfix_expression,char*stack,int top,int stack_size){

// This is the first algorithm we discussed in class about infix to postfix
  
   int i,j=0; 
   char ch, char_top_stack, popped_char;
   
   for(i=0;i<strlen(infix_expression);i++)
    {
      ch=infix_expression[i];	
	  if(ch=='+' || ch=='-' || ch=='/' || ch=='*' )//an operator
	    { 
		if(top==-1)//Stack is empty
	      push(stack,&top,ch,stack_size);
        else{//Stack is not empty
          char_top_stack=check_top_stack(stack,top);        	
		  while ((priority(char_top_stack)>= priority(ch)) && top!=-1)
		    {
             popped_char= pop(stack,&top);
			 postfix_expression[j++]=popped_char;
			 char_top_stack=check_top_stack(stack,top);			
			}
			push(stack,&top,ch,stack_size);		
		  }			
	    }
      else//operand
	   	 postfix_expression[j++]=ch;
	}//When scanning all the infix
   while(top!=-1)
     postfix_expression[j++]=pop(stack,&top);
   
     postfix_expression[j]='\0';
}
int main (void){

 char*stack,*infix_expression,*postfix_expression;
 FILE*infp; 
 int stack_size,infix_size,status,choice,top=-1;
 infp=fopen("Infix.txt","r");
 
 if(infp==NULL)
   printf("\n\t\tCould NOT open the FILE!\n\n\t\t");
 else{//File opened 
  infix_size=Compute_Size_Infix(infp);
  infix_expression = (char*)calloc(infix_size,sizeof(char));//Infix array has memory allocated
  Load_Expression_File_Array(infp,infix_expression,infix_size); 
  printf("\n\t\tYour file has the following expression:%s\n",infix_expression);
  fclose(infp);// From now on, I will work with the infix expression
  do{
  Menu();
  scanf("%d",&choice);
  switch(choice){
   
  case 1://Check if expression is balanced or not in terms of () and []
         status=check_expression_parentheses(infix_expression);
         if(status==1){//expression has () or/and[]
         stack_size=Compute_Size_Stack_p(infix_expression);
         stack = (char*)calloc(stack_size,sizeof(char));//stack created with memory that will hold either ( or [
         status=check_balanced_expression(infix_expression,stack,top,stack_size);//A function to implement // Return 0 if not balanced, 1 otherwise
         if(status==0)
           {
           	printf("\n\t\t%s is not a Balanced Expression!\n",infix_expression);
           	printf("\n\t\tSORRY, Your program will TERMINATE NOW!\n\n\t\t");
           	return 0;		   
		   }
         else{
		    printf("\n\t\t%s is a Balanced Expression!\n",infix_expression);
		    free(stack);
		 }
         }
         else
           printf("\n\t\tYour infix expression does not contain parentheses or brackets\n");
         break;  
  case 2:stack= (char*)calloc(2,sizeof(char)); 
         postfix_expression=(char*)calloc(infix_size,sizeof(char));
		 convert_infix_postfix_no_parentheses(infix_expression,postfix_expression,stack,top,2);
         printf("\n\t\t%s converted to postfix:%s\n",infix_expression, postfix_expression);		 
		 free(stack);         
         break;
  case 3://Here you need to call a function that 
         //Implements the second algorithm we discussed in class
         //The algorithm is the following: 
         /*
		 Read character by character:
		If it is a operand then write it to postfix
		If it is a left parenthesis then push it on stack
		If it is an operator:
			If the top of the stack is an operator of lower� priority OR the stack is empty then push the operator on the stack
			Else, as long as the stack is not empty, pop all operators from the stack � till encountering an operator of lower priority (strictly less) OR till a left parenthesis is encountered / this later should not be popped - and write them to postfix; then push the read operator onto stack 
			NB: The parenthesis is of less priority than operators
		Else if it is a right parenthesis:
			Pop all operators till a left parenthesis is popped and write them to the output Do not write parentheses to postfix
		When all characters are read, pop the remaining operators and write them to postfix
		 */
         break;
  case 4:/*You are asked to implement the following algorithm:
		 Use the postfix expression: character by character
		 IF a number then push it on stack
		 Else if an operator
		 Pop 2 numbers from stack
		 Apply the operator to the 2 numbers 
		 Push the result in the stack
		 */
         //You need to use a stack implemented using Linked Lists
		 //BEST of LUCK
         break;
  case 5: printf("\n\t\tYou are Quitting....\n\t\tBye");
          break;
  default:printf("\n\t\tWrong CHOICE!\n");
 }//Close of Switch
 }while(choice!=5);
 }
return(0);
}
