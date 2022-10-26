#include <stdio.h>
#include "stack_ErrorStates.h"
#include "stack_config.h"
#include "stack_privilege.h"

void display(StackEntry e){
	printf("%d, ", e);
}

int main(void){
	StackEntry e;
	Stack_t s;
	CreateStack(&s);
	
	int operation;
	while(1){
		printf("0/1/2 pop/push/traverse : ");
		scanf("%d", &operation);
		if(operation == 0){
			Pop(&e, &s);
			printf("poped %d\n", e);
		}
		else if(operation == 1){
			printf("Enter An Entry : ");
			scanf("%d", &e);
			Push(e, &s);
			printf("pushed %d\n", e);
		}
		else{
			TraverseStack(s, &display);
			printf("\n");
		}
	}
	return 0;
}