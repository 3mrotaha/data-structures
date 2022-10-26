#include <stdio.h>
#include <stdlib.h>
#include "../libs/std_types/std_types.h"
#include "../src/config.h"
#include "Error_States.h"
#include "stack_config.h"

/* pre: none
 * post: initialize the stack top to null, size to 0
 */
ErrorStates_t CreateStack(Stack_t * pstack){
	pstack->top = NULL;
	pstack->size = 0;
	return STACK_EMPTY;
}

ErrorStates_t ClearStack(Stack_t *pstack){
	if(pstack->size != 0){
		StackNode* node;
		while(pstack->top){
			node = pstack->top->next;
			free(pstack->top);
			pstack->top = node;
		}
		pstack->size = 0;
		return STACK_CLEARED;
	}
	else{
		return STACK_EMPTY;
	}
}

ErrorStates_t Push(StackEntry Entry, Stack_t * pstack){
	StackNode* NewNode = (StackNode*) calloc(1, sizeof(StackNode));
	NewNode->Item = Entry;
	NewNode->next = pstack->top;
	pstack->top = NewNode;
	pstack->size++;
	return PUSHED_SUCCESSFULLY;
}

ErrorStates_t Pop(StackEntry *Entry, Stack_t *pstack){
	StackNode* node = pstack->top;
	
	if(pstack->top != NULL){
		pstack->top = pstack->top->next;
		*Entry = node->Item;
		free(node);
		node = NULL;
		pstack->size--;
		return POPPED_SUCCESSFULLY;
	}
	else{
		return STACK_EMPTY;
	}
}

ErrorStates_t StackSize(u32_t* Size, Stack_t stack){
	if(stack.top == NULL){
		*Size = 0;
		return STACK_EMPTY;
	}
	else{
		*Size = stack.size;
		return STACK_NOT_EMPTY;
	}
}

ErrorStates_t StackTop(StackEntry * Entry, Stack_t * pstack){
	if(pstack->top != NULL){
		*Entry = pstack->top->Item;
		return TOP_ELEMENT_REVEILED;
	}
	else{
		return STACK_EMPTY;
	}
}

ErrorStates_t StackEmpty(Stack_t stack){
	if(stack.size == 0){
		return STACK_EMPTY;
	}
	else{
		return STACK_NOT_EMPTY;
	}
}

ErrorStates_t StackFull(Stack_t stack){
	return STACK_NOT_FULL;
}

ErrorStates_t TraverseStack(Stack_t stack, void (*pf) (StackEntry)){
	if(stack.top != NULL){
		for(StackNode* node = stack.top; node; node = node->next){
			(*pf)(node->Item);
		}
		return TOP_ELEMENT_REVEILED;
	}
	else{
		return STACK_EMPTY;
	}
}