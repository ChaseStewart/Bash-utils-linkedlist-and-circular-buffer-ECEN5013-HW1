/*****************************************************
 * Copyright (C) 2017 by Chase E Stewart
 *
 * 
 *
 *
 *
 *****************************************************/
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


/* enumeration of circular buffer status */
typedef enum {
	DBL_SUCCESS      =  0,
	DBL_INVALID_LL   = -1,
	DBL_CANNOT_ALLOC = -2,
	DBL_DOUBLE_FREE  = -3,
	DBL_NOT_FOUND    = -4,
	DBL_OUT_OF_RANGE = -5
} dbl_ll_status_t;

/* 
 * Struct for the linked list
 *
 * uint32_t data: the data held by the circular buffer 
 * struct dbl_ll_node *prev: pointer to the previous node in the linked-list
 * struct dbl_ll_node *next: pointer to the next node in the linked-list
 */
struct dbl_ll_node {
	uint32_t data;
	struct dbl_ll_node *prev;
	struct dbl_ll_node *next;
};

/*
 * @brief destroy the provided linked list completely and free all nodes
 *
 *
 * @param struct dbl_ll_node **ptr: pointer to a pointer to the head dbl_ll node
 *
 * @return dbl_ll_status_t: an enum of the function exit status
 */
dbl_ll_status_t destroy_dbl_ll(struct dbl_ll_node **ptr);

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
dbl_ll_status_t add_dbl_ll_node(struct dbl_ll_node **ptr, uint32_t value, uint32_t idx);

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
dbl_ll_status_t remove_dbl_ll_node(struct dbl_ll_node **ptr, uint32_t *retval, uint32_t idx);

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
dbl_ll_status_t search_dbl_ll(struct dbl_ll_node **ptr, uint32_t *retval, uint32_t value);

/*
 * @brief return the number of connected, allocated nodes in this dbl_ll
 *
 *
 * @param struct dbl_ll_node **ptr: pointer to a pointer to the head dbl_ll node
 *
 * @return dbl_ll_status_t: an enum of the function exit status
 */
dbl_ll_status_t dbl_ll_size(struct dbl_ll_node **ptr, uint32_t *retval);

#endif /* __MY_DBL_LINKLIST_H__ */
