
#include <stdio.h>
#include <stdlib.h>

#include "Graph.h"
#include "Stack.h"
#define TRUE 1
#define FALSE !TRUE

bool recDepthFirstSearch(Graph g, int curr, int size, int visited[], int parent) {
	int flag = FALSE;
	for (int w = 0; w < size; w++) {
		if (!visited[w] && GraphIsAdjacent(g, curr, w)) {
			visited[w] = TRUE;
			flag = recDepthFirstSearch(g, w, size, visited, curr);
		} else if (visited[w] && GraphIsAdjacent(g, curr, w) && w != parent) {
			return TRUE;
		}
	}
	return flag;
}

bool hasCycle(Graph g) {
	if (g == NULL) return FALSE;

	// Initialise visited array
	int size = GraphNumVertices(g);
	int visited[size];
	for (int i = 0; i < size; i++) {
		visited[i] = FALSE;
	}

	// Loop through all nodes, since node 0 might be dead end
	bool isCycle = FALSE;
	for (int i = 0; i < size; i++) {
		if (!visited[i]) {
			visited[i] = TRUE;
			isCycle = recDepthFirstSearch(g, i, size, visited, -1);
		}
	}
	return isCycle;
}

// bool hasCycle(Graph g) {
// 	// TODO
// 	return false;
// }
