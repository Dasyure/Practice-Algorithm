
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#define TRUE 1
#define FALSE !TRUE


void recDepthFirstSearch(Graph g, int src, int size, int visited[]) {
	for (int w = 0; w < size; w++) {
		if (!visited[w] && GraphIsAdjacent(g, src, w)) {
			visited[w] = TRUE;
			printf("%d ", w);
			recDepthFirstSearch(g, w, size, visited);
		}
	}
}

void depthFirstSearch(Graph g, int src) {
	if (g == NULL) return;

	// Initialise visited array
	int size = GraphNumVertices(g);
	int visited[size];
	for (int i = 0; i < size; i++) {
		visited[i] = FALSE;
	}

	// Loop through all nodes
	visited[src] = TRUE;
	printf("%d ", src);
	recDepthFirstSearch(g, src, size, visited);
}




// void depthFirstSearch(Graph g, int src) {
// 	// TODO
// }

