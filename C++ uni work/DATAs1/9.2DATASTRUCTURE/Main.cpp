#include "LinkedStack.h"
#include "ListQueue.h"
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(const string& someString);
bool isPalindromeImproved(const string& someString);

bool isPalindrome(const string& someString)
{
    ListQueue<char> aQueue;
    LinkedStack<char> aStack;

    for (char nextChar : someString)
    {
        aQueue.enqueue(nextChar);
        aStack.push(nextChar);
    }

    bool charactersAreEqual = true;

    while (!aQueue.isEmpty() && charactersAreEqual)
    {
        if (aQueue.peekFront() == aStack.peek())
        {
            aQueue.dequeue();
            aStack.pop();
        }
        else
        {
            charactersAreEqual = false;
        }
    }

    return charactersAreEqual;
}

bool isPalindromeImproved(const std::string& someString)
{
    ListQueue<char> aQueue;
    LinkedStack<char> aStack;
    size_t length = someString.length(); // Changed to size_t
    size_t halfLength = length / 2; // Changed to size_t

    for (size_t i = 0; i < halfLength; i++)
    {
        aQueue.enqueue(someString[i]);
    }

    for (size_t i = (length % 2 == 0) ? halfLength : halfLength + 1; i < length; i++)
    {
        aStack.push(someString[i]);
    }

    bool charactersAreEqual = true;

    while (!aQueue.isEmpty() && charactersAreEqual)
    {
        if (aQueue.peekFront() == aStack.peek())
        {
            aQueue.dequeue();
            aStack.pop();
        }
        else
        {
            charactersAreEqual = false;
        }
    }

    return charactersAreEqual;
}

int main()
{
    string test1 = "abcda";
    string test2 = "radar";

    cout << "Testing string: " << test1 << "\n";
    if (isPalindrome(test1))
        cout << "The string \"" << test1 << "\" is a palindrome.\n";
    else
        cout << "The string \"" << test1 << "\" is not a palindrome.\n";

    cout << "Testing string: " << test2 << "\n";
    if (isPalindrome(test2))
        cout << "The string \"" << test2 << "\" is a palindrome.\n";
    else
        cout << "The string \"" << test2 << "\" is not a palindrome.\n";

    return 0;
}
