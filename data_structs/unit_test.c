/*****************************************************
 * Redistribution, modification or use of this software in source or binary forms 
 * is permitted as long as the files maintain this copyright. Users are permitted to 
 * modify this and use it to learn about the field of embedded software but don't copy 
 * my (Chase E Stewart's) work for class, I worked really hard on this. Alex Fosdick and 
 * the University of Colorado and Chase E Stewart are not liable for any misuse of this material. 
 * License copyright (C) 2017 originally from Alex Fosdick, code by Chase E Stewart.
 *****************************************************/
/**
 * @file unit_test.c
 * @brief A unit test program for the data structures from the last assignment
 * 
 * This runs the testCircBuff and the testDoubleLinklist tests using the Unity Framework
 *
 * @author Chase E Stewart
 * @date Sept 19 2017
 * @version 1.0
 *
 */

#include "unity.h"
#include "test/testCircBuff.h"
#include "test/testDoubleLinklist.h"

/*
 * @brief just a stub for test setup
 *
 * @param none
 *
 * @return none
 */
void setUp(void)
{
}

/*
 * @brief just a stub for test teardown
 *
 * @param none
 *
 * @return none
 */
void tearDown(void)
{
}

/*
 * @brief start unity, run all unit tests, return results to stdout
 *
 * @param none
 *
 * @return int status 
 */
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

