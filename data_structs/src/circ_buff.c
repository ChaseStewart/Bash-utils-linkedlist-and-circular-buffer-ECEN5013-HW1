/*****************************************************
 * Redistribution, modification or use of this software in source or binary forms 
 * is permitted as long as the files maintain this copyright. Users are permitted to 
 * modify this and use it to learn about the field of embedded software but don't copy 
 * my (Chase E Stewart's) work for class, I worked really hard on this. Alex Fosdick and 
 * the University of Colorado and Chase E Stewart are not liable for any misuse of this material. 
 * License copyright (C) 2017 originally from Alex Fosdick, code by Chase E Stewart.
 *****************************************************/
/**
 * @file circ_buff.c
 * @brief A simple library for a circular buffer
 * 
 * This circular buffer holds a buffer and helpful counts/pointers in a struct
 * The file also contains methods to create, destroy, add, remove, dump, and count the struct.
 *
 * @author Chase E Stewart
 * @date Sept 4 2017
 * @version 1.0
 *
 */
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "../inc/circ_buff.h"

/*
 * @brief create a circular buffer
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 * @param size- size of the circular buffer
 *
 * @return circ_buff_status - enum of status
 */
circ_buff_status_t allocate_c_buff(struct c_node **ptr, uint32_t size){

	/* allocate struct pointer, else error */
	(*ptr) = (struct c_node *)malloc(sizeof(struct c_node));

	/* check whether struct malloc was successful */
	if (!(*ptr))
	{
		printf("ERROR: Cannot allocate array\n");
		return C_CANNOT_ALLOC;
	}

	/* allocate buffer, else error */
	uint32_t *buffer = NULL;
	buffer = (uint32_t *)malloc(sizeof(uint32_t) * size);
	
	/* check whether buffer malloc was successful */
	if (!buffer)
	{
		printf("ERROR: Cannot allocate buffer\n");
		return C_CANNOT_ALLOC;
	}

	/* set struct members to default values */
	(*ptr)->base_p    = buffer;
	(*ptr)->head      = buffer;
	(*ptr)->tail      = buffer;
	(*ptr)->size      = size;
	(*ptr)->num_items = 0;
	
	printf("Buffer of size %d allocated\n", size);
	return C_SUCCESS;
}

/**
 * @brief destroy an already-allocated circ-buffer
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 *
 * @return circ_buff_status - enum of status
 */
circ_buff_status_t destroy_c_buff(struct c_node **ptr)
{
	/* check whether buffer is valid */
	if (!(*ptr))
	{
		return C_DOUBLE_FREE;
	}
	
	/* first free the buffer itself, then the struct */
	free((*ptr)->base_p);
	free(*ptr);
	(*ptr) = NULL;
	return C_SUCCESS;
}

/**
 * @brief return boolean of whether buffer is full or not
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 *
 * @return bool true if buffer is full else false
 */
