#include<iostream>
#include<limits.h>
using namespace std;

# define V 5
// Number of vertices in the graph 
  
// Function to find the vertex with minimum key value
// from the set of vertices not yet included in MST 
int minKey(int key[], bool mstSet[]) // which represents the set of vertices included in the MST.
{ 
    // Initialize min value 
    int min = INT_MAX;
	int min_index; 
  
    for (int i = 0; i < V; i++){ 
        if (mstSet[i] == false && key[i] < min){ 
            min = key[i];
			min_index = i; 
        }
    }
  
    return min_index; 
} 
  
// Function to print constructed MST stored in parent[] 
void printMST(int parent[], int graph[V][V]) 
{   
    int cost = 0;
    cout<<"Edge \tWeight\n"; 
    for (int i = 1; i < V; i++){ 
        cout<<parent[i]<<" - "<<i<<" \t"<<graph[i][parent[i]]<<" \n";
        cost += graph[i][parent[i]]; 
    }
    cout<<"----------\n";
    cout<<"Cost = "<<cost<<endl;
} 
  
// Function to construct and print MST for a graph represented using 
// adjacency matrix representation 
void prims(int graph[V][V]) //take graph as input
{ 
    // Array to store constructed MST 
    int parent[V]; 
      
    // Key values used to pick minimum weight edge in cut 
    int key[V]; 
      
    // To represent set of vertices included in MST 
    bool mstSet[V]; 
  
    // Initialize all keys as INFINITE 
    for (int i = 0; i < V; i++){ 
        key[i] = INT_MAX;
		mstSet[i] = false; 
    }

    // Always include first 1st vertex in MST. 
    // Make key 0 so that this vertex is picked as first vertex. 
    key[0] = 0; 
    parent[0] = -1; // First node is always root of MST 
  
    // The MST will have V vertices 
    for (int count = 0; count < V - 1; count++)
    { 
        // Pick the minimum key vertex from the 
        // set of vertices not yet included in MST 
        int u = minKey(key, mstSet); 
  
        // Add the picked vertex to the MST Set 
        mstSet[u] = true; 
  
        // Update key value and parent index of 
        // the adjacent vertices of the picked vertex. 
        // Consider only those vertices which are not 
        // yet included in MST 
        for (int v = 0; v < V; v++){ 
  
            // graph[u][v] is non zero only for adjacent vertices of m 
            // mstSet[v] is false for vertices not yet included in MST 
            // Update the key only if graph[u][v] is smaller than key[v] 
            if ( graph[u][v]  &&  mstSet[v] == false &&  graph[u][v] < key[v] )
			{ 
                parent[v] = u; //u la parent banava 
				key[v] = graph[u][v]; //key la graph madhe include kara 
            }
        }
    } 
  
    // print the constructed MST 
    printMST(parent, graph); 
} 
  
int main() 
{ 
   /*					   0  1  2  3  4
    int graph[V][V] = { 0{ 0, 2, 0, 6, 0 },
                        1{ 2, 0, 3, 8, 5 },
                        2{ 0, 3, 0, 0, 7 },
                        3{ 6, 8, 0, 0, 9 },
                        4{ 0, 5, 7, 9, 0 } };
    // Print the solution 
    */
    
    
    int graph[V][V];
    cout << "Enter the adjacency matrix for the graph (" << V << "x" << V << "):" << endl;
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            cin >> graph[i][j];
        }
    }
    
    prims(graph); 
  
    return 0; 
}
