#ifndef	_CICULAR_LIST_CONFIG_
#define _CICULAR_LIST_CONFIG_

typedef int CListEntry;

typedef struct clistnode{
	CListEntry Item;
	struct clistnode *next;
}CListNode;

typedef struct clist{
	CListNode *head;
	CListNode *tail;
	int size;
}CList_t;

#endif