#pragma once
#include "blocktemplate.h"

ref class JBlock :
public BlockTemplate
{
public:
	JBlock(Point^ startDrawPoint, Point^startOffset, Color startColor, Graphics^ startCanvas);
	virtual void Rotate() override;
	virtual void InitializeBlockArray(Point^ startDrawPoint) override;
	
};
