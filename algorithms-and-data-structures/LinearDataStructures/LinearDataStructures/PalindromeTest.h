#pragma once
#include "Palindrome.h"
#define UNITS 5
ref class PalindromeTest
{
private:
	bool emptyStringTest();
	bool evenUnbalancedTest();
	bool evenBalancedTest();
	bool oddUnbalancedTest();
	bool oddBalancedTest();
public:
	PalindromeTest(void);
	String^ performTest();
};
