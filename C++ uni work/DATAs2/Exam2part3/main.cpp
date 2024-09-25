#include <iostream>
#include<stack>
#include <string>
using namespace std;

// Finds the end of a prefix expression, if one exists.
// Precondition: The substring of strExp from the index first through the end of
// the string contains no blank characters.
// Postcondition: Returns the index of the last character in the prefix expression that
// begins at index first of strExp, or 1 if no such prefix expression exists.
// Finds the end of a prefix expression, if one exists.
// Precondition: The substring of strExp from the index first through the end of
// the string contains no blank characters.
// Postcondition: Returns the index of the last character in the prefix expression that
// begins at index first of strExp, or -1 if no such prefix expression exists.
int endPre(string strExp, int first) {
    if (strExp.empty()) // Check if string is empty
        return -1;

    int last = strExp.length() - 1;
    if (first < 0 || first > last)
        return -1;

    char ch = strExp[first];
    if (isalnum(ch))
        return first;
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        int firstEnd = endPre(strExp, first + 1);
        if (firstEnd == -1) {
            cout << "Invalid prefix expression: " << strExp << endl;
            return -1; // Invalid expression
        }
        int secondEnd = endPre(strExp, firstEnd + 1);
        if (secondEnd == -1) {
            cout << "Invalid prefix expression: " << strExp << endl;
            return -1; // Invalid expression
        }
        return secondEnd;
    }
    else
        return -1;
}




// Returns the precedence of the given operator.
int precedence(char op) {
    if (op == '*' || op == '/') {
        return 2;
    }
    else if (op == '+' || op == '-') {
        return 1;
    }
    else {
        return 0; // Parentheses have the lowest precedence
    }
}
// Finds the end of a postfix expression, if one exists.
// Precondition: The substring of strExp from the index last to the beginning of
// the string contains no blank characters.
// Postcondition: Returns the index of the first character in the postfix expression that
// ends at index last of strExp, or 1 if no such postfix expression exists.
int endPost(string strExp, int last) {
    if (strExp.empty()) // Check if string is empty
        return -1;

    int first = 0;
    if (last < 0 || last >= strExp.length())
        return -1;

    char ch = strExp[last];
    if (isalnum(ch))
        return last;
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        int lastStart = endPost(strExp, last - 1);
        if (lastStart == -1)
            return -1;
        else
            return endPost(strExp, lastStart - 1);
    }
    else
        return -1;
}


// Converts an infix expression to postfix form.
// Precondition: The string infixExp is a valid infix expression with no blanks.
// Postcondition: Returns the equivalent postfix expression.
string infixToPostfix(string infixExp) {
    stack<char> operatorStack;
    string postfixExp = "";

    for (char ch : infixExp) {
        if (isalnum(ch)) {
            postfixExp += ch;
        }
        else if (ch == '(') {
            operatorStack.push(ch);
        }
        else if (ch == ')') {
            while (!operatorStack.empty() && operatorStack.top() != '(') {
                postfixExp += operatorStack.top();
                operatorStack.pop();
            }
            if (!operatorStack.empty() && operatorStack.top() == '(') {
                operatorStack.pop(); // Discard the '('
            }
        }
        else {
            while (!operatorStack.empty() && precedence(operatorStack.top()) >= precedence(ch)) {
                postfixExp += operatorStack.top();
                operatorStack.pop();
            }
            operatorStack.push(ch);
        }
    }

    while (!operatorStack.empty()) {
        postfixExp += operatorStack.top();
        operatorStack.pop();
    }

    return postfixExp;
}

bool isPal(string s) {
    if (s.empty() || s.length() == 1)
        return true;
    else if (s.front() == s.back())
        return isPal(s.substr(1, s.length() - 2));
    else
        return false;
}

bool isAnBn(string s) {
    if (s.empty())
        return true;

    else if (s.front() == 'A' && s.back() == 'B')
        return isAnBn(s.substr(1, s.length() - 2));
    else
        return false;
}

// Converts a prefix expression to postfix form.
// Precondition: The string pre is a valid prefix expression with no blanks.
// Postcondition: Returns the equivalent postfix expression.
string convertPrefixToPostfix(string preExp) {
    if (preExp.empty()) {
        return "";
    }

    int preLength = preExp.length();
    char ch = preExp[0];
    string postExp = "";

    if (islower(ch)) {
        postExp += ch;
    }
    else {
        int endFirst = endPre(preExp, 1);
        if (endFirst != -1 && endFirst < preLength - 1) {
            postExp += convertPrefixToPostfix(preExp.substr(1, endFirst));
            postExp += convertPrefixToPostfix(preExp.substr(endFirst + 1, preLength - endFirst - 1));
            postExp += ch;
        }
    }
    return postExp;
}

// Sees whether an expression is a prefix expression.
// Precondition: strExp contains a string with no blank characters.
// Postcondition: Returns true if the expression is in prefix form; otherwise returns false.
bool isPrefix(string strExp) {
    int lastChar = endPre(strExp, 0);
    return (lastChar >= 0) && (lastChar == strExp.length() - 1);
}

