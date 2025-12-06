#include <iostream>
using namespace std;

#define inf 99999
#define n 7

class dijkstragraph {
public:
    int v;
    int w[n][n];

    dijkstragraph(int vertices) {
        v = vertices;
        for (int i = 1; i <= v; i++)
            for (int j = 1; j <= v; j++)
                w[i][j] = (i == j ? 0 : inf);
    }

    void addedge(int u, int v2, int weight) {
        w[u][v2] = weight;
        w[v2][u] = weight;
    }

    void dijkstra(int start, int end) {
        int dist[n], visited[n], parent[n];

        for (int i = 1; i <= v; i++) {
            dist[i] = inf;
            visited[i] = 0;
            parent[i] = -1;
        }

        dist[start] = 0;

        for (int k = 1; k <= v; k++) {

            int u = -1, mindist = inf;

            for (int i = 1; i <= v; i++)
                if (!visited[i] && dist[i] < mindist) {
                    mindist = dist[i];
                    u = i;
                }

            visited[u] = 1;

            for (int i = 1; i <= v; i++) {
                if (w[u][i] < inf && dist[u] + w[u][i] < dist[i]) {
                    dist[i] = dist[u] + w[u][i];
                    parent[i] = u;
                }
            }
        }

        cout << "\nShortest Distance (B to E): " << dist[end] << endl;

        cout << "Path: ";
        int path[n], idx = 0;
        for (int i = end; i != -1; i = parent[i])
            path[idx++] = i;
        for (int i = idx - 1; i >= 0; i--)
            cout << path[i] << " ";
    }
};

int main() {
    dijkstragraph g(6);

    g.addedge(2, 1, 4);
    g.addedge(2, 3, 9);
    g.addedge(1, 4, 8);
    g.addedge(3, 4, 6);
    g.addedge(3, 5, 14);
    g.addedge(4, 6, 4);
    g.addedge(6, 5, 3);

    g.dijkstra(2, 5);

    return 0;
}
