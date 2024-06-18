#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
typedef struct nd
{
    char ch;
    struct nd *next;
} node;
//      Functions prototypes
int push(char *, int *, char, int);
char pop(char *, int *);
int check_balanced_expression(char *, char *, int, int);
void Load_Expression_File_Array(FILE *, char *, int);
int Compute_Size_Infix(FILE *);
int check_expression_parentheses(char *);
int Compute_Size_Stack_p(char *);
int Compute_Size_Stack_p_and_operators(char *);
void Menu(void);
char check_top_stack(char *, int);
int priority(char);
void convert_infix_postfix_no_parentheses(char *, char *, char *, int, int);
void convert_infix_postfix_wparentheses(char *infix_expression, char *postfix_expression, char *stack, int top, int stack_size);
int compute_postfix(node *top, char *postfix);
void push_LL(node **top, node *topush);
char pop_LL(node **top);

int main(void)
{
    // declarations
    char *stack, *infix_expression, *postfix_expression;
    FILE *infp;
    int stack_size, infix_size, status = 0, choice, top = -1, converted = 0, sum;
    node *top_LL = NULL;

    // opening the file
    infp = fopen("infix.txt", "r");
    if (infp == NULL)
        printf("\n\t\tCould NOT open the FILE!\n\n\t\t");
    else
    {
        // File opened
        infix_size = Compute_Size_Infix(infp);
        infix_expression = (char *)calloc(infix_size, sizeof(char)); // Dynamically allocating the memory of the array using the size of the infix
        Load_Expression_File_Array(infp, infix_expression, infix_size);
        printf("\n\t\tYour file has the following expression:%s\n", infix_expression);
        fclose(infp); // From now on, I will work with the infix expression

        do
        {
            Menu();
            scanf("%d", &choice);
            switch (choice)
            {

            case 1:
                // Check if expression is balanced or not in terms of () and []
                status = check_expression_parentheses(infix_expression);
                if (status == 1)
                { // expression has () or/and[]
                    stack_size = Compute_Size_Stack_p(infix_expression);
                    stack = (char *)calloc(stack_size, sizeof(char));                             // stack created with memory that will hold either ( or [
                    status = check_balanced_expression(infix_expression, stack, top, stack_size); // A function to implement // Return 0 if not balanced, 1 otherwise
                    if (status == 0)
                    {
                        printf("\n\t\t%s is not a Balanced Expression!\n", infix_expression);
                        printf("\n\t\tSORRY, Your program will TERMINATE NOW!\n\n\t\t");
                        return 0;
                    }
                    else
                    {
                        printf("\n\t\t%s is a Balanced Expression!\n", infix_expression);
                        free(stack);
                    }
                }
                else
                    printf("\n\t\tYour infix expression does not contain parentheses or brackets\n");
                break;
            case 2:
                stack = (char *)calloc(2, sizeof(char));
                postfix_expression = (char *)calloc(infix_size, sizeof(char));
                convert_infix_postfix_no_parentheses(infix_expression, postfix_expression, stack, top, 2);
                printf("\n\t\t%s converted to postfix:%s\n", infix_expression, postfix_expression);
                free(stack);
                converted = 1;
                break;
            case 3:
                // Here you need to call a function that
                // Implements the second algorithm we discussed in class
                // The algorithm is the following:
                /*
                 Read character by character:
                If it is a operand then write it to postfix
                If it is a left parenthesis then push it on stack
                If it is an operator:
                    If the top of the stack is an operator of lower priority OR the stack is empty then push the operator on the stack
                    Else, as long as the stack is not empty, pop all operators from the stack  till encountering an operator of lower priority (strictly less) OR till a left parenthesis is encountered / this later should not be popped - and write them to postfix; then push the read operator onto stack
                    NB: The parenthesis is of less priority than operators
                Else if it is a right parenthesis:
                    Pop all operators till a left parenthesis is popped and write them to the output Do not write parentheses to postfix
                When all characters are read, pop the remaining operators and write them to postfix
                 */
                if (!status)
                {
                    printf("\nPlease check if the expression is balanced");
                }
                else
                {
                    stack_size = Compute_Size_Stack_p_and_operators(infix_expression);
                    stack = (char *)calloc(stack_size, sizeof(char));
                    postfix_expression = (char *)calloc(infix_size, sizeof(char)); // look for a way to OPTIMIZE the size of the postfix====
                    convert_infix_postfix_wparentheses(infix_expression, postfix_expression, stack, top, stack_size);
                    printf("\n\t\t%s converted to postfix:%s\n", infix_expression, postfix_expression);
                    converted = 1;
                }

                break;
            case 4:
                /*You are asked to implement the following algorithm:
                 Use the postfix expression: character by character
                 IF a number then push it on stack
                 Else if an operator
                 Pop 2 numbers from stack
                 Apply the operator to the 2 numbers
                 Push the result in the stack
                */
                // You need to use a stack implemented using Linked Lists
                // BEST of LUCK
                if (converted)
                {
                    sum = compute_postfix(top_LL, postfix_expression);
                    printf("\nThe sum of %s is %d", postfix_expression, sum);
                }
                else
                {
                    printf("\nYou must first convert the infix expression into a postfix one!");
                }
                break;
            case 5:
                printf("\n\t\tYou are Quitting....\n\t\tBye");
                break;
            default:
                printf("\n\t\tWrong CHOICE!\n");
            } // Close of Switch
        } while (choice != 5);
    }
    return (0);
}

