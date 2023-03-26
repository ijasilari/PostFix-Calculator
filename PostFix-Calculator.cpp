#include<iostream>
#include<stack>
#include<math.h>
#include<ctype.h>
using namespace std;
int calculate(string);

int calculate(string input)
{
	stack <int> Stack;
	int len = input.length();

	for (int i = 0; i < len; i++)
	{
		if ( isdigit(input[i]) )
		{
			Stack.push( input[i] - 48);
		}
		else if(input[i] == 'x') {
			stack <int> tStack = Stack;

			int x = tStack.top();
			tStack.pop();
			int y = tStack.top();
			tStack.pop();

			tStack.push(x); tStack.push(y);

			tStack.swap(Stack);
		}
		else if(input[i] == 's')
		{
			int sum = 0;
			int size = Stack.size();
			for (int i = 0; i < size; i++) {
				sum += Stack.top();
				Stack.pop();
			}
			Stack.push(sum);
		}
		else if (input[i] == 'a')
		{
			int sum = 0;
			int size = Stack.size();
			int average = 0;

			for (int i = 0; i < size; i++) {
				sum += Stack.top();
				Stack.pop();
			}
			average = sum / size;
			Stack.push(average);
		}
		else if (input[i] == 'v')
		{
			int v = sqrt(Stack.top());
			Stack.pop();
			Stack.push(v);
		}
		else 
		{
			int x = Stack.top();
			Stack.pop();
			int y = Stack.top();
			Stack.pop();

			switch (input[i])
			{
			case '+':
				Stack.push(y + x);
				break;
			case '-':
				Stack.push(y - x);
				break;
			case '*':
				Stack.push(y * x);
				break;
			case '/':
				Stack.push(y / x);
				break;
			case '^':
				Stack.push(pow(y, x));
				break;
			case '%':
				Stack.push(y % x);
				break;
			}
		}
	}
	return Stack.top();
};

int main(int argc, char** argv)
{
	if (argc == 1) {
		cout << "Error: no arg" << endl;
		return 0;
	}
	string input = "";

	for (int i = 1; i < argc; i++) {
		input += argv[i];
	}

	if (input == "-p") {
		cout << "Input:";
		cin >> input;
		cout << "Answer: " << calculate(input) << endl;
	}
	else {
		cout << calculate(input) << endl;
	}
	return 0;
}
