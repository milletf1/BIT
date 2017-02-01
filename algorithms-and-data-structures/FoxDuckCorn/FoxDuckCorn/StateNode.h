#pragma once

using namespace System;

ref class StateNode
{
private:
	String^ state;
	int nodeId;
	bool endCondition;

public:
	StateNode(String^ nState, int nNodeId, bool b);

	String^ getState()				{ return state; }
	void setState(String^ s)		{ state = s; }

	int getNodeId()					{ return nodeId; }
	void setNodeId(int i)			{ nodeId = i; }

	bool getEndCondition()			{ return endCondition; }
	void setEndCondition(bool b)	{ endCondition = b; }
};
