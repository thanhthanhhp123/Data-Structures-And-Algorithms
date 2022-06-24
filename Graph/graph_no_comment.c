#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#define INIT_VAL INT_MIN
#define INF 3.402823466e+38F
void create_graph(int n, int** vertices, float*** edges) {
	*vertices = (int*)calloc(n, sizeof(int));
	*edges = (float**)calloc(n, sizeof(float*));
	for (int i = 0; i < n; i++) {
		(*edges)[i] = (float*)calloc(n, sizeof(float));
		(*vertices)[i] = INT_MIN;
		for (int j = 0; j < n; j++)
		{
			(*edges)[i][j] = INF;
		}
	}


}
bool exist(int value, int* arr, int n) {
	for (int i = 0; i < n; i++)if (value == arr[i])return true;
	return false;
}

bool adjacent(int x, int y, float** edge) {
	return edge[x][y] != INF;
}

bool add_vertex(int value, int* vertices, int n) {
	if (exist(value, vertices, n))return false;
	for (int i = 0; i < n; i++)
	{
		if (vertices[i] == INIT_VAL)
		{
			vertices[i] = value;
			return true;
		}
	}
	return false;
}
void add_edge(int x, int y, float distance, float** edges, int n, bool is_directed) {
	edges[x][y] = distance;
	if (!is_directed)edges[y][x] = distance;
}

int index(int value, int* vertices, int n) {
	for (int i = 0; i < n; i++)if (value == vertices[i])return i;
	return -1;
}

void delete_vertex(int value, int* vertices, int n, int** edges) {
	int idx = index(value, vertices, n);
	if (idx == -1)return;
	vertices[idx] = INIT_VAL;
	for (int i = 0; i < n; i++)
	{
		edges[i][idx] = INF;
		edges[idx][i] = INF;
	}
}




void BFS(int start, int* vertices, int n, float** edges) {
	bool* visited = (bool*)calloc(n, sizeof(bool));
	int* queue = (int*)calloc(n, sizeof(int));
	int front = 0, rear = 0;
	queue[rear++] = start;
	visited[start] = true;
	while (front != rear) {
		int u = queue[front++];
		printf("%d ", vertices[u]);
		for (int i = 0; i < n; i++)
		{ 
			if (adjacent(u, i, edges) && !visited[i])
			{
				queue[rear++] = i;
				visited[i] = true;
			}
		}
	}
	free(visited);
	free(queue);
	printf("\n");
}

void DFS(int start, int* vertices, int n, float** edges) {
	bool* visited = (bool*)calloc(n, sizeof(bool));
	int* stack = (int*)calloc(n, sizeof(int));
	int top = 0;
	stack[top++] = start;
	visited[start] = true;
	while (top != 0) {
		int u = stack[--top];
		printf("%d ", vertices[u]);
		for (int i = 0; i < n; i++)
		{
			if (adjacent(u, i, edges) && !visited[i])
			{
				stack[top++] = i;
				visited[i] = true;
			}
		}
	}
	free(visited);
	free(stack);
	printf("\n");
}

void Dijkstra(int start, int* vertices, int n, float** edges) {

	float* dist = (float*)calloc(n, sizeof(float));
	int* prev = (int*)calloc(n, sizeof(int));
	bool* visited = (bool*)calloc(n, sizeof(bool));
	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
		prev[i] = -1;
	}
	dist[start] = 0;
	int u = start;
	while (true) {
		visited[u] = true;
		for (int i = 0; i < n; i++)
		{
			if (adjacent(u, i, edges) && !visited[i] && dist[i] > dist[u] + edges[u][i])
			{
				dist[i] = dist[u] + edges[u][i];
				prev[i] = u;
			}
		}
		float min = INF;
		for (int i = 0; i < n; i++)
		{
			if (!visited[i] && dist[i] < min)
			{
				min = dist[i];
				u = i;
			}
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (visited[i])count++;
		}
		if (count == n)break;
	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d -> %d: %.1f\n", vertices[start], vertices[i], dist[i]);
	}
}
void BellmanFord(int start, int* vertices, int n, float** edges) {
	float* dist = (float*)calloc(n, sizeof(float));
	int* predecessor = (int*)calloc(n, sizeof(int));
	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
		predecessor[i] = -1;
	}
	dist[start] = 0;
	for (int i = 0; i < n - 1; i++) {
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				if (dist[u] != INF && dist[u] + edges[u][v] < dist[v]) {
					dist[v] = dist[u] + edges[u][v];
					predecessor[v] = u;
				}
			}
		}
		for (int u = 0; u < n; u++) {
			for (int v = 0; v < n; v++) {
				if (dist[u] != INF && dist[u] + edges[u][v] < dist[v]) {
					printf("Do thi chua chu trinh am\n");
					return;
				}
			}
		}

	}
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d -> %d: %.1f\n", vertices[start], vertices[i], dist[i]);
	}
}



int main() {
	int* vertices;
	float** edges;
	int n = 5;
	create_graph(n, &vertices, &edges);
	for (int i = 0; i < n; i++)
	{
		add_vertex(i, vertices, n);
	}
	add_edge(0, 1, 9.f, edges, n, true);
	add_edge(0, 2, 3.f, edges, n, true);
	add_edge(1, 2, 6.f, edges, n, true);
	add_edge(2, 1, 2.f, edges, n, true);
	add_edge(1, 4, 2.f, edges, n, true);
	add_edge(2, 3, 1.f, edges, n, true);
	add_edge(3, 2, 2.f, edges, n, true);
	add_edge(3, 4, 2.f, edges, n, true);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (edges[i][j] != INF)
				printf("%3.1f ", edges[i][j]);
			else printf("INF ");

		}
		printf("\n");
	}
	int start = index(0, vertices, n);
	printf("\nDuyet đo thi theo bfs\n");
	BFS(start, vertices, n, edges);
	printf("\nDuyet đo thi theo dfs\n");
	DFS(start, vertices, n, edges);
	printf("\nDijkstra\n");
	Dijkstra(start, vertices, n, edges);
	printf("\nBellman-Ford\n");
	BellmanFord(start, vertices, n, edges);
}