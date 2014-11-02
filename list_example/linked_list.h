#include<stdio.h>
#include<stdlib.h>

// Struct to store list element
typedef struct list_element {
	int value;			// Element value
	struct list_element* next;	// Pointer to next element
} list_element;

// Create new element, set its value to 'i', return pointer to new element
list_element* create_list_element(int i);

// Insert element 'elem' into list 'root' (on the 1st position)
list_element* insert_into_list(list_element* root, list_element* elem);

// Print list
void print_list(list_element* cur_element);

// Search for given value in the list
// Returns pointer to found element and NULL otherwise
list_element* search_by_value(list_element* root, int value);

// Returns pointer to element with number 'index'
// or NULL if index is out of range
list_element* get_by_index(list_element* root, int index);

// Deletes element from list
list_element* delete_from_list(list_element* root, list_element* elem);
