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
	printf("Retval is: %d should be: %d \n\n", retval, -2);

	retval = allocate_c_buff(&ptr, 5);
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
	printf("Retval is: %d should be: %d \n", retval, -4);
	
	retval = remove_c_buff_data(&ptr);
	printf("Retval is: %d should be: %d \n", retval, 0);

	retval = remove_c_buff_data(&ptr);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	//retval = remove_c_buff_data(&ptr);
	//printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_c_buff_data(&ptr, 600);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_c_buff_data(&ptr, 700);
	printf("Retval is: %d should be: %d \n", retval, 0);
//	
//	retval = add_c_buff_data(&ptr, 800);
//	printf("Retval is: %d should be: %d \n", retval, 0);
//
//	retval = add_c_buff_data(&ptr, 900);
//	printf("Retval is: %d should be: %d \n", retval, -4);
	
	dump_c_buff(&ptr);



	printf("\n\n*** DOUBLE_LINK_LIST ***\n");
	struct dbl_ll_node *d_ptr;
	d_ptr = (struct dbl_ll_node *) malloc (sizeof(struct dbl_ll_node));
	d_ptr->next = NULL;
	d_ptr->prev = NULL;
	d_ptr->data = 0;

	uint32_t data_val = 0;
	
	int32_t size = dbl_ll_size(&d_ptr);
	printf("Size is %d\n", size);

	retval = add_dbl_ll_node(&d_ptr, 12345, 0);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	size = dbl_ll_size(&d_ptr);
	printf("Size is %d\n", size);
	
	retval = add_dbl_ll_node(&d_ptr, 2345, 1);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	size = dbl_ll_size(&d_ptr);
	printf("Size is %d\n", size);
	
	retval = add_dbl_ll_node(&d_ptr, 345, 1);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	size = dbl_ll_size(&d_ptr);
	printf("Size is %d\n", size);

	retval = add_dbl_ll_node(&d_ptr, 505, 3);
	printf("Retval is: %d should be: %d \n", retval, 0);


	retval = remove_dbl_ll_node(&d_ptr, &data_val, 2);
	printf("Data val is: %d should be: %d \n", data_val, 2345);
	
	int32_t index = search_dbl_ll(&d_ptr, 505);
	printf("Search idx is: %d should be: %d \n", index, 3);
	
	index = search_dbl_ll(&d_ptr, 2345);
	printf("Search idx is: %d should be: %d \n", index, -4);
	
	index = search_dbl_ll(&d_ptr, 12345);
	printf("Search idx is: %d should be: %d \n", index, 1);

	size = dbl_ll_size(&d_ptr);
	printf("size is %d\n", size);
	
	retval = destroy_dbl_ll(&d_ptr);
	printf("Retval is: %d should be: %d \n", retval, 0);
	

	if (d_ptr == NULL)
	{
		printf("Delete was successful\n\n");
	}
	
	size = dbl_ll_size(&d_ptr);
	printf("size is %d\n", size);

}

