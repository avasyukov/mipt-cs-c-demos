#include "binary_tree.h"

// Create new element, set its value to 'i', return pointer to new element
tree_element* create_tree_element(int i)
{
	// Allocate memmory
	tree_element* elem = (tree_element*)malloc(sizeof(tree_element));
	// Set value
	elem->value = i;
	// There are no subtrees, set them to NULL
	elem->left = NULL;
	elem->right = NULL;

	return elem;
}

// Insert element 'elem' into tree 'root'
tree_element* insert_into_tree(tree_element* root, tree_element* elem)
{
	// Go to left subtree
	if(elem->value < root->value)
	{
		// If there is no element on the left - just insert our element
		if(root->left == NULL ) {
			root->left = elem;
		// If left subtree exists - use recursion to handle it
		} else {
			insert_into_tree(root->left, elem);
		}
	}
	// Go to right subtree and handle it the same way
	else
		if(root->right == NULL) {
			root->right = elem;
		} else {
			insert_into_tree(root->right, elem);
		}
	{
	}
	// We do not modify initial root, so just return it
	return root;
}

// Print list
void print_tree(tree_element* cur_element)
{
	// Print left subtree
	if(cur_element->left != NULL) {
		print_tree(cur_element->left);
	}
	// Print current value
	printf("Value: %d\n", cur_element->value);
	// Print right subtree
	if(cur_element->right != NULL) {
		print_tree(cur_element->right);
	}
}

// Search for given value in the tree
// Returns pointer to found element and NULL otherwise
tree_element* search_by_value(tree_element* root, int value)
{
	// If value equals current element - just return the pointer
	if(value == root->value)
		return root;
	// Handle left subtree
	if(value < root->value) {
		// If it exists - use recursion
		if(root->left != NULL) {
			return search_by_value(root->left, value);
		// If there is no left subtree - there is no such element, return NULL
		} else {
			return NULL;
		}
	}
	// Handle right subtree
	if(value > root->value) {
		if(root->right != NULL ) {
			return search_by_value(root->right, value);
		} else {
			return NULL;
		}
	}
	// We should never get here. This return is just to make compiler happy.
	return NULL;
}

// Helper function for delete.
// Returns parent element for 'elem'.
// Alternatively we can keep 'parent' link for each element (together with 'left' and 'right').
tree_element* find_parent(tree_element* root, tree_element* elem)
{
	// Smth went wrong
	if(root == elem)
		return NULL;
	// If 'elem' is between root's direct children - return root
	if(root->left == elem || root->right == elem)
		return root;
	// If elem value is lower than root value AND left subtree exists - search left subtree 
	if((elem->value < root->value) && (root->left !=NULL))
		return find_parent(root->left, elem);
	// If elem value is greater or equal to root value AND right subtree exists - search right subtree
	if((elem->value >= root->value) && (root->right !=NULL))
		return find_parent(root->right, elem);
	// If we are here - parent not found 
	return NULL;
}

// Helper function for delete.
// Takes node 'parent', determines if 'child' is left or right subtree, replaces link to 'child' with the link to 'new_child'
void replace_node_in_parent(tree_element* parent, tree_element* child, tree_element* new_child)
{
	if(parent->left == child)
		parent->left = new_child;
	if(parent->right == child)
		parent->right = new_child;
}

// Deletes element from tree
// Deleting root element is NOT supported now
tree_element* delete_from_tree(tree_element* root, tree_element* elem)
{
	printf("\t\tDelete called for element %d\n", elem->value);
	// Get parent element for 'elem'
	tree_element* parent = find_parent(root, elem);
	printf("\t\tParent value: %d\n", parent->value);

	// If 'elem' has both right and left children - we are to replace it with care
	if((elem->left != NULL) && (elem->right != NULL))
	{
		printf("\t\tBoth subtrees present\n");
		// Take _the_most_left_ element in _right_ subtree as a replacement for 'elem'
		tree_element* target_elem = elem->right;
		while(target_elem->left != NULL)
			target_elem = target_elem->left;
		printf("\t\tGoing to replace current element with element %d\n", target_elem->value);
		// Just copy values
		elem->value = target_elem->value;
		// Delete replacing element
		delete_from_tree(root, target_elem);
	}
	// If only left subtree exists
	else if(elem->left != NULL)
	{
		// Just move one link from parent
		printf("\t\tOnly left subtree present\n");
		replace_node_in_parent(parent, elem, elem->left);
		free(elem);
	}
	// If only right subtree exists 
	else if(elem->right != NULL)
	{
		// Again - just move one link
		printf("\t\tOnly right subtree present\n");
		replace_node_in_parent(parent, elem, elem->right);
		free(elem);
	}
	// If 'elem' has no children - replace link to it from parent with NULL
	else
	{
		printf("\t\tNo subtrees present\n");
		replace_node_in_parent(parent, elem, NULL);
	}

	return root;
}
