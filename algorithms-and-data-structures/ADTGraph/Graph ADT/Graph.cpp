#include "StdAfx.h"
#include "Graph.h"

//----------------------------------------------------------------------------------------------------------------------
// This form of the constructor creates a set of generic nodes. The graph is  built by adding values to the adjMatrix
// This is useful to have for developing methods and testing
//-----------------------------------------------------------------------------------------------------------------------
Graph::Graph(int startNodeCount, Graphics^ startTargetCanvas)
{
	// allocate memory for the main arrays
	nodeArray = gcnew array<GraphNode^>(MAXSYMBOLS);				// array to hold the nodes in the graph
    adjacencyMatrix = gcnew array<int, 2>(MAXSYMBOLS, MAXSYMBOLS);	// array to hold the adjacency matrix. Note odd syntax. 

	// clean out the main arrays
	for (int i=0; i< MAXSYMBOLS; i++)
		nodeArray[i] = nullptr;

	for (int col=0; col<MAXSYMBOLS; col++)
		for (int row=0; row<MAXSYMBOLS; row++)
			adjacencyMatrix[col,row] = 0;

	// store the parameter values in the corresponding class properties
	nodeCount = startNodeCount;
	targetCanvas = startTargetCanvas;

	// need an array to keep track of who has been visited during traversal. Two methods need to see it (cf. code below), so make it a property of the class
	visitedArray = gcnew array<bool>(MAXSYMBOLS);

	// set up the locations for the nodes so that they sit nicely on the screen
	locationTable = gcnew array<Point^>(MAXSYMBOLS);

	locationTable[0] = Point(100,100);
	locationTable[1] = Point(600,100);
	locationTable[2] = Point(100,400);
	locationTable[3] = Point(600,400);
	locationTable[4] = Point(230,200);
	locationTable[5] = Point(460,200);
	locationTable[6] = Point(230,300);
	locationTable[7] = Point(460,300);
	locationTable[8] = Point(100,200);
	locationTable[9] = Point(600,200);
	locationTable[10]= Point(100,300);
	locationTable[11]= Point(600,300);
	locationTable[12]= Point(230,100);
	locationTable[13]= Point(230,400);
	locationTable[14]= Point(460,100);
	locationTable[15]= Point(460,400);
	
} // end generic constructor


Graph::Graph(int startNodeCount, array<GraphNode^>^ startNodeArray, Graphics^ startTargetCanvas)
{
	// left as an exercise
}

Graph::Graph(int startNodeCount, array<GraphNode^>^ startNodeArray, array<int, MAXSYMBOLS>^ startAdjacencyMatrix, Graphics^ startTargetCanvas)
{
	// left as an exercise
}

//-----------------------------------------------------------------------------------
// Make a demo graph for testing
//-----------------------------------------------------------------------------------
void Graph::makeDemoGraph()
{
	//create the set of generic nodes

	Random^ randGen = gcnew Random();			// for random node colour generation if you wanted to

	for (int i=0; i<nodeCount; i++)
	{
		int newLeft = locationTable[i]->X;
		int newTop = locationTable[i]->Y;

		Color newColor = Color::FromArgb(0, 225, 180);
		String^ newLabel = "Node" + Convert::ToString(i);

		nodeArray[i] = gcnew GraphNode(newLeft, newTop, DEFAULT_DIAMETER, newColor, newLabel, targetCanvas);
		nodeArray[i]->setNodeId(i);
	}

	// add the edges
	addEdge(0,1,1);
	addEdge(1,3,2);
	addEdge(1,5,3);
	addEdge(0,4,4);
	addEdge(4,6,5);
	addEdge(6,7,4);
	addEdge(0,1,3);
	addEdge(6,2,2);
}

//-----------------------------------------------------------------------------------
// addNode adds a prepared node to the nodeArray
//-----------------------------------------------------------------------------------
void Graph::addNode(GraphNode^ newNode)
{
  ++nodeCount;
  nodeArray[nodeCount] = newNode;
}

//-----------------------------------------------------------------------------------
// addNode version to accept node data and create and add the node
//-----------------------------------------------------------------------------------
void Graph::addNode(String^ newLabel, Color newColor)
{
	// OPTIONAL EXERCISE
	// needs to figure out left and top for the new node, create it and add it
}

//-----------------------------------------------------------------------------------
// addEdge adds a new edge to the graph. This is accomplished by modifying the
// value(s) in the adjacency matrix that represents the edge between the two nodes
//-----------------------------------------------------------------------------------
void Graph::addEdge(int node1, int node2, int weight)
{
  adjacencyMatrix[node1,node2] = weight;

  // for an undirected graph only, you would need to add the symmetric edge
	adjacencyMatrix[node2,node1] = weight;
}



//----------------------------------------------------------------------------------------------
// deleteEdge removes an edge from the graph by setting the corresponding adjMatrix entry to 0
//----------------------------------------------------------------------------------------------
void Graph::deleteEdge(int node1, int node2)
{
  adjacencyMatrix[node1,node2] = 0;
}

//----------------------------------------------------------------------------------------------
// clearEdges empties the graph by deleting all the edges
//----------------------------------------------------------------------------------------------
void Graph::clearEdges()
{
  for (int i=0; i<MAXSYMBOLS; i++)
    for (int j=0; j<MAXSYMBOLS; j++)
      deleteEdge(i,j);
}

//=============================================================================================
// Traversal and traversal utility methods
//=============================================================================================

