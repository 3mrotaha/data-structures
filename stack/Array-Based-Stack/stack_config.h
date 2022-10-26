#ifndef _BASED_ARRAY_STACK_ADT_
#define _BASED_ARRAY_STACK_ADT_

/* Specify the size of your stack */
#define STACK_MAX_SIZE	100
/* Specify the type of the data contained in your stack */ 
typedef int StackEntry;

/* stack declaration */
typedef struct{
	int top;
	StackEntry Items[STACK_MAX_SIZE];
}Stack_t;

#endif 