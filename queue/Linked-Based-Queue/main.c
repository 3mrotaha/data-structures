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
		printf("pop/push/trav/front/rear/size/clear\n");
		printf("0	/1	/2	/3	/4	/5	/6 : ");
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
		else if(op == 3){
			if(QueueEmpty(q) != QUEUE_EMPTY){
				QueueFront(&e, q);
				printf("Front: %d\n", e);
			}
			else{
				printf("Queue empty!\n");
			}

		}
		else if(op == 4){
			if(QueueEmpty(q) != QUEUE_EMPTY){
				QueueRear(&e, q);
				printf("Rear: %d\n", e);
			}
			else{
				printf("Queue empty!\n");
			}
		}
		else if(op == 5){
			int s;
			QueueSize(&s, q);
			printf("Size: %d\n", s);
		}
		else if(op == 6){
			if(QueueEmpty(q) != QUEUE_EMPTY){
				ClearQueue(&q);
				printf("queue cleared\n");
			}
			else{
				printf("queue is already empty!\n");
			}
		}
		printf("\n");
	}
	return 0;
}