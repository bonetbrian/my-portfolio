#include "LinkedStack.h"
#include <iostream>
#include <cctype> // for isalpha
using namespace std;

int precedence(char op);
bool isLeftAssociative(char op);
bool isRightAssociative(char op);

string infixToPostfix(const string& infix) {
    string postfix;
    LinkedStack<char> stack;

    for (char token : infix) {
        if (isalpha(token)) {
            postfix += token;
            cout << "Operand: " << postfix << endl;
        }
        else if (token == '(') {
            stack.push(token);
            cout << "Pushed '(' onto stack" << endl;
        }
        else if (token == ')') {
            while (!stack.isEmpty() && stack.peek() != '(') {
                postfix += stack.peek();
                stack.pop();
            }
            stack.pop(); // Discard the '('
            cout << "Popped operators until '(' encountered: " << postfix << endl;
        }
        else { // Operator
            while (!stack.isEmpty() && precedence(stack.peek()) >= precedence(token)) {
                postfix += stack.peek();
                stack.pop();
            }
            stack.push(token);
            cout << "Pushed operator onto stack: " << postfix << endl;
        }
    }

    while (!stack.isEmpty()) {
        postfix += stack.peek();
        stack.pop();
    }

    cout << "Final postfix expression: " << postfix << endl;
    return postfix;


    // Pop remaining operators
    while (!stack.isEmpty()) {
        postfix += stack.peek();
        stack.pop();
    }

    return postfix;
}




int precedence(char op) {
    if (op == '^') {
        return 3; // Highest precedence for '^'
    }
    else if (op == '*' || op == '/') {
        return 2; // Higher precedence for '*' and '/'
    }
    else if (op == '+' || op == '-') {
        return 1; // Lower precedence for '+' and '-'
    }
    return 0;
}

bool isLeftAssociative(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

bool isRightAssociative(char op) {
    return op == '^';
}

int main() {
    // Convert infix expressions to postfix and display the result
    cout << "Infix expression: a / b / c - (d + e) * f\n";
    cout << "Postfix expression: " << infixToPostfix("a / b / c - (d + e) * f") << endl;

    cout << "\nInfix expression: a * (b / c / d) + e\n";
    cout << "Postfix expression: " << infixToPostfix("a * (b / c / d) + e") << endl;

    cout << "\nInfix expression: a - (b + c)\n";
    cout << "Postfix expression: " << infixToPostfix("a - (b + c)") << endl;

    cout << "\nInfix expression: a - (b + c * d) / e\n";
    cout << "Postfix expression: " << infixToPostfix("a - (b + c * d) / e") << endl;

    return 0;
}