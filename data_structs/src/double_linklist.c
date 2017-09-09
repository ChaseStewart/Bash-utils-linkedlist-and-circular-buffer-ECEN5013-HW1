/*****************************************************
 * Redistribution, modification or use of this software in source or binary forms 
 * is permitted as long as the files maintain this copyright. Users are permitted to 
 * modify this and use it to learn about the field of embedded software but don't copy 
 * my (Chase E Stewart's) work for class, I worked really hard on this. Alex Fosdick and 
 * the University of Colorado and Chase E Stewart are not liable for any misuse of this material. 
 * License copyright (C) 2017 originally from Alex Fosdick, code by Chase E Stewart.
 *****************************************************/
/*
 * @file double_linklist.c
 * @brief A simple library for a doubly-linked list
 * 
 * This linked list is a struct of structs that creates a doubly-linked list. There is no master struct here;
 * all operations are completed by iterating through the list.
 * The file also contains methods to add, remove, search, destroy, and count the linked list, one node at a time.
 *
 * @author Chase E Stewart
 * @date Sept 8 2017
 * @version 1.1
 *
 */
#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../inc/double_linklist.h"

/*
 * @brief destroy the provided linked list completely and free all nodes
 *
 *
 * @param struct dbl_ll_node **ptr: pointer to a pointer to the head dbl_ll node
 *
 * @return dbl_ll_status_t: an enum of the function exit status
 */
dbl_ll_status_t destroy_dbl_ll(struct dbl_ll_node **ptr)
{
	/* check whether buffer is valid, else refuse DOUBLE_FREE */
	if (!(*ptr))
	{
		return DBL_DOUBLE_FREE;
	}

	/* go thru list freeing node behind current in dbl_ll until next==NULL */
	while((*ptr)->next != NULL)
	{
		(*ptr) = (*ptr)->next;
		free((*ptr)->prev);
		(*ptr)->prev = NULL;
	}
	
	/* when 1 node left (next==NULL) just free that node */
	free(*ptr);
	(*ptr) = NULL;
	return DBL_SUCCESS;
}

/*
 * @brief add dbl_ll node at index idx with data=value
 *
 *
 * @param struct dbl_ll_node **ptr: pointer to a pointer to the head dbl_ll node
 * @param uint32_t value: the uint32 we want the double link_list to hold
 * @param uint32_t idx: the index at which we want to insert the new node
 *
 * @return dbl_ll_status_t: an enum of the function exit status
 */
dbl_ll_status_t add_dbl_ll_node(struct dbl_ll_node **ptr, uint32_t value, uint32_t idx )
{
	/* create+malloc a default new dbl_ll node */
	struct dbl_ll_node *new_node;
	new_node = (struct dbl_ll_node *)malloc(sizeof(struct dbl_ll_node));

	/* see if malloc worked, else ret failure code */
	if (!new_node)
	{
		return DBL_CANNOT_ALLOC;
	}
	
	/* set prev+next to NULL, set data to provided val */
	new_node->data = value;
	new_node->next = NULL;
	new_node->prev = NULL;

	/* check whether buffer is valid, for this function only initialize if so */
	if (!(*ptr))
	{
		(*ptr) = new_node;
		return DBL_SUCCESS;
	}
	

	/*create temp dbl_ll_node ptr to iterate thru dbl_ll */
	struct dbl_ll_node *temp = NULL;
	temp = (*ptr);

	/* if idx 0 was provided, set first node to this new node */
	if (idx == 0)
	{
		new_node->next = temp;
		(*ptr) = new_node;
		return DBL_SUCCESS;
	}
	else
	{
		/* iterate thru dbl_ll until the given idx is reached or end of list */
		for (int i=0; i<(idx-1); i++)
		{
			/* if the current node is null, requested idx is out of range  */
			if(temp->next == NULL)
			{
				return DBL_OUT_OF_RANGE;
			}
			temp = temp->next;
		}
		

		/* once requested idx is reached, next==NULL means adding to end of list */
		if (temp->next == NULL)
		{	
			temp->next = new_node;
			new_node->prev = temp;
		}
		/* elif next exists, add node into the list and push curr node at idx to next int */
		else
		{
			/* it helps to do this with your fingers to keep the logic straight */
			temp->next->prev = new_node;
			new_node->next = temp->next;
			temp->next = new_node;
			new_node->prev = temp;
		}
		return DBL_SUCCESS;
	}
}

