#include "StdAfx.h"
#include "GraphNode.h"

//-----------------------------------------------------------------------------------------------------------------------------
// GraphoNode constructor stores input parameters and creates the node's Brush and Pen
//-----------------------------------------------------------------------------------------------------------------------------
GraphNode::GraphNode(int startNodeLeft, int startNodeTop, int startNodeDiameter, Color startNodeColor, String^ startNodeLabel, Graphics^ startTargetCanvas)
{
  nodeLeft = startNodeLeft;
  nodeTop = startNodeTop;
  nodeDiameter = startNodeDiameter;
  nodeColor = startNodeColor;
  nodeLabel = startNodeLabel;
  targetCanvas = startTargetCanvas;

  nodeBrush = gcnew SolidBrush(nodeColor);
  nodePen = gcnew Pen(Color::Black);
  nodePen->Width = 3;

  Next = nullptr;
}

//-----------------------------------------------------------------------------------------------------------------------------
// drawNode() draws the node to targetCanvas
//-----------------------------------------------------------------------------------------------------------------------------

void GraphNode::drawNode()
{
	// create the RectangleF object to pass to the draw
	RectangleF nodeRect = RectangleF(nodeLeft,nodeTop,nodeDiameter,nodeDiameter);

	// Draw the fill
	targetCanvas->FillEllipse(nodeBrush,nodeRect);

	// Draw the stroke
	targetCanvas->DrawEllipse(nodePen, nodeRect);

	// compute where to draw the node label.
	// The x location for the label is the horizontal center of the node - an estimate of half the length of the label (subtraction => 'shift left')
	// The y location is the vertical center of the node
	int radius = nodeDiameter/2;
	int labelAdjustment = nodeLabel->Length * 5;
	int centreX = nodeLeft + radius - labelAdjustment;
	int centreY = nodeTop + radius;

	// prepare the font object. Could do this in the constructor if you want the node to hold onto it (as with the Brush and Pen)
	System::Drawing::Font^ labelFont = gcnew Font("Calibri", 12);

	// Need a brush to draw the text in, in a contrasting colour
	System::Drawing::SolidBrush^ labelBrush = gcnew SolidBrush(Color::Black);

  
	// write out the label to the computed locations
	targetCanvas->DrawString(nodeLabel, labelFont, labelBrush, centreX, centreY);
}

//-----------------------------------------------------------------------------------------------------------------------------
// change the node color for use in the animation
//-----------------------------------------------------------------------------------------------------------------------------
void GraphNode::highlightNode()
{
	Color oldColor = nodeBrush->Color;
	nodeBrush->Color = Color::Red;
	drawNode();
	nodeBrush->Color = oldColor;
}
