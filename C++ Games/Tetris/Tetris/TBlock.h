#pragma once
#include "blocktemplate.h"

ref class TBlock :
public BlockTemplate
{
public:
	TBlock(Point^ startDrawPoint, Point^startOffset, Color startColor, Graphics^ startCanvas);
	virtual void Rotate() override;	
	virtual void InitializeBlockArray(Point^ startDrawPoint) override;
};
