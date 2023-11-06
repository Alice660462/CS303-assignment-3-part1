#pragma once
#include <iostream>
#include<stack>
using namespace std;

#ifndef STACK_BALANCE
#define STACK_BALANCE
struct stack_balance {
	string OPERATOR = "+-*/";
	string OPEN = "([{";
	string CLOSE = ")]}";
	bool is_operator(char ch);
	bool is_open(char ch);
	bool is_close(char ch);
	bool is_balanced(string& expression);
	string display(string& expression);
};

#endif
