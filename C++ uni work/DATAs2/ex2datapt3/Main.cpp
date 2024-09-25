#include <iostream>
#include <string>
#include "ArrayStack.h"
#include "LinkedStack.h"
using namespace std;


bool isStringInLanguageL(const std::string& str) {
    LinkedStack<char> stack;
    int countA = 0;
    int countB = 0;

    // Count the number of 'A's at the beginning of the string
    while (str[countA] == 'A') {
        countA++;
    }

    // Push 'B's onto the stack and count them
    for (size_t i = countA; i < str.length(); i++) {
        if (str[i] == 'B') {
            stack.push('B');
            countB++;
        }
        else {
            // If any character other than 'B' is encountered, the string is not in the language
            return false;
        }
    }
    // Pop 'B's from the stack and compare with 'A's
    for (int i = 0; i < countA; i++) {
        if (stack.isEmpty() || stack.peek() != 'B') {
            return false;
        }
        else {
            stack.pop();
        }
    }
    // If the stack is empty and the counts of 'A's and 'B's match, the string is in the language
    return stack.isEmpty() && countA == countB;
}

bool isStringInLanguageL2(const std::string& str) {
    ArrayStack<char> stack;

    for (char c : str) {
        if (c == 'A' || c == 'B') {
            if (stack.isEmpty()) {
                stack.push(c);
            }
            else {
                char top = stack.peek();
                if ((top == 'A' && c == 'B') || (top == 'B' && c == 'A')) {
                    stack.pop();
                }
                else {
                    stack.push(c);
                }
            }
        }
    }

    return stack.isEmpty();
}

int main() {

    string testString = "ABABBA";
    if (isStringInLanguageL(testString)) {
        cout << "String is in language L." << endl;
    }
    else {
        cout << "String is not in language L." << endl;
    }

    string testStrings = "AABB";
    if (isStringInLanguageL2(testString)) {
        cout << "String is in language L." << std::endl;
    }
    else {
        cout << "String is not in language L." << std::endl;
    }

    return 0;
}