/*****************************************************
 * Redistribution, modification or use of this software in source or binary forms 
 * is permitted as long as the files maintain this copyright. Users are permitted to 
 * modify this and use it to learn about the field of embedded software but don't copy 
 * my (Chase E Stewart's) work for class, I worked really hard on this. Alex Fosdick and 
 * the University of Colorado and Chase E Stewart are not liable for any misuse of this material. 
 * License copyright (C) 2017 originally from Alex Fosdick, code by Chase E Stewart.
 *****************************************************/
/**
 * @file testCircBuff.h
 * @brief A set of unit tests for the circular buffer from HW 1
 * 
 *
 * @author Chase E Stewart
 * @date Sept 19 2017
 * @version 1.0
 *
 */

#ifndef __MY_UNIT_CIRC_BUFF_H__
#define __MY_UNIT_CIRC_BUFF_H__

/*
 * @brief test alloc_c_buff
 *
 * @param none
 *
 * @return none
 */
void test_allocate_c_buff(void);

/*
 * @brief test dump_c_buff
 *
 * @param none
 *
 * @return none
 */
void test_dump_c_buff(void);

/*
 * @brief test destroy_c_buff
 *
 * @param none
 *
 * @return none
 */
void test_destroy_c_buff(void);

/*
 * @brief test add_c_buff
 *
 * @param none
 *
 * @return none
 */
void test_add_c_buff(void);

/*
 * @brief test size_c_buff
 *
 * @param none
 *
 * @return none
 */
void test_size_c_buff(void);

/*
 * @brief test remove_c_buff
 *
 * @param none
 *
 * @return none
 */
void test_remove_c_buff(void);

/*
 * @brief test c_buff full/empty
 *
 * @param none
 *
 * @return none
 */
void test_c_buff_full_and_empty(void);

#endif /* end __MY_UNIT_CIRC_BUFF_H__ */
