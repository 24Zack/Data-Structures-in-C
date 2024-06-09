// C program for Merge Sort
#include <stdio.h>
#include <stdlib.h>
//Function prototypes
void merge(int arr[], int left, int m, int right);
void mergeSort(int arr[], int left, int right);
void printArray(int A[], int size);

// Driver code
int main(void)
{
	int arr[] = { 12, 11, 13, 5, 6, 7 };
	// int arr_size = sizeof(arr) / sizeof(arr[0]);
    int arr_size=6;
	printf("\nGiven array is: ");
	printArray(arr, arr_size);

	mergeSort(arr, 0, arr_size - 1);

	printf("\nSorted array is \n");
	printArray(arr, arr_size);
	return 0;
}

// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
void merge(int arr[], int left, int m, int right)
{
	int i, j, k;
	int n1 = m - left + 1;
	int n2 = right - m;

	// Create temp arrays
	int L[n1], R[n2];

	// Copy data to temp arrays L[] and R[]
	for (i = 0; i < n1; i++){
		L[i] = arr[left + i];
    }
	for (j = 0; j < n2; j++){
		R[j] = arr[m + 1 + j];
    }
	// Merge the temp arrays back into arr[l..r
	i = 0;
	j = 0;
	k = left;
	while (i < n1 && j < n2) 
    {
		if (L[i] <= R[j])
        {
			arr[k] = L[i];
			i++;
		}
		else
        {
			arr[k] = R[j];
			j++;
		}
		k++;
	}

	// Copy the remaining elements of L[],
	// if there are any
	while (i < n1) 
    {
		arr[k] = L[i];
		i++;
		k++;
	}

	// Copy the remaining elements of R[],
	// if there are any
	while (j < n2) 
    {
		arr[k] = R[j];
		j++;
		k++;
	}
}

//  lwb = lower bound
//  upb = upper bound
//
// sub-array of arr to be sorted
void mergeSort(int arr[], int lwb, int upb)
{
	if (lwb < upb) 
    {
		int m = lwb + (upb - lwb) / 2;

		// Sort first and second halves
		mergeSort(arr, lwb, m);
		mergeSort(arr, m + 1, upb);

		merge(arr, lwb, m, upb);
	}
}

// Function to print an array
void printArray(int A[], int size)
{
	int i;
	for (i = 0; i < size; i++){
		printf("%d ", A[i]);
    }
	printf("\n");
}
