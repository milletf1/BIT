#pragma once
#include "blocktemplate.h"

ref class ZBlock :
public BlockTemplate
{
public:
	ZBlock(Point^ startDrawPoint, Point^startOffset, Color startColor, Graphics^ startCanvas);
	virtual void Rotate() override;
	virtual void InitializeBlockArray(Point^ startDrawPoint) override;
};
