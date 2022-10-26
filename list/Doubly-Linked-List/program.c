#include <stdio.h>
#include <stdlib.h>
#include "list_ErrorStates.h"
#include "list_config.h"
#include "list_private.h"


DListError_t CreateDList(DList_t* list){
	if(list != NULL){
		list->head = NULL;
		list->headpos = -1;
		list->size = 0;
		return LIST_CREATED;
	}
	else{
		return NULL_POINTER;
	}
}

DListError_t DestroyDList(DList_t* list){
	if(list->head != NULL){
		DListNode* forward, *backward;
		forward = list->head->next; 
		backward = list->head->previous;
		list->head->next = list->head->previous = NULL;
		free(list->head);
		list->head = NULL;
		DListNode* temp;
		while(forward != NULL|| backward != NULL){			
			if(forward != NULL){
				temp = forward->next;
				free(forward);
				forward = temp;
			}
			if(backward != NULL){
				temp = backward->previous;
				free(backward);
				backward = temp;
			}
		}
		list->headpos = -1;
		list->size = 0;
		return LIST_DESTROYED;
	}
	else{
		return LIST_EMPTY;
	}
}

DListError_t DListEmpty(DList_t list){
	return list.head == NULL? LIST_EMPTY:LIST_NOT_EMPTY;
}

DListError_t DListFull(DList_t list){
	return LIST_NOT_FULL;
}

DListError_t DListSize(int* Size, DList_t list){
	if(list.head != NULL){
		*Size = list.size;
		return LIST_NOT_EMPTY;
	}
	else{
		*Size = 0;
		return LIST_EMPTY;
	}
}

DListError_t DListHead(int* pos, DList_t list){
	if(list.head != NULL){
		*pos = list.headpos;
		return HEAD_REVIELED;
	}
	else{
		return LIST_EMPTY;
	}
}

DListError_t DListInsert(int pos, DListEntry e, DList_t* list){
	DListNode* NewNode = (DListNode*) malloc(sizeof(DListNode));
	NewNode->Item = e;
	if(list->head != NULL){
		while(list->headpos != pos && list->headpos != list->size - 1){
			if(list->headpos < pos){
				list->head = list->head->next;
				list->headpos++;
			}
			else if(list->headpos > pos){
				list->head = list->head->previous;
				list->headpos--;
			}
		}
		if(pos == list->size){
			list->head->next = NewNode;
			NewNode->previous = list->head;
			NewNode->next = NULL;
		}
		else{
			NewNode->next = list->head;
			NewNode->previous = list->head->previous;
			if(pos != 0)
				list->head->previous->next = NewNode;
			list->head->previous = NewNode;
			list->headpos++;
		}
		list->size++;
		return INSERTION_SUCCESS;
	}
		
	list->head = NewNode;
	list->head->next = list->head->previous = NULL;
	list->size++;
	list->headpos++;
	return FIRST_TIME_INSERTION;
}

DListError_t DListDelete(int pos, DListEntry* e, DList_t* list){
	if(list->head != NULL){
		DListNode* temp;
		while(list->headpos != pos){
			if(list->headpos < pos){
				list->head = list->head->next;
				list->headpos++;
			}
			else if(list->headpos > pos){
				list->head = list->head->previous;
				list->headpos--;
			}
		}
		if(pos == 0){
			temp = list->head->next;
			free(list->head);
			temp->previous = NULL;
			list->head = temp;			
		}
		else if(pos == list->size - 1){
			temp = list->head->previous;
			free(list->head);
			temp->next = NULL;
			list->head = temp;
			list->headpos--;
		}
		else{
			temp = list->head->previous;
			temp->next = list->head->next;
			list->head->next->previous = temp;
			free(list->head);
			list->head = temp;
			list->headpos--;
		}
		list->size--;
		return DELETION_DONE;
	}
	else{
		return LIST_EMPTY;
	}
}

DListError_t DListRetrieve(int pos, DListEntry* e, DList_t list){
	if(list.head != NULL){
		if(list.headpos == pos){
			*e = list.head->Item;
		}
		else if(list.headpos <= pos - 1){ // add it forward
			for(; list.headpos != pos - 1; list.head = list.head->next)
				list.headpos++;
			
			*e = list.head->next->Item;
		}
		else if(list.headpos >= pos + 1){ // add it backward
			for(; list.headpos != pos + 1; list.head = list.head->previous)
				list.headpos--;
			*e = list.head->previous->Item;
		}
		return LIST_RETRIEVED;
	}
	else{
		return LIST_EMPTY;
	}
}

DListError_t DListReplace(int pos, DListEntry e, DList_t* list){
	if(list->head != NULL){
		if(list->headpos == pos){
			 list->head->Item = e;
		}
		else if(list->headpos <= pos - 1){ // add it forward
			for(; list->headpos != pos - 1; list->head = list->head->next)
				list->headpos++;
			
			list->head->next->Item = e;
		}
		else if(list->headpos >= pos + 1){ // add it backward
			for(; list->headpos != pos + 1; list->head = list->head->previous)
				list->headpos--;
			list->head->previous->Item = e;
		}
		return LIST_REPLACED;
	}
	else{
		return LIST_EMPTY;
	}
}

DListError_t DListTraverse(DList_t list, void (*pf) (DListEntry)){
	if(list.head != NULL){
		for(; list.headpos != 0; list.head = list.head->previous)
			list.headpos--;
		for(; list.headpos < list.size; list.head = list.head->next){
			pf(list.head->Item);
			list.headpos++;
		}
		return LIST_TRAVERSED;
	}
	else{
		return LIST_EMPTY;
	}
}