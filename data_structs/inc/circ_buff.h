/*****************************************************
 * Copyright (C) 2017 by Chase E Stewart
 *
 * 
 *
 *
 *
 *****************************************************/
/*
 * @file circ_buff.h
 * @brief A simple library for a circular buffer
 * 
 * This circular buffer holds structs 
 *
 * @author Chase E Stewart
 * @date Sept 4 2017
 * @version 1.0
 *
 */
#ifndef __MY_CIRC_BUFF_H__
#define __MY_CIRC_BUFF_H__

#include <stdbool.h>
#include <stdint.h>

/* enumeration of circular buffer status */
typedef enum {
	C_SUCCESS        =  0,
	C_INVALID_BUFFER = -1,
	C_CANNOT_ALLOC   = -2,
	C_DOUBLE_FREE    = -3,
	C_BUFFER_FULL    = -4,
	C_BUFFER_EMPTY   = -5
} circ_buff_status_t;

/* 
 * Struct for the circular buffer
 *
 * uint32_t *head: a pointer to the 'head' (latest element) of the buffer
 * uint32_t *tail: a pointer to the 'tail' (earliest element) of the buffer
 * uint32_t *base_p: a pointer to the start of the buffer, used for wrapping around the buffer
 * uint32_t size: the total size of the circular buffer (immutable upon creation)
 * uint32_t num_items: the current number of items in the buffer (mutable)
 */
struct c_node {
	uint32_t *head;
	uint32_t *tail;
	uint32_t *base_p;
	uint32_t size;
	uint32_t num_items;
}; 


/*
 * @brief create a circular buffer
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 * @param size- size of the circular buffer
 *
 * @return circ_buff_status - enum of status
 */
circ_buff_status_t allocate_c_buff(struct c_node **ptr, uint32_t size);

/**
 * @brief destroy an already-allocated circ-buffer
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 *
 * @return circ_buff_status - enum of status
 */
circ_buff_status_t destroy_c_buff(struct c_node **ptr);

/**
 * @brief return boolean of whether buffer is full or not
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 *
 * @return bool true if buffer is full else false
 */
bool is_c_buff_full(struct c_node **ptr);

/**
 * @brief return boolean of whether buffer is empty or not
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 *
 * @return bool true if buffer is empty else false
 */
bool is_c_buff_empty(struct c_node **ptr);

/**
 * @brief add a value into the circular buffer if it's not full
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 * @param data- the uint32 value we want to put into the circ buffer
 *
 * @return circ_buff_status - enum of status
 */
circ_buff_status_t  add_c_buff_data(struct c_node **ptr, uint32_t data);

/**
 * @brief remove a value from the circular buffer if it's not empty
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 *
 * @return circ_buff_status - enum of status
 */
circ_buff_status_t remove_c_buff_data(struct c_node **ptr);

/**
 * @brief print current status of circular buffer to stdout
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 *
 * @return none
 */
void dump_c_buff(struct c_node **ptr);

/**
 * @brief return current size of circular buffer
 *
 *
 * @param struct c_node **ptr: pointer to a pointer to a c_node struct
 *
 * @return uint32_t - size of circular buffer
 */
uint32_t c_buff_size(struct c_node **ptr);


#endif /* __MY_CIRC_BUFF_H__ */
