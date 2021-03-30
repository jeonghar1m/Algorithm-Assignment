//참조 코드: 수업시간에 사용한 10장 adj_list.c

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 6
typedef struct GraphNode
{
	int vertex;	//정점
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;	// Number of vertices
	GraphNode* adj_list[MAX_VERTICES];
	int inDegree[MAX_VERTICES];		//진입 차수
	int outDegree[MAX_VERTICES];	//진출 차수
} GraphType;

// Initialize graph
void init(GraphType* g)
{
	int u, v;
	g->inDegree[u] = 0;
	g->outDegree[v] = 0;
	g->n = 0;
	for (v = 0; v<MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

// Insert a vertex into graph g
void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "Too many vertices!!");
		return;
	}
	g->n++;
}

// Insert an edge into graph g
// u: start vertex
// v: end vertex

void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node;

	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "Graph: Vertex number error!!");
		return;
	}
	
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;

	g->inDegree[v]++;
	g->outDegree[u]++;
}

void print_adj_list(GraphType* g) 
{
	for (int i = 0; i<g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("정점 %d의 인접 리스트: %d ", i, i);

		while (p!=NULL) {
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

void print_inoutput_degree(GraphType* g)
{
	for(int i = 0; i<g->n; i++)
		printf("정점 %d의 진입 차수: %d\n", i, g->inDegree[i]);

	printf("-------------------------------------\n");
	
	for(int i = 0; i<g->n; i++)
		printf("정점 %d의 진출 차수: %d\n", i, g->outDegree[i]);
}

void print_min_and_max_indgree(GraphType* g)
{
	int min = 10;
	int max = 0;
	int minVertex = 0;
	int maxVertex = 0;

	for(int i = 0; i < MAX_VERTICES; i++)
	{
		if(g->inDegree[i] < min)
		{
			min = g->inDegree[i];
			minVertex = i;
		}

		if(g->inDegree[i] > max)
		{
			max = g->inDegree[i];
			maxVertex = i;
		}
	}

	printf("진입 차수가 가장 낮은 정점: %d / 차수: %d\n", minVertex, min);
	printf("진입 차수가 가장 큰 정점: %d / 차수: %d\n", maxVertex, max);
}

void print_min_and_max_outdegree(GraphType* g)
{
	int min = 10;
	int max = 0;
	int minVertex = 0;
	int maxVertex = 0;

	for(int i = 0; i < MAX_VERTICES; i++)
	{
		if(g->outDegree[i] < min)
		{
			min = g->outDegree[i];
			minVertex = i;
		}

		if(g->outDegree[i] > max)
		{
			max = g->outDegree[i];
			maxVertex = i;
		}
	}

	printf("진출 차수가 가장 낮은 정점: %d / 차수: %d\n", minVertex, min);
	printf("진출 차수가 가장 큰 정점: %d / 차수: %d\n", maxVertex, max);
}

int main()
{
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));
	init(g);

	for(int i=0;i<MAX_VERTICES;i++)
		insert_vertex(g, i);

	insert_edge(g, 0, 1);
	insert_edge(g, 1, 2);
	insert_edge(g, 2, 4);
	insert_edge(g, 4, 2);
	insert_edge(g, 0, 2);
	insert_edge(g, 4, 1);
	insert_edge(g, 1, 3);
	insert_edge(g, 3, 0);
	insert_edge(g, 0, 3);
	insert_edge(g, 3, 4);
	insert_edge(g, 5, 4);

	print_adj_list(g);

	printf("-------------------------------------\n");

	print_inoutput_degree(g);

	printf("-------------------------------------\n");

	print_min_and_max_indgree(g);

	printf("-------------------------------------\n");

	print_min_and_max_outdegree(g);

	free(g);
	
	return 0;
}