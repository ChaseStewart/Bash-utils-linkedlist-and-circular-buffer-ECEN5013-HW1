/*****************************************************
 * Copyright (C) 2017 by Chase E Stewart
 *
 * 

 
*
******************************************************/
/**
 * @file double_linklist.h
 * @brief A simple library for a doubly-linked list
 * 
 * This circular buffer holds structs 
 *
 * @author Chase E Stewart
 * @date Sept 4 2017
 * @version 1.0
 *
 */
#ifndef __MY_DBL_LINKLIST_H__
#define __MY_DBL_LINKLIST_H__

#include <stdint.h>

struct dbl_ll_node;

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint8_t destroy(struct dbl_ll_node *ptr);

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint8_t add_node(uint8_t *ptr, uint8_t value);

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint8_t remove_node(uint8_t *ptr, uint8_t value);

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint8_t search(uint8_t *ptr, uint8_t value);

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint32_t size(struct dbl_ll_node *ptr);

#endif /* __MY_DBL_LINKLIST_H__ */