// Sees whether an expression is a postfix expression.
// Precondition: strExp contains a string with no blank characters.
// Postcondition: Returns true if the expression is in postfix form; otherwise returns false.
bool isPostfix(string strExp) {
    int firstChar = endPost(strExp, strExp.length() - 1);
    return (firstChar >= 0) && (firstChar == 0);
}

// Returns the value of a given prefix expression.
// Precondition: strExp is a string containing a valid prefix expression with no blanks.
double evaluatePrefix(string strExp) {
    double strLength = strExp.length();
    if (strLength == 1)
        return strExp[0] - '0'; // Base case—single identifier
    else {
        char op = strExp[0]; // strExp begins with an operator
        // Find the end of the first prefix expression—will be the first operand
        double endFirst = endPre(strExp, 1);
        // Recursively evaluate this first prefix expression
        double operand1 = evaluatePrefix(strExp.substr(1, endFirst));
        // Recursively evaluate the second prefix expression—will be the second operand
        double operand2 = evaluatePrefix(strExp.substr(endFirst + 1));
        // Evaluate the prefix expression
        switch (op) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            return operand1 / operand2;
        default:
            return 0; // Invalid operator
        }
    }
}

// Returns the value of a given postfix expression.
// Precondition: strExp is a string containing a valid postfix expression with no blanks.
double evaluatePostfix(string strExp) {
    stack<double> operandStack;
    for (char ch : strExp) {
        if (isdigit(ch)) {
            operandStack.push(ch - '0');
        }
        else {
            if (operandStack.empty()) {
                cout << "Error: Invalid postfix expression" << endl;
                return 0; // Stack is empty, invalid expression
            }
            double operand2 = operandStack.top();
            operandStack.pop();
            if (operandStack.empty()) {
                cout << "Error: Invalid postfix expression" << endl;
                return 0; // Stack is empty, invalid expression
            }
            double operand1 = operandStack.top();
            operandStack.pop();
            switch (ch) {
            case '+':
                operandStack.push(operand1 + operand2);
                break;
            case '-':
                operandStack.push(operand1 - operand2);
                break;
            case '*':
                operandStack.push(operand1 * operand2);
                break;
            case '/':
                operandStack.push(operand1 / operand2);
                break;
            default:
                cout << "Error: Invalid operator" << endl;
                return 0; // Invalid operator
            }
        }
    }
    if (operandStack.empty()) {
        cout << "Error: Invalid postfix expression" << endl;
        return 0; // Stack should not be empty at this point
    }
    return operandStack.top();
}
int main() {
    cout << "\n\n\n"; // empty line

    // testing isPal
    cout << "isPal(\"abcdeba\"): " << boolalpha << isPal("abcdeba") << endl;
    cout << "isPal(\"deed\"): " << boolalpha << isPal("deed") << endl;
    cout << "isPal(\"level\"): " << boolalpha << isPal("level") << endl;

    cout << "\n\n\n";// empty line

    // testing isAnBn
    cout << "isAnBn(\"AABB\"): " << boolalpha << isAnBn("AABB") << endl;
    cout << "isAnBn(\"AAABBB\"): " << boolalpha << isAnBn("AAABBB") << endl;

    cout << "\n\n\n";// empty line

    // Testing endPre
    string expression = "-*/abcd";
    int first = 0;

    int end_prefix = endPre(expression, first);
    if (end_prefix == -1)
        cout << "No prefix expression found." << endl;
    else
        cout << "End of prefix expression: " << end_prefix << endl;

    cout << "\n\n\n"; // empty line

    // Testing convertPrefixToPostfix
    string prefixExp = "+*a-b/c++de-fg";
    string postfixExp = convertPrefixToPostfix(prefixExp);
    cout << "Prefix expression: " << prefixExp << endl;
    cout << "Postfix expression: " << postfixExp << endl;

    // Testing isPrefix
    cout << "Is \"" << prefixExp << "\" a prefix expression? " << boolalpha << isPrefix(prefixExp) << endl;

    // Testing isPostfix
    cout << "Is \"" << postfixExp << "\" a postfix expression? " << boolalpha << isPostfix(postfixExp) << endl;

    // Testing evaluatePrefix
    string prefixExp2 = "+-/*abc*+def*gh";
    cout << "Prefix expression: " << prefixExp2 << endl;
    cout << "Value of prefix expression: " << evaluatePrefix(prefixExp2) << endl;

    // Testing evaluatePostfix
    string postfixExp2 = "ab/c*efg*h/+d-+";
    cout << "Postfix expression: " << postfixExp2 << endl;
    cout << "Value of postfix expression: " << evaluatePostfix(postfixExp2) << endl;

    cout << "Is ab/c*efg*h/+d–+a a postfix expression? " << boolalpha << isPostfix("ab/c*efg*h/+d–+a") << endl;


    return 0;
}
