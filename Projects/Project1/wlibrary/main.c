#include "library.h"

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
                printf("\nThe file you tried to open doesn't exist in this directory, please retry! ");
            }else
            {
                start_office_hours(infp,&front,&rear);
                status=1;
                fclose(infp);
                printf("\n\tOffice hours started...");
            }
            break;
        case Serve:
            if (status)
            {
                if (Serve_student(&front,&rear,Served)==0)
                {
                    printf("\n\tThe Queue is empty");
                }else
                {
                    office_status(Served);  
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
                printf("\nEnter the name of the new student: ");
                gets(toAdd->name);
                fflush(stdin);
                printf("\nEnter %s's ID: ",toAdd->name);
                scanf("%hu",&toAdd->ID);
                printf("\nHow much time does %s need in the office: ",toAdd->name);
                scanf("%hu",&toAdd->time_mins);
                //Enqueue
                enqueue(&front,&rear,toAdd);
                printf("\n\t-----------------------------------------------");
                printf("\n\t%s (%d) joined the Queue successfully!",toAdd->name,toAdd->ID);
                if (!display_waitlist(front))
                {
                    printf("\n\tThe Queue is empty");
                }
                

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
                if (Change_place_students(front,id1,id2))
                {
                    printf("\n\tYou entered one or two wrong IDs, please retry!");
                }else
                {
                    printf("\n\tThe change has been executed successfully!");
                }
                
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
                    printf("\n\t%d has left the Queue successfully",id1);
                }else
                {
                    printf("\n\tYou entered a wrong ID, or you are not in the Queue");
                }  
            }else
            {
                printf("\n\tYou first must start the office hours! ");
            }
            break;
        case Stop:
            if (status)
            {
                finish_office_hours(&front,&rear);
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
    } while (choice!=6);
    
    return 0; 
}