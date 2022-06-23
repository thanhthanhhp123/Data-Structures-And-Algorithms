

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
/*Đồ thị bằng mảng*/
#define INIT_VAL INT_MIN
#define INF 3.402823466e+38F /* max value */
/// <summary>
/// Tạo đồ thị mới với n đỉnh
/// 1 mảng có thể hiểu là con trỏ tới phần tử đầu tiên của mảng đó: int *vertices tương tự int vertices[]
/// **vertices là con trỏ tới mảng đó ( muốn thay đổi giá trị của 1 biến, ta cần tryền vào con trỏ trỏ tới nó)
/// 
/// mảng 2 chiều là 1 mảng 1 chiều chứa các phần tử là con trỏ tới nhiều mảng 1 chiều khác
/// vd ta có mảng 2 chiều A có m dòng x n cột
/// A = {*cột 1, *cột 2,..} m phần tử
/// tương tự **edges có thể coi như là mảng 2 chiều với ***edges là con trỏ tới mảng đó
/// </summary>
/// <param name="n">số đỉnh cần tạo</param>
/// <param name="vertices">con trỏ mảng 1 chiều chứa danh sách các đỉnh</param>
/// <param name="edges">con trỏ mảng 2 chiều chứa danh sách các cạnh</param>
void create_graph(int n, int** vertices, float*** edges) {
	//Calloc là cấp phát bộ nhớ cho mảng
	//int *A = (int*)calloc(n, sizeof(int)); tương tự int A[n];
	*vertices = (int*)calloc(n, sizeof(int));
	*edges = (float**)calloc(n, sizeof(float*));
	//lặp qua n phần tử
	for (int i = 0; i < n; i++) {
		//tạo các cột cho mảng 2 chiều
		(*edges)[i] = (float*)calloc(n, sizeof(float));
		//cho giá trị ban đầu của các đỉnh = 0
		(*vertices)[i] = INT_MIN;
		for (int j = 0; j < n; j++)
		{
			(*edges)[i][j] = 0.f;
		}
	}
	//Cả hàm này có thể thay thế bằng đoạn dưới đây với n là hằng số (trên là n thay đổi đc)
	/*
	void create_graph(int n, int vertices[n], float edges[n][n]) {
		for (int i = 0; i < n; i++) {
		vertices[i] = 0;
		for (int j = 0; j < n; j++)
		{
			edges[i][j] = 0;
		}
	}
	
	}
	*/

	
}
/// <summary>
/// Kiểm tra xem đã có value trong mảng hay chưa
/// </summary>
/// <param name="arr">mảng cần kiểm tra</param>
/// <param name="value">giá trị cần kiểm tra</param>
/// <returns>true nếu có, false nếu không</returns>
bool exist(int value,int* arr,int n ) {
	for (int i = 0; i < n; i++)if (value == arr[i])return true;
	return false;
}

/// <summary>
///Kiểm tra đỉnh x và y có cạnh nhau hay không
/// </summary>
/// <param name="x">đỉnh x</param>
/// <param name="y">đỉnh y</param>
/// <param name="edges">mảng cạnh</param>
bool adjacent(int x, int y,int **edge) {
	return edge[x][y] != 0.f;
}

/// <summary>
///Thêm đỉnh vào đồ thị
/// </summary>
/// <param name="n">số đỉnh hiện tại</param>
/// <param name="vertices">mảng đỉnh</param>
/// <param name="value">giá trị cần thêm</param>
bool add_vertex(int value,int* vertices, int n) {
	//nếu đã có đỉnh này thì return false
	if (exist(value, vertices, n))return false;
	//nếu chưa có đỉnh này thì thêm vào
	//Lặp qua mảng đỉnh, tìm vị trí có giá trị là INT_MIN (đỉnh chưa có)
	for (int i = 0; i < n; i++)
	{
		if (vertices[i] == INIT_VAL)
		{
			//Nếu tìm thấy vị trí có giá trị là INT_MIN thì thêm giá trị vào đó
			vertices[i] = value;
			//trả lại true nếu thêm được, false nếu không thêm được
			return true;
		}
	}
	return false;
}
/// <summary>
///Thêm cạnh vào đồ thị
/// </summary>
/// <param name="x">đỉnh x</param>
/// <param name="y">đỉnh y</param>
/// <param name="edges">mảng cạnh</param>
/// <param name="distance">khoảng cách giữa 2 đỉnh</param>
/// <param name="n">số đỉnh hiện tại</param>
void add_edge(int x, int y,float distance, float** edges, int n) {
	edges[x][y] = distance;
	edges[y][x] = distance;
}

