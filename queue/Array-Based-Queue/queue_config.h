#ifndef _ADT_BASED_ARRAY_QUEUE_
#define _ADT_BASED_ARRAY_QUEUE_

/* Specify max number of elements you will enter in your queue */
#define QUEUE_MAX_SIZE	10

/* Specify the type of the queue entries*/
typedef int QueueEntry;

/* Declaration of the queue type */
typedef struct{
	int front;
	int rear;
	int size;
	QueueEntry Items[QUEUE_MAX_SIZE];
}Queue_t;

#endif