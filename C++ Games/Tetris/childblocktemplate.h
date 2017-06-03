#pragma once
#include "BlockTemplate.h"

ref class child : public BlockTemplate
{
public:
//constructor
	child(Point^ startDrawPoint, Point^startOffset, Color startColor, Graphics^ startCanvas);
	virtual void Rotate() override;
	virtual void InitializeBlockArray(Point^ startDrawPoint) override;
};
//add graphics^ startCanvas to BlockTemplate constructor before coding it DONE