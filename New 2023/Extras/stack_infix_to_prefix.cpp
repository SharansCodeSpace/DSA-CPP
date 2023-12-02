#include <iostream>
#include <string>
using namespace std;

#define SIZE 100

class Stack
{
private:
    int top;
    char arr[SIZE];

public:
    Stack()
    {
        top = -1;
    }
    bool isEmpty()
    {
        return top == -1;
    }
    bool isFull()
    {
        return top == SIZE - 1;
    }
    void push(int data)
    {
        if (!isFull())
            arr[++top] = data;
        else
            cout << "Stack Overflow" << endl;
    }
    char pop()
    {
        if (!isEmpty())
            return arr[top--];
        else
            return -1;
    }
    char peek()
    {
        if (!isEmpty())
            return arr[top];
        else
            return -1;
    }
};

int getPrecedence(char ch)
{
    if (ch == '^')
        return 4;
    else if (ch == '*' || ch == '/')
        return 3;
    else if (ch == '+' || ch == '-')
        return 2;
    else
        return 0;
}

bool isOperator(char ch)
{
    if (ch == '*' || ch == '/' || ch == '+' || ch == '-' || ch == '^')
        return true;
    else
        return false;
}

string infixToPostfix(string infix)
{
    Stack s;
    string postfix = "";
    for (char c : infix)
    {
        if (isalnum(c))
            postfix += c;
        else if (c == '(')
            s.push(c);
        else if (c == ')')
        {
            while (!s.isEmpty() && s.peek() != '(')
                postfix += s.pop();
            s.pop();
        }
        else if (isOperator(c))
        {
            while (!s.isEmpty() && s.peek() != '(' && getPrecedence(c) <= getPrecedence(s.peek()))
            {
                postfix += s.pop();
            }
            s.push(c);
        }
    }
    while (!s.isEmpty())
        postfix += s.pop();
    return postfix;
}

void reverse(string str)
{
    for (int i = str.length() - 1; i >= 0; i--)
        cout << str[i];
    cout << endl;
}

int main()
{
    string infix = "(a+b)*c-(d/e)";
    reverse(infixToPostfix(infix));
    return 0;
}