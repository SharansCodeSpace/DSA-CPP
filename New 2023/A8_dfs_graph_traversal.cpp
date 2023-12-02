#include <iostream>
#include <vector>
#include <stack>
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
    void DFS(int start) {
        vector<bool> visited(vertices, false);
        stack<int> s;
        visited[start] = true;
        s.push(start);
        while (!s.empty()) {
            int current = s.top();
            cout << current << " ";
            s.pop();
            for (int neighbor : adjacencyList[current]) {
                if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    s.push(neighbor);
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
    cout << "DFS starting from vertex 0: ";
    g.DFS(0);
    return 0;
}