#pragma once

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

ref class GraphNode
{
 private:
    // assorted properties to allow the node to draw itself
	int nodeLeft;				
    int nodeTop;
    int nodeDiameter;
	Color nodeColor;
    Graphics^ targetCanvas;
	SolidBrush^ nodeBrush;
	Pen^ nodePen;

	// node data value. In this case just a string, but can be anything depending on the application
	String^ nodeLabel;

	int nodeId;

  public:
	  
	GraphNode^ Next;

    GraphNode(int startNodeLeft, int startNodeTop, int startNodeDiameter, Color startNodeColor, String^ startNodeLabel, Graphics^ startTargetCanvas);

	// display methods   
	void drawNode();
    void highlightNode();

	// sets and gets
    void setNodeLeft(int l)				{nodeLeft = l;}
    int getNodeLeft()					{return nodeLeft;}

    void setNodeTop(int t)				{nodeTop = t;}
    int getNodeTop()					{return nodeTop;}

    void setNodeDiameter(int d)			{nodeDiameter = d;}
    int getNodeDiameter()				{return nodeDiameter;}

    void setnodeColor(Color c)			{nodeColor = c;}
    Color getNodeColor()				{return nodeColor;}

    void setNodeLabel(String^ l)		{nodeLabel = l;}
    String^ getNodeLabel()				{return nodeLabel;}

	int getNodeId()					{return nodeId;}
	void setNodeId(int i)				{nodeId = i;}

    void setTargetCanvas(Graphics^ t)	{targetCanvas = t;}

};
