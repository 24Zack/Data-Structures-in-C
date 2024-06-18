#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Enumerated type for the menu
typedef enum {
  Start_office_hours = 1,
  Serve = 2,
  Join = 3,
  Change_place = 4,
  Quit_Queue = 5,
  Stop = 6
} menu_t;

// Structure
typedef struct s_inf {
  char name[80];
  unsigned short ID;
  unsigned short time_mins;
  struct s_inf *next;
} s_info;

// Function prototypes
void menu(void);
void enqueue(s_info **front,s_info**rear,s_info*To_enqueue);
void dequeue(s_info **front,s_info**rear,char *To_serve);
void start_office_hours(FILE* infp, s_info** front, s_info** rear);
int Serve_student(s_info **front, s_info **rear, char *Currently_served);
void office_status(char *Student);
void display_waitlist(s_info *front);
int Change_place_students(s_info *front,unsigned short id1, unsigned short id2);
void finish_office_hours(s_info* front);
int Quit(s_info**front, s_info**rear, unsigned short id); 
void _fill_nd( s_info*To_fill, s_info *To_copy);
void _fill_nd_wnull( s_info*To_fill, s_info *To_copy);
void queue_to_file(s_info *front);
void timer(s_info *temp);


int main(void)
{
    //declarations
    s_info  *front=NULL,*rear=NULL,*toAdd;
    unsigned short  choice,status=0,id1,id2;
    char Served[80];
    FILE *infp;
    do
    {
        menu();
        scanf("%hu",&choice);
        switch (choice)
        {
        case Start_office_hours:

            infp= fopen("Appointment.txt","r");
            if (infp==NULL)
            {
                infp= fopen("Appointment.txt","w");
                status=1;
            }else
            {
                start_office_hours(infp,&front,&rear);
                status=1;
                fclose(infp);
                display_waitlist(front);
                queue_to_file(front);
            }
            printf("\n\n\tOffice hours started...");
            break;
        case Serve:
            if (status)
            {
                if (!Serve_student(&front,&rear,Served))
                {
                    printf("\n\tThe Queue is empty !");
                }else
                {
                    office_status(Served);  
                    display_waitlist(front);
                    queue_to_file(front);
                }
            }else
            {
                printf("\n\tYou first must start the office hours! ");
            }

            break;
        case Join:
            if (status)
            {
                //create node
                toAdd=(s_info*)malloc(sizeof(s_info));
                //fill
                fflush(stdin);
                printf("\n\tEnter the name of the new student: ");
                gets(toAdd->name);
                fflush(stdin);
                printf("\n\tEnter %s's ID: ",toAdd->name);
                scanf("%hu",&toAdd->ID);
                printf("\n\tHow much time does %s need in the office: ",toAdd->name);
                scanf("%hu",&toAdd->time_mins);
                //Enqueue
                enqueue(&front,&rear,toAdd);
                printf("\n\t-----------------------------------------------");
                printf("\n\t%s (%d) joined the Queue successfully!",toAdd->name,toAdd->ID);
                display_waitlist(front);
                queue_to_file(front);
            }else
            {
                printf("\n\tYou first must start the office hours! ");
            }
            
            break;
        case Change_place:
            if (status)
            {
                fflush(stdin);
                printf("\n\tEnter the ID of the first student: ");
                scanf("%hu",&id1);
                fflush(stdin);
                printf("\n\tEnter the ID of the student who wants to take the first student's place: ");
                scanf("%hu",&id2);
                fflush(stdin);
                if (!Change_place_students(front,id1,id2))
                {
                    printf("\n\tYou entered one or two wrong IDs,or the Queue is empty, please retry!");
                }else
                {
                    printf("\n\tThe change has been executed successfully!");
                }
                display_waitlist(front);
                queue_to_file(front);
            }else
            {
                printf("\n\tYou first must start the office hours! ");
            }
            break;
        case Quit_Queue:
            if (status)
            {
                printf("\n\tEnter the student's ID: ");
                scanf("%hu",&id1);
                if (Quit(&front,&rear,id1))
                {
                    printf("\n\t%hu has left the Queue successfully !",id1);
                }else
                {
                    printf("\n\tYou entered a wrong ID, or %hu is not in the Queue!",id1);
                }  
                display_waitlist(front);
                queue_to_file(front);
            }else
            {
                printf("\n\tYou first must start the office hours! ");
            }
            break;
        case Stop:
            if (status)
            {
                finish_office_hours(front);
                printf("\n\tOffice hours OVER!!   Goodbye !");
            }else
            {
                printf("\n\tYou first must start the office hours, before stopping them !");
            }
            break;
        default:
            printf("\n\tYou made an invalid choice.");
            break;
        }
        fflush(stdin);
        printf("\n");
    }while((choice!=6) || status!=1);
    
    return 0; 
}


