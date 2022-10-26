#include <stdio.h>
#include <stdlib.h>
#include "list_ErrorStates.h"
#include "list_config.h"


CListError_t CreateCList(CList_t* plist){
	if(plist != NULL){
		plist->head = NULL;
		plist->tail = NULL;
		plist->size = 0;
		return LIST_CREATED;
	}
	return NULL_POINTER;
}

CListError_t DestroyCList(CList_t* plist){
	if(plist->head != NULL){
		while(plist->size != 0){
			plist->tail = plist->head->next;
			plist->head->next = plist->tail->next;
			free(plist->tail);
			plist->size--;
		}
		plist->head = NULL;
		plist->tail = plist->head;
		return LIST_DESTROYED;
	}
	else{
		return LIST_EMPTY;
	}
}

CListError_t CListEmpty(CList_t list){
	return list.head == NULL? LIST_EMPTY: LIST_NOT_EMPTY;
}

CListError_t CListFull(CList_t list){
	return LIST_NOT_FULL;
}

CListError_t CListSize(int* psize, CList_t list){
	*psize = list.size;
	return list.head == NULL? LIST_EMPTY: LIST_NOT_EMPTY;
}

CListError_t CListInsert(int pos, CListEntry e, CList_t* plist){
	CListNode* NewNode = (CListNode*) malloc(sizeof(CListNode));
	if(NewNode != NULL){
		NewNode->Item = e;
		if(plist->size == 0){
			plist->head = plist->tail = NewNode;
			NewNode->next = plist->head;
			plist->size++;
			return FIRST_TIME_INSERTION;
		}
		else if(pos == 0){
			plist->tail->next = NewNode;
			NewNode->next = plist->head;
			plist->head = NewNode;
		}
		else if(pos == plist->size){
			plist->tail->next = NewNode;
			plist->tail = plist->tail->next;
			plist->tail->next = plist->head;
		}
		else{
			while(pos > 1){
				plist->head = plist->head->next;
				pos--;
			}
			NewNode->next = plist->head->next;
			plist->head->next = NewNode;
			plist->head = plist->tail->next;
		}
		plist->size++;
		return INSERTION_SUCCESS;
	}
	else{
		return NULL_POINTER;
	}
}

CListError_t CListDelete(int pos, CListEntry* pe, CList_t* plist){
	if(plist->head != NULL){
		for(int i = 0; i < pos - 1; i++){
			plist->head = plist->head->next;
		}
		
		if(pos == 0){
			*pe = plist->head->Item;
			if(plist->size > 1){
				plist->tail->next = plist->head->next;
				free(plist->head);
				plist->head = plist->tail->next;
			}else{
				plist->tail = NULL;
				free(plist->head);
				plist->head = plist->tail;
			}
		}
		else{
			*pe = plist->head->next->Item;
			if(pos == plist->size - 1){
				plist->head->next = plist->tail->next;
				free(plist->tail);
				plist->tail = plist->head;
			}
			else{
				CListNode* temp;
				temp = plist->head->next;
				plist->head->next = temp->next;
				free(temp);
			}
			plist->head = plist->tail->next;
		}
		plist->size--;
		return DELETION_DONE;
	}
	else{
		return LIST_EMPTY;
	}
}

CListError_t CListRetrieve(int pos, CListEntry* pe, CList_t list){
	if(list.head != NULL){
		for(int i = 0; i < pos; i++){
			list.head = list.head->next;
		}
		*pe = list.head->Item;
		return LIST_RETRIEVED;
	}
	else{
		return LIST_EMPTY;
	}
}

CListError_t CListReplace(int pos, CListEntry e, CList_t* plist){
	if(plist->head != NULL){
		for(int i = 0; i < pos; i++){
			plist->head = plist->head->next;
		}
		plist->head->Item = e;
		plist->head = plist->tail->next;
		return LIST_REPLACED;
	}
	else{
		return LIST_EMPTY;
	}
}

CListError_t CListTraverse(CList_t list, void (*pf) (CListEntry)){
	if(list.head != NULL){
		while(list.head != list.tail){
			pf(list.head->Item);
			list.head = list.head->next;
		}
		pf(list.tail->Item);
		return LIST_TRAVERSED;
	}
	else{
		return LIST_EMPTY;
	}
}