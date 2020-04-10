#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

int main()
{

  /* omp_get_wtime() is a function used to calculate the running time of the program */
  /* The variable on is used to denote the starting time of the program */
	double on = omp_get_wtime();

  /* The variable nov is used to denote the number of vertices of the given graph */
	int nov = 0;
	printf("Enter the number of vertices : ");
	scanf("%d", &nov);

  /* The variable start is used to store the value of the vertex from which a new round starts */
	int start = 0;
  
  /* The variable rem_vertices is used to keep track of the remaining number of vertices that haven't
  been used in a round */
	int rem_vertices = nov;

  /* The array p is used to keep track of what are all the variables removed in Phase 3 and
  what are all the variables yet remaining */
  /* We have used the sentinel value "10" to denote if a vertex has been aldready removed in Phase 3 */
	int p[nov];
  
  /* The array mis is used to store the vertices that enter the MIS in Phase 3 */
	int mis[nov];
  
  /* The variable count is used to point to the next location in that array "mis" to write down the entering vertex */
	int counter = 0;
  
	while(rem_vertices)
	{
		/* The variable n is used to denote the number of elements present in the adjacency list of the starting vertex */
    int n;
    
		printf("Enter the number of vertices adjacent to %d : ", start);
		scanf("%d", &n);

    /* The array a is used to store the elements of the adjacency list of the starting vertex */
		int a[n];
    
    /* Getting from the user the adjacency list */
		for(int i=0; i<n; i++)
		{
			printf("\nEnter the vertex : ");
			scanf("%d", &a[i]);
		}

    /* The variable flag is used to check if the starting vertex satisfies the candidacy property */
    /* If flag is zero, it means the strating vertex satisfies the property mentioned in Phase 2 */
		int flag = 0;
    
		if(start==0)
		{
      /* The variable r holds the random value assigned to the starting vertex */
			int r = rand();
      
      /* The below section of code is parallel in nature and implemented using threads */
      /* #pragma omp parallel for - since we are parallelising a for loop */
      /* reduction(+:flag) - since the flag variable is getting updated by multiple threads and the updation is addition */
      /* shared(r) - since the variable r is read and used by all the threads */
			#pragma omp parallel for reduction(+:flag) shared(r)
			for(int i=0 ; i<n; i++)
			{
        /* The variable x hold the random value assigned to the vertex in the adjacency list - for each thread this is private */
				int x = rand();

        /* Checking if violation of Phase 2 property. If so, increment the variable flag */
				if(r>x)
				{
					flag += 1;
				}
			}
		}
    
    /* Checking if the starting vertex has satisfied the Phase 2 property */
		if(flag==0)
		{
    
      /* Adding the vertex into the MIS and updating the variable counter */
			mis[counter] = start;
			counter = counter + 1;

      /* The variable new_start is used to find out the next starting vertex for the next round */
			int new_start = -1;
      
      /* The below section of code is parallel in nature and implemented using threads */
      /* #pragma omp parallel for - since we are parallelising a for loop */
      /* reduction(+:check) - since the check variable is getting updated by multiple threads and the updation is addition */
      /* shared(new_start) - since the variable new_start is read and used by all the threads */
			
      /* We are now iterating over all the vertices of the graph and checking if any of them haven't yet been in a round */
			#pragma omp parallel for shared(new_start)
			for(int j=0; j<nov; j++)
			{
        /* If p[j]=10, it means our vertex was aldready removed in Phase 3 of some round */
				if(p[j]!=10)
        {
          /* This variable is used to check if the vertex is present in the adjacency list of the starting vertex */
          /* This is because, we haven't yet updated the array for these variables */
          int check = 0;
          #pragma omp parallel for reduction(+:check)
          for(int k=0; k<n; k++)
          {
            /* If this vertex is present in the list aldready, increment variable check */
            if(j==a[k])
            {
              check += 1;
            }
          }
          
          /* The starting vertex needs to satisfy 3 main properties */
          /* 1st - it should not be in the adjacency list */
          /* 2nd - it shouldn't be the start variable itself */
          /* 3rd - it should be the first one to satisfy as many vertices can satisfy this property */
          if(check==0 && start!=j && new_start==-1)
          {
            new_start = j;
          }
        }
			}

      /* The variable p is updated for the variable start */
			p[start] = 10;

      /* Incase a new start was found, update the variable start */
			if(new_start!=-1)
			{
				start = new_start;
			}

      /* Updating the variable p for the vertices in the adjacency list */
      /* Incase it is aldready updated, no need to re-update */
      /* Meanwhile decrement the variable rem_vertices for these vertices and the starting vertex */
			for(int l=0; l<n; l++)
			{
				if(p[a[l]]!=10)
				{
					rem_vertices -= 1;
					p[a[l]] = 10;
				}
			}
			rem_vertices -= 1;
		}
		else
		{
      /* Incase the starting vertex 0 or any other fails, simply move on to the next vertex */
			start += 1;
		}
	}

  /* Printing the MIS of the graph */
  printf("\n The MIS of the graph is ");
	for(int i=0; i<counter; i++)
	{
		printf("%d ", mis[i]);
	}

  /* The off variable is used to denote the end of the program */
  /* We are then displaying the actual running time of the program */
	double off = omp_get_wtime();
	printf("\n Time : %f\n", off - on);
	return 0;
}
