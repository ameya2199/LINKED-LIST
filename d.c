//CIRCULAR DOUBLY LINKED LIST
//CREATE,INSERT,DELETE BY POSITION,DELETE BY VALUE,DISPLAY
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* next, * prev;
}node;
node* newnode, * head, * temp, * temp1;
void display()
{
	for (temp = head; temp->next != head; temp = temp->next)
		printf("\n%d", temp->data);
	printf("\n%d\n\n", temp->data);
}
void del_val()
{
	int n, i;
	printf("\nWHICH VALUE YOU WANT TO DELETE:");
	scanf("%d", &n);
	if (head->data == n)
	{
		temp = head;
		head->prev->next = head->next;
		head->next->prev = head->prev;
		head = head->next;
		temp->next = temp->prev = NULL;
		free(temp);
	}
	else
	{
		if (head->prev->data == n)
		{
			temp = head->prev;
			temp->prev->next = head;
			head->prev = temp->prev;
			temp->next = temp->prev = NULL;
			free(temp);
		}
		else
		{
			for (temp = head; temp->next != head; temp = temp->next)
			{
				if (temp->next->data == n)
				{
					temp1 = temp->next;
					temp->next = temp1->next;
					temp1->next->prev = temp;
					temp1->prev = temp1->next = NULL;
					free(temp1);
				}
			}
		}
	}
	display();
}
void del_pos()
{
	int n, i;
	printf("\nFROM WHICH POSITION YOU WANT TO DELETE:");
	scanf("%d", &n);
	if (n == 1)
	{
		temp = head;
		head->prev->next = head->next;
		head->next->prev = head->prev;
		head = head->next;
		temp->next = temp->prev = NULL;
		free(temp);
	}
	else
	{
		for (temp = head, i = 1; i < n - 1 && temp->next != head; i++, temp = temp->next);
		if (temp->next->next == head)
		{
			temp1=temp->next;
			temp->next = head;
			head->prev = temp;
			temp1->prev = temp1->next = NULL;
			free(temp1);
		}
		else
		{
			temp1 = temp->next;
			temp->next = temp1->next;
			temp->next->prev = temp;
			free(temp1);
		}
	}
	display();
}
void insert()
{
	int i, n;
	printf("\nON WHICH POSITION YOU WANT TO INSERT:");
	scanf("%d", &n);
	printf("\nENTER ELEMENT:");
	newnode = (node*)malloc(sizeof(node));
	scanf("%d", &newnode->data);
	if (n == 1)
	{
		head->prev->next = newnode;
		newnode->prev = head->prev;
		newnode->next = head;
		head = newnode;
	}	
	else
	{
		for (i = 1, temp = head; i < n - 1 && (temp->next != head); i++, temp = temp->next);
		if (temp->next == head)
		{
			temp->next = newnode;
			newnode->prev = temp;
			newnode->next = head;
			head->prev = newnode;
		}
		else
		{
			temp1 = temp->next;
			temp->next = newnode;
			newnode->prev = temp;
			newnode->next = temp1;
			temp1->prev = newnode;
		}
	}
	display();
}
void create()
{
	int n,i;
	printf("\nHOW MUCH VALUE YOU WANT TO STORE:");
	scanf("%d", &n);
	head = NULL;
	printf("\nENTER NUMBERS:\n");
	for (i = 0; i < n; i++)
	{
		if (head == NULL)
		{
			newnode = (node*)malloc(sizeof(node));
			scanf("%d", &newnode->data);
			newnode->prev = NULL;
			head = newnode;
			head->next = head;
			temp = newnode;
		}
		else
		{
			newnode = (node*)malloc(sizeof(node));
			scanf("%d", &newnode->data);
			newnode->next = head;
			newnode->prev = temp;
			temp->next = newnode;
			head->prev = newnode;
			temp = newnode;
		}
	}
	display();
}
int main()
{
	int n;
	printf("WELCOME!!!");
	create();
	do
	{
		printf("\nwhich operation you want to do:\n1.INSERT\n2.DELETE BY POSITION\n3.DELETE BY VALUE\n4.DISPLAY\n5.EXIT\n\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:insert();
			break;
		case 2:del_pos();
			break;
		case 3:del_val();
			break;
		case 4:printf("\n\nBYE....BYE.....\n\n");
			break;
		}
	} while (n < 4);
	return 0;
}