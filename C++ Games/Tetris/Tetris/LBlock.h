#pragma once
#include "blocktemplate.h"

ref class LBlock :
public BlockTemplate
{
public:
	LBlock(Point^ startDrawPoint, Point^startOffset, Color startColor, Graphics^ startCanvas);
	virtual void Rotate() override;	
	virtual void InitializeBlockArray(Point^ startDrawPoint) override;	
};
