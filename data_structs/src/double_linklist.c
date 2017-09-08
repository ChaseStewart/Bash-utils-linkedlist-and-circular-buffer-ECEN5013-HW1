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

	struct dbl_ll_node *temp = NULL;
	temp = (*ptr);

	for (int i=0; i<idx; i++)
	{
		if(temp == NULL)
		{
			return DBL_OUT_OF_RANGE;
		}
		temp = temp->next;
	}
	if (temp == NULL)
	{
		temp = new_node;
	}
	else if (temp->next == NULL)
	{	
		temp->next = new_node;
		new_node->prev = temp;
	}
	else
	{
		temp->next->prev = new_node;
		new_node->next = temp->next;
		temp->next = new_node;
		new_node->prev = temp;
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
dbl_ll_status_t remove_dbl_ll_node(struct dbl_ll_node **ptr, uint32_t *retval, uint32_t idx)
{
	if (!(*ptr))
	{
		return DBL_INVALID_LL;
	}

	struct dbl_ll_node *temp = NULL;
	temp = (*ptr);
	for (int i=0; i<=idx; i++)
	{
		if(temp == NULL)
		{
			return DBL_OUT_OF_RANGE;
		}
		temp = temp->next;
	}
	if (temp->next == NULL)
	{
		if (temp->prev == NULL)
		{
			*retval = temp->data;
			free(temp);
		}
		else
		{
			temp->prev->next = NULL;
			*retval = temp->data;
			free(temp);
		}
	}
	else
	{
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		*retval = temp->data;
		free(temp);
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
dbl_ll_status_t search_dbl_ll(struct dbl_ll_node **ptr, uint32_t *retval, uint32_t value)
{
	if (!(*ptr))
	{
		return DBL_INVALID_LL;
	}
	*retval = 0;
	struct dbl_ll_node *temp = NULL;
	temp = *ptr;

	while (temp != NULL)
	{
		if (temp->data == value)
		{
			return DBL_SUCCESS;
		}
		temp = temp->next;
		*retval++;
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
	struct dbl_ll_node *temp = NULL;
	temp = *ptr;

	while (temp != NULL)
	{
		temp = temp->next;
		counter++;
	}
	return counter;
}

