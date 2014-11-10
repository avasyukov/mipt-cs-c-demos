#include <stdio.h>
#include "binary_tree.h"

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

	cur_elem = search_by_value(root, 3);
	root = delete_from_tree(root, cur_elem);
	printf("List after deletion of element:\n");
	print_tree(root);

	return 0;
}
