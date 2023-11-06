#include <iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<stack>
#include<iterator>
#include"stack_balance.h"
using namespace std;

// the boolean function to check if the char is ( [ {.
bool stack_balance::is_open(char ch) {
	return OPEN.find(ch)!= string::npos;
}

// the boolean function to check if the char is ) ] }.
bool stack_balance::is_close(char ch) {
	return CLOSE.find(ch)!= string::npos;
}

// the boolean function to check if the char is + - * /.
bool stack_balance::is_operator(char ch) {
	return OPERATOR.find(ch) != string::npos;
}

// the boolean fucntion to check if the expression is balanced.
// while traversing the expression, if it's open, then push to the stack,
// if it's closed, compare current char to the top of the stack to see if they match.
// return true if they match, otherwise false.
bool stack_balance::is_balanced( string& expression) {
	stack<char>stack1;
	bool balance = true;
	string::iterator it = expression.begin();
	while (balance && it != expression.end()) {
		char next_char = *it;
		if (is_open(next_char)) {
			stack1.push(next_char);
		}
		else if (is_close(next_char)) {
			if (stack1.empty()) {
				return false;
			}
			else {
				char top_ch = stack1.top();
				stack1.pop();
				balance = OPEN.find(top_ch) == CLOSE.find(next_char);
			}
		}
		it++;
	}return balance && stack1.empty();
}


// the function display a string of a postfixed equation equivalent to the balanced expression.
string stack_balance::display( string& expression) {
	stack<string> stack1;
	stack<char> stack2;
	string::iterator it = expression.begin();
	istringstream tokens(expression);
	char next_char;
	while (tokens >> next_char) {
		if (isdigit(next_char)) {
			tokens.putback(next_char);
			int value;
			tokens >> value;
			string str_val;
			str_val = to_string(value);
			stack1.push(str_val);
		}
		else if (is_operator(next_char) || is_open(next_char)) {
			stack2.push(next_char);
			string character;
			int number = 0;
			character = number;
		}
		else {
			while (is_operator(stack2.top())) {
				string top;
				top = stack2.top();
				stack2.pop();
				stack1.push(top);
			}
			stack2.pop();
		}
	}
	while (!stack2.empty()) {
		string top;
		top = stack2.top();
		stack1.push(top);
		stack2.pop();
	}
	string result= "";
	while (!stack1.empty()) {
		string item;
		item = stack1.top();
		result = item + " " + result;
		stack1.pop();
	}
	return result;
}