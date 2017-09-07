/*****************************************************
 * Copyright (C) 2017 by Chase E Stewart
 *
 * 
 *
 *
 *
 *****************************************************/
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
#include <stdio.h>
#include <stdbool.h>
#include "../inc/double_linklist.h"

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
dbl_ll_status_t destroy_dbl_ll(struct dbl_ll_node **ptr)
{
	if (!(*ptr))
	{
		return DBL_DOUBLE_FREE;
	}
	while((*ptr)->next != NULL)
	{
		(*ptr) = (*ptr)->next;
		free((*ptr)->prev);
	}
	free(*ptr);
	return DBL_SUCCESS;
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
dbl_ll_status_t add_dbl_ll_node(struct dbl_ll_node **ptr, uint32_t value, uint32_t idx )
{
	if (!(*ptr))
	{
		return DBL_INVALID_LL;
	}
	
	struct dbl_ll_node *new_node;
	new_node = (struct dbl_ll_node *)malloc(sizeof(struct dbl_ll_node));
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	for (int i=0; i<idx; i++)
	{
		if((*ptr) == NULL)
		{
			return DBL_OUT_OF_RANGE;
		}
		(*ptr) = (*ptr)->next;
	}
	if ((*ptr) == NULL)
	{
		(*ptr) = new_node;
	}
	else if ((*ptr)->next == NULL)
	{	
		(*ptr)->next = new_node;
		new_node->prev = (*ptr);
	}
	else
	{
		(*ptr)->next->prev = new_node;
		new_node->next = (*ptr)->next;
		(*ptr)->next = new_node;
		new_node->prev = (*ptr);
	}
	return DBL_SUCCESS;
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
dbl_ll_status_t remove_dbl_ll_node(struct dbl_ll_node **ptr, uint32_t idx)
{
	if (!(*ptr))
	{
		return DBL_INVALID_LL;
	}
	for (int i=0; i<=idx; i++)
	{
		if((*ptr) == NULL)
		{
			return DBL_OUT_OF_RANGE;
		}
		(*ptr) = (*ptr)->next;
	}
	if ((*ptr)->next == NULL)
	{
		if ((*ptr)->prev == NULL)
		{
			free(*ptr);
		}
		else
		{
			(*ptr)->prev->next = NULL;
			free(*ptr);
		}
	}
	else
	{
		(*ptr)->prev->next = (*ptr)->next;
		(*ptr)->next->prev = (*ptr)->prev;
		free(*ptr);
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
uint32_t search_dbl_ll(struct dbl_ll_node **ptr, uint32_t value)
{
	if (!(*ptr))
	{
		return DBL_INVALID_LL;
	}
	uint32_t counter = 0;
	while ((*ptr) != NULL)
	{
		if ((*ptr)->data == value)
		{
			return counter;
		}
		(*ptr) = (*ptr)->next;
		counter ++;
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
uint32_t dbl_ll_size(struct dbl_ll_node **ptr)
{
	if (!(*ptr))
	{
		return DBL_INVALID_LL;
	}
	uint32_t counter = 0;
	while ((*ptr) != NULL)
	{
		(*ptr) = (*ptr)->next;
		counter++;
	}
	return counter;
}

