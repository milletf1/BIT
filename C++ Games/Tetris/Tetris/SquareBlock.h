#pragma once
#include "blocktemplate.h"

ref class SquareBlock : public BlockTemplate
{
public:
	SquareBlock(Point^ startDrawPoint, Point^startOffset, Color startColor, Graphics^ startCanvas);
	virtual void Rotate() override;
	virtual void InitializeBlockArray(Point^ startDrawPoint) override;
};
