/*****************************************************
 * Redistribution, modification or use of this software in source or binary forms 
 * is permitted as long as the files maintain this copyright. Users are permitted to 
 * modify this and use it to learn about the field of embedded software but don't copy 
 * my (Chase E Stewart's) work for class, I worked really hard on this. Alex Fosdick and 
 * the University of Colorado and Chase E Stewart are not liable for any misuse of this material. 
 * License copyright (C) 2017 originally from Alex Fosdick, code by Chase E Stewart.
 *****************************************************/
/**
 * @file testDoubleLinklist.h
 * @brief A set of unit tests for the doubleLinklist from HW 
 * 
 * This linked list is a struct of structs that creates a doubly-linked list. There is no master struct here;
 * all operations are completed by iterating through the list.
 * The file also contains methods to add, remove, search, destroy, and count the linked list, one node at a time.
 *
 * @author Chase E Stewart
 * @date Sept 13 2017
 * @version 1.1
 *
 */

#ifndef __MY_UNIT_DBL_LINKLIST_H__
#define __MY_UNIT_DBL_LINKLIST_H__

void test_destroy_dbl_ll(void);

void test_add_dbl_ll(void);

void test_remove_dbl_ll(void);

void test_size_dbl_ll(void);

void test_search_dbl_ll(void);

#endif /* end __MY_UNIT_DBL_LINKLIST_H__ */
