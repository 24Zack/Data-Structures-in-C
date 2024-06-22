#include "library.h"

//Function prototypes
void _fill_nd( s_info*To_fill, s_info *To_copy);

//Function definitions
void menu(void)
{
    printf("\n\t==================MENU==================");
    printf("\n\t1. Start office hours");
    printf("\n\t2. Serve a student");
    printf("\n\t3. A new student is joining the Queue");
    printf("\n\t4. Two students want to change place");
    printf("\n\t5. A student wants to quit the Queue");
    printf("\n\t6. Office hours are over!");
    printf("\n\t========================================");
    printf("\n\tYour choice: ");
 
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
        if (*front==NULL)
        {
            *rear=NULL;
        }
        free(temp);
    }
}

void start_office_hours(FILE* infp, s_info** front, s_info** rear)
{
    s_info *new_node, *walker;
    new_node = (s_info*)malloc(sizeof(s_info));
    char line[50];
    fseek(infp, 0, 0);
    while(!feof(infp)){
    fgets(new_node->name, 80, infp);
    fscanf(infp,"%hu\n", &new_node->ID);
    fscanf(infp,"%hu\n", &new_node->time_mins);
    fgets(line, 50, infp);
    new_node->next=NULL;
    enqueue(front,rear,new_node);
    }
}

int Serve_student(s_info **front, s_info**rear, char *Currently_served)
{
    //local declarations
    s_info *temp=*front,*new_nd;
    if (*front==NULL)
    {
        return 0;
    } else if (temp->time_mins<=10)
    {
        dequeue(front,rear,Currently_served);
    }else if ((temp->time_mins>10)&& temp->next==*front)
    {
        //one person is waiting in the Queue
        dequeue(front,rear,Currently_served);
    }else
    {
        //create
        new_nd=(s_info*)malloc(sizeof(s_info));
        //fill 
        _fill_nd(new_nd,*front);
        // strcpy(temp->name,(*front)->name);
        // temp->ID=(*front)->ID;
        // temp->time_mins=(*front)->time_mins;
        // temp->next=NULL;
        
        //update the number of mins
        new_nd->time_mins-=10; 
        // dequeue temp
        dequeue(front,rear,Currently_served);
        //enqueue temp
        enqueue(front,rear,temp);
    }
    return 1;
}

void office_status(char *Student)
{
    printf("\n========================================");
    printf("\n%s is currently in the office",Student);
    printf("\n========================================");
}

//      Error
int display_waitlist(s_info *front)
{
    //local declarations
    s_info *real_front=front;
    if (front==NULL)
    {
        return 0;
    }else
    {   
        printf("\n\t========================================");
        printf("\n\t\tStudents waiting");
        // do
        // {
        //     printf("\n\t%s, ID: %d, Time requested: %d min",front->name,front->ID,front->time_mins);
        //     front=front->next;
        // } while (front!=real_front);
        //
        //  OR
        //
        while (front!=real_front)
        {
            printf("\n%s, ID: %d, Time requested: %d min",front->name,front->ID,front->time_mins);
            front=front->next;
        }
        return 1;
    }
}

int Change_place_students(s_info *front,unsigned short id1, unsigned short id2)
{
    //local declarations
    s_info  *real_front=front,
            *target1=NULL,
            *target2=NULL;
    int f1=0,
        f2=0;
    do
    {
        if (front->ID==id1)
        {
            f1=1;
            target1=front;

        }
        if (front->ID==id2)
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
        _fill_nd(tempstudent,target1);
        //swapping
        _fill_nd(target1,target2);
        _fill_nd(target2,tempstudent);
        free(tempstudent);
        return 1;
    }
    
}

int Quit(s_info**front, s_info**rear, unsigned short id)
{
    if((*front)==NULL){
        return 0;
    }
    else if((*front)->ID==id){
        s_info* temp=*front;
        (*front)=(*front)->next;
        free(temp);
        (*rear)->next= *front;
        return 1;
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

void finish_office_hours(s_info** front, s_info**rear){
    FILE *outfp= fopen("Appointment.txt","w");

    if((*front)!=NULL){
        char line[] = "-------------------------------------";
        s_info* walker;
        walker=*front;
        do{
            fprintf(outfp, "%s\n", walker->name);
            fprintf(outfp, "%d\n", walker->ID);
            fprintf(outfp, "%d\n", walker->time_mins);
            fputs(line ,outfp);
            walker=walker->next;
        }
        while(walker!= *front);
    }
}

void _fill_nd( s_info*To_fill, s_info *To_copy)
{
    strcpy(To_fill->name,To_copy->name);
    To_fill->ID=To_copy->ID;
    To_fill->time_mins=To_copy->time_mins;
    To_fill->next=NULL;
}

// usleep in stdlib
// sleep() function