#include<stdio.h>
#include<stdlib.h>
unsigned int *quicksort(unsigned int *, unsigned int, unsigned int, unsigned int, unsigned int);

int main()
{
	unsigned int *arr, size;
	unsigned int pivot, i, big_index, small_index;

	arr = (unsigned int*)malloc(sizeof(unsigned int)*15);
	printf("Enter the size of the array :\n");
	scanf("%d", &size);
	printf("Enter the array elements : \n");
	for(i=0; i<size; i++)
	{

		scanf("%d", (arr+i));
	}
	for(i=0; i<size; i++)
	{
	
		printf("%d", *(arr+i));
	}

	printf("Enter the Position of pivot element : \n");
	scanf("%d", &pivot);

	big_index = pivot + 1;
        small_index = size-1;
	arr = quicksort(arr, big_index, small_index, size, pivot);
	
	for(i=0; i<size; i++)
	{
		printf("%d\t", *(arr+i));
	}

	return 0;
}
unsigned int *quicksort(unsigned int *arr, unsigned int big_index, unsigned int small_index, unsigned int size, unsigned int pivot)
{
	unsigned int i, temp1, temp2;
	unsigned int n = small_index, b, s;

	if(big_index > small_index)
		return arr;
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
	s = small_index;
	printf("Position of pivot : %d\n", pivot);
	printf("Small_index : %d\n", small_index);
	printf("Big_index : %d\n", big_index);
	if(small_index > 0)
	{
		big_index = pivot + 1;
		small_index = small_index - 1;
		size = small_index;
		printf("Function Calling Again\n");
		arr = quicksort(arr, big_index, small_index, size, pivot);
	}
		

		printf("Function one ends here\n");
/*		pivot = s;
		big_index = pivot + 1;

	if(big_index < n)
	{


		small_index = n;
		printf("Function Calling Again Again\n");
		arr = quicksort(arr, big_index, small_index, n, pivot);
	}
*/	return arr;

}
