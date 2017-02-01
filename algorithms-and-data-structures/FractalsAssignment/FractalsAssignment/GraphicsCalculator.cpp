#include "StdAfx.h"
#include "GraphicsCalculator.h"

GraphicsCalculator::GraphicsCalculator()
{
	Radians = Math::PI / 180;
}

/*****************************************************************************************
 * Precondition:  Both the startPoint and endPoint parameters must be initialized.
 * 
 * Postcondition: Calculates and returns the distance between the startPoint and endPoint 
 *				  parameters.
 ****************************************************************************************/
double GraphicsCalculator::calculateDistance(Point^ startPoint, Point^ endPoint)
{
	// Calculate the distance beween the x and y coordinates of startPoint and endPoint.
	double xD = endPoint->X - startPoint->X;
	double yD = endPoint->Y - startPoint->Y;
	
	// Calculate and return the distance between startPoint and endPoint.
	return  Math::Sqrt( Math::Pow(xD, 2) + Math::Pow(yD, 2) );
}

/***************************************************************************************
 * Precondition:  Both the startPoint and endPoint parameters must be initialized.
 * 
 * Postcondition: Calculates and returns the angle in radians between the startPoint and
 *				  endPoint parameters.
 ***************************************************************************************/
float GraphicsCalculator::getAngle(Point^ startPoint, Point^ endPoint)
{
	// Calculate the distance beween the x and y coordinates of startPoint and endPoint.
	double xD = endPoint->X - startPoint->X;
	double yD = endPoint->Y - startPoint->Y;
	
	// Calculate and return the radians between startPoint and endPoint.
	return Math::Atan2(yD, xD);
}

/**********************************************************************************
 * Precondition:  the startPoint parameter must be initialized.
 * 
 * Postcondition: Returns a point from the given startPoint, radians, and distance.
 **********************************************************************************/
Point^ GraphicsCalculator::calculatePoint(Point^ startPoint, float radians, double distance)
{
	 int endX = startPoint->X + Math::Cos(radians) * distance;
	 int endY = startPoint->Y + Math::Sin(radians) * distance;

	 return gcnew Point(endX, endY);
}

