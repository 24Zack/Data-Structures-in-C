#include <stdio.h>
#include <string.h>
#define SIZE 10

// Enumerated type for the menu
typedef enum{
    Start_auction=1,
    New_offer=2,
    Update_offer=3,
    Display_list_offers=4,
    Retract_bid=5,
    End_auction=6
}menu_t;

//  Structure
typedef struct{
  int ID;
  char name[80];
  int offer;
}C_info;

// Function prototypes
void menu(void);
void heapify(C_info* ,int, int);
int generate_new_ID();
int check_new_offer(C_info *, int);
int Add_new_offer(C_info *, C_info, int *);
void swap(C_info*, C_info*);
void update_existing_offer(C_info*, int, int, int, int);
int find_max(C_info*, int, int);
C_info delete(C_info*, int*);
void heapsort(C_info*, int);
int search(C_info*, int, int);
int retract_bid(C_info*, int, int*);
void end(C_info*, int);
int start_auction(FILE*, C_info*);
void print_no_wcommas(int);


//  Global variable
int GV=5;

//  Main function

int main(void)
{
    //declarations
    int choice,status=0,last_index=0;
    int ID,new_offer,loc,search_status;
    C_info arr[SIZE],toAdd;
    
    do
    {
        menu();
        scanf("%d",&choice);
        switch (choice)
        {
        case Start_auction:
            if (!status)
            {
                FILE* infp= fopen("CommissionBid.txt", "r");
                if (infp==NULL)
                {
                    printf("\n\tThe indicated file was not found in the directory");
                }else
                {
                last_index=start_auction(infp, arr);
                printf("\n\tAuction starting...");
                fclose(infp);
                heapsort(arr, last_index);
                status=1;
                }
            }else
            {
                printf("\n\tThe auction already started!");
            }
            
            break;
        case New_offer:
            if (status)
            {
                fflush(stdin); 
                printf("\n\tEnter the name of the new bidder: ");
                fgets(toAdd.name,80,stdin);
                //   remove \n from the string
                toAdd.name[strlen(toAdd.name)-1]='\0';
                printf("\n\tWhat's his offer?");
                printf("\n\tEnter amount here: ");
                scanf("%d",&toAdd.offer);

                // //  Debugging
                // printf("\n\n Name: %s",toAdd.name);

                //  update offer
                toAdd.offer/=1000;
                if (!check_new_offer(arr,toAdd.offer))
                {
                    // printf("\n\tThe offer is less than the maximum bid of $%d, please give a bigger bid!",arr[0].offer); 
                    printf("\n\tThe offer is less than the maximum bid of $");
                    print_no_wcommas(arr[0].offer*1000);
                    printf(" please give a bigger bid!");
                }else
                {
                    toAdd.ID=generate_new_ID();
                    if (Add_new_offer(arr,toAdd,&last_index))
                    {
                        printf("\n\tThe new bidder %s was added successfully!",toAdd.name);
                    }else
                    {
                        printf("\n\tThe new bidder %s was not added successfully!",toAdd.name);
                    }   
                }
            }else
            {
                printf("\n\tYou must start the auction first!");
            }
            break;
        case Update_offer:
            if (status)
            {
                printf("\n\tEnter the bidder's ID: ");
                scanf("%d",&ID);
                printf("\n\tEnter the new offer: ");
                scanf("%d",&new_offer);
                new_offer/=1000;
                if (!check_new_offer(arr,new_offer))
                {
                    printf("\n\tThe offer is less than the maximum bid of $");
                    print_no_wcommas(arr[0].offer*1000);
                    printf(" please give a bigger bid!"); 
                }else
                {
                    loc=search(arr, ID, last_index);
                    if (loc==-1)
                    {
                        printf("\n\tThe ID of the client you entered doesn't exist");
                    }else
                    {
                        update_existing_offer(arr,ID,new_offer,loc,last_index);
                        printf("\n\tThe offer has been updated successfully!");
                    }
                }
                
                
            }else
            {
                printf("\n\tYou must start the auction first!");
            }

            break;
        case Display_list_offers:
            if (status)
            {
               heapsort(arr,last_index);
            }else
            {
                printf("\n\tYou must start the auction first!");
            }

            break;
        case Retract_bid:
            if (status)
            {
                int ID;
                printf("\n\tEnter the bidder's ID: ");
                scanf("%d",&ID);
                if(retract_bid( arr, ID, &last_index)){
                    printf("Offer successfully retracted!");
                    last_index--;
                    heapsort(arr,last_index);

                }
                else printf("ID not found!");
            }else
            {
                printf("\n\tYou must start the auction first!");
            }

            break;
        case End_auction:
            if (status)
            {
                end(arr, last_index);
            }else
            {
                printf("\n\tYou must start the auction first!");
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

//  Functions definitions

 void menu(void)
{
    printf("\n\t==================MENU==================");
    printf("\n\tWelcome to Da Vinci's Salvator Auction!");
    printf("\n\t1. Start the auction");
    printf("\n\t2. A new offer from a new bidder");
    printf("\n\t3. Update my offer!");
    printf("\n\t4. View list of offers");
    printf("\n\t5. Retract my bid");
    printf("\n\t6. End the auction");
    printf("\n\t========================================");
    printf("\n\tYour choice please: ");
}

int check_new_offer(C_info *arr, int offer)
{
    if (arr[0].offer > offer){
        return 0;
    }else{
        return 1;
    }

}

C_info delete(C_info*arr,int*no_elements)
{
    //  local declarations
    C_info urgent_elt;
    int last_index;
    if (*no_elements==0)
    {
        urgent_elt.offer=-1;
        return urgent_elt;
    }else
    {
        urgent_elt=arr[0];
        arr[0]=arr[--(*no_elements)];
        last_index=(*no_elements)-1;
        if (last_index<0)
        {
            return urgent_elt;
        }
        heapify(arr,0,last_index);
        return urgent_elt;
    }
}

void heapify(C_info*arr,int parent_index, int last_index)
{
    int l, left_c, right_c;
    if(parent_index>((last_index-1)/2))
        return;
    else{
        left_c= (parent_index*2)+1;
        right_c= (parent_index*2)+2;
        if(right_c>last_index)
            l=find_max(arr, parent_index, left_c);
        else{
            l=find_max(arr, parent_index, left_c);
            l=find_max(arr, l, right_c);
        }
        if(l!=parent_index){
            swap(&arr[parent_index], &arr[l]);
            heapify(arr, l, last_index);
        }
    }
}

int find_max(C_info* arr, int l, int right_c)
{
    if(arr[l].offer<arr[right_c].offer)
        return right_c;
    else return l;
}

int start_auction(FILE* infp, C_info*arr)
{
    //declarations
    char line[80], first[30], second[30], full[80];
    int last_i,i=0;

    fseek(infp, 0, 0);
    while(!feof(infp))
    {
        fgets(line, 80, infp);
        sscanf(line, "Bidder%d $%d,000 %s %s\n", &arr[i].ID, &arr[i].offer, first, second);
        strcpy(full, first);
        strcat(full, " ");
        strcat(full, second);
        strcpy(arr[i].name, full);
        i++;
    }
    last_i=i;
    for(int i=(last_i-1)/2; i>=0; i--){
        heapify(arr, 0, last_i);
    }
    return last_i;
}

int generate_new_ID()
{
    return (++GV);
}


int Add_new_offer(C_info *arr, C_info toAdd, int *no_elements)
{
    //  local declarations
    int index;
    
    if (*no_elements==SIZE)
    {
        return 0;
    }else
    {
        index=((*no_elements)++);
        arr[index]=toAdd;
        
        while (index>=1 && arr[index].offer>arr[(index-1)/2].offer)
        {
            swap(&arr[index],&arr[(index-1)/2]);
            index=(index-1)/2;
        }
        
    }
    return 1;
}

void swap(C_info*A,C_info*B)
{
    C_info temp;
    temp=*A;
    *A=*B;
    *B=temp;
}

void update_existing_offer(C_info*arr,int ID,int new_offer, int index, int last_index)
{
    //  local declarations
    int i;
    //update offer
    new_offer/=1000;
    arr[index].offer=new_offer;
    //heapify
    for ( i = (last_index-1)/2; i >=0 ; i--)
    {
        heapify(arr,i,last_index);
    }
}

void heapsort(C_info*arr,int N)
{
    //  local declarations
    C_info element,arr2[SIZE];
    int i,off,cnt=0;
    for ( i = 0; i < N; i++)
    {
        arr2[i]=arr[i];
    }
    while (N!=0)
    {
        element=delete(arr2,&N);
        if (element.offer==-1)
        {
            break;
        }
        if (element.offer>=1000)
        {
            printf("\n\tBidder %d, $",element.ID);
            print_no_wcommas(element.offer*1000);
            printf(" %s",element.name);
        }else
        {
            printf("\n\tBidder %d, $%d,000 %s", element.ID, element.offer, element.name);
        }
    }
}

int retract_bid(C_info* arr, int id, int* last_index)
{
    int n=search(arr, id, *last_index);
    if(n==-1)
        return n;
    else{
        arr[n]=arr[*(last_index)];
        heapify(arr, n, *last_index);
        return 1;
    }
}

int search(C_info* arr, int id, int last_index)
{
    for (int i=0; i<last_index+1; i++) {
        if (arr[i].ID == id) {
            return i;
        }
    }
    return -1;
}

void end(C_info* arr, int last_index)
{
    if(last_index==-1)
        printf("\n\tEmpty list!!!");
    else{
        C_info urgent= delete(arr, &last_index);
        printf("\n\tThe winner of our auction is %s under ID %d with an offer of $", urgent.name, urgent.ID);
        print_no_wcommas(urgent.offer*1000);
        putchar('\n');
        for(int i=0; i<last_index; i++){
                printf("\n\tBidder%d $", arr[i].ID);
                print_no_wcommas(arr[i].offer*1000);
                printf(" %s",arr[i].name);
        }
    }
}

void print_no_wcommas(int number)
{
    if (number < 1000)
    {
        printf("%d", number);
        return;
    }
    print_no_wcommas(number/1000);
    printf(",%03d", number % 1000);
}
