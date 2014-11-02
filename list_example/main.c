#include <stdio.h>
#include "linked_list.h"

int main()
{
	int i;
	list_element* cur_elem;

	list_element* root = create_list_element(0);
	for(i = 1; i < 10; i++)
	{
		list_element* elem = create_list_element(i*i);
		root = insert_into_list(root, elem);
	}

	printf("List after creation:\n");
	print_list(root);

	printf("The 2nd element of the list: %d\n", get_by_index(root, 2)->value);

	cur_elem = get_by_index(root, 100);
	if(cur_elem == NULL)
	{
		printf("Can not get 100th element - index out of range\n");
	}

	cur_elem = search_by_value(root, 25);
	if(cur_elem != NULL)
	{
		printf("Search for value 25: found\n");
	}

	cur_elem = search_by_value(root, 111);
	if(cur_elem == NULL)
	{
		printf("Search for value 111: not found\n");
	}

	cur_elem = get_by_index(root, 2);
	root = delete_from_list(root, cur_elem);
	printf("List after deletion of the 2nd element:\n");
	print_list(root);

	cur_elem = get_by_index(root, 0);
	root = delete_from_list(root, cur_elem);
	printf("List after deletion of root element:\n");
	print_list(root);

	return 0;
}
