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

struct dbl_ll_node {
	uint32_t data;
	struct dbl_ll_node *prev;
	struct dbl_ll_node *next;
};

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint8_t destroy_dbl_ll(struct dbl_ll_node *ptr);

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint8_t add_dbl_ll_node(struct dbl_ll_node *ptr, uint32_t value, uint32_t idx);

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint8_t remove_dbl_ll_node(struct dbl_ll_node *ptr, uint32_t idx);

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint32_t search_dbl_ll(struct dbl_ll_node *ptr, uint32_t value);

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint32_t dbl_ll_size(struct dbl_ll_node *ptr);

#endif /* __MY_DBL_LINKLIST_H__ */
