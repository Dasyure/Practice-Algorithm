
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"

int numReachable(Graph g, int src) {
	// TODO

	int i = 0;
	int j = 0;
	int visited[GraphNumVertices(g)];
	// first you make every vertices unvisited
    for (i = 0; i < GraphNumVertices(g); i++) {
		visited[i] = -1; 
	}
	i = 0;
	visited[src] = 2;
	int count = 1;
	while (i < GraphNumVertices(g)) {
		
	    if (GraphIsAdjacent(g, src, i)) {
			if (visited[i] != 2) {
				visited[i] = 2;
				count++;
				//printf("how come\n");
			}
			j = 0;
			while (j < GraphNumVertices(g)) {
				if (GraphIsAdjacent(g, i, j) && visited[j] != 2) {
					//printf("i:%d, j:%d\n", i, j);
					visited[j] = 2;
					count++;
					//printf("count: %d\n", count);
					i = j;
					j = 0;

				}
				else {
					j++;
				}
			}
			
		}
		i++;
	}

	return  count;
}

