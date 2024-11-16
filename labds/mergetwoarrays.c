 
#include <stdio.h> 
#include <stdlib.h> 

void merge(int a[], int l, int m, int u) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = u - m; 

	
	int L[n1], R[n2]; 

	for (i = 0; i < n1; i++) 
		L[i] = a[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = a[m + 1 + j]; 

	
	i = 0; 
 
	j = 0; 

	k = l; 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			a[k] = L[i]; 
			i++; 
		} 
		else { 
			a[k] = R[j]; 
			j++; 
		} 
		k++; 
	} 

	
	while (i < n1) { 
		a[k] = L[i]; 
		i++; 
		k++; 
	} 

	while (j < n2) { 
		a[k] = R[j]; 
		j++; 
		k++; 
	} 
} 

void mergeSort(int a[], int l, int u) 
{ 
	if (l < u) { 
		
		int m = l + (u - l) / 2; 

		mergeSort(a, l, m); 
		mergeSort(a, m + 1, u); 

		merge(a, l, m, u); 
	} 
} 

void printArray(int a[], int n) 
{ 
	int i; 
	for (i = 0; i < n; i++) 
		printf("%d ", a[i]); 
	printf("\n"); 
} 

// Driver code 
int main() 
{ 
	int a[] = { 12, 11, 13, 5, 6, 7 }; 
	int arr_size = sizeof(a) / sizeof(a[0]); 

	printf("Given array is \n"); 
	printArray(a, arr_size); 

	mergeSort(a, 0, arr_size - 1); 

	printf("\nSorted array is \n"); 
	printArray(a, arr_size); 
	return 0; 
}

