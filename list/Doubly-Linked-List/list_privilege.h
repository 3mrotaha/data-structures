#ifndef	_DOUBLY_LIST_PRIVILEGE_
#define _DOUBLY_LIST_PRIVILEGE_

DListError_t CreateDList(DList_t*);

DListError_t DestroyDList(DList_t*);

DListError_t DListEmpty(DList_t);

DListError_t DListFull(DList_t);

DListError_t DListSize(int*, DList_t);

DListError_t DListHead(int*, DList_t);

DListError_t DListInsert(int, DListEntry, DList_t*);

DListError_t DListDelete(int, DListEntry*, DList_t*);

DListError_t DListRetrieve(int, DListEntry*, DList_t);

DListError_t DListReplace(int, DListEntry, DList_t*);

DListError_t DListTraverse(DList_t, void (*) (DListEntry));

#endif