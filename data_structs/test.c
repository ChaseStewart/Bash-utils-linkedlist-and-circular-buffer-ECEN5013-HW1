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
	printf("Retval is: %d should be: %d \n", retval, -4);
	
	retval = remove_c_buff_data(&ptr);
	printf("Retval is: %d should be: %d \n", retval, 0);

	retval = remove_c_buff_data(&ptr);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_c_buff_data(&ptr, 600);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_c_buff_data(&ptr, 700);
	printf("Retval is: %d should be: %d \n", retval, 0);
	
	dump_c_buff(&ptr);

	retval = destroy_c_buff(&ptr); 
	printf("Retval is %d\n", retval);
	
	if (!ptr)
	{
		printf(" C Buff delete was successful\n\n");
	}
	
	retval = add_c_buff_data(&ptr, 700);
	printf("Retval is: %d should be: %d \n", retval, -1);

	printf("\n\n*** DOUBLE_LINK_LIST ***\n");
	struct dbl_ll_node *d_ptr = NULL;

	uint32_t data_val;
	
	retval = dbl_ll_size(&d_ptr, &data_val);
	printf("Size is %d and return code is %d\n", data_val, retval );

	retval = add_dbl_ll_node(&d_ptr, 12345, 0);
	printf("[12345] Retval is: %d should be: %d \n", retval, 0);
	
	retval = dbl_ll_size(&d_ptr, &data_val );
	printf("Size is %d\n", data_val);
	
	retval = add_dbl_ll_node(&d_ptr, 2345, 1);
	printf("[12345, 2345] Retval is: %d should be: %d \n", retval, 0);
	
	retval = dbl_ll_size(&d_ptr, &data_val);
	printf("Size is %d\n", data_val);
	
	retval = add_dbl_ll_node(&d_ptr, 345, 1);
	printf("[12345, 345, 2345] Retval is: %d should be: %d \n", retval, 0);
	
	retval = dbl_ll_size(&d_ptr, &data_val);
	printf("Size is %d\n", data_val);

	retval = add_dbl_ll_node(&d_ptr, 505, 3);
	printf("[12345, 345, 2345, 505] Retval is: %d should be: %d \n", retval, 0);

	retval = add_dbl_ll_node(&d_ptr, 8080, 0);
	printf("[8080, 12345, 345, 2345, 505 ] Retval is: %d should be: %d \n", retval, 0);
	
	retval = add_dbl_ll_node(&d_ptr, 9090, 6);
	printf("[8080, 12345, 345, 2345, 505 ] Retval is: %d should be: %d \n", retval, -5);
	
	retval = add_dbl_ll_node(&d_ptr, 9090, 100);
	printf("[8080, 12345, 345, 2345, 505 ] Retval is: %d should be: %d \n", retval, -5);

	retval = remove_dbl_ll_node(&d_ptr, &data_val, 2);
	printf("[8080, 12345, 345, 2345, 505 ] Data val is: %d should be: %d \n", data_val, 345);
	
	retval = search_dbl_ll(&d_ptr, &data_val, 505);
	printf("Search idx is: %d should be: %d \n", data_val, 3);
	
	retval = search_dbl_ll(&d_ptr, &data_val, 2345);
	printf("Search idx is: %d should be: %d \n", data_val, 2);
	
	retval = search_dbl_ll(&d_ptr, &data_val, 8080);
	printf("Search idx is: %d should be: %d \n", data_val, 0);

	retval = dbl_ll_size(&d_ptr, &data_val);
	printf("size is %d\n", data_val);
	
	retval = remove_dbl_ll_node(&d_ptr, &data_val, 8);
	printf("Retval is: %d should be: %d \n", retval, -5);

	retval = destroy_dbl_ll(&d_ptr);
	printf("Retval is: %d should be: %d \n", retval, 0);
	

	if (d_ptr == NULL)
	{
		printf("Delete was successful\n\n");
	}
	
	retval = dbl_ll_size(&d_ptr, &data_val);
	printf("size retcode is %d and val is is %d\n", retval, data_val);

}

