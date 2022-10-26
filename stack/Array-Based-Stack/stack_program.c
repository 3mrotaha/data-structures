#include <stdio.h>
#include "stack_ErrorStates.h"
#include "stack_config.h"

ErrorStates_t CreateStack(Stack_t * pstack){
	if(pstack != NULL){
		pstack->top = 0;
		return STACK_CREATED;
	}
	else{
		return CREATION_ERROR;
	}
}

ErrorStates_t ClearStack(Stack_t *pstack){
	if(pstack->top != 0){
		pstack->top = 0;
		return STACK_CLEARED;
	}
	else{
		return STACK_EMPTY;
	}
}

ErrorStates_t Push(StackEntry entry, Stack_t *pstack){
	if(pstack->top <= STACK_MAX_SIZE){
		pstack->Items[pstack->top++] = entry;
		return PUSHED_SUCCESSFULLY;
	}
	else{
		return STACK_FULL;
	}
}

ErrorStates_t Pop(StackEntry * pentry, Stack_t *pstack){
	if(pstack->top != 0){
		--pstack->top;
		*pentry = pstack->Items[pstack->top];
		return POPPED_SUCCESSFULLY;
	}
	else{
		return STACK_EMPTY;
	}
}

ErrorStates_t StackSize(int* Size, Stack_t stack){
	if(stack.top == 0){
		*Size = 0;
		return STACK_EMPTY;
	}
	else{
		*Size = stack.top;
		return STACK_NOT_EMPTY;
	}
}

ErrorStates_t StackTop(StackEntry* pentry, Stack_t* pstack){
	if(pstack->top != 0){
		*pentry = pstack->Items[pstack->top - 1];
		return TOP_ELEMENT_REVEILED;
	}
	else{
		return STACK_EMPTY;
	}
}

ErrorStates_t StackEmpty(Stack_t stack){
	if(stack.top == 0)
		return STACK_EMPTY;
	else
		return STACK_NOT_EMPTY;
}

ErrorStates_t StackFull(Stack_t stack){
	if(stack.top > STACK_MAX_SIZE)
		return STACK_FULL;
	else
		return STACK_NOT_FULL;
}

ErrorStates_t TraverseStack(Stack_t stack, void (*pf) (StackEntry)){
	while(stack.top > 0){
		(*pf)(stack.Items[--stack.top]);
	}
}