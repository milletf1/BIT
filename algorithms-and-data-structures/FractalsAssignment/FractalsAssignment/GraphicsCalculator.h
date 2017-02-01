#pragma once

#define NINETY_DEGREES 90

using namespace System;
using namespace System::Drawing;


ref class GraphicsCalculator
{
public:

	float Radians;

	GraphicsCalculator();

	double calculateDistance(Point^ startPoint, Point^ endPoint);

	float getAngle(Point^ startPoint, Point^ endPoint);

	Point^ calculatePoint(Point^ startPoint, float radians, double distance);
};
