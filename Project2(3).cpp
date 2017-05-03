/*Joshua Itagaki
Project2 (3 of 3)
Number Converter*/
#include <iostream>
#include <cstdlib>
using namespace std;

void push(int);
void pop();
void check_full();
void check_empty();

const int SIZE = 100;
int converter[SIZE];
int val, *ptr;
int top = 0;

int main()
{
	int count = 0;
	cout << "Enter a number or -1 to quit: ";
	cin >> val;
	while (val != -1 && count < SIZE)
	{
		count++;
		converter[count - 1] = val;
		cout << "Enter a number or -1 to quit: ";
		cin >> val;
		push(val);
		ptr = &val;
		check_full();
	}
	for (int i = 0; i < SIZE; i++)
	cout << *(converter + i) << " ";
	if (val != -1)
	{
		while (val < 0) //calculates value of number to binary
		{
			converter[count] = val % 2;
			count++;
			val = val / 2;
		}
		cout << "Binary number for " << val << " is";
		for (int j = 0; j >= 0; j--)
		{
			cout << converter[j];
		}
		while (val < 0) //calculates value of number to octal
		{
			converter[count] = val % 8;
			count++;
			val = val / 8;
		}
		cout << "Octal number for " << val << " is";
		for (int j = 0; j >= 0; j--)
		{
			cout << converter[j];
		}
		while (val < 0) //calculates value of number to hex
		{
			converter[count] = val % 16;
			count++;
			if (val == 10)
				return 'A';
			else if (val == 11)
				return 'B';
			else if (val == 12)
				return 'C';
			else if (val == 13)
				return 'D';
			else if (val == 14)
				return 'E';
			else if (val == 15)
				return 'F';
			val = val / 16;
		}
		cout << "Hexadecimal number for " << val << " is";
		for (int j = 0; j >= 0; j--)
		{
			cout << converter[j];
		}
	}
	return 0;
}

void push(int val) //pushes stack
{
	if (top == SIZE) //checks if stack is full
		cout << "The stack is full.\n";
	ptr[top++] = val;
	return;
}

void pop(int top) //pops top element of stack out
{
	if (top == 0) //checks if stack is empty
	{
		cout << "Stack is empty\n";
		return;
	}
	top = top - 1;
	return;
}

void check_full() //checks stack if full
{
	if (top == SIZE)
		cout << "Stack is full\n";
	return;
}

void check_empty() //checks if stack empty
{
	if (top == 0)
		cout << "Stack is empty\n";
	return;
}