#include <iostream>
#include <queue>
using namespace std;

int adj_mat[50][50] = {0, 0};
int visited[50] = {0};

void dfs(int s, int n, string arr[]) {
    visited[s] = 1;
    cout << arr[s] << " ";
    for (int i = 0; i < n; i++) {
        if (adj_mat[s][i] && !visited[i])
            dfs(i, n, arr);
    }
}

void bfs(int s, int n, string arr[]) {
    queue<int> bfsq;
    bfsq.push(s);
    visited[s] = 1;

    while (!bfsq.empty()) {
        int v = bfsq.front();
        bfsq.pop();
        cout << arr[v] << " ";

        for (int i = 0; i < n; i++) {
            if (adj_mat[v][i] && !visited[i]) {
                bfsq.push(i);
                visited[i] = 1;
            }
        }
    }
}

int main() {
    cout << "Enter no. of cities: ";
    int n, u;
    cin >> n;
    string cities[n];
    for (int i = 0; i < n; i++) {
        cout << "Enter city #" << i + 1 << " (Airport Code): ";
        cin >> cities[i];
    }

    cout << "\nYour cities are: " << endl;
    for (int i = 0; i < n; i++)
        cout << "city #" << i + 1 << ": " << cities[i] << endl;

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cout << "Enter distance between " << cities[i] << " and " << cities[j] << " : ";
            cin >> adj_mat[i][j];
            adj_mat[j][i] = adj_mat[i][j];
        }
    }

    cout << endl;
    for (int i = 0; i < n; i++)
        cout << "\t" << cities[i] << "\t";
    for (int i = 0; i < n; i++) {
        cout << "\n" << cities[i];
        for (int j = 0; j < n; j++)
            cout << "\t" << adj_mat[i][j] << "\t";
        cout << endl;
    }

    cout << "Enter Starting Vertex (1 to " << n << "): ";
    cin >> u;
    if (u < 1 || u > n) {
        cout << "Invalid starting vertex!" << endl;
        return 1;
    }

    cout << "DFS: ";
    dfs(u - 1, n, cities);
    cout << endl;
    cout << "BFS: ";
    bfs(u - 1, n, cities);

    return 0;
}

