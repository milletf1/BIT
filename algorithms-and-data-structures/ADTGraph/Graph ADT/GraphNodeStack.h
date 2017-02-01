#pragma once

#include "GraphNode.h"

ref class GraphNodeStack
{
private:
	GraphNode^ head;
	GraphNode^ tail;
public:
	GraphNodeStack();

	void push(GraphNode^ v);
	GraphNode^ pop();
	GraphNode^ peek();

	bool isEmpty();
};
