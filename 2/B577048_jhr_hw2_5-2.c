// dfs-r-list.c

#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

#define MAX_VERTICES 50
typedef struct GraphNode
{
	int vertex;
	struct GraphNode* link;
} GraphNode;

typedef struct GraphType {
	int n;	
	GraphNode* adj_list[MAX_VERTICES];
} GraphType;

int visited[MAX_VERTICES];	// 방문한 정점들 표시

void init(GraphType* g)
{
	int v;
	g->n = 0;
	for (v = 0; v<MAX_VERTICES; v++)
		g->adj_list[v] = NULL;
}

void insert_vertex(GraphType* g, int v)
{
	if (((g->n) + 1) > MAX_VERTICES) {
		fprintf(stderr, "Graph: Too many vertices!");
		return;
	}
	g->n++;
}

void insert_edge(GraphType* g, int u, int v)
{
	GraphNode* node;
	if (u >= g->n || v >= g->n) {
		fprintf(stderr, "Graph: Wrong vertex number!");
		return;
	}
	node = (GraphNode*)malloc(sizeof(GraphNode));
	node->vertex = v;
	node->link = g->adj_list[u];
	g->adj_list[u] = node;
}

void print_adj_list(GraphType* g) 
{
	for (int i = 0; i<g->n; i++) {
		GraphNode* p = g->adj_list[i];
		printf("Adjacency list - Vertex %d:  ", i);
		while (p!=NULL) {
			printf("-> %d ", p->vertex);
			p = p->link;
		}
		printf("\n");
	}
}

// 인접 리스트를 이용한 recursion 기반의 깊이 우선 탐색 
void dfs_list(GraphType* g, int v)
{
GraphNode* w;
visited[v] = TRUE;   		// 정점 v의 방문 표시 

printf("Vertex %d -> ", v);	// 방문한 정점 출력
for (w = g->adj_list[v]; w; w = w->link) // 인접 정점 탐색 
    if (!visited[w->vertex])
        dfs_list(g, w->vertex);  //정점 w에서 DFS 새로 시작

return;
}

int main()
{
	GraphType *g;
	g = (GraphType *)malloc(sizeof(GraphType));

	init(g);

	for(int i=0;i<=9;i++)
		insert_vertex(g, i);

    // Vertex 0
    insert_edge(g, 0, 1);
    // Vertex 1
    insert_edge(g, 1, 0);
    insert_edge(g, 1, 2);          
    insert_edge(g, 1, 3);
    // Vertex 2
    insert_edge(g, 2, 1);
    insert_edge(g, 2, 4);
    // Vertex 3
    insert_edge(g, 3, 1);
    insert_edge(g, 3, 4);
    insert_edge(g, 3, 5);
    // Vertex 4
    insert_edge(g, 4, 2);
    insert_edge(g, 4, 3);
    // Vertex 5
    insert_edge(g, 5, 3);
    insert_edge(g, 5, 6);
    insert_edge(g, 5, 7);
    // Vertex 6
    insert_edge(g, 6, 5);
    insert_edge(g, 6, 7);
    // Vertex 7
    insert_edge(g, 7, 5);
    insert_edge(g, 7, 6);
    insert_edge(g, 7, 8);
    insert_edge(g, 7, 9);
    // Vertex 8
    insert_edge(g, 8, 7);
    // Vertex 9
    insert_edge(g, 9, 7);         
	print_adj_list(g);

    printf("DFS: ");
    dfs_list(g,0);
    printf("\n");

	free(g);
	return 0;
}
