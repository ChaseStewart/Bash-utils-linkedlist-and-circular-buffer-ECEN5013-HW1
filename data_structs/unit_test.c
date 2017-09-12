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
	UNITY_BEGIN();
	RUN_TEST(test_allocate_c_buff);
	RUN_TEST(test_destroy_c_buff);
	RUN_TEST(test_add_c_buff);
	RUN_TEST(test_dump_c_buff);
	RUN_TEST(test_size_c_buff);
	RUN_TEST(test_remove_c_buff);
	RUN_TEST(test_c_buff_full_and_empty);
	return UNITY_END();
}

