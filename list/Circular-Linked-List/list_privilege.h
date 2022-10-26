#ifndef	_CICULAR_LIST_PRIVILEGE_
#define _CICULAR_LIST_PRIVILEGE_

CListError_t CreateCList(CList_t*);

CListError_t DestroyCList(CList_t*);

CListError_t CListEmpty(CList_t);

CListError_t CListFull(CList_t);

CListError_t CListSize(int*, CList_t);

CListError_t CListInsert(int, CListEntry, CList_t*);

CListError_t CListDelete(int, CListEntry*, CList_t*);

CListError_t CListRetrieve(int, CListEntry*, CList_t);

CListError_t CListReplace(int, CListEntry, CList_t*);

CListError_t CListTraverse(CList_t, void (*) (CListEntry));

#endif