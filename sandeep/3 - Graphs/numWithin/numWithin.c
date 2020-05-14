
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"
#define NOT_FOUND -1
#define TRUE 1
#define FALSE !TRUE

int nodesWithin(Graph g, int src, int dist, int pred[], int size) {
	int sumNodes = 0;
	// Calculate distance for each node
	for (int i = 0; i < size; i++) {
		int distance = 1;
		// Source node is always within range
		if (i == src) {
			sumNodes++;
			continue;
		// If not found, don't calculate the distance
		} else if (pred[i] == NOT_FOUND) {
			continue;
		// Else loop backwards through pred
		} else {
			int num = i;
			while (pred[num] != src) {
				num = pred[num];
				distance++;
			}
			// If distance within range, add to sum
			if (distance <= dist) {
				sumNodes++;
			}
		}
	}
	return sumNodes;
}

int numWithin(Graph g, int src, int dist) {
	if (g == NULL) return 0;
	int size = GraphNumVertices(g);

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
	while (!QueueIsEmpty(q)) {
		Vertex v = QueueDequeue(q);
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
	return nodesWithin(g, src, dist, pred, size);
}

// int numWithin(Graph g, int src, int dist) {
// 	// TODO
// 	return 0;
// }