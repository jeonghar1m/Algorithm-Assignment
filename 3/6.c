// Reference: 수업시간에 사용한 소스코드
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0
#define MAX_VERTICES 100	
#define INF	1000000

typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;	// number of vertices in the graph
	int weight[MAX_VERTICES][MAX_VERTICES];
} GraphType;

int distance[MAX_VERTICES];     // The shortest path so far from source
int found[MAX_VERTICES];		// To indicate the visited vertex (Set S)
int adjancyList[MAX_VERTICES];

// Choose the index of the smallest element in the array distance[]							
int choose(int distance[], int n, int found[])
{
	int i, min, minpos;
	min = INT_MAX;
	minpos = -1;
	for (i = 0; i<n; i++)
		if (distance[i]< min && !found[i]) {
			min = distance[i];
			minpos = i;
		}
	return minpos;
}

void print_status(GraphType* g)
{
	static int step=1;
	printf("STEP %d: ", step++);
	printf("distance: ");
	for (int i = 0; i < g->n; i++) {
		if (distance[i] == INF)
			printf(" ∞ ");
		else
			printf("%2d ", distance[i]);
	}
	printf("\n");
	printf("        found:    ");
	for (int i = 0; i<g->n; i++)
		printf("%2d ", found[i]);
	printf("\n");
	printf("Adjancy List: ");
	for(int i = 0; i< g->n ;i++)
		if(adjancyList[i] != -1)
			printf("%2d ->", adjancyList[i]);
	printf("\n\n");

	return;
}


void shortest_path(GraphType* g, int start)
{
	int i, u, w;
	for (i = 0; i<g->n; i++) // Initialization
	{
		distance[i] = g->weight[start][i];
		found[i] = FALSE;
		adjancyList[i] = -1;
	}
	found[start] = TRUE;    // Source vertex is visted
	distance[start] = 0;    // Distance of source vertex is zero

	for (i = 0; i<g->n-1; i++) {
		adjancyList[0] = start;
		print_status(g);
		u = choose(distance, g->n, found);
		found[u] = TRUE;
		for (w = 0; w<g->n; w++)
			if (!found[w])
				if (distance[u] + g->weight[u][w]<distance[w])
					distance[w] = distance[u] + g->weight[u][w];
		adjancyList[i + 1] = u;
	}

	return;
}


int main(void)
{
	GraphType g = { 6,
	{{ 0,  50, 45, 10, INF, INF},	// 0
	{ INF, 0, 10, 15, INF, INF},	// 1
	{ INF, INF, 0, INF, 30, INF}, 	// 2
	{ 20, INF, INF, 0, 15, INF}, 	// 3
	{ INF, 20, 35, INF, 0, INF},	// 4
	{ INF, INF, INF, INF, 3, 0}}	// 5
	};
	shortest_path(&g, 0);
	return 0;
}