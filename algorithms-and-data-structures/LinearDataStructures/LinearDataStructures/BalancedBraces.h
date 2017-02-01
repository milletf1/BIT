#pragma once
#include "charstack.h"
ref class BalancedBraces
{
private:
	static const Char OPEN_BRACE = '{';
	static const Char CLOSE_BRACE = '}';
	static const Char PUSH_CHAR = 'c';
public:
	BalancedBraces();
	bool isBalanced(String^ s);
};
