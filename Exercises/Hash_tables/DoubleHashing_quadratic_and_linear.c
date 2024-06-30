#include <stdio.h>
#include <string.h>
#define tableSize 10
#define MAX_NO_PERSON

//  Enumerated type
typedef enum
{
    Hash=1,
    Delete=2,
    Search=3,
    Print_hash_table=4,
    QUIT=5
}menu_t;

//  Structure
typedef struct
{
    int id;
    char name[40];
    int status;
}person;

//  Fucntion prototypes
void menu(void);
int HF1(int);
int HF2(int);
int add_person(person*,person,int,int*);
int delete_person(person*,int,int,int*);
int search_person(person *,int,int,int,int*);
void Initialize_HT(person*);
void print_HT(person*,int);

//  Global variable
int Collision_resolution=1; //  It can be 1,2 or 3
/**
 * i.e.
 * 3: DH - double hashing
 * 2: QP - quadratic probing
 * 1: LP - linear probing
*/

int main(void)
{
    //  declarations
    person Hash_table[tableSize],Newperson;
    int choice_n,persons=0,index,status,id,position,hash;
    char temp;
    Initialize_HT(Hash_table);
    do
    {
        menu();
        scanf("%d",&choice_n);
        switch (choice_n)
        {
        case Hash:
            printf("\nEnter the person's name: ");
            fflush(stdin);
            gets(Newperson.name);
            printf("\nEnter his ID: ");
            scanf("%d",&Newperson.id);
            hash=HF1(Newperson.id);
            status=add_person(Hash_table,Newperson,hash,&persons);
            if (status==1)
            {
                printf("\n%s was added successfully!",Newperson.name);
            }else if (status==2)
            {
                printf("\nSorry, you reached the maximum number of persons to add");
            }

            break;
        case Delete:
            printf("\nPlease enter the person's ID: ");
            scanf("%d",&id);
            index=HF1(id);
            status=delete_person(Hash_table,index,id,&persons);
            if (status==1)
            {
                printf("\nStudent with ID: %d was deleted successgully from the Hash table",id);
            }else if (status==0)
            {
                printf("\nStudent %d is not in the Hash table",id);
            }else
            {
                printf("\nSorry, the Hash table is empty");
            }
            break;
        case Search:
            printf("\nPrint enter the person's ID: ");
            scanf("%d",&id);
            index=HF1(id);
            status=search_person(Hash_table,id,persons,index,&position);
            if (status==3)
            {
                printf("\nSorry, hash table is empty");
            }else if (status==1)
            {
                printf("\nStudent with ID: %d is located at the index %d",id,position);
            }else
            {
                printf("\nSorry, Student %d is not in the hash table",id);
            }

            break;
        case Print_hash_table:
            print_HT(Hash_table,persons+1);
            break;
        case QUIT:
            printf("\nBye!");
            break;
        default:
            printf("\nInvalid choice!!");
            break;
        }
    } while (choice_n!=5);
    return 0;
}

void menu(void)
{
    printf("\n----------Hash Tables practice----------");
    printf("\n\t1. Add a person");
    printf("\n\t2. Delete a person");
    printf("\n\t3. Search a person");
    printf("\n\t4. Print the content of the hash table");
    printf("\n\t5. QUIT");
    printf("\n\tYour choice: ");
}

int add_person(person* HT,person toAdd,int location,int* n_persons)
{
    //  local declarations
    int i=1;
    int h1_location=location;
    if (*n_persons==MAX_NO_PERSON)
    {
        return 2;
    }
    while (HT[location].status==1)
    {
        if (Collision_resolution==0)
        {
            location=(location+1)%tableSize;
        }else
        {
            location=(h1_location+i*HF2(toAdd.id))%tableSize;
            i++;
        }
    }
    // strcpy(HT[location].name,toAdd.name);
    // HT[location].id=toAdd.id;
    // HT[location].status=1;
    HT[location]=toAdd;
    HT[location].status=1; //making sure
    (*n_persons)++;
    printf("\n\t%s is at index %d",toAdd.name,location);
    return 1;
}

int HF1(int key)
{
    return (key%tableSize);
}
int HF2(int key)
{
    return (3-key%3);   //  where 3 is const & prime number >0
}

int delete_person(person* HT,int location,int ID,int* no_persons)
{
    //  local declarations
    int no_tries=0,flag=0;
    int i=1,h1_location=location;
    if (*no_persons==0)
    {
        return 3;
    }
    while (HT[location].status!=0 &&no_tries<=tableSize)
    {
        if (HT[location].id==ID)
        {
            HT[location].id=0;
            strcpy(HT[location].name,"nothings");
            HT[location].status=-1;
            (*no_persons)--;
            flag=1;
            break;
        }else if (Collision_resolution==1)
        {
            location=HF1(location+1);
        }else if (Collision_resolution==2)
        {
            location=(location+i*i)%tableSize;
            i++;
        }else
        {
            location=(h1_location+i*HF2(ID))%tableSize;
            i++;
        }
        no_tries++;
    }
    return flag;
}

int search_person(person *HT,int ID, int no_persons,int location,int*position)
{
    //  local declarations
    int no_of_tries=0,flag=0,i=1;

    if (no_persons==0)
    {
        return 3;
    }
    while (HT[location].status!=0 && no_of_tries<=tableSize)
    {
        if (HT[location].id==ID)
        {
            // found
            flag=1;
            break;
        }else if (Collision_resolution==1)
        {
            location=HF1(location+1);
        }else if (Collision_resolution==2)
        {
            location=(location+i*i)%tableSize;
            i++;
        }else if (Collision_resolution==3)
        {
            location=(location+i*HF2(ID))%tableSize;
            i++;
        }
        no_of_tries++;
    }

    return flag;
}
void Initialize_HT(person* HT)
{
    int i;
    for ( i = 0; i < tableSize; i++)
    {
        HT[i].id=0;
        HT[i].status=0;
        strcpy(HT[i].name,"nothings");
    }

}
void print_HT(person* HT,int n_pers)
{
    int i;
    if (n_pers==0)
    {
        printf("\nEmpty hash table");
        return;
    }
    printf("\nHash table contains the following");
    for ( i = 0; i < n_pers; i++)
    {
        if (HT[i].status==1)
        {
         printf("\nID: %d, name: %s",HT[i].id,HT[i].name);
        }
    }
}
