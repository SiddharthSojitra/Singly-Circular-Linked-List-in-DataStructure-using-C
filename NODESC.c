#include<stdio.h>
#include"NODESC.h"

main()
{
	NODE *head=NULL;
	while(1)
	{
		int S,val=0,pos,nval,eval;

		printf("\n||||||||||||||||||||||||||||||||||||||||||");
		printf("\n||          CHOOSE THE OPTION           ||");
		printf("\n||||||||||||||||||||||||||||||||||||||||||");
		printf("\n|| 01_INSERT_FIRST                      ||");
		printf("\n|| 02_INSERT_LAST                       ||");
		printf("\n|| 03_DISPLAY                           ||");
		printf("\n|| 04_INSERT_AT_POSITION                ||");
		printf("\n|| 05_INSERT_BEFORE                     ||");
		printf("\n|| 06_INSERT_AFTER                      ||");
		printf("\n|| 07_DELETE_FIRST                      ||");
		printf("\n|| 08_DELETE_LAST                       ||");
		printf("\n|| 09_DELETE_AT_POSITION                ||");
		printf("\n|| 10_DELETE_BEFORE                     ||");
		printf("\n|| 11_DELETE_AFTER                      ||");
		printf("\n|| 00_EXIT                              ||");
		printf("\n||||||||||||||||||||||||||||||||||||||||||\n");
		printf("\n\t\t\t\t Enter your choice...");
		scanf("%d",&S);
		switch(S)
		{
			case 0: return 0;

			case 1:
				printf("Enter the value :");
				scanf("%d",&val);
				head = insertfirst(head,val);
			break;

			case 2:
				printf("Enter the value :");
				scanf("%d",&val);
				head = insertlast(head,val);
			break;

			case 3:
				display(head);
			break;

			case 4:
				printf("Enter the Position : ");
				scanf("%d",&pos);
				printf("Enter the Value : ");
				scanf("%d",&val);
				head = insertpos(head,pos,val);
			break;

			case 5:
				printf("Where you add the new value : before..");
				scanf("%d",&eval);
				printf("Enter the new value :");
				scanf("%d",&nval);
				head = insertbefore(head,eval,nval);
			break;

			case 6:
				printf("Where you add the new value : after..");
				scanf("%d",&nval);
				printf("Enter the new value :");
				scanf("%d",&eval);
				head = insertafter(head,nval,eval);
			break;

			case 7:
				head = deletefirst(head);
			break;

			case 8:
				deletelast(head);
			break;

			case 9:
				printf("Enter the Position : ");
				scanf("%d",&pos);
				head = deleteatpos(head,pos);
			break;

			case 10:
				printf("Enter the EXISTING value :");
				scanf("%d",&val);
				head=deleteBefore(head,val);
			break;

			case 11:
				printf("Enter the EXISTING value :");
				scanf("%d",&val);
				deleteAfter(head,val);
			break;

			default : printf("\n PLEASE ENTER VALID OPTION \n");
			break;
		}
	}
}
