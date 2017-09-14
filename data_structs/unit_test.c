#include "unity.h"
#include "test/testCircBuff.h"
#include "test/testDoubleLinklist.h"


void setUp(void)
{
}

void tearDown(void)
{
}


int main(void)
{
	/* Start the unit testing */
	UNITY_BEGIN();
	
	/* Unit-Test Circ Buffer */	
	RUN_TEST(test_allocate_c_buff);
	RUN_TEST(test_destroy_c_buff);
	RUN_TEST(test_add_c_buff);
	RUN_TEST(test_dump_c_buff);
	RUN_TEST(test_size_c_buff);
	RUN_TEST(test_remove_c_buff);
	RUN_TEST(test_c_buff_full_and_empty);


	/* Unit-Test Double Linklist */	
	RUN_TEST(test_add_dbl_ll);
	RUN_TEST(test_destroy_dbl_ll);
	RUN_TEST(test_remove_dbl_ll);
	RUN_TEST(test_size_dbl_ll);
	RUN_TEST(test_search_dbl_ll);

	/* End the unit testing */
	return UNITY_END();
}
