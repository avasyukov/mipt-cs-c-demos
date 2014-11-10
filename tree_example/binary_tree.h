#include<stdio.h>
#include<stdlib.h>

// Struct to store tree element
typedef struct tree_element {
	int value;			// Element value
	struct tree_element* left;	// Pointer to left subtree
	struct tree_element* right;	// Pointer to right subtree
} tree_element;

// Create new element, set its value to 'i', return pointer to new element
tree_element* create_tree_element(int i);

// Insert element 'elem' into tree 'root'
tree_element* insert_into_tree(tree_element* root, tree_element* elem);

// Print tree
void print_tree(tree_element* cur_element);

// Search for given value in the tree
// Returns pointer to found element and NULL otherwise
tree_element* search_by_value(tree_element* root, int value);

// Deletes element from the tree
tree_element* delete_from_tree(tree_element* root, tree_element* elem);
