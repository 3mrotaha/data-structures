#include <stdio.h>
#include "Error_States.h"
#include "queue_config.h"
#include "queue_privilege.h"

void display(QueueEntry e){
	printf("%d, ", e);
}
int main(void){
	QueueEntry e;
	Queue_t q;
	CreateQueue(&q);
	int op;
	while(1){
		printf("0/1/2 : ");
		scanf("%d", &op);
		
		if(op == 0){
			if(Pop(&e, &q) != QUEUE_EMPTY){
				printf("Poped : %d\n", e);
			}
			else{
				printf("queue is empty!\n");
			}
		}
		else if(op == 1){
			printf("Entry : ");
			scanf("%d", &e);
			if(Push(e, &q) != QUEUE_FULL){
				printf("Pushed : %d\n", e);
			}
			else{
				printf("queue is full!\n");
			}
		}
		else if(op == 2){
			if(QueueTraverse(q, &display) != QUEUE_EMPTY)
				printf("\n");
			else{
				printf("queue is empty!\n");
			}
		}
		printf("\n");
	}
	return 0;
}