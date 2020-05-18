
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"

#define NOT_FOUND -1
#define TRUE 1
#define FALSE !TRUE

int getDistance(int pred[], int src, int dest) {
	int distance = 1;
	// If not found, return -1
	if (pred[dest] == NOT_FOUND) {
		return NOT_FOUND;
	// If src == dest, distance == 0
	} else if (src == dest) {
		return 0;
	// Else loop backwards through pred
	} else {
		int num = dest;
		while (pred[num] != src) {
			num = pred[num];
			distance++;
		}
	}
	return distance;
}

int shortestDistance(Graph g, int src, int dest) {
	if (g == NULL) return 0;
	int size = GraphNumVertices(g);
	int found = FALSE;

	int visited[size];
	int pred[size];
	for (int i = 0; i < size; i++) {
		visited[i] = FALSE;
		pred[i] = NOT_FOUND;
	}
	visited[src] = TRUE;
	pred[src] = src;
	Queue q = QueueNew();
	QueueEnqueue(q, src);

	// Add to queue after visited, then pop and go through its neighbours
	while (found == FALSE && !QueueIsEmpty(q)) {
		Vertex v = QueueDequeue(q);
		if (v == dest) {
			break;
		}
		for (int w = 0; w < size; w++) {
			// If vertex adjacent and vertex not visited
			if (GraphIsAdjacent(g, v, w) && visited[w] == FALSE) {
				visited[w] = TRUE;
				pred[w] = v;
				QueueEnqueue(q, w);
			}
		}
	}
	QueueFree(q);
	return getDistance(pred, src, dest);
}

// int shortestDistance(Graph g, int src, int dest) {
// 	// TODO
// 	return -1;
// }