bool is_c_buff_full(struct c_node **ptr)
{
	/* check whether buffer is valid */
	if (!(*ptr))
	{
		printf("Invalid Buffer\n");
		return C_INVALID_BUFFER;
	}
	
	/* return true if num of items in the buffer == its size, else false */
	if ( (*ptr)->num_items == (*ptr)->size)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * @brief return boolean of whether buffer is empty or not
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 *
 * @return bool true if buffer is empty else false
 */
bool is_c_buff_empty(struct c_node **ptr)
{
	/* check whether buffer is valid */
	if (!(*ptr))
	{
		printf("Invalid Buffer\n");
		return C_INVALID_BUFFER;
	}

	/* return true if there are 0 items in the buffer, else false */
	if ( (*ptr)->num_items == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

/**
 * @brief add a value into the circular buffer if it's not full
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 * @param data- the uint32 value we want to put into the circ buffer
 *
 * @return circ_buff_status - enum of status
 */
circ_buff_status_t add_c_buff_data(struct c_node **ptr, uint32_t data)
{
	/* check whether buffer is valid */
	if ( !(*ptr))
	{
		return C_INVALID_BUFFER;
	}

	/* cannot add to full buffer, return error */
	else if (is_c_buff_full(ptr))
	{
		return C_BUFFER_FULL;
	}

	/* place data into deref of head ptr */
	*((*ptr)->head) = data;

	/* increment head ptr: if end of list reached, wrap around to base_p */
	(*ptr)->head++;
	if ((*ptr)->head == ((*ptr)->base_p + (sizeof(uint32_t) * (*ptr)->size )))
	{
		(*ptr)->head = (*ptr)->base_p;
	}

	/* increment count of items in the circular_buffer */
	(*ptr)->num_items++;
	return C_SUCCESS;
}

/**
 * @brief remove a value from the circular buffer if it's not empty
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 *
 * @return circ_buff_status - enum of status
 */
circ_buff_status_t remove_c_buff_data(struct c_node **ptr)
{
	/* check whether buffer is valid */
	if (!(*ptr))
	{
		return C_INVALID_BUFFER;
	}
	
	/* cannot remove from empty buffer, return error */
	else if (is_c_buff_empty(ptr))
	{
		return C_BUFFER_EMPTY;
	}

	/* increment tail ptr: if end of list reached, wrap around to base_p */
	(*ptr)->tail++;
	if ((*ptr)->tail == ((*ptr)->base_p + (sizeof(uint32_t)* (*ptr)->size )))
	{
		(*ptr)->tail = (*ptr)->base_p;
	}
	
	/* decrement count of items in the circular_buffer */
	(*ptr)->num_items--;
	return C_SUCCESS;
}

/**
 * @brief print current status of circular buffer to stdout
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 *
 * @return none
 */
void dump_c_buff(struct c_node **ptr)
{

	/* check whether buffer is valid */
	if (!(*ptr))
	{
		printf("ERROR: Invalid Buffer\n");
		return;
	}
	
	/* Check whether buffer is empty, if so print a blank*/
	else if (is_c_buff_empty(ptr))
	{
		printf("[]\n");
		return;
	}
	
	/* create temporary uint32_t ptr to iterate thru buffer */
	uint32_t *temp_ptr = NULL;
	temp_ptr = (*ptr)->tail;

	/* print instructions on interpreting data*/
	printf("\n*** Dump Circ Buffer ***\n");
	printf("note: '^'=head '*'=tail '|'= base_pointer \n");
	printf("\n[ ");

	/* walk thru buffer from head to tail, print items */
	for (uint32_t idx=1; idx<((*ptr)->num_items); idx++)
	{
		/* print "^" at head pointer */
		if (temp_ptr == (*ptr)->head)
		{
			printf("^");
		}
		
		/* print "|" at start of buffer */
		if (temp_ptr == (*ptr)->base_p)
		{
			printf("|");
		}
		/* print "*" at tail pointer */
		if (temp_ptr == (*ptr)->tail)
		{
			printf("*");
		}
		
		/* print item in buffer as list */
		printf("%d, ", *temp_ptr);
		
		/* increment temp_ptr, and wrap if end of c_buffer is reached */
		temp_ptr++;
		if (temp_ptr == ((*ptr)->base_p + (sizeof(uint32_t)* (*ptr)->size )))
		{
			temp_ptr = (*ptr)->base_p;
		}
	}

	/* check whether head pointer is the end of the list (usual case) */
	if (temp_ptr+1  == (*ptr)->head)
	{
		printf("^");
	}

	/* end the list with last item */
	printf("%d ]\n", *temp_ptr);
	return;
}

/**
 * @brief return current size of circular buffer
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 *
 * @return circ_buff_status - enum of status
 */
uint32_t c_buff_size(struct c_node **ptr)
{
	/* check whether buffer is valid */
	if (!(*ptr))
	{
		return C_INVALID_BUFFER;
	}

	/* return num of items in circuler buffer */
	return (*ptr)->num_items;
}

