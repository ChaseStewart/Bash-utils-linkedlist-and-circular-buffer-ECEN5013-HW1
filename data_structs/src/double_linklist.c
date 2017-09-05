/*****************************************************
 * Copyright (C) 2017 by Chase E Stewart
 *
 * 
 *
 *
 *
******************************************************/
/**
 * @file double_linklist.c
 * @brief A simple library for a doubly-linked list
 * 
 * This circular buffer holds structs 
 *
 * @author Chase E Stewart
 * @date Sept 4 2017
 * @version 1.0
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../inc/double_linklist.h"

enum dbl_ll_errors{
	DBL_SUCCESS     =  0,
	DBL_INVALID_LL  = -1,
	DBL_CANNOT_ALLOC= -2,
	DBL_DOUBLE_FREE = -3,
	DBL_NOT_FOUND   = -4
};

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
uint8_t destroy_dbl_ll(struct dbl_ll_node *ptr)
{
	if (!ptr)
	{
		return DBL_DOUBLE_FREE;
	}
}

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint8_t add_dbl_ll_node(uint8_t *ptr, uint32_t value, uint32_t idx )
{
	if (!ptr)
	{
		return DBL_INVALID_LL;
	}
	if 
}

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint8_t remove_dbl_ll_node(uint8_t *ptr, uint8_t value)
{
	if (!ptr)
	{
		return DBL_INVALID_LL;
	}
	return  DBL_SUCCESS;
}

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint8_t search_dbl_ll(uint8_t *ptr, uint32_t data)
{
	if (!ptr)
	{
		return DBL_INVALID_LL;
	}
	return DBL_NOT_FOUND;
}

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
uint32_t dbl_ll_size(struct dbl_ll_node *listptr)
{
	if (!ptr)
	{
		return DBL_INVALID_LL;
	}
	uint32_t counter = 0;
	while ()
	{
	
	}
}