//Function definitions
void menu(void)
{
    printf("\n\t==================MENU==================");
    printf("\n\tWelcome to Dr. T's office hours!");
    printf("\n\t1. Start office hours");
    printf("\n\t2. Serve a student");
    printf("\n\t3. Join the queue");
    printf("\n\t4. Switch places");
    printf("\n\t5. Quit the queue");
    printf("\n\t6. Office hours are over!");
    printf("\n\t========================================");
    printf("\n\tYour choice please: ");
 
}

void enqueue(s_info **front,s_info**rear,s_info*To_enqueue)
{
    if (*front==NULL)
    {
        *front=To_enqueue;
        *rear=To_enqueue;
        (*rear)->next=*front;
    }else
    {
        (*rear)->next=To_enqueue;
        *rear=To_enqueue;
        (*rear)->next=*front;
    }
}

void dequeue(s_info **front,s_info**rear,char *To_serve)
{
    //local declarations
    s_info*temp; 

    if (*front==NULL)
    {
        strcpy(To_serve,"empty");
    }else
    {
        temp=*front;
        strcpy(To_serve,temp->name);
        *front=temp->next;
        if(*front==temp){
            *front=NULL;
            *rear=NULL;
        } else{
            (*rear)->next=*front;
        }
        free(temp);
    }
}

void start_office_hours(FILE* infp, s_info** front, s_info** rear)
{
    s_info *new_node, *walker;
    char line[50];
    fseek(infp, 0, 0);//make sure that the cursor is at the start
    if (fgetc(infp) == EOF)//in case the file is empty
    fseek(infp, 0 ,0);//just reseting the cursor
    else{
        fseek(infp,0,0);
        while(!feof(infp)){
            new_node = (s_info*)malloc(sizeof(s_info));
            fgets(new_node->name, 80, infp);
            //remove \n
            new_node->name[strcspn(new_node->name, "\n")] = '\0';
            fscanf(infp,"%hu\n", &new_node->ID);
            fscanf(infp,"%hu\n", &new_node->time_mins);
            fgets(line, 50, infp);
            new_node->next=NULL;
            enqueue(front,rear,new_node);
        }
    }
}

int Serve_student(s_info **front, s_info**rear, char *Currently_served)
{
    //local declarations
    s_info *temp=*front,*new_nd;
    if (*front==NULL)
    {
        return 0;
    } else if (temp->time_mins<=5)
    {
        printf("Current time: %s\n", time(NULL));
        timer(temp);
        dequeue(front,rear,Currently_served);
    }else if ((temp->time_mins>5)&& temp->next==*front)
    {
        //one person is waiting in the Queue
        printf("Current time: %s\n", time(NULL));
        timer(temp);
        dequeue(front,rear,Currently_served);
    }else
    {
        //create
        new_nd=(s_info*)malloc(sizeof(s_info));
        //fill 
        _fill_nd(new_nd,*front);
        //update the number of mins
        new_nd->time_mins-=5; 
        // dequeue new_nd
        printf("Current time: %s\n", time(NULL));
        timer(temp);
        dequeue(front,rear,Currently_served);
        //enqueue new_nd
        enqueue(front,rear,new_nd);
    }
    return 1;
}

void timer(s_info* temp){//add this fct before dequeueing
    int seconds= (temp->time_mins)*60;
    while(seconds>0){
    //printf("\r%d", seconds);
    clock_t stop = clock() + CLOCKS_PER_SEC;
    while(clock()<stop){

    }
    seconds--;}
    if(temp==temp->next)
    printf("\n%s's time is up! But the queue is empty!\n");
    else printf("\n%s's time is up! %s is up next\n", temp->name, temp->next->name);
}

