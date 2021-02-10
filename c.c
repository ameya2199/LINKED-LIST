
//DOUBLY LINKED LIST
//CREATE,INSERT,REVERSE,DELETE BY VALUE,DELETE BY POSITION,SEARCH
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* prev, * next;
}node;
node* head, * newnode,*temp,*temp1;
void display()
{
	for (temp = head; temp != NULL; temp = temp->next)
	{
		printf("\n%d", temp->data);
	}
}
void create()
{
	int n,i;
	printf("\nHOW MUCH VALUE YOU WANT TO STORE:");
	scanf("%d", &n);
	printf("\nPLEASE ENTER VALUE:");
	head = NULL;
	for (i = 0; i < n; i++)
	{
		newnode = (node*)malloc(sizeof(node));
		if (head == NULL)
		{
			scanf("%d", &newnode->data);
			newnode->prev = newnode->next = NULL;
			head = newnode;
			temp = head;
		}
		else 
		{
			scanf("%d", &newnode->data);
			newnode->next = NULL;
			temp->next = newnode;
			newnode->prev = temp;
			temp = newnode;
		}
	}
	display();
}
void insert()
{
	int i,n;
	printf("\nON WHICH POSITION YOU WANT INSERT:");
	scanf("%d", &n);
	printf("\nENTER NO.:");
	newnode = (node*)malloc(sizeof(node));
	newnode->next = NULL;
	newnode->prev = NULL;
	scanf("%d", &newnode->data);
	for (i = 0, temp = head; i < n-2; i++, temp = temp->next);
		if (n == 1)
		{
			temp = head;
			head = newnode;
			head->next = temp;
		}
		else
			if (temp->next == NULL)
			{
				temp->next = newnode;
				newnode->prev = temp;
			}
			else
			{
				temp1 = temp->next;
				temp->next = newnode;
				newnode->next = temp1;
				temp1->prev = newnode;
				newnode->prev = temp;
			}
	display();
}
void del_pos()
{
	int n, i;
	printf("\nENTER WHICH POSITION:");
	scanf("%d", &n);
	if (n == 1)
	{
		temp1 = head;
		head = head->next;
		free(temp1);
	}
	else
	{
		for (i = 0, temp = head; (temp->next!=NULL) && i < n - 1; i++, temp = temp->next);
		if (temp->next == NULL)
		{
			temp1 = temp->prev;
			temp1->next = NULL;
		}
		else
		{
			temp1 = temp->prev;
			temp1->next = temp->next;
			temp->next->prev = temp1;
		}
	}
	display();
}
void del_val()
{
	int n;
	printf("\nENTER WHICH VALUE YOU WANT TO DELETE:");
	scanf("%d", &n);
	if (head->data == n)
	{
		temp = head;
		head = head->next;
		head->prev = NULL;
		free(temp);
	}
	else
	{
		for (temp = head; temp != NULL; temp = temp->next)
		{
			if (temp->next->data == n)
			{
				temp1 = temp->next;
				temp->next = temp1->next;
				temp1->prev = temp;
				break;
			}
		}
	}
	display();
}
int main()
{
	printf("HELLO!!!MAN");
	int i, n;
	create();
	do
	{
		printf("\nWHICH OPERATION YOU WANT TO EXECUTE:\n1.INSERT\n2.DELETE BY POSITION\n3.DELETE BY VALUE\n4.DISPLAY\n5.EXIT\n\n");
		printf("\nENTER VALUE:");
		scanf("%d", &n);
		switch (n)
		{
		case 1:insert();
			break;
		case 2:del_pos();
			break;
	    case 3:del_val();
			break;
		case 4:display();
			break;
		case 5:printf("\n\nBYE....BYE...\n\n");
			break;
		}
	} while (n < 5);
	return 0;
}