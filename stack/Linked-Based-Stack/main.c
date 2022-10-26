#include <stdio.h>
#include "Error_States.h"
#include "stack_config.h"
#include "stack_privilege.h"


void display(StackEntry e){
	printf("%d, ", e);
}

int main(void){
	StackEntry e;
	Stack_t s;
	CreateStack(&s);
	
	int op;
	while(1){
		printf("pop/push/trav/top/size/clear\n");
		printf("0	/1	/2	/3	/4	/5 : ");
		scanf("%d", &op);
		
		if(op == 0){
			if(Pop(&e, &s) != STACK_EMPTY){
				printf("Poped : %d\n", e);
			}
			else{
				printf("stack is empty!\n");
			}
		}
		else if(op == 1){
			printf("Entry : ");
			scanf("%d", &e);
			if(Push(e, &s) != STACK_FULL){
				printf("Pushed : %d\n", e);
			}
			else{
				printf("stack is full!\n");
			}
		}
		else if(op == 2){
			if(TraverseStack(s, &display) != STACK_EMPTY)
				printf("\n");
			else{
				printf("stack is empty!\n");
			}
		}
		else if(op == 3){
			if(StackEmpty(s) != STACK_EMPTY){
				StackTop(&e, &s);
				printf("Top: %d\n", e);
			}
			else{
				printf("Stack empty!\n");
			}

		}
		else if(op == 4){
			int size;
			StackSize(&size, s);
			printf("Size: %d\n", size);
		}
		else if(op == 5){
			if(StackEmpty(s) != STACK_EMPTY){
				ClearStack(&s);
				printf("stack cleared\n");
			}
			else{
				printf("stack is already empty!\n");
			}
		}
	}
	return 0;
}