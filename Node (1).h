#include <stdlib.h>
#include <stdio.h>

struct Node{
	int data;
	struct Node *next;
};

struct Node *head, *ptr;

/* Function to get a new node */

struct Node* CreateNode( int elt )
{
	struct Node *NewNode = (struct Node*) malloc(sizeof(struct Node));
	NewNode->data = elt;
	NewNode->next = NULL;
	return NewNode;
}

/* Function to insert a new node into the linked list */

void InsertNode( int elt )
{
	struct Node* n = CreateNode(elt);
	ptr->next = n;
	n->next = NULL;
	ptr = ptr->next;
}

/* Function to diaplay the entire list */

void DisplayNode()
{
	struct Node* temp = head;
	while(temp->next!=NULL)
	{
		printf("%d->", temp->data);
		temp = temp->next;
	}
	printf("%d", temp->data);
}

