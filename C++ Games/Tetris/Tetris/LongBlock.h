#pragma once
#include "blocktemplate.h"

ref class LongBlock : public BlockTemplate
{
public:
//constructor
	LongBlock(Point^ startDrawPoint, Point^startOffset, Color startColor, Graphics^ startCanvas);
	virtual void Rotate() override;
	virtual void InitializeBlockArray(Point^ startDrawPoint) override;
};
