
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
struct graph {
	int nV;
	bool **edges;
};


int numReachable(Graph g, int src) {
	// TODO

	int i = 0;
	int j = 0;
	int visited[g->nV];
	// first you make every vertices unvisited
    for (i = 0; i < g->nV; i++) {
		visited[i] = -1; 
	}
	i = 0;
	visited[src] = 2;
	int count = 1;
	while (i < g->nV) {
		
	    if (g->edges[src][i]) {
			if (visited[i] != 2) {
				visited[i] = 2;
				count++;
				//printf("how come\n");
			}
			j = 0;
			while (j < g->nV) {
				if (g->edges[i][j] && visited[j] != 2) {
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

