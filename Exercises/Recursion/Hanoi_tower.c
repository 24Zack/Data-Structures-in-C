//Using recursion to solve the tower of Hanoi problem
#include <stdio.h>

// C recursive function to solve tower of hanoi puzzle
void towerOfHanoi(char S, char T, char D, int n)
{
	if (n==1)
    {
        printf("\n%c to %c",S,D);
    }else
    {
        towerOfHanoi(S,D,T,n-1);
        printf("\n%c to %c",S,D);
        towerOfHanoi(T,S,D,n-1);
    }
}

int main()
{
	int n = 3; // Number of disks
	towerOfHanoi('A','B','C',n);// A, B and C are names of rods
	return 0;
}
