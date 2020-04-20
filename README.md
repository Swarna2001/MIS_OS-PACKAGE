This project is used for finding out the MIS of a given graph. 
It makes use of an algorithm "FAST MIS" that was presented in a research paper. The algorithm is a simple, randomised parallel algorithm. The project further parallelises this by making use of OpenMP API.

The code for the serial algorithm is present in the file final.c

The code for the parallel algorithm is present in the file parallel.c

**System requirements :** You need an Linux or Putty terminal to run this program.

**Steps for installation :**

1. Download all the files namely Node.h, final.c, parallel.c
   into your desktop.

2. In order to compile the program, type the command
   **cc -fopenmp filename**

3. In order to run the program, type the command ./a.out

**Instructions for the user to input the graph :**

Note that the programs require the user to input the 
adjacency list for the vertices of the graph.

**Serial program :**

 When you run this program, the user is prompted to specify the number of vertices present in the adjacency
list of each vertex. 

 First input the number of elements present in the adjacency list,
and then the actual elements present.

**Parallel program :**

  Here the program itself will prompt the user to input the adjacency list of what vertex is required.
Only that needs to be given.
