#include <stdio.h>
#include <stdlib.h>

void my_func(int* arr, int n)
{
	int i;
	for(i = 0; i < n; i++) {
		printf("val[%d] = %d\n", i, arr[i]);
	}
}

int main()
{
	// Part 1 - Static pointers

	int b;
	b = 5;
	printf("Value: %d Address: %d\n", b, &b);

	int* c = &b;
	*c = 6;
	printf("Value: %d Address: %d\n", *c, c);
	printf("b = %d *c = %d\n", b, *c);

	int** d = &c;
	**d = 7;
	printf("Value: %d Pointer: %d Pointer2: %d", **d, *d ,d);
	// b == *c === **d
	// &b == c === *d


	// Part 2 - Pointers and arrays

	int arr[10];
	for(int i = 0; i < 10; i++) {
		arr[i] = i;
		printf("a[%d]=%d addr %d\n", i, arr[i], &arr[i]);
	}
	// arr == &arr[0]
	for(int i = 0; i < 10; i++) {
		printf("a[%d]=%d\n", i, *(arr+i));
	}
	my_func(arr, 10);


	// Part 3 - Dynamic memmory allocation

	int* a = (int*)malloc(10000*sizeof(int));
	printf("Pointer value: %d\n", a);
	for(int i = 0; i < 10000; i++) {
		*(a+i) = i; // ~ a[i] = i
	}
	a = realloc(20000*sizeof(int));
	free(a);

	return 0;
}
