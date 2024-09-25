#include <iostream>
#include "Student.h"
#include "BinarySearchTree.h"
using namespace std;

int main() {
    // Create a BinarySearchTree of Students
    BinarySearchTree<Student> bst;

    // Input sample data
    cout << "Enter sample data in the format: Gender (Male/Female) Height(feet inches) Weight(pounds) Age" << endl;
    cout << "Example: Female 5 2 115 54" << endl;
    cout << "Enter 'done' to finish input." << endl;
    Student sample;
    while (cin >> sample) {
        bst.add(sample);
        
    }

    // Display inorder traversal of BST
    cout << "Inorder traversal of BST:" << endl;
    bst.inorderTraverse(displayStudent);

    // Calculate average BFP
    // Calculate average BFP
    int count = 0;
    double totalBFP = bst.calculateAverageBFP(bst.getRootPtr(), count);
    double averageBFP = (count != 0) ? totalBFP / count : 0.0;
    
    
    return 0;

}
