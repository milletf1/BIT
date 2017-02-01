#include "StdAfx.h"
#include "StateNode.h"

StateNode::StateNode(String^ nState, int nNodeId, bool b)
{
	state = nState;
	nodeId = nNodeId;
}