/*
 * @brief remove dbl_ll node at index idx, return its value in retval
 *
 *
 * @param struct dbl_ll_node **ptr: pointer to a pointer to the head dbl_ll node
 * @param uint32_t *retval: a pointer to the value of the removed node- we return it
 * @param uint32_t idx: the index of the list we wish to return
 *
 * @return dbl_ll_status_t: an enum of the function exit status
 */
dbl_ll_status_t remove_dbl_ll_node(struct dbl_ll_node **ptr, uint32_t *retval, uint32_t idx)
{
	/* check whether buffer is valid */
	if (!(*ptr))
	{
		*retval = 0;
		return DBL_INVALID_LL;
	}

	/*create temp dbl_ll_node ptr to iterate thru dbl_ll */
	struct dbl_ll_node *temp = NULL;
	temp = (*ptr);

	/* if idx 0 was provided, set ptr to point to 2nd node and free 1st */
	if (idx == 0)
	{
		*retval = temp->data;
		(*ptr) = (*ptr)->next;
		free(temp);
	}
	else
	{
		/* iterate thru dbl_ll until the given idx is reached or end of list */
		for (int i=0; i<=(idx-1); i++)
		{
			/* if the current node is null, requested idx is out of range  */
			if(temp->next == NULL)
			{
				*retval = 0;
				return DBL_OUT_OF_RANGE;
			}
			temp = temp->next;
		}
		/* elif once requested idx is reached, next==NULL means adding to end of list */
		if (temp->next == NULL)
		{
			temp->prev->next = NULL;
			*retval = temp->data;
			free(temp);
		}
		/* else node is in the middle, take it out of list, then free the node */
		else
		{
			/* once again, use fingers to make sense of this */
			/* next's prev is current's prev and likewise prev's next is curr next  */
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			*retval = temp->data;
			free(temp);
		}
	}
	return DBL_SUCCESS;
}

/*
 * @brief search through dbl_ll for given value, place it into retval if found else error
 *
 *
 * @param struct dbl_ll_node **ptr: pointer to a pointer to the head dbl_ll node
 * @param uint32_t *retval: pointer to the index of the returned value in the l_list
 * @param uint32_t value: the value for which we want to search
 *
 * @return dbl_ll_status_t: an enum of the function exit status
 */
dbl_ll_status_t search_dbl_ll(struct dbl_ll_node **ptr, uint32_t *retval, uint32_t value)
{
	/* check whether buffer is valid */
	if (!(*ptr))
	{
		return DBL_INVALID_LL;
	}

	/* set deref of retval to 0 */
	uint32_t temp_counter = 0;
	
	/*create temp dbl_ll_node ptr to iterate thru dbl_ll */
	struct dbl_ll_node *temp = NULL;
	temp = *ptr;

	/* until end of list, iter thru list and keep incrementing retval */
	while (temp != NULL)
	{
		/* my algo: return idx of first data val that matches */
		if (temp->data == value)
		{
			*retval = temp_counter;
			return DBL_SUCCESS;
		}
		temp = temp->next;
		temp_counter++;
	}

	/* if temp==NULL is reached, the val wasn't in the list */
	return DBL_NOT_FOUND;
}

/*
 * @brief return the number of connected, allocated nodes in this dbl_ll
 *
 *
 * @param struct dbl_ll_node **ptr: pointer to a pointer to the head dbl_ll node
 * @param uint32_t *retval: pointer to the returned size of the linked list
 *
 * @return dbl_ll_status_t: an enum of the function exit status
 */
dbl_ll_status_t dbl_ll_size(struct dbl_ll_node **ptr, uint32_t *retval)
{
	/* check whether buffer is valid */
	if (!(*ptr))
	{
		printf("Invalid Doubly-Linked List \n");
		*retval = 0;
		return DBL_INVALID_LL;
	}

	/* create counter var and temp ptr to iterate thru dbl_ll */
	uint32_t counter = 0;
	struct dbl_ll_node *temp = NULL;
	temp = *ptr;

	/* until a null node is found, continue down dbl_ll and inc counter */
	while (temp != NULL)
	{
		temp = temp->next;
		counter++;
	}
	(*retval) = counter;
	return DBL_SUCCESS;
}

