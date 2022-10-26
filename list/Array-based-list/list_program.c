#include <stdio.h>
#include "Error_States.h"
#include "list_config.h"



ErrorStates_t CreateList(List_t* pList){
	pList->size = 0;
	return LIST_CREATED;
}


ErrorStates_t DestroyList(List_t* pList){
	if(pList->size != 0){
		pList->size = 0;
		return LIST_DESTROYED;		
	}else{
		return LIST_EMPTY;
	}
}


ErrorStates_t ListEmpty(List_t List){
	return List.size == 0? LIST_EMPTY : LIST_NOT_EMPTY;
}


ErrorStates_t ListFull(List_t List){
	return List.size == LIST_MAX_SIZE? LIST_FULL : LIST_NOT_FULL;
}


ErrorStates_t ListSize(int* pSize, List_t List){
	*pSize = List.size;
	return List.size == 0? LIST_EMPTY : LIST_NOT_EMPTY;
}


ErrorStates_t ListInsert(int index, ListEntry Entry, List_t* pList){
	if(pList->size != LIST_MAX_SIZE){
		// shift all the elemnts in indecies >= index on position to right
		for(int i = pList->size - 1; i >= index; i--)
			pList->Items[i + 1] = pList->Items[i];
		
		pList->Items[index] = Entry;
		pList->size++;
		return LIST_INSERTION_DONE;
	}
	else{
		return LIST_FULL;
	}
}


ErrorStates_t ListDelete(int index, ListEntry* pEntry, List_t* pList){
	if(pList->size != 0){
		*pEntry = pList->Items[index];
		// shift elements in indecies >= index one position to the right
		for(int i = index + 1; i <= pList->size - 1; i++)
			pList->Items[i - 1] = pList->Items[i];
		
		pList->size--;
		return LIST_DELETION_DONE;
	}
	else{
		return LIST_EMPTY;
	}
}


ErrorStates_t ListRetrieve(int index, ListEntry* pEntry, List_t List){
	if(List.size != 0){
		*pEntry = List.Items[index];
		return LIST_RETRIVE_DONE;
	}
	else{
		return LIST_EMPTY;
	}
}


ErrorStates_t ListReplace(int index, ListEntry Entry, List_t* pList){
	if(pList->size != 0){
		pList->Items[index] = Entry;
		return LIST_REPLACEMENT_DONE;
	}
	else{
		return LIST_EMPTY;
	}
}


ErrorStates_t ListTraverse(List_t List, void (*pf) (ListEntry)){
	if(List.size != 0){
		for(int i = 0; i < List.size; i++)
			(*pf)(List.Items[i]);
		return LIST_TRAVERSED;
	}
	else{
		return LIST_EMPTY;
	}
}