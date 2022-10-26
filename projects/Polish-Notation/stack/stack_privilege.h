#ifndef _ADT_PRIVILEGE_
#define _ADT_PRIVILEGE_
#include "../libs/std_types/std_types.h"
#include "Error_States.h"
#include "stack_config.h"

/*
	pre: none
	post: initialize the stack and returns enum(STACK_CREATED)
*/
ErrorStates_t CreateStack(Stack_t *);

/*
	pre: stack initialized and not empty
	post: - removes all the stack elements 
		  - if stack was not empty it returns enum(STACK_CLEARED)
		  - if the stack was emppty it returns enum(STACK_EMPTY)
*/
ErrorStates_t ClearStack(Stack_t *);

/*
	pre: stack initialized and not empty
	post: - adds a new element onto the top of the stack
		  - if stack is not full it returns enum(PUSHED_SUCCESSFULLY)
		  - if the stack was emppty it returns enum(STACK_FULL)
*/
ErrorStates_t Push(StackEntry, Stack_t *);

/*
	pre: stack initialized and not empty
	post: - removes an element from the top of the stack
		  - if stack was not empty it returns enum(POPPED_SUCCESSFULLY)
		  - if the stack was emppty it returns enum(STACK_EMPTY)
*/
ErrorStates_t Pop(StackEntry *, Stack_t *);

/*
	pre: stack initialized and not empty
	post: - gets the number of elements in the stack
		  - if stack was not empty it returns enum(STACK_NOT_EMPTY)
		  - if the stack was emppty it returns enum(STACK_EMPTY)
*/
ErrorStates_t StackSize(u32_t* , Stack_t);

/*
	pre: stack initialized and not empty
	post: - gets the element in the top of the stack
		  - if stack was not empty it returns enum(TOP_ELEMENT_REVEILED)
		  - if the stack was emppty it returns enum(STACK_EMPTY)
*/
ErrorStates_t StackTop(StackEntry *, Stack_t *);

/*
	pre: stack initialized and not empty
	post: - if stack was not empty it returns enum(STACK_NOT_EMPTY)
		  - if the stack was emppty it returns enum(STACK_EMPTY)
*/
ErrorStates_t StackEmpty(Stack_t);

/*
	pre: stack initialized and not empty
	post: - if stack was not full it returns enum(STACK_NOT_FULL)
		  - if the stack was full it returns enum(STACK_FULL)
*/
ErrorStates_t StackFull(Stack_t);

/*
	pre: stack initialized and not empty
	post: - enables a user to interact with the stack memebers with a function written by him
		  - if stack was not full it returns enum(STACK_NOT_FULL)
		  - if the stack was full it returns enum(STACK_FULL)
*/
ErrorStates_t TraverseStack(Stack_t, void (*) (StackEntry));

#endif