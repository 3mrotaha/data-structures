#ifndef	_ADT_ARRAY_BASED_LIST_
#define _ADT_ARRAY_BASED_LIST_

/* Specify the max size of the list */
#define LIST_MAX_SIZE	10

/* Specify the type of the list entries */
typedef int ListEntry;

/* Declare the List type */
typedef struct{
	int size;
	ListEntry Items[LIST_MAX_SIZE];
}List_t;

#endif