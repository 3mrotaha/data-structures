#ifndef _ADT_LINKED_STACK_CONFIG_
#define _ADT_LINKED_STACK_CONFIG_
#include "../libs/std_types/std_types.h"
#include "../src/private.h"
/* type of data stored inside the stack nodes*/
typedef Element_t StackEntry;

/* Elements of the stack are of type node, so we need to declare node type */
typedef struct stacknode{
	StackEntry Item;
	struct stacknode* next;
}StackNode;

/* we declare the stack */
typedef struct{
	StackNode* top;
	u32_t size;
}Stack_t;



#endif