//----------------------------------------------------------------------------------------------
// findUnvisited: Accepts a node index and returns the index of the first unvisited neighbour
//----------------------------------------------------------------------------------------------
int Graph::findUnvisited(int startNode)
{
  int foundNode = -1;

  for (int i = 0; i < nodeCount; i++)
  {
    // if not looking at your self, and there is an edge, and that neighbour hasn't been visited...
    if ((i != startNode) && (adjacencyMatrix[startNode,i]) && (!visitedArray[i]))
    {
      foundNode = i;
      break;
    }
  }
  return foundNode;
}

//----------------------------------------------------------------------------------------------
// Depth-First traversal of the graph. Animated by highlighting the nodes as they are touched
// Run the traversal with a stack. We can manage the nodes via their indices in nodeArray, so we
// just push ints onto the stack
//----------------------------------------------------------------------------------------------

void Graph::traverseGraph(ListBox^ targetListBox)
{	
	targetListBox->Items->Clear();

	// Set each bool in the visited array to false.
	for each(bool^ b in visitedArray) 
		b = false;

	// Generate a node stack.
	GraphNodeStack^ stack = gcnew GraphNodeStack();

	// Set the starting node to the first node in the nodeArray.
	GraphNode^ v = nodeArray[0];
	stack->push(v);
	visitedArray[v->getNodeId()] = true;

	while(!stack->isEmpty())
	{
		// Get the node on top of the stack.
		GraphNode^ currV = stack->peek();

		// Display node label and highlight node.
		targetListBox->Items->Add(currV->getNodeLabel());		
		currV->highlightNode();
		targetListBox->Refresh();
		Threading::Thread::Sleep(500);

		// bool used to determine if this node has visited all its neighbors.
		bool visitedAllNeighbours = true;

		// check if node currV shares an edge with other nodes in the graph.
		for(int i = 0; i < MAXSYMBOLS; i++)
		{
			// if the current node shares an edge and its neighbour hasn't been visited...
			if(adjacencyMatrix[currV->getNodeId(), i] > 0 && visitedArray[i] == false)
			{
				// ...push the new node onto the stack.
				GraphNode^ u = nodeArray[i];
				stack->push(u);

				// record the node as visited
				visitedArray[i] = true;

				// and set the visited all neighbours bool as false
				visitedAllNeighbours = false;

				// display data.
				String^ traverseData = currV->getNodeLabel() + " is travelling to " + u->getNodeLabel();
				targetListBox->Items->Add(traverseData);
				targetListBox->Refresh();
				Threading::Thread::Sleep(500);

			}
		}
		// if the node currV has visited all its neighbors...
		if(visitedAllNeighbours)
		{
			// ...pop it off the stack
			stack->pop();	
			
			// and output this data to the listbox
			String^ traverseData = currV->getNodeLabel() + " has travelled to all neighbours ";
			targetListBox->Items->Add(traverseData);
			targetListBox->Refresh();
			Threading::Thread::Sleep(500);
		}
	}
}

//==================================================================================
// drawGraph displays the graph
// First the nodeArray is looped over, and every node is asked to draw itself
// Then the adjacency matrix is looped over. For each non-zero value at the intersection
// of a column and row, an edge is drawn between the column vertex and the row vertex
//==================================================================================
void Graph::drawGraph()
{

	// create a pen to draw the edges
	Pen^ edgePen = gcnew Pen(Color::Black);
	edgePen->Width = 3;

	for (int i=0; i<nodeCount; i++)
		nodeArray[i]->drawNode();

	for (int node1=0; node1<nodeCount; ++node1)
		for(int node2=0; node2<nodeCount; ++node2)
		{
			int currWeight = adjacencyMatrix[node1,node2];
			if (currWeight > 0)
			{
				// work out end points for the edges. In each case end point is the center of the vertex
				int radius = DEFAULT_DIAMETER/2;
				int startX = nodeArray[node1]->getNodeLeft() + radius;
				int startY = nodeArray[node1]->getNodeTop() + radius;
				int endX = nodeArray[node2]->getNodeLeft() + radius;
				int endY = nodeArray[node2]->getNodeTop() + radius;

				// draw the line

				targetCanvas->DrawLine(edgePen,startX,startY,endX,endY);

		        // draw the weight

				// prepare the font object. Could do this in the constructor if you want the node to hold onto it (as with the Brush and Pen)
				System::Drawing::Font^ weightFont = gcnew Font("Garamond", 12,FontStyle::Bold);

				// Need a brush to draw the text
				System::Drawing::SolidBrush^ weightBrush = gcnew SolidBrush(Color::Black);
	
				// compute the location of the edge label (this is rough)
		        int weightX = ((startX + endX)/2) - WEIGHT_OFFSET;
				int weightY = ((startY + endY)/2) + WEIGHT_OFFSET;

				// write out the label to the computed locations
				targetCanvas->DrawString(Convert::ToString(currWeight), weightFont, weightBrush, weightX, weightY);
			}
		}
}
//----------------------------------------------------------------------------------------------
// Used by the draw method
//----------------------------------------------------------------------------------------------
void Graph::drawEdge(int v1, int v2, Color edgeColour)
{
				int radius = DEFAULT_DIAMETER/2;
				int startX = nodeArray[v1]->getNodeLeft() + radius;
				int startY = nodeArray[v1]->getNodeTop() + radius;
				int endX = nodeArray[v2]->getNodeLeft() + radius;
				int endY = nodeArray[v2]->getNodeTop() + radius;

				// draw the line
				Pen^ edgePen = gcnew Pen(edgeColour);
				edgePen->Width = 4;
				targetCanvas->DrawLine(edgePen,startX,startY,endX,endY);
}

