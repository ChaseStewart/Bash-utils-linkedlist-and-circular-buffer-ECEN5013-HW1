#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "circ_buff.h"
#include "testCircBuff.h"
#include "unity.h"


void test_allocate_c_buff(void)
{
	struct c_node *ptr=NULL;
	TEST_ASSERT_NULL(ptr);
	TEST_ASSERT_EQUAL_INT32(-2, allocate_c_buff(&ptr, -1));
	TEST_ASSERT_EQUAL_INT32(0, allocate_c_buff(&ptr, 10000));
	TEST_ASSERT_NOT_NULL(ptr);
	TEST_ASSERT_EQUAL_INT32(-2, allocate_c_buff(&ptr, -1000)); // TODO make MALLOC FAIL
}

void test_dump_c_buff(void)
{
	//char test_string1[3] = "[]";
	//char test_string2[17] = "[1, 14, 30, 236]";

	struct c_node *ptr;
	allocate_c_buff(&ptr, 4);
	//TEST_ASSERT_EQUAL_STRING(dump_c_buff(&ptr), test_string1);
	add_c_buff_data(&ptr, 1);
	add_c_buff_data(&ptr, 14);
	add_c_buff_data(&ptr, 30);
	add_c_buff_data(&ptr, 236);
	//TEST_ASSERT_EQUAL_STRING(dump_c_buff(&ptr), test_string2);
}


void test_destroy_c_buff(void)
{

	struct c_node *ptr=NULL;
	TEST_ASSERT_NULL(ptr);
	allocate_c_buff(&ptr, 4);
	TEST_ASSERT_NOT_NULL(ptr);
	add_c_buff_data(&ptr, 1);
	add_c_buff_data(&ptr, 14);
	add_c_buff_data(&ptr, 30);
	add_c_buff_data(&ptr, 236);
	destroy_c_buff(&ptr);
	TEST_ASSERT_NULL(ptr);
}

void test_add_c_buff(void)
{
	struct c_node *ptr=NULL;
	TEST_ASSERT_NULL(ptr);
	allocate_c_buff(&ptr, 4);
	TEST_ASSERT_EQUAL_INT32( 0, add_c_buff_data(&ptr, 1));
	TEST_ASSERT_EQUAL_INT32( 0, add_c_buff_data(&ptr, 1));
	TEST_ASSERT_EQUAL_INT32( 0, add_c_buff_data(&ptr, 1));
	TEST_ASSERT_EQUAL_INT32( 0, add_c_buff_data(&ptr, 1));
	TEST_ASSERT_EQUAL_INT32(-4, add_c_buff_data(&ptr, 1));

}

void test_size_c_buff(void)
{
	struct c_node *ptr=NULL;
	TEST_ASSERT_NULL(ptr);
	TEST_ASSERT_EQUAL_INT32(-1, c_buff_size(&ptr));
	allocate_c_buff(&ptr, 4);
	TEST_ASSERT_EQUAL_INT32(0, c_buff_size(&ptr));
	add_c_buff_data(&ptr, 1);
	add_c_buff_data(&ptr, 1);
	add_c_buff_data(&ptr, 1);
	TEST_ASSERT_EQUAL_INT32(3, c_buff_size(&ptr));
	add_c_buff_data(&ptr, 1);
	TEST_ASSERT_EQUAL_INT32(4, c_buff_size(&ptr));
	add_c_buff_data(&ptr, 1);
	add_c_buff_data(&ptr, 1);
	TEST_ASSERT_EQUAL_INT32(4, c_buff_size(&ptr));
	
}

void test_remove_c_buff(void)
{
	struct c_node *ptr=NULL;

	/* allocate buffer */
	TEST_ASSERT_NULL(ptr);
	allocate_c_buff(&ptr, 4);
	
	/* fill buffer */
	TEST_ASSERT_EQUAL_INT32( 0, add_c_buff_data(&ptr, 1));
	TEST_ASSERT_EQUAL_INT32( 0, add_c_buff_data(&ptr, 1));
	TEST_ASSERT_EQUAL_INT32( 0, add_c_buff_data(&ptr, 1));
	TEST_ASSERT_EQUAL_INT32( 0, add_c_buff_data(&ptr, 1));
	
	/* fill buffer */
	TEST_ASSERT_EQUAL_INT32( 4, c_buff_size(&ptr));
	TEST_ASSERT_EQUAL_INT32( 0, remove_c_buff_data(&ptr));
	
	/* fill buffer */
	TEST_ASSERT_EQUAL_INT32( 3, c_buff_size(&ptr));
	TEST_ASSERT_EQUAL_INT32( 0, remove_c_buff_data(&ptr));
	
	/* fill buffer */
	TEST_ASSERT_EQUAL_INT32( 2, c_buff_size(&ptr));
	TEST_ASSERT_EQUAL_INT32( 0, remove_c_buff_data(&ptr));
	
	/* fill buffer */
	TEST_ASSERT_EQUAL_INT32( 1, c_buff_size(&ptr));
	TEST_ASSERT_EQUAL_INT32( 0, remove_c_buff_data(&ptr));
	
	/* fill buffer */
	TEST_ASSERT_EQUAL_INT32( 0, c_buff_size(&ptr));
	
	/* fill buffer */
	TEST_ASSERT_EQUAL_INT32(-5, remove_c_buff_data(&ptr));
	TEST_ASSERT_EQUAL_INT32( 0, c_buff_size(&ptr));

}

void test_c_buff_full_and_empty(void)
{
	struct c_node *ptr=NULL;
	
	/* allocate buffer */
	TEST_ASSERT_NULL(ptr);
	allocate_c_buff(&ptr, 3);
	TEST_ASSERT_NOT_NULL(ptr);

	/* test empty buffer */
	TEST_ASSERT_EQUAL_INT32(true, is_c_buff_empty(&ptr));
	TEST_ASSERT_EQUAL_INT32(false, is_c_buff_full(&ptr));
	
	/* test full buffer */
	add_c_buff_data(&ptr, 1);
	add_c_buff_data(&ptr, 1);
	add_c_buff_data(&ptr, 1);
	TEST_ASSERT_EQUAL_INT32(false, is_c_buff_empty(&ptr));
	TEST_ASSERT_EQUAL_INT32(true, is_c_buff_full(&ptr));
	
	/* test in-between buffer */
	remove_c_buff_data(&ptr);
	TEST_ASSERT_EQUAL_INT32(false, is_c_buff_empty(&ptr));
	TEST_ASSERT_EQUAL_INT32(false, is_c_buff_full(&ptr));
}

