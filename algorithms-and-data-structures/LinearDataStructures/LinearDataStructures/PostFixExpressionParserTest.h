#pragma once
#include "PostfixExpressionParser.h"
#define UNITS 9
ref class PostFixExpressionParserTest
{
private:
	bool emptyStringTest();
	bool noOperatorOneIntTest();
	bool noOperatorManyIntTest();
	bool noIntOneOperatorTest();
	bool multiplicationTest();
	bool additionTest();
	bool manyOperatorTest();
	bool threeIntOneOperatorTest();
	bool oneIntOneOperatorTest();
	
public:
	PostFixExpressionParserTest(void);
	String^ performTest();
};
