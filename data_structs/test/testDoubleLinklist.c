#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "double_linklist.h"
#include "testDoubleLinklist.h"
#include "unity.h"

void test_destroy_dbl_ll(void)
{
	struct dbl_ll_node *d_ptr=NULL;
	uint32_t data_val=0;
	TEST_ASSERT_NULL(d_ptr);
	
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 2, 0));
	TEST_ASSERT_EQUAL_INT32(0, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(1, data_val );
	TEST_ASSERT_NOT_NULL(d_ptr);
	TEST_ASSERT_EQUAL_INT32(0, destroy_dbl_ll(&d_ptr));
	TEST_ASSERT_NULL(d_ptr);
	TEST_ASSERT_EQUAL_INT32(-3, destroy_dbl_ll(&d_ptr));
}

void test_add_dbl_ll(void)
{
	struct dbl_ll_node *d_ptr=NULL;
	uint32_t data_val=0;
	TEST_ASSERT_NULL(d_ptr);

	/* Test that size inits to 0 */
	TEST_ASSERT_EQUAL_INT32(-1, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(0, data_val );

	/* Test that adding a node sets size to 1 */
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 2, 0));
	TEST_ASSERT_EQUAL_INT32(0, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(1, data_val );
	
	/* Test that adding a node to the end succeeds */
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 4, 1));
	TEST_ASSERT_EQUAL_INT32(0, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(2, data_val );
	
	/* Test that adding a node to the beginning succeeds */
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 1, 0));
	TEST_ASSERT_EQUAL_INT32(0, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(3, data_val );
	
	/* Test that adding a node to the middle succeeds */
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 1, 2));
	TEST_ASSERT_EQUAL_INT32(0, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(4, data_val );
	
	/* Test that adding a node beyond the end fails */
	TEST_ASSERT_EQUAL_INT32(-5, add_dbl_ll_node(&d_ptr, 12345, 100));
	TEST_ASSERT_EQUAL_INT32(0, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(4, data_val );
	
	/* Test that adding a node to a negative index fails */
	TEST_ASSERT_EQUAL_INT32(-5, add_dbl_ll_node(&d_ptr, 12345, -1));
	TEST_ASSERT_EQUAL_INT32(0, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(4, data_val );
	
	TEST_ASSERT_NOT_NULL(d_ptr);
	TEST_ASSERT_EQUAL_INT32(0, destroy_dbl_ll(&d_ptr));

}

void test_remove_dbl_ll(void)
{
	struct dbl_ll_node *d_ptr=NULL;
	uint32_t data_val=0;
	TEST_ASSERT_EQUAL_INT32(-1, remove_dbl_ll_node(&d_ptr, &data_val, 0));
	TEST_ASSERT_EQUAL_INT32( 0, add_dbl_ll_node(&d_ptr, 1, 0));
	TEST_ASSERT_EQUAL_INT32( 0, add_dbl_ll_node(&d_ptr, 2, 0));
	TEST_ASSERT_EQUAL_INT32( 0, add_dbl_ll_node(&d_ptr, 3, 0));
	TEST_ASSERT_EQUAL_INT32( 0, add_dbl_ll_node(&d_ptr, 4, 0));
	TEST_ASSERT_EQUAL_INT32( 0, add_dbl_ll_node(&d_ptr, 5, 0));
	
	TEST_ASSERT_EQUAL_INT32(-5, remove_dbl_ll_node(&d_ptr, &data_val, 5));
	TEST_ASSERT_EQUAL_INT32( 0, remove_dbl_ll_node(&d_ptr, &data_val, 4));
	TEST_ASSERT_EQUAL_INT32( 0, remove_dbl_ll_node(&d_ptr, &data_val, 3));
	TEST_ASSERT_EQUAL_INT32( 0, remove_dbl_ll_node(&d_ptr, &data_val, 2));
	TEST_ASSERT_EQUAL_INT32( 0, remove_dbl_ll_node(&d_ptr, &data_val, 0));

}

void test_size_dbl_ll(void)
{
	struct dbl_ll_node *d_ptr=NULL;
	uint32_t data_val=0;
	TEST_ASSERT_NULL(d_ptr);
	TEST_ASSERT_EQUAL_INT32(-1, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(0, data_val );
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 12345, 0));
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 12345, 0));
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 12345, 0));
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 12345, 0));
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 12345, 0));
	TEST_ASSERT_EQUAL_INT32(0, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(5, data_val );

}

void test_search_dbl_ll(void)
{
	struct dbl_ll_node *d_ptr=NULL;
	uint32_t data_val=0;
	TEST_ASSERT_NULL(d_ptr);
	TEST_ASSERT_EQUAL_INT32(-1, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(0, data_val );
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 1, 0));
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 2, 0));
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 3, 0));
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 4, 0));
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 5, 0));
	TEST_ASSERT_EQUAL_INT32(0, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(5, data_val );

}

