/*****************************************************
 * Redistribution, modification or use of this software in source or binary forms 
 * is permitted as long as the files maintain this copyright. Users are permitted to 
 * modify this and use it to learn about the field of embedded software but don't copy 
 * my (Chase E Stewart's) work for class, I worked really hard on this. Alex Fosdick and 
 * the University of Colorado and Chase E Stewart are not liable for any misuse of this material. 
 * License copyright (C) 2017 originally from Alex Fosdick, code by Chase E Stewart.
 *****************************************************/
/**
 * @file testDoubleLinklist.c
 * @brief A set of unit tests for the doubleLinklist from HW 
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

#include "double_linklist.h"
#include "testDoubleLinklist.h"
#include "unity.h"


/*
 * @brief test destroy dbl_ll on a valid ll and an invalid ll 
 *
 * @param none
 *
 * @return none
 */
void test_destroy_dbl_ll(void)
{
	struct dbl_ll_node *d_ptr=NULL;
	uint32_t data_val=0;
	TEST_ASSERT_NULL(d_ptr);
	
	/* make dbl_ll has nodes */
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 2, 0));
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 3, 0));
	TEST_ASSERT_EQUAL_INT32(0, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(2, data_val );
	TEST_ASSERT_NOT_NULL(d_ptr);

	/* now destroy the valid node */
	TEST_ASSERT_EQUAL_INT32(0, destroy_dbl_ll(&d_ptr));
	TEST_ASSERT_NULL(d_ptr);
	TEST_ASSERT_EQUAL_INT32(-3, destroy_dbl_ll(&d_ptr));
}

/*
 * @brief test add to dbl_ll in different locations, 
 *
 * @param none
 *
 * @return none
 */
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

/*
 * @brief test remove dbl_ll on valid ll nodes and invalid ll nodes
 *
 * @param none
 *
 * @return none
 */
void test_remove_dbl_ll(void)
{
	struct dbl_ll_node *d_ptr=NULL;
	uint32_t data_val=0;
	/* Create ll and some nodes */
	TEST_ASSERT_EQUAL_INT32(-1, remove_dbl_ll_node(&d_ptr, &data_val, 0));
	TEST_ASSERT_EQUAL_INT32( 0, add_dbl_ll_node(&d_ptr, 1, 0));
	TEST_ASSERT_EQUAL_INT32( 0, add_dbl_ll_node(&d_ptr, 2, 0));
	TEST_ASSERT_EQUAL_INT32( 0, add_dbl_ll_node(&d_ptr, 3, 0));
	TEST_ASSERT_EQUAL_INT32( 0, add_dbl_ll_node(&d_ptr, 4, 0));
	TEST_ASSERT_EQUAL_INT32( 0, add_dbl_ll_node(&d_ptr, 5, 0));
	
	/* test invalid removal */
	TEST_ASSERT_EQUAL_INT32(-5, remove_dbl_ll_node(&d_ptr, &data_val, 5));
	/* test valid removal from end */
	TEST_ASSERT_EQUAL_INT32( 0, remove_dbl_ll_node(&d_ptr, &data_val, 4));
	/* test valid removal from middle */
	TEST_ASSERT_EQUAL_INT32( 0, remove_dbl_ll_node(&d_ptr, &data_val, 3));
	/* test valid removal from middle */
	TEST_ASSERT_EQUAL_INT32( 0, remove_dbl_ll_node(&d_ptr, &data_val, 2));
	/* test valid removal from start */
	TEST_ASSERT_EQUAL_INT32( 0, remove_dbl_ll_node(&d_ptr, &data_val, 0));

}

/*
 * @brief test check size for dbl_ll 
 *
 * @param none
 *
 * @return none
 */
void test_size_dbl_ll(void)
{
	struct dbl_ll_node *d_ptr=NULL;
	uint32_t data_val=0;
	TEST_ASSERT_NULL(d_ptr);
	
	/* test invalid size */
	TEST_ASSERT_EQUAL_INT32(-1, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(0, data_val );

	/* Create ll and some nodes */
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 12345, 0));
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 12345, 0));
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 12345, 0));
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 12345, 0));
	TEST_ASSERT_EQUAL_INT32(0, add_dbl_ll_node(&d_ptr, 12345, 0));

	/* test valid size and ret code */
	TEST_ASSERT_EQUAL_INT32(0, dbl_ll_size(&d_ptr, &data_val ));
	TEST_ASSERT_EQUAL_INT32(5, data_val );

}

/*
 * @brief test search for vals indbl_ll dbl_ll on a valid ll and an invalid ll 
 *
 * @param none
 *
 * @return none
 */
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

