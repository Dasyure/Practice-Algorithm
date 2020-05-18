
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"
#define TRUE 1
#define FALSE !TRUE

void breadthFirstSearch(Graph g, int src) {
	if (g == NULL) return;
	int size = GraphNumVertices(g);

	int visited[size];
	for (int i = 0; i < size; i++) {
		visited[i] = FALSE;
	}
	visited[src] = TRUE;
	printf("%d ", src);
	Queue q = QueueNew();
	QueueEnqueue(q, src);

	// Add to queue after visited, then pop and go through its neighbours
	while (!QueueIsEmpty(q)) {
		Vertex v = QueueDequeue(q);
		for (int w = 0; w < size; w++) {
			// If vertex adjacent and vertex not visited
			if (GraphIsAdjacent(g, v, w) && visited[w] == FALSE) {
				visited[w] = TRUE;
				printf("%d ", w);
				QueueEnqueue(q, w);
			}
		}
	}
	QueueFree(q);
}

// void breadthFirstSearch(Graph g, int src) {
// 	// TODO
// }