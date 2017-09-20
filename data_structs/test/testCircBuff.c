/*****************************************************
 * Redistribution, modification or use of this software in source or binary forms 
 * is permitted as long as the files maintain this copyright. Users are permitted to 
 * modify this and use it to learn about the field of embedded software but don't copy 
 * my (Chase E Stewart's) work for class, I worked really hard on this. Alex Fosdick and 
 * the University of Colorado and Chase E Stewart are not liable for any misuse of this material. 
 * License copyright (C) 2017 originally from Alex Fosdick, code by Chase E Stewart.
 *****************************************************/
/**
 * @file testCircBuff.c
 * @brief A set of unit tests for the circular buffer from HW 1
 * 
 *
 * @author Chase E Stewart
 * @date Sept 19 2017
 * @version 1.0
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "circ_buff.h"
#include "testCircBuff.h"
#include "unity.h"

/*
 * @brief test alloc_c_buff for valid and invalid
 *
 * @param none
 *
 * @return none
 */
void test_allocate_c_buff(void)
{
	struct c_node *ptr=NULL;
	TEST_ASSERT_NULL(ptr);
	/* test invalid allocation size */
	TEST_ASSERT_EQUAL_INT32(-2, allocate_c_buff(&ptr, -1));
	/* test valid allocation size */
	TEST_ASSERT_EQUAL_INT32(0, allocate_c_buff(&ptr, 10000));
	TEST_ASSERT_NOT_NULL(ptr);
	/* test invalid allocation size */
	TEST_ASSERT_EQUAL_INT32(-2, allocate_c_buff(&ptr, -1000));
}

/*
 * @brief test dump_c_buff 
 *
 * @param none
 *
 * @return none
 */
void test_dump_c_buff(void)
{
	struct c_node *ptr;
	allocate_c_buff(&ptr, 4);

	/* dump empty buffer */
	printf("Buffer should be empty\n");
	dump_c_buff(&ptr);
	
	/* add items to buffer */
	add_c_buff_data(&ptr, 1);
	add_c_buff_data(&ptr, 14);
	add_c_buff_data(&ptr, 30);
	add_c_buff_data(&ptr, 236);
	/* dump full buffer and view output */
	printf("Buffer should have []\n");
	dump_c_buff(&ptr);
}


/*
 * @brief test alloc_c_buff for valid and invalid
 *
 * @param none
 *
 * @return none
 */
void test_destroy_c_buff(void)
{

	struct c_node *ptr=NULL;
	TEST_ASSERT_NULL(ptr);
	allocate_c_buff(&ptr, 4);
	
	/* test that buffer was allocated */
	TEST_ASSERT_NOT_NULL(ptr);

	/* fill up the buffer */
	add_c_buff_data(&ptr, 1);
	add_c_buff_data(&ptr, 14);
	add_c_buff_data(&ptr, 30);
	add_c_buff_data(&ptr, 236);

	/* destroy buffer, ensure it's gone */
	destroy_c_buff(&ptr);
	TEST_ASSERT_NULL(ptr);
}

/*
 * @brief test add_c_buff for valid and invalid
 *
 * @param none
 *
 * @return none
 */
void test_add_c_buff(void)
{
	struct c_node *ptr=NULL;
	TEST_ASSERT_NULL(ptr);
	allocate_c_buff(&ptr, 4);
	
	/* add data to start */
	TEST_ASSERT_EQUAL_INT32( 0, add_c_buff_data(&ptr, 1));
	TEST_ASSERT_EQUAL_INT32( 0, add_c_buff_data(&ptr, 1));
	TEST_ASSERT_EQUAL_INT32( 0, add_c_buff_data(&ptr, 1));
	TEST_ASSERT_EQUAL_INT32( 0, add_c_buff_data(&ptr, 1));
	
	/* try to add data to full buffer */
	TEST_ASSERT_EQUAL_INT32(-4, add_c_buff_data(&ptr, 1));

}

/*
 * @brief test size_c_buff for valid and invalid
 *
 * @param none
 *
 * @return none
 */
void test_size_c_buff(void)
{
	struct c_node *ptr=NULL;
	TEST_ASSERT_NULL(ptr);
	
	/* test size fail on invalid c_buff */
	TEST_ASSERT_EQUAL_INT32(-1, c_buff_size(&ptr));
	allocate_c_buff(&ptr, 4);

	/* test size success on valid c_buff */
	TEST_ASSERT_EQUAL_INT32(0, c_buff_size(&ptr));
	add_c_buff_data(&ptr, 1);
	add_c_buff_data(&ptr, 1);
	add_c_buff_data(&ptr, 1);

	/* test correct size on valid c_buff */
	TEST_ASSERT_EQUAL_INT32(3, c_buff_size(&ptr));
	add_c_buff_data(&ptr, 1);

	/* test correct size on valid c_buff */
	TEST_ASSERT_EQUAL_INT32(4, c_buff_size(&ptr));

	/* these adds are invalid bc buffer is full */
	add_c_buff_data(&ptr, 1);
	add_c_buff_data(&ptr, 1);
	
	/* test size stays at max for full c_buff */
	TEST_ASSERT_EQUAL_INT32(4, c_buff_size(&ptr));
	
}

/*
 * @brief test removing items from the circular buffer
 *
 * @param none
 *
 * @return none
 */
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
	
	/* remove item from buffer */
	TEST_ASSERT_EQUAL_INT32( 4, c_buff_size(&ptr));
	TEST_ASSERT_EQUAL_INT32( 0, remove_c_buff_data(&ptr));
	
	/* remove item from buffer */
	TEST_ASSERT_EQUAL_INT32( 3, c_buff_size(&ptr));
	TEST_ASSERT_EQUAL_INT32( 0, remove_c_buff_data(&ptr));
	
	/* remove item from buffer */
	TEST_ASSERT_EQUAL_INT32( 2, c_buff_size(&ptr));
	TEST_ASSERT_EQUAL_INT32( 0, remove_c_buff_data(&ptr));
	
	/* remove item from buffer */
	TEST_ASSERT_EQUAL_INT32( 1, c_buff_size(&ptr));
	TEST_ASSERT_EQUAL_INT32( 0, remove_c_buff_data(&ptr));
	
	/* test buffer size == 0 */
	TEST_ASSERT_EQUAL_INT32( 0, c_buff_size(&ptr));
	
	/* test an invalid remove item from buffer */
	TEST_ASSERT_EQUAL_INT32(-5, remove_c_buff_data(&ptr));
	TEST_ASSERT_EQUAL_INT32( 0, c_buff_size(&ptr));

}

/*
 * @brief test buffer full and empty for various situations
 *
 * @param none
 *
 * @return none
 */
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

