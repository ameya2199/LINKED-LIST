//SINGLY CIRCULAR LINKED LIST
//CREATE,INSERT,DELETE BY POSITION,DELETE BY VALUE,DISPLAY
#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
	int data;
	struct node* next;
}node;
node* newnode, * head, * temp, * temp1;
void display()
{
	for (temp = head; temp->next != head; temp = temp->next)
		printf("\n%d", temp->data);
	printf("\n%d\n", temp->data);
}
void del_val()
{
	int n, i;
	printf("\nWHICH VALUE YOU WANT TO DELETE:");
	scanf("%d", &n);
	if (head->data == n)
	{
		if (head->next == head)
		{
			head->next = NULL;
			free(head);
		}
		else
		{
			for (temp = head; temp->next != head; temp = temp->next);
			temp1 = head;
			head = head->next;
			temp1->next = NULL;
			temp->next = head;
			free(temp1);
		}
	}
	else
	{
		for (temp = head; temp->next != head; temp = temp->next)
		{
			if (temp->next->data == n)
			{
				temp1 = temp->next;
				temp->next = temp1->next;
				temp1->next = NULL;
				free(temp1);
				break;
			}
		}
	}
	display();
}
void del_pos()
{
	int n, i;
	printf("\n\nplease enter from where you want to delete:");
	scanf("%d", &n);
	if (n == 1)
	{
		for (temp1 = head; temp1->next != head; temp1 = temp1->next);
		temp1->next = NULL;
		temp = head;
		head = head->next;
		temp->next = NULL;
		temp1->next = head;
		free(temp);
	}
	else
	{
		for (i = 1, temp = head; i < n-1 && (temp->next != head); i++, temp = temp->next);
		if (temp->next == head)
		{
			temp1 = temp->next;
			temp->next = head;
			temp1->next = NULL;
			free(temp1);
		}
		else
		{
			temp1 = temp->next;
			temp->next = temp1->next;
			free(temp1);
		}
	}
	display();
}
void insert()
{
	int n, i;
	printf("\n\nON WHICH POSITION YOU WANT TO INSERT:");
	scanf("%d", &n);
	printf("\nPLEASE ENTER NUMBER:");
	newnode = (node*)malloc(sizeof(node));
	scanf("%d", &newnode->data);
	if (n == 1)
	{
		for (temp = head; temp->next != head; temp = temp->next);
		newnode->next = head;
		temp->next = newnode;
		head = newnode;
	}
	else
	{
		for (i = 1, temp = head; i < n - 1 && (temp->next != head); i++, temp = temp->next);
			if (temp->next == head)
			{
				temp->next = newnode;
				newnode->next = head;
			}
			else
			{
			   temp1 = temp->next;
				temp->next = newnode;
				newnode->next = temp1;
			}
		}
	display();
}
void create()
{
	int n, i;
	printf("\nENTER HOW MUCH VALUE YOU WANT TO STORE:");
	scanf("%d", &n);
	printf("enter value\n");
	for (i = 0; i < n; i++)
	{
		if (head == NULL)
		{
			newnode = (node*)malloc(sizeof(node));
			scanf("%d", &newnode->data);
			head = newnode;
			temp = head;
			temp->next = head;
		}
		else
		{
			newnode = (node*)malloc(sizeof(node));
			scanf("%d", &newnode->data);
			newnode->next = head;
			temp->next = newnode;
			temp = newnode;
		}
	}
	display();
}
int main()
{
	int n;
	printf("\nWELCOME!!!TO OPERATE SINGLY CIRCULAR LIST\n\n");
	create();
	do
	{
		printf("WHICH OPERATION YOU WANT TO DO:\n1.INSERT\n2.DELETE BY POSITIO\n3.DELETE BY VALUE\n4.DISPLAY\n5.EXIT\n\n");
		printf("PLEASE ENTER:");
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
		case 5:printf("\n\nBYE......BYE..........\n\n");
			break;
		}
	} while (n < 5);
	return 0;
}