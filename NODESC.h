typedef struct Node
{
	int data;
	struct Node *ptr;
}NODE;

NODE *createNode()
{
	NODE *n = (NODE*)malloc(sizeof(NODE));
	n->data = NULL;
	n->ptr = NULL;

	return n;
}

NODE *insertfirst(NODE *head, int val)
{
	NODE *tr = head;
	NODE *n = createNode();
	n->data = val;
	if(head==NULL)
	{
		n->ptr=n;
		head=n;
	}
	else
	{
		n->ptr=head;
		while(tr->ptr != head)
		{
			tr=tr->ptr;
		}
		tr->ptr=n;
		head=n;
	}
	printf("\n %d is Inserted \n",val);
	return head;
}

NODE *insertlast(NODE *head, int val)
{
	NODE *tr = head;
	NODE *n = createNode();
	n->data = val;
	if(head==NULL)
	{
		n->ptr=n;
		head=n;
	}
	else
	{
		n->ptr = head;
		while(tr->ptr != head)
		{
			tr = tr->ptr;
		}
		tr->ptr = n;
	}
	printf("\n %d is Inserted \n",val);
	return head;
}

void display(NODE *head)
{
	NODE *tr=head;
	if(tr==NULL)
	{
		printf("\n Link List is EMPTY");
	}
	else
	{
		while(tr->ptr != head)
		{
			printf("%d_",tr->data);
			tr = tr->ptr;
		}
		printf("%d",tr->data);
		//printf("\n");
	}
}

NODE *insertpos(NODE *head,int pos, int val)
{
	int con=1;
	NODE *n = createNode();
	n->data = val;
    NODE *tr = head;
    if (head==NULL)
	{
        printf("\n Link List is EMPTY");
	}
	else if(pos==1)
	{
		head = insertfirst(head,val);
	}
	else
	{
		while (con < (pos-1))
	        {
				tr = tr->ptr;
        		con++;
        	}
	        if(tr == head)
        	{
        		printf("INVALID POSITION \n");
        	}
	        else
        	{
        		n->ptr = tr->ptr;
				tr->ptr = n;
        	}
        	printf("\n %d is Inserted \n",val);
	}
	return head;
}

NODE *insertbefore(NODE *head, int eval, int nval)
{
	NODE *tr = head, *pre=NULL;
	NODE *n = createNode();
	n->data = nval;


	if(head==NULL)
	{
		printf("\n Link List is EMPTY");
	}
	else  if(head->data == eval)
	{
		while(tr->ptr != head)
		{
			tr = tr->ptr;
		}
		n->ptr=head;
		head = n;
		tr->ptr = head;
	}
	else
	{
		do
		{
			pre = tr;
			tr = tr->ptr;
		}while(tr!=head && tr->data != eval);
			pre->ptr = n;
			n -> ptr = tr;
	}
	printf("\n %d is Inserted \n",nval);
	return head;
}

NODE *insertafter(NODE *head, int eval, int nval)
{
	NODE *tr = head;
	NODE *n = createNode();
	n->data = nval;

	if(head == NULL)
	{
		printf("\n Link List is Already EMPTY");
	}
	if(head->data == eval)
	{
		n->ptr = head -> ptr;
		head->ptr = n;
	}
	else
	{
		while(tr->data != eval && tr->ptr != head)
		{
			tr = tr->ptr;
		}
		n->ptr = tr->ptr ;
		tr -> ptr = n;
	}
	printf("\n %d is Inserted \n",nval);
	return head;
}

NODE *deletefirst(NODE *head)
{
	NODE *tr = head, *del=NULL;

	if(head==NULL)
	{
		printf("\n Link List is EMPTY \n");
	}
	else  if(head->ptr == head)
	{
		printf("\n %d is Deleted \n",head->data);
		free(head);
		head = NULL;
	}
	else
	{
		del = head;
		while(tr -> ptr != head)
		{
			tr = tr -> ptr;
		}
		head = head -> ptr;
		tr -> ptr = head;
		printf("\n %d is Deleted \n",del->data);
		free(del);
	}
	return head;
}

void deletelast(NODE *head)
{
	NODE *tr = head, *pre=NULL;

	if(head==NULL)
	{
		printf("\n Link List is EMPTY \n");
	}
	else  if(head->ptr == head)
	{
		printf("\n %d is Deleted \n",head->data);
		free(head);
		head = NULL;
	}
	else
	{
		while(tr->ptr != head)
		{
			pre = tr;
			tr = tr->ptr;
		}
		pre->ptr = head;
		printf("\n %d is Deleted \n",tr->data);
		free(tr);
	}
}

NODE *deleteBefore(NODE *head, int val)
{
	NODE *tr=head, *pre=NULL, *pre2=NULL;

	if(head==NULL)
	{
		printf("\n Link List is EMPTY \n");
	}
	else if(head -> data == val)
	{
		printf("\n NO NODE IN LINKED LIST TO DELETE \n");
	}
	else
	{
		do
		{
			if(tr->data == val)
			{
				break;
			}
			pre2 = pre;
			pre = tr;
			tr = tr->ptr;
		}while(tr != head);
		if(tr==head)
		{
			printf("\n VALUE NOT FOUND...\n");
		}
		else if(pre == head)
		{
			head=deletefirst(head);
		}
		else
		{
			pre2->ptr = tr;
			printf("\n %d is Deleted \n",pre->data);
			free(pre);
		}
	}
	return head;
}

void deleteAfter(NODE *head, int val)
{
	NODE *tr=head, *del=NULL;

	if(head==NULL)
	{
		printf("\n Link List is EMPTY \n");
	}
	else if(head->ptr == head && head->data == val)
	{
		printf("\n %d is Deleted \n",head->data);
		free(head);
		head=NULL;
	}
	else
	{
		do
		{
			if(tr->data == val)
			{	break;	}
			tr = tr->ptr;
		}while(tr != head);
		if(tr == head && tr->data != val)
		{
			printf("\nVALUE NOT FOUND...\n");
		}
		else if(tr->ptr == head)
		{
			head = deletefirst(head);
		}
		else
		{
			del=tr->ptr;
			tr->ptr = del->ptr;
			printf("\n %d is Deleted \n",del->data);
			free(del);
		}
	}

}

NODE *deleteatpos(NODE *head, int pos)
{
    int con=1;
    NODE *tr = head, *pre=NULL;

    if(head==NULL)
    {
        printf("\n Link List is EMPTY");
    }
    if(pos == 1)
    {
        head = deletefirst(head);
    }
    else
    {
        while(con < pos)
        {
            pre = tr;
			tr = tr->ptr;
			con++;
        }
        if(tr == head)
		{
			printf("\n VALUE NOT FOUND...");
		}
		else
		{
			pre -> ptr = tr -> ptr;
			printf("\n %d is Deleted \n",tr->data);
			free(tr);
		}
    }
    return head;
}
