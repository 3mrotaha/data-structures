#include <stdio.h>
#include "list_ErrorStates.h"
#include "list_config.h"
#include "list_private.h"
#include "list_privilege.h"


void display(DListEntry e){
	printf("%d, ", e);
}


int main(void){
	DListEntry e;
	DList_t l;
	CreateDList(&l);
	int op, index;
	while(1){
		printf("Delete(0)/Insert(1)/Retrieve(2)/Replace(3)/Traverse(4)/Size(5)/Head(6)/Destroy(7) : ");
		scanf("%d", &op);
		if(op == 0){
			if(DListEmpty(l) != LIST_EMPTY){
				printf("Enter the index : ");
				scanf("%d", &index);
				DListDelete(index, &e, &l);
				printf("%d Deleted from %d\n", e, index);
			}
			else{
				printf("List is Empty!\n");
			}
		}
		else if(op == 1){
			if(DListFull(l) != LIST_FULL){
				printf("Enter Element & Index : ");
				scanf("%d %d", &e, &index);
				DListInsert(index, e, &l);
				printf("%d inserted in %d", e, index);
			}
			else{
				printf("List is Full!\n");
			}
		}
		else if(op == 2){
			if(DListEmpty(l) != LIST_EMPTY){
				printf("Enter the index : ");
				scanf("%d", &index);
				DListRetrieve(index, &e, l);
				printf("You retrieved %d\n", e);
			}
			else{
				printf("List is Empty!\n");
			}
		}
		else if(op == 3){
			if(DListEmpty(l) != LIST_EMPTY){
				printf("Enter Element & Index : ");
				scanf("%d %d", &e, &index);;
				DListReplace(index, e, &l);
				printf("Entry in %d Replaced with %d\n", index, e);
			}
			else{
				printf("List is Empty!\n");
			}
		}
		else if(op == 4){
			if(DListEmpty(l) != LIST_EMPTY){
				DListTraverse(l, &display);
				printf("\n");
			}
			else{
				printf("List is Empty!\n");
			}
		}
		else if(op == 5){
			int size;
			if(DListSize(&size, l) != LIST_EMPTY){
				printf("List contains %d ", size);
				if(size == 1) printf("Element\n");
				else printf("Elements\n");
			}
			else{
				printf("List is Empty!\n");
			}
		}
		else if(op == 6){
			int pos;
			if(DListHead(&pos, l) != LIST_EMPTY){
				printf("Head -> %d\n", pos);
			}
			else{
				printf("List is Empty!\n");
			}
		}
		else if(op == 7){
			if(DListEmpty(l) != LIST_EMPTY){
				DestroyDList(&l);
				printf("List Destroied\n");
			}
			else{
				printf("List is Empty!\n");
			}			
		}		
		printf("\n");
	}
	
	return 0;
}