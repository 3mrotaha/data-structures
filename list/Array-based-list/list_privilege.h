#ifndef	_ADT_ARRAY_LIST_PRIVILEGE_
#define _ADT_ARRAY_LIST_PRIVILEGE_

/*
	pre: none
	post: Initialize the list and returns enum(LIST_CREATED)
	complexity: O(1)
*/
ErrorStates_t CreateList(List_t*);

/*
	pre: list is initialized and not empty
	post: - deletes the whole list elements
	      - if the list is not empty, it returns (LIST_DESTROYED)
		  - if the list is empty, it returns (LIST_EMPTY)
	complexity: O(1)
*/
ErrorStates_t DestroyList(List_t*);

/*
	pre: list is initialized
	post: - checks if the list is empty or not
	      - if the list is not empty, it returns (LIST_NOT_EMPTY)
		  - if the list is empty, it returns (LIST_EMPTY)
	complexity: O(1)
*/
ErrorStates_t ListEmpty(List_t);

/*
	pre: list is initialized
	post: - checks if the list is full or not
	      - if the list is not full, it returns (LIST_NOT_FULL)
		  - if the list is full, it returns (LIST_FULL)
	complexity: O(1)
*/
ErrorStates_t ListFull(List_t);

/*
	pre: list is initialized
	post: - gets the current size of the list
	      - if the list is not empty, it returns (LIST_NOT_EMPTY)
		  - if the list is empty, it returns (LIST_EMPTY)
	complexity: O(1)
*/
ErrorStates_t ListSize(int*, List_t);

/*
	pre: - list is initialized and not full
	     - 0 <= index <= current size of the list
	post: - inserts an element to a specific index in the list
	      - if the list is not full, it returns (LIST_INSERTION_DONE)
		  - if the list is full, it returns (LIST_FULL)
	complexity: O(N)
*/
ErrorStates_t ListInsert(int, ListEntry, List_t*);

/*
	pre: - list is initialized and not empty
	     - 0 <= index <= (current size of the list) - 1
	post: - deletes an element from a specific index in the list
	      - if the list is not empty, it returns (LIST_DELETION_DONE)
		  - if the list is empty, it returns (LIST_EMPTY)
	complexity: O(N)
*/
ErrorStates_t ListDelete(int, ListEntry*, List_t*);

/*
	pre: - list is initialized and not empty
	     - 0 <= index <= (current size of the list) - 1
	post: - getd an element from a specific index in the list
	      - if the list is not empty, it returns (LIST_RETRIVE_DONE)
		  - if the list is empty, it returns (LIST_EMPTY)
	complexity: O(1)
*/
ErrorStates_t ListRetrieve(int, ListEntry*, List_t);

/*
	pre: - list is initialized and not empty
	     - 0 <= index <= (current size of the list) - 1
	post: - replace an element value in a specific index in the list
	      - if the list is not empty, it returns (LIST_REPLACEMENT_DONE)
		  - if the list is empty, it returns (LIST_EMPTY)
	complexity: O(1)
*/
ErrorStates_t ListReplace(int, ListEntry, List_t*);

/*
	pre: - list is initialized and not empty
	post: - enables the user to visit the list elements
	      - if the list is not empty, it returns (LIST_TRAVERSED)
		  - if the list is empty, it returns (LIST_EMPTY)
	complexity: O(N)
*/
ErrorStates_t ListTraverse(List_t, void (*) (ListEntry));

#endif