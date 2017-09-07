/*****************************************************
 * Copyright (C) 2017 by Chase E Stewart
 *
 * 

 
*
******************************************************/
/**
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

typedef enum {
	C_SUCCESS        =  0,
	C_INVALID_BUFFER = -1,
	C_CANNOT_ALLOC   = -2,
	C_DOUBLE_FREE    = -3,
	C_BUFFER_FULL    = -4,
	C_BUFFER_EMPTY   = -5
} circ_buff_status_t;

struct c_node {
	uint32_t *head;
	uint32_t *tail;
	uint32_t *base_p;
	uint32_t size;
	uint32_t num_items;
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
circ_buff_status_t allocate_c_buff(struct c_node **ptr, uint32_t size);

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
circ_buff_status_t destroy_c_buff(struct c_node **ptr);

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
bool is_c_buff_full(struct c_node **ptr);


/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
bool is_c_buff_empty(struct c_node **ptr);



/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
circ_buff_status_t  add_c_buff_data(struct c_node **ptr, uint32_t data);

/**
 * @brief
 *
 *
 * @param
 * @param
 *
 * @return
 */
circ_buff_status_t remove_c_buff_data(struct c_node **ptr);

/**
 * @brief print current status of circular buffer to stdout
 *
 *
 * @param *buff - pointer to buffer
 *
 * @return
 */
void dump_c_buff(struct c_node **ptr);

/**
 * @brief return current size of circular buffer
 *
 *
 * @param *buff - pointer to buffer
 *
 * @return
 */
uint32_t c_buff_size(struct c_node **ptr);


#endif /* __MY_CIRC_BUFF_H__ */
