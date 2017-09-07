#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "inc/circ_buff.h"
#include "inc/double_linklist.h"

int main()
{
	printf("*** CIRC_BUFFER ***\n");
	struct c_node *ptr;
	int32_t retval = 0;
	printf("The test below should fail\n");
	retval = allocate_c_buff(&ptr, -1);
	printf("Retval is: %d should be: %d \n\n", retval, 254);

	retval = allocate_c_buff(&ptr, 4);
	printf("Retval is: %d should be: %d \n", retval, 0);


	retval = add_c_buff_data(&ptr, 100);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_c_buff_data(&ptr, 200);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_c_buff_data(&ptr, 300);
	printf("Retval is: %d should be: %d \n", retval, 0);

	retval = add_c_buff_data(&ptr, 400);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_c_buff_data(&ptr, 500);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = remove_c_buff_data(&ptr);
	printf("Retval is: %d should be: %d \n", retval, 0);

	retval = remove_c_buff_data(&ptr);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = remove_c_buff_data(&ptr);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	dump_c_buff(&ptr);



	printf("*** DOUBLE_LINK_LIST ***\n");
	struct dbl_ll_node *d_ptr;
	d_ptr = (struct dbl_ll_node *) malloc (sizeof(struct dbl_ll_node));
	d_ptr->next = NULL;
	d_ptr->prev = NULL;
	d_ptr->data = 0;

	retval = add_dbl_ll_node(&d_ptr, 12345, 0);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_dbl_ll_node(&d_ptr, 2345, 1);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_dbl_ll_node(&d_ptr, 345, 1);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_dbl_ll_node(&d_ptr, 505, 2);
	printf("Retval is: %d should be: %d \n", retval, 0);

	int32_t size = dbl_ll_size(&d_ptr);
	printf("Size is %d\n", size);

	retval = remove_dbl_ll_node(&d_ptr, 1000);
	printf("Retval is: %d should be: %d \n", retval, -5);
	
	int32_t index = search_dbl_ll(&d_ptr, 505);
	printf("Search idx is: %d should be: %d \n", index, 3);
	
	index = search_dbl_ll(&d_ptr, 2345);
	printf("Search idx is: %d should be: %d \n", index, 1);
	
	index = search_dbl_ll(&d_ptr, 12345);
	printf("Search idx is: %d should be: %d \n", index, 0);

	retval = destroy_dbl_ll(&d_ptr);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	size = dbl_ll_size(&d_ptr);
	printf("size is %d\n", size);

	if (d_ptr == NULL)
	{
		printf("Delete was successful\n\n");
	}
	
	size = dbl_ll_size(&d_ptr);
	printf("size is %d\n", size);

}

