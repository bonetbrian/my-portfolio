#include <iostream>
#include "ArrayStack.h"
using namespace std;

int main() {
    ArrayStack<char> stack;

    // Strings to be checked for balanced braces
    string input1 = "x{{yz}}}";
    string input2 = "{x{y{{z}}}";
    string input3 = "{{{x}}}";

    // Process each input string
    for (const string& input : { input1, input2, input3 }) {
        cout << "Input string: " << input << endl;

        // Traverse each character in the input string
        for (char ch : input) {
            if (ch == '{') {
                stack.push(ch);
            }
            else if (ch == '}') {
                if (!stack.isEmpty() && stack.peek() == '{') {
                    stack.pop();
                }
                else {
                    cout << "Unbalanced braces" << endl;
                    break; // Break out of the inner loop if unbalanced braces are found
                }
            }
        }

        // Check if the stack is empty after processing the string
        if (stack.isEmpty()) {
            cout << "Braces are balanced" << endl;
        }
        else {
            cout << "Unbalanced braces" << endl;
        }

        // Clear the stack for the next input
        stack.clear();
    }

    return 0;
}