void Menu(void)
{

    printf("\n\t\t------------------- MENU-------------------\n");
    printf("\n\t\t1.Check if a Math Expression is Balanced\n");
    printf("\n\t\t2.Convert infix to postfix (expression without()[])\n");
    printf("\n\t\t3.Convert infix to postfix (expression with()[])\n");
    printf("\n\t\t4.Execute Postfix Expression\n");
    printf("\n\t\t5.QUIT\n");
    printf("\n\t\t--------------------------------------------\n");
    printf("\n\t\tYour choice please:");
}

//  Functions definitions
int push(char *stack, int *top, char ToPush, int size)
{

    if (*top == size - 1) // Stack Overflow
        return (0);
    else
    {
        stack[++(*top)] = ToPush;
        return (1);
    }
}

char pop(char *stack, int *top)
{

    if (*top == -1) // Empty Stack
        return ('$');
    else
    {
        return (stack[(*top)--]);
    }
}

int check_balanced_expression(char *infix, char *stack, int top, int stack_size)
{
    // declarations
    int i;
    char ch_s;
    for (i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '(' || infix[i] == '[')
        {
            push(stack, &top, infix[i], stack_size);
        }
        else if (infix[i] == ')' || infix[i] == ']')
        {
            ch_s = pop(stack, &top);
            if (ch_s == '$')
            {
                return 0;
            }
            else if ((infix[i] == ')' && ch_s != '(') || (infix[i] == ']' && ch_s != '['))
            {
                return 0; // expression is not balanced, meaning the closing parenthesis is not of the same type as the opening parenthesis
            }
        }
    }
    // check if the stack is empty
    if (top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Load_Expression_File_Array(FILE *infp, char *expression, int size)
{
    fseek(infp, 0, 0);
    fgets(expression, size, infp);
}

int Compute_Size_Infix(FILE *infp)
{
    // declrations
    int cnt = 0;
    char ch;

    do
    {
        ch = getc(infp);
        cnt++;
    } while (ch != EOF);

    return (cnt); // cnt is the size to use for the infix array
}

int check_expression_parentheses(char *infix)
{
    // declarations
    int i;
    for (i = 0; i < strlen(infix); i++)
    {
        if (infix[i] == '(' || infix[i] == ')' || infix[i] == '[' || infix[i] == ']')
        {
            return 1;
        }
    }
    return 0;
}

int Compute_Size_Stack_p(char *infix_expression)
{
    int i = 0, cnt = 0;
    char ch;
    while (infix_expression[i] != '\0')
    {
        ch = infix_expression[i++];
        if (ch == '(' || ch == '[')
            cnt++;
    }
    return (cnt);
}
int Compute_Size_Stack_p_and_operators(char *infix_expression)
{
    // local declarations$
    int i = 0, cnt = 0;
    char ch;
    while (infix_expression[i] != '\0')
    {
        ch = infix_expression[i];
        if (ch == '(' || ch == '[' || ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            cnt++;
        }
        i++;
    }
    return cnt;
}

char check_top_stack(char *stack, int top)
{

    if (top == -1)
        return ('$');
    else
        return (stack[top]);
}

int priority(char ch)
{

    if (ch == '*' || ch == '/')
        return (2);
    else if (ch == '+' || ch == '-')
        return (1);
    else
        return (0);
}

void convert_infix_postfix_no_parentheses(char *infix_expression, char *postfix_expression, char *stack, int top, int stack_size)
{

    // This is the first algorithm we discussed in class about infix to postfix

    int i, j = 0;
    char ch, char_top_stack, popped_char;

    for (i = 0; i < strlen(infix_expression); i++)
    {
        ch = infix_expression[i];
        if (ch == '+' || ch == '-' || ch == '/' || ch == '*') // an operator is encountered
        {
            if (top == -1) // Stack is empty
                push(stack, &top, ch, stack_size);
            else
            { // Stack is not empty
                char_top_stack = check_top_stack(stack, top);
                while ((priority(char_top_stack) >= priority(ch)) && top != -1)
                {
                    popped_char = pop(stack, &top);
                    postfix_expression[j++] = popped_char;
                    char_top_stack = check_top_stack(stack, top);
                }
                push(stack, &top, ch, stack_size);
            }
        }
        else // operand
            postfix_expression[j++] = ch;
    } // When scanning all the infix
    while (top != -1)
        postfix_expression[j++] = pop(stack, &top);

    postfix_expression[j] = '\0';
}

void convert_infix_postfix_wparentheses(char *infix_expression, char *postfix_expression, char *stack, int top, int stack_size)
{
    // Here you need to call a function that
    // Implements the second algorithm we discussed in class
    // The algorithm is the following:
    /*
     Read character by character:
    If it is a operand then write it to postfix
    If it is a left parenthesis then push it on stack
    If it is an operator:
        If the top of the stack is an operator of lower priority OR the stack is empty then push the operator on the stack
        Else, as long as the stack is not empty, pop all operators from the stack  till encountering an operator of lower priority (strictly less) OR till a left parenthesis is encountered / this later should not be popped - and write them to postfix; then push the read operator onto stack
        NB: The parenthesis is of less priority than operators
    Else if it is a right parenthesis:
        Pop all operators till a left parenthesis is popped and write them to the output Do not write parentheses to postfix
    When all characters are read, pop the remaining operators and write them to postfix
     */
    // local declarations
    int i, j = 0;
    char ch, char_top_stack, popped_char;
    for (i = 0; i < strlen(infix_expression); i++)
    {
        ch = infix_expression[i];
        if (ch == '(' || ch == '[')
        {
            push(stack, &top, ch, stack_size);
        }
        else if (ch == '+' || ch == '-' || ch == '/' || ch == '*')
        {
            if (top == -1)
            {
                push(stack, &top, ch, stack_size);
            }
            else
            {
                char_top_stack = check_top_stack(stack, top);
                while ((priority(char_top_stack) >= priority(ch)) && top != -1)
                {
                    popped_char = pop(stack, &top);
                    postfix_expression[j++] = popped_char;
                    char_top_stack = check_top_stack(stack, top);
                }
                push(stack, &top, ch, stack_size);
            }
        }
        else if (ch == ')' || ch == ']')
        {
            char_top_stack = check_top_stack(stack, top);
            while (char_top_stack != '(' && char_top_stack != '[')
            {
                popped_char = pop(stack, &top);
                postfix_expression[j++] = popped_char;
                char_top_stack = check_top_stack(stack, top);
            }
            popped_char = pop(stack, &top);
        }
        else
        {
            postfix_expression[j++] = ch;
        }
    }

    while (top != -1)
    {
        popped_char = pop(stack, &top);
        postfix_expression[j++] = popped_char;
    }
    postfix_expression[j] = '\0';
}

int compute_postfix(node *top, char *postfix)
{
    // declarations
    int i, tot;
    char c, op1, op2, total;
    node *new_nd;
    for (i = 0; i < strlen(postfix); i++)
    {
        c = postfix[i];
        if (isdigit(c))
        {
            // create
            new_nd = (node *)malloc(sizeof(node));
            // fill
            new_nd->ch = c;
            // attach
            push_LL(&top, new_nd);
        }
        else if (c == '*' || c == '+' || c == '-' || c == '/')
        {
            op1 = pop_LL(&top);
            op2 = pop_LL(&top);
            // applying the operation
            switch (c)
            {
            case '*':
                tot = ((int)(op1 - '0') * (int)(op2 - '0'));
                break;
            case '+':
                tot = ((int)(op1 - '0') + (int)(op2 - '0'));
                break;
            case '-':
                tot = ((int)(op1 - '0') - (int)(op2 - '0'));
                break;
            case '/':
                tot = ((int)(op1 - '0') / (int)(op2 - '0'));
                break;
            default:
                break;
            }
            // create
            new_nd = (node *)malloc(sizeof(node));
            // fill
            total = tot + '0';
            new_nd->ch = total;
            // attach
            push_LL(&top, new_nd);
        }
    }
    // Pop the content of the stack at the end
    c = pop_LL(&top);
    tot = c - '0';
    return tot;
}

void push_LL(node **top, node *topush)
{
    if (*top == NULL)
    {
        *top = topush;
    }
    else
    {
        topush->next = *top;
        *top = topush;
    }
}

char pop_LL(node **top)
{
    // local declarations
    node *temp;
    char c;
    if (*top == NULL)
    {
        return '^';
    }
    else
    {
        temp = *top;
        *top = temp->next;
        c = temp->ch;
        free(temp);
        return c;
    }
}