#include <iostream>
using namespace std;

#define max_vertices 10
#define max_deg 10

class graph {
public:
    int v;
    int adjlist[max_vertices][max_deg];
    int adjcount[max_vertices];
    int adjmatrix[max_vertices][max_vertices];

    graph(int vertices) {
        v = vertices;
        for (int i = 1; i <= v; i++) {
            adjcount[i] = 0;
            for (int j = 1; j <= v; j++)
                adjmatrix[i][j] = 0;
        }
    }

    void addedge(int u, int v2) {
        adjlist[u][adjcount[u]++] = v2;
        adjlist[v2][adjcount[v2]++] = u;

        adjmatrix[u][v2] = 1;
        adjmatrix[v2][u] = 1;
    }

    void displayadjlist() {
        cout << "Adjacency List:\n";
        for (int i = 1; i <= v; i++) {
            cout << i << " -> ";
            for (int j = 0; j < adjcount[i]; j++)
                cout << adjlist[i][j] << " ";
            cout << endl;
        }
    }

    void displayadjmatrix() {
        cout << "\nAdjacency Matrix:\n";
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++)
                cout << adjmatrix[i][j] << " ";
            cout << endl;
        }
    }

    void bfs(int start) {
        int visited[max_vertices] = {0};
        int queuearr[max_vertices], front = 0, rear = 0;

        cout << "\nBFS Traversal: ";
        queuearr[rear++] = start;
        visited[start] = 1;

        while (front < rear) {
            int node = queuearr[front++];
            cout << node << " ";

            for (int i = 0; i < adjcount[node]; i++) {
                int v2 = adjlist[node][i];
                if (!visited[v2]) {
                    visited[v2] = 1;
                    queuearr[rear++] = v2;
                }
            }
        }
    }

    void dfsutil(int node, int visited[]) {
        visited[node] = 1;
        cout << node << " ";

        for (int i = 0; i < adjcount[node]; i++) {
            int v2 = adjlist[node][i];
            if (!visited[v2])
                dfsutil(v2, visited);
        }
    }

    void dfs(int start) {
        int visited[max_vertices] = {0};
        cout << "\nDFS Traversal: ";
        dfsutil(start, visited);
        cout << endl;
    }
};

int main() {
    graph g(5);

    g.addedge(1, 2);
    g.addedge(1, 4);
    g.addedge(2, 4);
    g.addedge(2, 5);
    g.addedge(3, 5);
    g.addedge(4, 5);

    g.displayadjlist();
    g.displayadjmatrix();

    g.bfs(1);
    g.dfs(1);

    return 0;
}
