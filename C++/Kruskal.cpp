#include <iostream>
using namespace std;
#define V 4

int parent[V];

int find(int i) {
  while (parent[i] != i)
    i = parent[i];
  return i;
}
void union1(int i, int j) {
  int a = find(i);
  int b = find(j);
  parent[a] = b;
}
void kruskalMST(int graph[V][V]) {
  int mincost = 0;

  for (int i = 0; i < V; i++)
    parent[i] = i;

  int edge_count = 0;
  while (edge_count < V - 1) {
    int min = INT_MAX, a = -1, b = -1;
    for (int i = 0; i < V; i++) {
      for (int j = 0; j < V; j++) {
        if (find(i) != find(j) && graph[i][j] < min) {
          min = graph[i][j];
          a = i;
          b = j;
        }
      }
    }
    union1(a, b);
    cout << "Edge " << edge_count++ << ":(" << a << ", "<< b << ") cost:" << min << endl;
    mincost += min;
  }
  cout << "\n Minimum graph= " << mincost << endl;
}
int main() {
  int graph[V][V] = {
    {INT_MAX,10,6,5},
    {10,INT_MAX,INT_MAX,15},
    {6,INT_MAX,INT_MAX,4},
    {5,15,4,INT_MAX},
  };
  kruskalMST(graph);
  return 0;
}