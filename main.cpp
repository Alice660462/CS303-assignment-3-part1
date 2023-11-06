#include <iostream>
#include<iomanip>
#include<string>
#include"stack_balance.h"
using namespace std;



int main()
{
	stack_balance balance;

	cout << "Enter an exbpression: " << endl;
	string expression;
	while (getline(cin, expression) && expression != "") {
		if (balance.is_balanced(expression)) {
			cout << "is balanced" << endl;
			cout << "Postfix: " << balance.display(expression) << endl;
		}
		else {
			cout << "is not balanced" << endl;
		}
		cout << "Enter another expression: " << endl;
	}

	return 0;
}