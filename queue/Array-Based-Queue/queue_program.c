#include <stdio.h>
#include "Error_States.h"
#include "queue_config.h"


ErrorStates_t	CreateQueue(Queue_t* pQueue){
	pQueue->front = 0;
	pQueue->rear = -1;
	pQueue->size = 0;
	return QUEUE_CREATED;
}

ErrorStates_t 	ClearQueue(Queue_t* pQueue){
	if(pQueue->size != 0){
		pQueue->front = 0;
		pQueue->rear = -1;
		pQueue->size = 0;
		return QUEUE_CLEARED;
	}else{
		return QUEUE_EMPTY;
	}
}

ErrorStates_t	Push(QueueEntry Entry, Queue_t* pQueue){
	if(pQueue->size != QUEUE_MAX_SIZE){
		pQueue->rear = (pQueue->rear + 1) % QUEUE_MAX_SIZE;
		pQueue->Items[pQueue->rear] = Entry;
		pQueue->size++;
		return QUEUE_PUSHED_SUCCESSFULLY;
	}else{
		return QUEUE_FULL;
	}

}

ErrorStates_t	Pop(QueueEntry* Entry, Queue_t* pQueue){
	if(pQueue->size != 0){
		*Entry = pQueue->Items[pQueue->front];
		pQueue->front = (pQueue->front + 1) % QUEUE_MAX_SIZE;
		pQueue->size--;
		return QUEUE_POPPED_SUCCESSFULLY;
	}else{
		return QUEUE_EMPTY;
	}
}

ErrorStates_t	QueueSize(int* Size,Queue_t Queue){
	*Size = Queue.size;
	if(Queue.size == 0){
		return QUEUE_EMPTY;
	}
	else{
		return QUEUE_NOT_EMPTY;
	}
}

ErrorStates_t	QueueFront(QueueEntry* Front, Queue_t Queue){
	if(Queue.size != 0){
		*Front = Queue.front;
		return QUEUE_FRONT_REVEILED;
	}else{
		return QUEUE_EMPTY;
	}
}

ErrorStates_t	QueueRear(QueueEntry* Rear, Queue_t Queue){
	if(Queue.size != 0){
		*Rear = Queue.rear;
		return QUEUE_REAR_REVEILED;
	}else{
		return QUEUE_EMPTY;
	}
}

ErrorStates_t	QueueEmpty(Queue_t Queue){
	if(Queue.size == 0){
		return QUEUE_EMPTY;
	}
	else{
		return QUEUE_NOT_EMPTY;
	}
}

ErrorStates_t	QueueFull(Queue_t Queue){
	if(Queue.size == QUEUE_MAX_SIZE){
		return QUEUE_FULL;
	}
	else{
		return QUEUE_NOT_FULL;
	}
}

ErrorStates_t	QueueTraverse(Queue_t Queue, void (*pf) (QueueEntry)){
	if(Queue.size != 0){
		for(int pos = Queue.front, s = 1; s <= Queue.size; s++){
			pf(Queue.Items[pos]);
			pos = (pos + 1) % QUEUE_MAX_SIZE;
		}
		return QUEUE_TRAVERSED;
	}else{
		return QUEUE_EMPTY;
	}
}