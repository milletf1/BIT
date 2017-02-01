#pragma once
#include "BalancedBraces.h"
#define UNITS 12 
ref class BalancedBracesTest
{
private:
	bool unclosedBraceTest();
	bool startOpenBraceTest();
	bool emptyStringTest();
	bool closedBraceTest();
	bool charWithinClosedBraceTest();
	bool charOutsideClosedBraceTest();
	bool closedBraceInsideClosedBraceTest();
	bool closedBraceBesideClosedBraceTest();
	bool unclosedBraceBeforeClosedBraceTest();
	bool closedBraceBeforeUnclosedBraceTest();
	bool closedBraceBeforeOpenBraceTest();
	bool allCharsNoBraceTest();


public:
	BalancedBracesTest();
	String^ performTest();
};
