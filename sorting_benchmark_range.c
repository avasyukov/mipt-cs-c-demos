#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Returns time difference in milliseconds
long get_time_diff(struct timespec start, struct timespec stop)
{
	return (stop.tv_sec - start.tv_sec) * 1000 + (int)( (stop.tv_nsec - start.tv_nsec) / 1.0e6 );
}

// Fills array with given numbers
void init_array(long int* array, long int number_of_elements)
{
	long int i;
	for( i = 0; i < number_of_elements; i++ )
		array[i] = rand();
}

// Looks for maximum value in a given array - O(N)
int find_max_using_scan(long int* array, long int number_of_elements)
{
	long int i;
	long int res = array[0];
	for( i = 0; i < number_of_elements; i++ )
		if( array[i] > res )
			res = array[i];
	return res;
}

// Sorts array using find-and-insert method - O(N^2)
void insert_sort(long int* src, long int* dst, long int number_of_elements)
{
	long int max;
	long int index;
	long int i, j;
	for( i = 0; i < number_of_elements; i++ )
	{
		max = src[i];
		index = i;
		for( j = i+1; j < number_of_elements; j++ )
		{
			if( src[j] > max )
			{
				max = src[j];
				index = j;
			}
		}
		dst[index] = src[i];
		dst[i] = src[index];
	}
}

// Sorts array using bubble sort
void bubble_sort(long int* src, long int* dst, long int number_of_elements)
{
	// Implement me
}

void run_test(long int number_of_elements)
{
	// Start and stop time of different stages
	struct timespec start, stop;
	// Pointer to initial random array
	long int* a;
	// Pointer to working copy of array
	long int* b;
	// Just counter
	int i;

	// Allocate memmory
	a = (long int*)malloc(number_of_elements*sizeof(long int));
	b = (long int*)malloc(number_of_elements*sizeof(long int));

	// Initialize pseudo-random number generator with current time
	srand(start.tv_nsec);
	// Fill array
	init_array(a, number_of_elements);

	// Benchmark insert sort
	clock_gettime(CLOCK_REALTIME, &start);
	insert_sort(a, b, number_of_elements);
	clock_gettime(CLOCK_REALTIME, &stop);
	printf("%d\t\t|\t%d msec\n", number_of_elements, get_time_diff(start, stop) );

	// Free memmory and exit
	free(a);
	free(b);
}

// Main function
int main(int argc, char** argv)
{
	// Number of elements
	long int number_of_elements;
	long int current_size;

	// number_of_elements parameter is mandatory
	if( argc != 2 )
	{
		printf("Usage: %s number_of_elements\n", argv[0]);
		return -1;
	}
	// Read number of elements from command line
	number_of_elements = atoi(argv[1]);
	printf("Running tests up to %d elements\n", number_of_elements);
	printf("=====================================\n");
	printf("Array Size\t|\tSort Time\n");
	printf("=====================================\n");

	current_size = 1000;
	while(current_size <= number_of_elements)
	{
		run_test(current_size);
		current_size *= 2;
	}

	return 0;
}
