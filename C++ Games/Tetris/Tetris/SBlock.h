#pragma once
#include "blocktemplate.h"

ref class SBlock :
public BlockTemplate
{
public:
	SBlock(Point^ startDrawPoint, Point^startOffset, Color startColor, Graphics^ startCanvas);
	virtual void Rotate() override;
	virtual void InitializeBlockArray(Point^ startDrawPoint) override;
};
