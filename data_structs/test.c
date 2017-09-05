#include <stdio.h>
#include <stdbool.h>

#include "inc/circ_buff.h"
#include "inc/double_linklist.h"

int main()
{
	struct c_node ptr;
	uint8_t retval = 0;
	printf("The test below should fail\n");
	retval = allocate_c_buff(&ptr, -1);
	printf("Retval is: %d should be: %d \n\n", retval, 254);

	retval = allocate_c_buff(&ptr, 100);
	printf("Retval is: %d should be: %d \n", retval, 0);

	retval = is_c_buff_empty(&ptr);
	printf("Retval is: %d should be: %d \n", retval, true);

	retval = is_c_buff_full(&ptr);
	printf("Retval is: %d should be: %d \n", retval, false);
}

