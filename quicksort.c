#include<stdio.h>
#include<stdlib.h>
unsigned int *quicksort(unsigned int *, unsigned int, unsigned int);

int main()
{
	unsigned int *arr, size;
	unsigned int pivot, i, big_index, small_index;

	arr = NULL;
	printf("Enter the size of the array :\n");
	scanf("%d", &size);
	printf("Enter the array elements : \n");
	for(i=0; i<size; i++)
	{
		arr = (unsigned int*)realloc(arr, i+1);
		scanf("%d", (arr+i));
	}
	for(i=0; i<size; i++)
	{
	
		printf("%d", *(arr+i));
	}


	big_index = 1;
        small_index = size-1;
	quicksort(arr, big_index, small_index);
	
	for(i=0; i<size; i++)
	{
		printf("%d\t", *(arr+i));
	}	
//	free(arr);
	return 0;
}
unsigned int *quicksort(unsigned int *arr, unsigned int big_index, unsigned int small_index)
{
	unsigned int i, temp1, temp2, pivot;
	printf("Enter the Position of pivot element : \n");
	scanf("%d", &pivot);
GO :	while(*(arr+big_index) <= *(arr+pivot))
	{
		++(big_index);
	}
	
	while(*(arr+small_index) > *(arr+pivot))
	{
		--(small_index);
	}
	
	if(big_index < small_index)
	{
		temp1 = *(arr+big_index);
		*(arr+big_index) = *(arr+small_index);
		*(arr+small_index) = temp1;
	}
	printf("*(arr+small_index) = %d\n", *(arr+small_index));
	
	while(small_index > big_index)
	{
		goto GO;
	}
	
	printf("*(arr+small_index) = %d\n", *(arr+small_index));
	printf("*(arr+pivot) = %d\n", *(arr+pivot));

	temp2 = *(arr+small_index);
	*(arr+small_index) = *(arr+pivot);
	*(arr+pivot) = temp2;

	printf("Position of pivot : %d\n", pivot);
	printf("Small_index : %d\n", small_index);
	printf("Big_index : %d\n", big_index);
	while(big_index <= small_index)
	{
		big_index = pivot + 1;
		small_index = small_index - 1;
		arr = quicksort(arr, big_index, small_index);
	
		big_index = pivot + 2;
		small_index = small_index - 1;
		arr = quicksort(arr, big_index, small_index);
	}

}
