#include <stdio.h>
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
// tree_element* delete_from_tree(tree_element* root, tree_element* elem);

int main()
{
	int a[7] = {-3, -1, -5, 3, 1, 5, 6};
	int i;
	tree_element* cur_elem;

	tree_element* root = create_tree_element(0);
	for(i = 0; i < 7; i++)
	{
		tree_element* elem = create_tree_element(a[i]);
		root = insert_into_tree(root, elem);
	}

	printf("Tree after creation:\n");
	print_tree(root);

	cur_elem = search_by_value(root, 3);
	if(cur_elem != NULL)
	{
		printf("Search for value 3: found\n");
	}

	cur_elem = search_by_value(root, 111);
	if(cur_elem == NULL)
	{
		printf("Search for value 111: not found\n");
	}

	return 0;
}