/// <summary>
///Tìm thứ tự đỉnh có giá trị value
/// </summary>
/// <param name="value">giá trị cần tìm</param>
/// <param name="vertices">mảng đỉnh</param>
/// <param name="n">số đỉnh hiện tại</param>
int index(int value, int* vertices, int n) {
	for (int i = 0; i < n; i++)if (value == vertices[i])return i;
	return -1;
}

/// <summary>
/// Xóa đỉnh có giá trị value
/// </summary>
/// <param name="value">giá trị cần xóa</param>
/// <param name="vertices">mảng đỉnh</param>
/// <param name="n">số đỉnh hiện tại</param>
/// <param name="edges">mảng cạnh</param>
void delete_vertex(int value, int* vertices, int n, int** edges) {
	int idx = index(value, vertices, n);
	if (idx == -1)return;
	vertices[idx] = INIT_VAL;
	for (int i = 0; i < n; i++)
	{
		edges[i][idx] = 0.f;
		edges[idx][i] = 0.f;
	}
}




/// <summary>
///Duyệt đồ thị theo bfs
/// </summary>
/// <param name="start">đỉnh bắt đầu</param>
/// <param name="vertices">mảng đỉnh</param>
/// <param name="n">số đỉnh hiện tại</param>
/// <param name="edges">mảng cạnh</param>
void BFS(int start, int* vertices, int n, float** edges) {
	//Tạo mảng đỉnh đã duyệt
	bool *visited = (bool*)calloc(n, sizeof(bool));
	//tạo hàng đợi
	int *queue = (int*)calloc(n, sizeof(int));
	int front = 0, rear = 0;
	//thêm đỉnh bắt đầu vào hàng đợi, cộng 1 vào rear sau khi thêm
	queue[rear++] = start;
	visited[start] = true;
	//Lặp vòng lặp while, khi hàng đợi không rỗng
	while (front != rear) {
		//Lấy đỉnh đầu tiên trong hàng đợi
		int u = queue[front++];
		//In ra đỉnh đó
		printf("%d ", vertices[u]);
		//Lặp qua tất cả các đỉnh
		for (int i = 0; i < n; i++)
		{ 	//nếu đỉnh i kề với đỉnh u và chưa được duyệt
			if (adjacent(u, i, edges) && !visited[i])
			{	
				//thêm đỉnh i vào hàng đợi
				queue[rear++] = i;
				visited[i] = true;
			}
		}
	}
	//Xóa mảng đỉnh đã duyệt và hàng đợi
	free(visited);
	free(queue);
	printf("\n");
}

/// <summary>
///Duyệt đồ thị theo dfs
/// </summary>
/// <param name="start">đỉnh bắt đầu</param>
/// <param name="vertices">mảng đỉnh</param>
/// <param name="n">số đỉnh hiện tại</param>
/// <param name="edges">mảng cạnh</param>
void DFS(int start, int* vertices, int n, float** edges) {
	//Tạo mảng đỉnh đã duyệt, nếu chưa được duyệt thì giá trị là false, đã duyệt thì giá trị là true
	bool *visited = (bool*)calloc(n, sizeof(bool));
	//Tạo stack
	int *stack = (int*)calloc(n, sizeof(int));
	int top = 0;
	//thêm đỉnh bắt đầu vào stack, cộng 1 vào top sau khi thêm
	stack[top++] = start;
	visited[start] = true;
	//Lặp vòng lặp while, khi stack không rỗng
	while (top != 0) {
		//Lấy đỉnh đầu tiên trong stack
		int u = stack[--top];
		//In ra đỉnh đó
		printf("%d ", vertices[u]);
		//Lặp qua tất cả các đỉnh
		for (int i = 0; i < n; i++)
		{
			//nếu đỉnh i kề với đỉnh u và chưa được duyệt
			if (adjacent(u, i, edges) && !visited[i])
			{
				//thêm đỉnh i vào stack
				stack[top++] = i;
				//đánh dấu đỉnh i là đã duyệt
				visited[i] = true;
			}
		}
	}
	//Xóa mảng đỉnh đã duyệt và stack
	free(visited);
	free(stack);
	printf("\n");
}

