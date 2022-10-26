#ifndef	_DOUBLY_LIST_PRIVATE_
#define _DOUBLY_LIST_PRIVATE_

typedef struct node{
	DListEntry Item;
	struct node* next;
	struct node* previous;
}DListNode;

typedef struct list{
	DListNode* head;
	int headpos;
	int size;
}DList_t;

#endif