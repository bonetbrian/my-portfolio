#include <iostream>
#include <string>
#include <stack>
#include <stdexcept>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedStack {
private:
    Node* top;

public:
    LinkedStack() : top(nullptr) {}

    bool isEmpty() {
        return top == nullptr;
    }

    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }

    int pop() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        int val = top->data;
        Node* temp = top;
        top = top->next;
        delete temp;
        return val;
    }

    int peek() {
        if (isEmpty()) {
            throw runtime_error("Stack is empty");
        }
        return top->data;
    }
};

int evaluatePostfix(string expression) {
    LinkedStack stack;

    for (char c : expression) {
        if (isdigit(c)) {
            stack.push(c - '0'); // Convert char to int
        }
        else {
            int operand2 = stack.pop();
            int operand1 = stack.pop();
            int result;
            switch (c) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1*operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                throw invalid_argument("Invalid character in expression");
            }
            stack.push(result);
        }
    }

    return stack.pop();
}

int main() {
    string expression = "23+4"; // Example expression
    int result = evaluatePostfix(expression);
    cout << "Result of expression " << expression << ": " << result << endl;
    return 0;
}