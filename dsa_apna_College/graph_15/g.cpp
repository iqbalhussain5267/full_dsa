// #include <iostream>
// #include <list>

// using namespace std;
// class Graph
// {
//   int V;
//   list<int> *l;

// public:
//   Graph(int V)
//   {
//     this->V = V;
//     l = new list<int>[V];
//   }
//   void edges(int u, int v)
//   {
//     l[u].push_back(v);
//     l[v].push_back(u);
//   }
//   void printAdjcent()
//   {
//     for (int i = 0; i < V; i++)
//     {
//       cout <<  i<< " ";
//       for (int neigh : i[l])
//       {
//         cout << neigh << " ";
//       }
//       cout << endl;
//     }
//   }
// };

// int main()
// {
//   Graph g(5);
//   g.edges(0, 1);
//   g.edges(1, 2);
//   g.edges(1, 3);
//   g.edges(2, 3);
//   g.edges(2, 4);
//   g.printAdjcent();
//   return 0;
// }

// // bfs
// #include <iostream>
// #include <queue>
// #include <list>
// #include <vector> // Required for vector
// using namespace std;

// class Graph
// {
//   int V;
//   list<int> *l;

// public:
//   Graph(int V)
//   {
//     this->V = V;
//     l = new list<int>[V];
//   }

//   void edges(int u, int v)
//   {
//     l[u].push_back(v);
//     l[v].push_back(u);
//   }
//   // bfs  move to the first immediate univisited
//   void BFS(int src)
//   { // Made 'src' dynamic instead of hardcoding 0
//     queue<int> Q;
//     vector<int> Visited(V, false);

//     Q.push(src);
//     Visited[src] = true;

//     while (Q.size() > 0)
//     {
//       int u = Q.front();
//       Q.pop();
//       cout << u << " ";

//       for (int v : l[u])
//       {
//         if (!Visited[v])
//         {
//           Visited[v] = true;
//           Q.push(v);
//         }
//       }
//     }
//     cout << endl;
//   }
//   void dfsHelper(int u, vector<bool> &vis)
//   {
//     cout << u << " ";
//     vis[u] = true;
//     for (int v : l[u])
//     {
//       if (!vis[v])
//       {
//         dfsHelper(v, vis);
//       }
//     }
//   }
//   void dfs()
//   {
//     int src = 0;
//     vector<bool> vis(V, false);
//     dfsHelper(src, vis);
//   }
// };

// int main()
// {
//   Graph g1(5);
//   g1.edges(0, 1);
//   g1.edges(1, 2);
//   g1.edges(1, 3);
//   g1.edges(2, 4);

//   // cout << "BFS Traversal starting from vertex 0: ";
//   // g1.BFS(0);
//   cout << "DFS Traversal: ";
//   g1.dfs();
//   return 0;
// }



// cycle detect
#include <iostream>
#include <queue>
#include <list>
#include <vector>

using namespace std;

class Graph {
    int V; // Stores the number of vertices
    list<int> *l; // Pointer to an array containing adjacency lists

public:
    // Constructor to initialize the graph with V vertices
    Graph(int V) {
        this->V = V;
        l = new list<int>[V]; // Allocate memory for V adjacency lists
    }

    // Function to add an undirected edge between vertices u and v
    void edges(int u, int v) {
        l[u].push_back(v); // Add v to u's list
        l[v].push_back(u); // Add u to v's list (since it's an undirected graph)
    }

    // Helper function that performs BFS to detect a cycle in a specific component
    bool isCycleBFS(int src, vector<bool>& visited) {
        // Create a queue that stores pairs: {current_node, parent_node}
        queue<pair<int, int>> q; 

        // Mark the source vertex as visited
        visited[src] = true; 

        // Push the source vertex into the queue; its parent is set to -1
        q.push({src, -1}); 

        // Loop until the queue becomes empty
        while (!q.empty()) {
            // Extract the front element from the queue
            int node = q.front().first;   // Get the current node
            int parent = q.front().second; // Get the parent of the current node
            q.pop(); // Remove the element from the queue

            // Iterate through all the adjacent neighbors of the current node
            for (int neighbor : l[node]) {
                
                // If the neighbor has not been visited yet
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // Mark it as visited
                    q.push({neighbor, node}); // Push it to queue, setting 'node' as its parent
                }
                // If the neighbor is already visited AND it is not the parent of the current node,
                // it means we reached this neighbor via a different path. A cycle is detected!
                else if (neighbor != parent) {
                    return true; 
                }
            }
        }
        // Return false if no cycle is found in this component
        return false; 
    }

    // Main public function to check if the graph contains any cycle
    bool detectCycle() {
        // Initialize a visited vector of size V with all values set to false
        vector<bool> visited(V, false);

        // Loop through all vertices to handle disconnected graphs
        for (int i = 0; i < V; i++) {
            // If the vertex is not visited, run the BFS cycle detection on it
            if (!visited[i]) {
                // If BFS returns true, a cycle exists in the graph
                if (isCycleBFS(i, visited)) {
                    return true;
                }
            }
        }
        // Return false if no cycle is detected in any component of the graph
        return false;
    }
};

int main() {
    // Create a graph with 4 vertices (0, 1, 2, 3)
    Graph g(4);
    
    // Add edges to form a cycle: 0 - 1, 1 - 2, 2 - 3, 3 - 0
    g.edges(0, 1);
    g.edges(1, 2);
    g.edges(2, 3);
    g.edges(3, 0);

    // Call the function and print the result
    if (g.detectCycle()) {
        cout << "Graph contains a cycle." << endl;
    } else {
        cout << "Graph does not contain a cycle." << endl;
    }

    return 0;
}
