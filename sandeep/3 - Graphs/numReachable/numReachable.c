
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#define TRUE 1
#define FALSE !TRUE

void recDepthFirstSearch(Graph g, int src, int size, int visited[], int *nodes) {
	for (int w = 0; w < size; w++) {
		if (!visited[w] && GraphIsAdjacent(g, src, w)) {
			visited[w] = TRUE;
			(*nodes)++;
			recDepthFirstSearch(g, w, size, visited, nodes);
		}
	}
}

int numReachable(Graph g, int src) {
	if (g == NULL) return 0;

	// Initialise visited array
	int size = GraphNumVertices(g);
	int visited[size];
	for (int i = 0; i < size; i++) {
		visited[i] = FALSE;
	}

	// Loop through all nodes
	visited[src] = TRUE;
	int nodes = 1;
	recDepthFirstSearch(g, src, size, visited, &nodes);
	return nodes;
}

// int numReachable(Graph g, int src) {
// 	// TODO
// 	return -1;
// }
