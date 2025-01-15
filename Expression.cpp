#include <string>
#include<stack>
#include<iostream>
using namespace std;
//Orhan Güner - 152120201073 | Abdülkerim Pekince - 152120201021
///----------------------------------------------------------------------------------
/// Given an expression in infix-notation, converts it to a string in post-fix notation 
/// 

string Infix2Postfix(string& s) {
	string result;
	stack<char>op;
	for (int i = 0; i < s.length(); i++)
	{
		char c = s[i];

		if (c == '(')
		{
			op.push(c);
		}
		else if (c == ')')
		{
			while (op.top() != '(')
			{
				result += op.top();
				result += ' ';
				op.pop();
			}
			op.pop();
		}
		else if (c == '*')
		{
			if (op.empty())
			{
				op.push(c);
			}
			else if (op.top() == '*' || op.top() == '/') {
				while (op.top() == '*' || op.top() == '/') {
					result += op.top();
					result += ' ';
					op.pop();
					if (op.empty()) break;
				}
				op.push(c);
			}


			else
			{
				op.push(c);
				result += ' ';
			}

		}
		else if (c == '/')
		{
			if (op.empty())
			{
				op.push(c);
			}
			else if (op.top() == '*' || op.top() == '/') {
				while (op.top() == '*' || op.top() == '/') {
					result += op.top();
					result += ' ';
					op.pop();
					if (op.empty()) break;
				}
				op.push(c);
			}
			else {
				op.push(c);
				result += ' ';
			}
		}
		else if (c == '+')
		{
			if (op.empty())
			{
				op.push(c);
				result += ' ';
			}
			else
			{
				while (true)
				{
					if (op.empty())
					{
						break;
					}
					else if (op.top() == '(')
					{
						break;
					}
					else {
						result += op.top();
						result += " ";
						op.pop();
					}
				}
				op.push(c);
				result += ' ';
			}

		}
		else if (c == '-')
		{
			if (op.empty() || op.top() == '(')
			{
				op.push(c);
				result += ' ';
			}
			else
			{
				while (true)
				{
					if (op.empty())
					{
						break;
					}
					else if (op.top() == '(')
					{
						break;
					}
					else {
						result += op.top();
						result += ' ';
						op.pop();
					}
				}
				op.push(c);
				result += ' ';
			}

		}
		else if (c == ' ')
		{
			result += c;
		}
		else
		{
			while (c != ' ' && c != '+' && c != '-' && c != '*' && c != '/' && c != '(' && c != ')')
			{
				result += c;
				if (i == (s.length() - 1))
				{
					break;
				}
				else
				{
					i++;
					c = s[i];

				}


			}
			if (c == ' ' || c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')')
			{
				i--;
				c = s[i];
			}

		}

	}
	if (!op.empty())
	{
		while (!op.empty())
		{
			result += op.top();
			op.pop();
		}
	}
	return result;
} // end-Infix2Postfix

///----------------------------------------------------------------------------------
/// Given a string in post-fix notation, evaluates it and returns the result
/// 
int EvaluatePostfixExpression(string& s) {
	stack<int>numbers;
	int number1;
	int number2;
	int number;
	int strSize = s.length();
	for (int i = 0; i < strSize; i++)
	{
		char c = s[i];
		string cc;


		while (s[i] != ' ' && s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/')
		{

			cc += s[i];
			if (s[i + 1] == ' ' || s[i + 1] == '+' || s[i + 1] == '-' || s[i + 1] == '*' || s[i + 1] == '/')
			{
				int x = stoi(cc);
				numbers.push(x);
			}
			i++;
			c = s[i];

		}



		if (c == '*')
		{
			number1 = numbers.top();
			numbers.pop();
			number2 = numbers.top();
			numbers.pop();
			(number) = (number1) * (number2);
			numbers.push(number);
		}
		if (c == '/')
		{
			number1 = numbers.top();
			numbers.pop();
			number2 = numbers.top();
			numbers.pop();
			double(number) = double(number2) / double(number1);
			numbers.push(number);
		}
		if (c == '+')
		{
			number1 = numbers.top();
			numbers.pop();
			number2 = numbers.top();
			numbers.pop();
			number = number1 + number2;
			numbers.push(number);
		}
		if (c == '-')
		{
			number1 = numbers.top();
			numbers.pop();
			number2 = numbers.top();
			numbers.pop();
			number = number2 - number1;
			numbers.push(number);
		}
	}

	number = numbers.top();
	numbers.pop();
	return number;
} // end-EvaluatePostfixExpression