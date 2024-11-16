#include <stdio.h> 

void swap(int* a, int* b) 
{ 
	int temp = *a; 
	*a = *b; 
	*b = temp; 
} 

// Partition function 
int partition(int a[], int l, int u) 
{ 

	// initialize pivot to be the first element 
	int pivot = a[l]; 
	int i = l; 
	int j = u; 

	while (i < j) { 

		while (a[i] <= pivot && i <= u - 1) { 
			i++; 
		} 

		while (a[j] > pivot && j >= l + 1) { 
			j--; 
		} 
		if (i < j) { 
			swap(&a[i], &a[j]); 
		} 
	} 
	swap(&a[l], &a[j]); 
	return j; 
} 

void quickSort(int a[], int l, int u) 
{ 
	if (l < u) { 

		int partitionIndex = partition(a, l, u); 

		quickSort(a, l, partitionIndex - 1); 
		quickSort(a, partitionIndex + 1, u); 
	} 
} 

int main() 
{  
    int n;
    scanf("%d",&n);

	int a[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    } 
	 

	printf("Original array: "); 
	for (int i = 0; i < n; i++) { 
		printf("%d ", a[i]); 
	} 

	quickSort(a, 0, n - 1); 

	printf("\nSorted array: "); 
	for (int i = 0; i < n; i++) { 
		printf("%d ", a[i]); 
	} 

	return 0; 
}

