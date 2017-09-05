#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "inc/circ_buff.h"
#include "inc/double_linklist.h"

int main()
{
	struct c_node ptr;
	int8_t retval = 0;
	printf("The test below should fail\n");
	retval = allocate_c_buff(&ptr, -1);
	printf("Retval is: %d should be: %d \n\n", retval, 254);

	retval = allocate_c_buff(&ptr, 100);
	printf("Retval is: %d should be: %d \n", retval, 0);

	retval = is_c_buff_empty(&ptr);
	printf("Retval is: %d should be: %d \n", retval, true);

	retval = is_c_buff_full(&ptr);
	printf("Retval is: %d should be: %d \n", retval, false);

	struct dbl_ll_node *d_ptr;
	d_ptr = (struct dbl_ll_node *)malloc(sizeof(struct dbl_ll_node));
	d_ptr->next = NULL;
	d_ptr->prev = NULL;
	d_ptr->data = 0;

	retval = add_dbl_ll_node(d_ptr, 12345, 0);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_dbl_ll_node(d_ptr, 2345, 1);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_dbl_ll_node(d_ptr, 345, 1);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_dbl_ll_node(d_ptr, 505, 3);
	printf("Retval is: %d should be: %d \n", retval, 0);

	retval = add_dbl_ll_node(d_ptr, 345, 1000);
	printf("Retval is: %d should be: %d \n", retval, -5);

	uint32_t size = dbl_ll_size(d_ptr);
	printf("Size is %d\n", size);

	retval = remove_dbl_ll_node(d_ptr, 1000);
	printf("Retval is: %d should be: %d \n", retval, -5);
	
	retval = remove_dbl_ll_node(d_ptr, 1);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	size = dbl_ll_size(d_ptr);
	printf("Size is %d\n", size);

	uint32_t index = search_dbl_ll(d_ptr, 505);
	printf("Search idx is: %d should be: %d \n", index, 3);
	
	index = search_dbl_ll(d_ptr, 12345);
	printf("Search idx is: %d should be: %d \n", index, 1);
	
	index = search_dbl_ll(d_ptr, 0);
	printf("Search idx is: %d should be: %d \n", index, 0);

	retval = destroy_dbl_ll(d_ptr);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	size = dbl_ll_size(d_ptr);
	printf("size is %d\n", size);

	if (d_ptr == NULL)
	{
		printf("Delete was successful\n\n");
	}
	
	retval = remove_dbl_ll_node(d_ptr, 0);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = remove_dbl_ll_node(d_ptr, 0);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = remove_dbl_ll_node(d_ptr, 0);
	printf("Retval is: %d should be: %d \n", retval, 0);

	retval = remove_dbl_ll_node(d_ptr, 0);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	size = dbl_ll_size(d_ptr);
	printf("size is %d\n", size);

}

