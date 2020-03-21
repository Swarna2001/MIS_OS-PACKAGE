#include <stdio.h>
#include "Node.h"

/* This is the GRAPH object i am using */
struct Graph
{
	char name[20];
	int nov;
	int noe;
	struct Node* arr[10];
};

/* HERE name refers to the name of the graph, nov refers to the number of vertices
noe referes to the number of edges, and arr refers to an array of node* pointers -
each of the element of arr refers to the adjacency list of a vertex */

int main()
{
	/* initailising the head and ptr to NULL */
	head = NULL;
	ptr = NULL;

	struct Graph G;

	printf("Enter the name of the graph : ");
	scanf("%s", G.name);

	printf("Enter the number of vertices : ");
	scanf("%d", &G.nov);

	printf("Enter the number of edges : ");
	scanf("%d", &G.noe);

	/* initialising the node* pointers */
	for(int k=0; k<G.nov; k++)
	{
		G.arr[k] = (struct Node*) malloc(sizeof(struct Node));
	}

	/* for each vertex we are updating the adjacency list */
	for(int j=0; j<G.nov; j++)
	{
		int n;
		printf("Vertex %d - enter number of elements : ", j); /* we get in the number of elements to be added to the list */
		scanf("%d", &n);
		/* adding elements to the list */
		for(int l =0; l<n ;l++)
		{
			int elt;
			printf("Enter the element : ");
			scanf("%d", &elt);

			if(l == 0)
			{
				/* initialising the head pointer */
				head = G.arr[j];
				ptr = G.arr[j];
				G.arr[j]->data = elt;
				G.arr[j]->next = NULL;
			}
			else
			{
				InsertNode(elt);
			}
		}
	}
	return 0;
}


