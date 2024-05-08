#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>

using namespace std;

class Graph {
    vector<vector<int>> adj; // represent the adjacency list of the graph.

public:
    Graph(int n) : adj(n) {} //Constructor of the Graph class, 
	//which initializes the adjacency list with size n.

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfsUtil(int v, unordered_set<int>& visited) {
	// recursively traverses the graph starting from vertex v and marks visited vertices.
        visited.insert(v); // recursively traverses the graph starting from vertex v and marks visited vertices.
        cout << v << " ";

        for (int neighbor : adj[v])
		//Iterates through the neighbors of vertex v. 
		{
            if (visited.find(neighbor) == visited.end())//Checks if the neighbor is not visited yet.
			{
                dfsUtil(neighbor, visited);//unvisited neighbor.
            }
        }
    }

    void dfs(int start)// (DFS) traversal starting from vertex start.
	{
        unordered_set<int> visited;// Initializes an empty set to keep track of visited vertices.
        dfsUtil(start, visited); // Calls the dfsUtil function to start DFS traversal from the start vertex.
        cout << endl;
    }

    void bfs(int start) {
        unordered_set<int> visited;
        queue<int> q;
        q.push(start); //Pushes the start vertex into the queue to start BFS traversal.
        visited.insert(start);

        while (!q.empty()) {
            int current = q.front(); //Retrieves the front element of the queue.
            q.pop(); //Removes the front element from the queue
            cout << current << " ";

            for (int neighbor : adj[current]) //Iterates through the neighbors of the current vertex.
			{
                if (visited.find(neighbor) == visited.end()) {
                    q.push(neighbor);// Pushes the unvisited neighbor into the queue.
                    visited.insert(neighbor); //Marks the neighbor as visited.
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int n, e;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> e;

    Graph g(n); //Creates a Graph object with n vertices.

    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < e; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    int startNode;
    cout << "Enter the starting node for DFS and BFS: ";
    cin >> startNode;

    cout << "DFS: ";
    g.dfs(startNode);

    cout << "BFS: ";
    g.bfs(startNode);

    return 0;
}
