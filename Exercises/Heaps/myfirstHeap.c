/**
 * Implemetning a max-heap
*/
#include <stdio.h>
#define SIZE 10
//  Prototypes
void heapify(int*, int, int);
int delete(int *,int*);
int Add(int*,int,int*);
void heapsort(int*,int);
int find_max(int*,int,int);
void swap(int *, int *);
int main(void)
{
    //  declarations
    int arr[SIZE];
    int last_i;
    FILE *infp;
    int choice;

    do
    {
        //  to be completed
        //  the functions are the ones which matter the most
    } while (choice!=6);


    return 0;
}
void swap(int *a, int *b)
{
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}

int find_max(int*arr,int i,int j)
{
    if (arr[i]>arr[j])
    {
        return i;
    }else
    {
        return j;
    }


}
void heapify(int*arr, int par_i, int last_i)
{
    //  local declarations
    int left,right,largest;
   if (par_i>((last_i-1)/2))
   {
    return;
   }else
   {
    left=par_i*2+1;
    right=par_i*2+2;
    if (right>last_i)
    {
        largest=find_max(arr,par_i,left);
    }else
    {
        largest=find_max(arr,par_i,left);
        largest=find_max(arr,largest,right);
    }
    if (largest!=par_i)
    {
        swap(&arr[par_i],&arr[largest]);
        heapify(arr,largest,last_i);
    }
   }
}
int delete(int *arr,int*no_elts)
{
    //  declarations
    int last_i,urgent;
    if (*no_elts==0)
    {
        return (-2024);
    }else
    {
        urgent=arr[0];
        arr[0]=arr[--(*no_elts)];
        last_i=(*no_elts)-1;
        if (last_i<0)
        {
            return urgent;
        }else
        {
            heapify(arr,0,last_i);
            return urgent;
        }
    }
}

int Add(int*arr,int toAdd,int*no_elts)
{
    //  local declarations
    int index;
    if (*no_elts==SIZE)
    {
        return 0;
    }
    index=(*no_elts)++;
    arr[index]=toAdd;
    while (index>=1&&arr[index]>arr[(index-1)/2])
    {
        swap(&arr[index],&arr[(index-1)/2]);
        index=(index-1)/2;
    }
    return 1;
}
void heapsort(int*arr,int N)
{
    //  local declarations
    int arr2[N],element,i;
    for ( i = 0; i < N; i++)
    {
        arr2[i]=arr[i];
    }
}
