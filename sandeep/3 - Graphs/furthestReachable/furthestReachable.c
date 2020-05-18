
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Queue.h"
#define NOT_FOUND -1
#define TRUE 1
#define FALSE !TRUE

int getDistance(int pred[], int src, int size) {
	int maxDist = 0;
	Vertex maxVertex = src;
	// Calculate distance from vertex src for each vertex i
	for (int i = 0; i < size; i++) {
		int distance = 1;
		// If not found, don't calculate the distance
		if (pred[i] == NOT_FOUND || i == src) {
			continue;
		// Else loop backwards through pred
		} else {
			int num = i;
			while (pred[num] != src) {
				num = pred[num];
				distance++;
			}
			// If distance is larger, or dist equal but vertex bigger, update:
			if (distance > maxDist || (distance == maxDist && i > maxVertex)) {
				maxDist = distance;
				maxVertex = i;
			}
		}
	}
	return maxVertex;
}

int furthestReachable(Graph g, int src) {
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
	return getDistance(pred, src, size);
}

// int furthestReachable(Graph g, int src) {
// 	// TODO
// 	return -1;
// }