/// <summary>
/// Tìm đường đi ngắn nhất tới tất cả các đỉnh theo thuật toán Dijkstra
/// </summary>
/// <param name="start">đỉnh bắt đầu</param>
/// <param name="vertices">mảng đỉnh</param>
/// <param name="n">số đỉnh hiện tại</param>
/// <param name="edges">mảng cạnh</param>
void Dijkstra(int start, int* vertices, int n, float** edges) {

	//Tạo mảng float lưu đường đi từ đỉnh bắt đầu tới các đỉnh khác
	float *dist = (float*)calloc(n, sizeof(float));
	//Tạo mảng lưu đỉnh trước đỉnh hiện tại
	int *prev = (int*)calloc(n, sizeof(int));
	//Tạo mảng đỉnh đã duyệt, nếu chưa được duyệt thì giá trị là false, đã duyệt thì giá trị là true
	bool *visited = (bool*)calloc(n, sizeof(bool));
	//Khởi tạo các giá trị cho mảng dist, prev
	for (int i = 0; i < n; i++)
	{
		dist[i] = INF;
		prev[i] = -1;
	}
	//Thêm đỉnh bắt đầu vào mảng đã duyệt
	dist[start] = 0;
	int u = start;
	//Lặp vòng lặp while, cho đến khi đã tìm hết đường đi tới tất cả các đỉnh
	while (true) {
		//đánh dấu đỉnh u là đã duyệt
		visited[u] = true;
		//Lặp qua tất cả các đỉnh
		for (int i = 0; i < n; i++)
		{
			//nếu đỉnh i kề với đỉnh u và chưa được duyệt, và đường đi từ u đến i nhỏ hơn đường đi từ u đến i trước đó
			if (adjacent(u, i, edges) && !visited[i] && dist[i] > dist[u] + edges[u][i])
			{
				//cập nhật đường đi từ u đến i
				dist[i] = dist[u] + edges[u][i];
				prev[i] = u;
			}
		}
		float min = INF;
		for (int i = 0; i < n; i++)
		{
			//Lặp qua tất cả các đỉnh, tìm đỉnh cần duyệt tiếp theo
			//Đỉnh cần duyệt tiếp là đỉnh có đường đi nhỏ nhất, chưa được duyệt
			if (!visited[i] && dist[i] < min)
			{
				min = dist[i];
				u = i;
			}
		}
		//DONE: check if all vertices are visited
		//Nếu đã duyệt hết các đỉnh
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (visited[i])count++;
		}
		//Thoát vòng lặp
		if (count == n)break;
	}
	//In ra kết quả
	printf("\n");
	for (int i = 0; i < n; i++)
	{
		printf("%d -> %d: %.1f\n", vertices[start], vertices[i], dist[i]);
	}
}

int main() {
	//Khởi tạo đỉnh
	int* vertices;
	//Khởi tạo mảng cạnh là mảng 2 chiều
	float** edges;
	//Khởi tạo số đỉnh
	int n  = 5;
	//Tạo đồ thị
	create_graph(n, &vertices, &edges);
	//Thêm đỉnh vào đồ thị
	for (int i = 0; i < n; i++)
	{
		add_vertex(i, vertices, n);
	}
	//Thêm cạnh vào các đỉnh
	add_edge(0, 1, 1.f, edges, n);
	add_edge(0, 2, 2.f, edges, n);
	add_edge(1, 3, 3.f, edges, n);
	add_edge(2, 3, 4.f, edges, n);
	add_edge(3, 4, 5.f, edges, n);
	add_edge(4, 0, 6.f, edges, n);
	//In ra đồ thị
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			printf("%.1f ", edges[i][j]);
		}
		printf("\n");
	}
	//Chọn điểm bắt đầu là đỉnh có giá trị 0
	int start = index(0, vertices, n);
	//Duyệt đồ thị theo bfs và dfs
	BFS(start, vertices, n, edges); 
	DFS(start, vertices, n, edges);
	//Thuật toán dijkstra, tìm đường đi ngắn nhất từ đỉnh bắt đầu đến tất cả các đỉnh
	Dijkstra(start, vertices, n, edges);
}