#pragma once
#include "IntStack.h"

using namespace System::Text::RegularExpressions;
ref class PostfixExpressionParser
{
private:
	static String^ INT_REGEX = "[0-9]{1}";
	static String^ OPERATOR_REGEX = "[\+\*]{1}";
public:
	PostfixExpressionParser();
	int evaluate(String^ s);
};
