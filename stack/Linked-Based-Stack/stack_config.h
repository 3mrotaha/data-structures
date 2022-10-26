#ifndef _ADT_LINKED_STACK_CONFIG_
#define _ADT_LINKED_STACK_CONFIG_

/* type of data stored inside the stack nodes*/
typedef int StackEntry;

/* Elements of the stack are of type node, so we need to declare node type */
typedef struct stacknode{
	StackEntry Item;
	struct stacknode* next;
}StackNode;

/* we declare the stack */
typedef struct{
	StackNode* top;
	int size;
}Stack_t;



#endif