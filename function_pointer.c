#include<stdio.h>

#define N 10

// Function one
void init(int* elem, int i)
{
	*elem = i*i;
}

// Function two
void print(int* elem, int i)
{
	printf("Element: %d\n", *elem);
}

// Meta-function with arguments:
// elem - pointer to element
// i - number of this element
// func - pointer to function that should be called for this element
void process_element(int* elem, int i, void (*func)(int*,int))
{
	func(elem, i);
}

int main()
{
	int i;
	int a[N];
	for(i = 0; i < N; i++)
	{
		// Call processing, pass 'init' function as an argument
		process_element(&a[i], i, &init);
		// Call processing, pass 'print' function as an argument
		process_element(&a[i], i, &print);
	}
	return 0;
}
