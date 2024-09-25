#include <iostream>
#include <cctype>
#include <string>
using namespace std;


// Finds the end of a prefix expression, if one exists.
// Precondition: The substring of strExp from the index first through the end of
// the string contains no blank characters.
// Postcondition: Returns the index of the last character in the prefix expression that
// begins at index first of strExp, or 1 if no such prefix expression exists.
int endPre(string strExp, int first) {
    int last = strExp.length() - 1;
    if (first < 0 || first > last)
        return -1;

    char ch = strExp[first];
    if (isalnum(ch))
        return first;
    else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
    {
        int firstEnd = endPre(strExp, first + 1);
        if (firstEnd > -1)
            return endPre(strExp, firstEnd + 1);
        else
            return -1;
    }
    else
        return -1;
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
string convert(string preExp) {
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
            postExp += convert(preExp.substr(1, endFirst));
            postExp += convert(preExp.substr(endFirst + 1, preLength - endFirst - 1));
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

// Returns the value of a given prefix expression .
// Precondition: strExp is a string containing a valid prefix expression with no blanks.
double evaluatePrefix(string strExp) {
    int strLength = strExp.length();
    if (strLength == 1)
        return strExp[0] - '0'; // Base case—single identifier
    else {
        char op = strExp[0]; // strExp begins with an operator
        // Find the end of the first prefix expression—will be the first operand
        int endFirst = endPre(strExp, 1);
        // Recursively evaluate this first prefix expression
        double operand1 = evaluatePrefix(strExp.substr(1, endFirst - 1));
        // Recursively evaluate the second prefix expression—will be the second operand
        double operand2 = evaluatePrefix(strExp.substr(endFirst, strLength - endFirst));
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

/*
Question 10. Is "+*a–b/c++ de–fg" a prefix expression? Explain in terms of the grammar for prefix expressions.
Question 4. Is the following string a prefix expression? "+–/abc*+def*gh"

*/
int main() {
    
    cout << "\n\n\n"; // empty line

    // testing isPal
   cout << "isPal(\"abcdeba\"): " <<boolalpha << isPal("abcdeba") << endl; 
    cout << "isPal(\"deed\"): " << boolalpha << isPal("deed") << endl; 
    cout << "isPal(\"level\"): " << boolalpha << isPal("level") << endl;

    cout << "\n\n\n";// empty line

    // testing isAnBn
    cout << "isAnBn(\"AABB\"): " << boolalpha << isAnBn("AABB") << endl; 
    cout << "isAnBn(\"AAABBB\"): " << boolalpha << isAnBn("AAABBB") << endl;



    // testing endPre
    string expression = "-*/abcd";
    int first = 0;

    int end_prefix = endPre(expression, first);
    if (end_prefix == -1)
        cout << "No prefix expression found." << endl;
    else
        cout << "End of prefix expression: " << end_prefix << endl;

    cout << "\n\n\n"; // empty line

    // Testing convert
    string prefixExp = "+*a-b/c++de-fg";
    cout << "Prefix expression: " << prefixExp << endl;
    cout << "Postfix expression: " << convert(prefixExp) << endl;

    // Testing isPrefix
    cout << "Is \"" << prefixExp << "\" a prefix expression? " << boolalpha << isPrefix(prefixExp) << endl;

    // Testing evaluatePrefix
    string prefixExp2 = "+-/*abc*+def*gh";
    cout << "Prefix expression: " << prefixExp2 << endl;
    cout << "Value of prefix expression: " << evaluatePrefix(prefixExp2) << endl;

    return 0;
}