void office_status(char *Student)
{
    printf("\n\t========================================");
    printf("\n\t%s is currently in the office",Student);
    printf("\n\t========================================");
}

void display_waitlist(s_info *front)
{
    if (front==NULL){
    printf("\n\tThe queue is empty!!");
    }else {
    s_info *temp=front;
    do{
    printf("\n\t%s is waiting (ID:%hu, %hu min)", temp->name, temp->ID, temp->time_mins);
    temp=temp->next;
    }
    while(temp!=front);
    }
}

void queue_to_file(s_info *front)
{
    FILE *infp2= fopen("Queue.txt","w");
    if (front==NULL){
    fprintf(infp2, "\n\tThe queue is empty!!");
    }else {
    s_info *temp=front;
    do{
    fprintf(infp2, "%s is waiting (ID:%hu, %hu min)\n", temp->name, temp->ID, temp->time_mins);
    temp=temp->next;
    }
    while(temp!=front);
    }
    fclose(infp2);
}

int Change_place_students(s_info *front,unsigned short id1, unsigned short id2)
{
    //local declarations
    s_info  *real_front=front,
            *target1=NULL,
            *target2=NULL;
    int f1=0,
        f2=0;
    if (front==NULL)
    {
        return 0;
    }else
    {   
        do
        {
            if ((front->ID==id1)&& target1==NULL)
            {
                f1=1;
                target1=front;

            }
            if ((front->ID==id2)&& target2==NULL)
            {
                f2=1;
                target2=front;

            }
            if (f1==1 && f2==1)
            {
                break;
            }
            front=front->next;
        } while (front!=real_front);
        //check wether the IDs have been found
        if (f1==0 || f2==0)
        {
            return 0;
        }else
        {
            //Swapping the node's content
            s_info *tempstudent= (s_info*)malloc(sizeof(s_info));
            //set up the temp 
             _fill_nd_wnull(tempstudent,target1);
            //swapping
            _fill_nd_wnull(target1,target2);
            _fill_nd_wnull(target2,tempstudent);
            free(tempstudent);
            return 1;
        }
    }
}

int Quit(s_info**front, s_info**rear, unsigned short id)
{
    if((*front)==NULL){
        return 0;
    }
    else if((*front)->ID==id){
        if(*front == *rear){
            *front=NULL;
            *rear=NULL;
            return 1;
        } else{
            s_info* temp=*front;
            (*front)=(*front)->next;
            free(temp);
            (*rear)->next= *front;
            return 1;
        }
    }
    else{
        s_info *walker, *temp;
        walker=*front;
        do{
        if (walker->next->ID==id){
            temp=walker->next;
            walker->next=temp->next;
            if(temp==*rear)
            (*rear)=walker;
            free(temp);
            return 1;
        }
        walker=walker->next;
        }
        while(walker!=*front);
    }
    return 0;
}

void _fill_nd( s_info*To_fill, s_info *To_copy)
{
    strcpy(To_fill->name,To_copy->name);
    To_fill->ID=To_copy->ID;
    To_fill->time_mins=To_copy->time_mins;
    To_fill->next=NULL;
}

void _fill_nd_wnull( s_info*To_fill, s_info *To_copy)
{
    strcpy(To_fill->name,To_copy->name);
    To_fill->ID=To_copy->ID;
    To_fill->time_mins=To_copy->time_mins;
}

void finish_office_hours(s_info* front)
{
    //local declarations
    FILE *outfp;
    s_info *real_front;
    outfp=fopen("Appointment.txt","w");
    if(front!=NULL)
    {
        real_front=front;
        do{
            fprintf(outfp, "%s\n", front->name);
            fprintf(outfp, "%hu\n", front->ID);
            fprintf(outfp, "%hu\n", front->time_mins);
            if (front->next==real_front)
            {
               fprintf(outfp, "-------------------------------------"); 
            }else
            {
                fprintf(outfp, "-------------------------------------\n");
            }
            
            front=front->next;
        }
        while(front!= real_front);
    }
    fclose(outfp);
}