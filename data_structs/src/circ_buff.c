/*****************************************************
 * Copyright (C) 2017 by Chase E Stewart
 *
 * 
 *
 *
 *
******************************************************/
/**
 * @file circ_buff.c
 * @brief A simple library for a circular buffer
 * 
 * This circular buffer holds structs 
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

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
circ_buff_status_t allocate_c_buff(struct c_node *ptr, uint32_t size){

	/* allocate struct pointer, else error */
	ptr = (struct c_node *)malloc(sizeof(struct c_node));
	if (!ptr)
	{
		printf("ERROR: Cannot allocate array\n");
		return C_CANNOT_ALLOC;
	}

	/* allocate buffer, else error */
	uint32_t *buffer = NULL;
	buffer = (uint32_t *)malloc(sizeof(uint32_t) * size);
	if (!buffer)
	{
		printf("ERROR: Cannot allocate buffer\n");
		return C_CANNOT_ALLOC;
	}

	/* set struct members to default values */
	ptr->base_p    = buffer;
	ptr->head      = buffer;
	ptr->tail      = buffer;
	ptr->size      = size;
	ptr->num_items = 0;
	
	printf("Buffer of size %d allocated\n", size);
	return C_SUCCESS;
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
circ_buff_status_t destroy_c_buff(struct c_node *ptr)
{
	if (!ptr)
	{
		printf("ERROR: Cannot destroy array\n");
		return C_DOUBLE_FREE;
	}
	else
	{
		free(ptr->base_p);
		free(ptr->head);
		free(ptr->tail);
		free(ptr);
		printf("Buffer Deleted\n");
		return C_SUCCESS;
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
bool is_c_buff_full(struct c_node *ptr)
{
	if (!ptr)
	{
		printf("Invalid Buffer\n");
		return C_INVALID_BUFFER;
	}
	else
	{
		if ( ptr->num_items == ptr->size)
		{
			printf("Buffer is full\n");
			return true;
		}
		else
		{
			printf("Buffer num_items is %d\n", ptr->num_items);
			return false;
		}
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
bool is_c_buff_empty(struct c_node *ptr)
{
	if (!ptr)
	{
		printf("Invalid Buffer\n");
		return C_INVALID_BUFFER;
	}
	else
	{
		if ( ptr->num_items == 0)
		{
			printf("Buffer is empty\n");
			return true;
		}
		else
		{
			printf("Buffer num_items is %d\n", ptr->num_items);
			return false;
		}
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
circ_buff_status_t add_c_buff_data(struct c_node *ptr, uint32_t data)
{
	if (!ptr)
	{
		return C_INVALID_BUFFER;
	}
	else if (ptr->size == ptr->num_items)
	{
		return C_BUFFER_FULL;
	}

	*ptr->head = data;
	ptr->head += sizeof(uint32_t);
	ptr->num_items ++;

	return C_SUCCESS;
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
circ_buff_status_t remove_c_buff_node(struct c_node *ptr)
{
	if (!ptr)
	{
		return C_INVALID_BUFFER;
	}
	else if (ptr->num_items == 0)
	{
		return C_BUFFER_EMPTY;
	}

	return C_SUCCESS;
}

/**
 * @brief print current status of circular buffer to stdout
 *
 *
 * @param *buff - pointer to buffer
 *
 * @return
 */
void dump_c_buff(struct c_node *ptr)
{

	if (!ptr)
	{
		printf("ERROR: Invalid Buffer\n");
		return;
	}
	else if (ptr->num_items == 0)
	{
		printf("[]");
		return;
	}
	
	uint32_t alloc_size = 100 + ( ptr->num_items*10);
	char print_str[alloc_size];

	sprintf(print_str, "[ %d", ptr->base_p[0]);
	
	for (uint32_t idx=1; idx<ptr->num_items; idx++)
	{
		char snippet[100];
		sprintf(snippet, ", %d", ptr->base_p[idx]);
		strcpy(print_str, snippet);
	}
	printf("%s", print_str);
	return;
}

/**
 * @brief return current size of circular buffer
 *
 *
 * @param *buff - pointer to buffer
 *
 * @return
 */
uint32_t c_buff_size(struct c_node *ptr)
{
	if (!ptr)
	{
		return C_INVALID_BUFFER;
	}
	return ptr->size;
}


