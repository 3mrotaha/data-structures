#include <stdio.h>
#include "list_ErrorStates.h"
#include "list_config.h"
#include "list_privilege.h"


void display(CListEntry e){
	printf("%d, ", e);
}


int main(void){
	CListEntry e;
	CList_t l;
	CreateCList(&l);
	int op, index;
	while(1){
		printf("Delete(0)/Insert(1)/Retrieve(2)/Replace(3)/Traverse(4)/Size(5)/Destroy(6) : ");
		scanf("%d", &op);
		if(op == 0){
			if(CListEmpty(l) != LIST_EMPTY){
				printf("Enter the index : ");
				scanf("%d", &index);
				CListDelete(index, &e, &l);
				printf("%d Deleted from %d\n", e, index);
			}
			else{
				printf("List is Empty!\n");
			}
		}
		else if(op == 1){
			if(CListFull(l) != LIST_FULL){
				printf("Enter Element & Index : ");
				scanf("%d %d", &e, &index);
				CListInsert(index, e, &l);
				printf("%d inserted in %d", e, index);
			}
			else{
				printf("List is Full!\n");
			}
		}
		else if(op == 2){
			if(CListEmpty(l) != LIST_EMPTY){
				printf("Enter the index : ");
				scanf("%d", &index);
				CListRetrieve(index, &e, l);
				printf("You retrieved %d\n", e);
			}
			else{
				printf("List is Empty!\n");
			}
		}
		else if(op == 3){
			if(CListEmpty(l) != LIST_EMPTY){
				printf("Enter Element & Index : ");
				scanf("%d %d", &e, &index);;
				CListReplace(index, e, &l);
				printf("Entry in %d Replaced with %d\n", index, e);
			}
			else{
				printf("List is Empty!\n");
			}
		}
		else if(op == 4){
			if(CListEmpty(l) != LIST_EMPTY){
				CListTraverse(l, &display);
				printf("\n");
			}
			else{
				printf("List is Empty!\n");
			}
		}
		else if(op == 5){
			int size;
			if(CListSize(&size, l) != LIST_EMPTY){
				printf("List contains %d ", size);
				if(size == 1) printf("Element\n");
				else printf("Elements\n");
			}
			else{
				printf("List is Empty!\n");
			}
		}
		else if(op == 6){
			if(CListEmpty(l) != LIST_EMPTY){
				DestroyCList(&l);
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