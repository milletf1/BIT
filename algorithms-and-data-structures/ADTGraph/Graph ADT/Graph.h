#pragma once

#include "GraphNode.h"
#include "GraphNodeStack.h"

#define MAXSYMBOLS 16
#define DEFAULT_SEPARATION 50
#define DEFAULT_DIAMETER 100
#define SLEEP_TIME 2000
#define WEIGHT_OFFSET 10
#define INFINITY 99999
#define NULLNEIGHBOUR -1

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;


ref class Graph
{
  private:
    int nodeCount;									// track the number of nodes in the graph
	array<GraphNode^>^ nodeArray;					// array to hold the nodes in the graph
    array<int, 2>^ adjacencyMatrix;			// array to hold the adjacency matrix. Note odd syntax. See constructor for generation code
    Graphics^ targetCanvas;

	array<Point^>^ locationTable;				// where to draw the nodes for a tidy layout
    
	int findUnvisited(int startNode);				// utility method for traversal. See code
	array<bool>^ visitedArray;						// utility array for traversal. See code

    
  public:

    //assortment of constructors that one might want to have
	Graph(int startNodeCount, Graphics^ startTargetCanvas); // creates a set of generic nodes. Graph built by entries in the adjMatrix
    Graph(int startNodeCount, array<GraphNode^>^ startNodeArray, Graphics^ startTargetCanvas); // accepts a premade array of nodes
    Graph(int startNodeCount, array<GraphNode^>^ startNodeArray, array<int, MAXSYMBOLS>^ startAdjacencyMatrix, Graphics^ startTargetCanvas);  // premade edge matrix as well
 
	void makeDemoGraph();
	
	// useful set and get methods

    int getNodeCount()								{return nodeCount;}
    
	// returns the weight of the edge between nodes n1 and n2. This value is stored in the adjacencyMatrix 2D array
	int getWeight(int n1, int n2)					{return adjacencyMatrix[n1,n2];}

   
	// Methods to modify the graph by adding/deleting nodes and edges

	void addNode(GraphNode^ newNode);                     // adds a premade node
    void addNode(String^ newLabel, Color newColor);        // creates and adds a node with specified label and color. Uses default diameter
    void addEdge(int node1, int node2, int weight);        // for an undirected graph, add the recipricol edge as well
    void deleteEdge(int node1, int node2);
    void clearEdges();

    // display the graph.
	void drawGraph();
	void drawEdge(int v1, int v2, Color edgeColour);

	// Depth first traversal. Print visited nodes in order
    void traverseGraph(ListBox^ targetListBox);
};
