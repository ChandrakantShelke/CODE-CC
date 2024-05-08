#include <iostream>
#include <list>
#include <string>

using namespace std;

// A class representing the graph
class Graph {
   int V;
   list<int> *graph; //array of list 

public:
	
   // Constructor
   // It initializes the number of vertices V and 
   //allocates memory for the adjacency list graph of size V.
   
   Graph(int V) {
   	
      this->V = V;
      
      graph = new list<int>[V];
      
   }

   // a function that will add an edge to the graph.
   void insertEdge(int u, int v) {
      graph[u].push_back(v);
      graph[v].push_back(u);
   }

   // Greedy algo of printing the colors
   void graphColoringAlgorithm() {
   	
   	//Step - 1
      string colorNames[] = {"Red", "Green", "Blue", "Yellow", "Orange", "Purple", "Pink", "Cyan", "Magenta", "Brown"};
	  int colorArray[V]; //Store the color assigned to the vertices 
	  colorArray[0] = 0;  // Assign 0 as the first vertex

	//step - 2 
      /*
      Assigning (-1) to the rest of the vertex means the rest of the colors are not yet assigned
      */
      for (int i = 1; i < V; i++)
         colorArray[i] = -1;

     /* A boolean array to track available colors during the coloring process. 
	    Initialized with false.
	 */
	 //Step-3
      bool temp[V];
      for (int i = 0; i < V; i++)
         temp[i] = false;
         
         
    //step-4
      for (int u = 1; u < V; u++) { 
         // an iterator to iterate over graph list except 1   
         
         //iterates over adjacency list 
         list<int>::iterator i;
         for (i = graph[u].begin(); i != graph[u].end(); i++)
         /*. If a neighboring vertex v of u already has a color assigned (colorArray[*i] != -1),
		  it marks the corresponding color as unavailable in the temp array.
		  */
            if (colorArray[*i] != -1)
               temp[colorArray[*i]] = true;

//minimum available color j by iterating through the temp array

		//step - 5
         int j;
         for (j = 0; j < V; j++)
            if (temp[j] == false)
               break;

		//step - 6
// it assigns this color to the current vertex u in the colorArray

         colorArray[u] = j;

		//step -7 
//After assigning the color, it resets the temp array for the next iteration.
         for (i = graph[u].begin(); i != graph[u].end(); ++i)
            if (colorArray[*i] != -1)
               temp[colorArray[*i]] = false;
      }

		//step-7
      // printing the assigned colors.
      for (int i = 0; i < V; i++)
         cout << "Vertex: " << i << " Color: " << colorNames[colorArray[i]] << endl;
   }
   
};

int main() {
   int V;
   cout << "Enter the number of vertices: ";
   cin >> V;

   Graph g(V);
   
   int u, v;
   char cont;
   
   do {
      cout << "Enter an edge (u v): ";
      cin >> u >> v;
      g.insertEdge(u, v);
      
      cout << "Do you want to enter another edge? (y/n): ";
      cin >> cont;
      
   } while (cont == 'y' || cont == 'Y');
   

   cout << "The assigned colors of the graph are:" << endl;
   g.graphColoringAlgorithm();

   return 0;
}
