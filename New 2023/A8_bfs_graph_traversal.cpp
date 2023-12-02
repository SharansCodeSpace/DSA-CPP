#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Graph {
private:
    int vertices;
    vector<vector<int>> adjacencyList;
public:
    Graph(int v) : vertices(v), adjacencyList(v) {}
    void addEdge(int v, int w) {
        adjacencyList[v].push_back(w);
    }
    void BFS(int start) {
        vector<bool> visited(vertices, false);
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while (!q.empty()) {
            int current = q.front();
            cout << current << " ";
            q.pop();
            for (int neighbor : adjacencyList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);
    g.addEdge(2, 5);
    cout << "BFS starting from vertex 0: ";
    g.BFS(0);
    return 0;
}