#include <iostream>
#include <string>
using namespace std;

struct Node {
    string value;
    Node* left;
    Node* right;
};

void preorder(Node* node) {
    if (node == NULL) return;
    cout << node->value << " ";
    preorder(node->left);
    preorder(node->right);
}

void inorder(Node* node) {
    if (node == NULL) return;
    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
}

void postorder(Node* node) {
    if (node == NULL) return;
    postorder(node->left);
    postorder(node->right);
    cout << node->value << " ";
}

int main() {
    Node* root = new Node{ "-", new Node{"*", new Node{"+", new Node{"x"}, new Node{"2"}}, new Node{"-", new Node{"y"}, new Node{"+", new Node{"3z"}, new Node{"5"}}}}, new Node{"5"} };
    cout << "Preorder: ";
    preorder(root);
    cout << "\nInorder: ";
    inorder(root);
    cout << "\nPostorder: ";
    postorder(root);


    Node* root1 = new Node{ "+", new Node{"+", new Node{"x"}, new Node{"*", new Node{"x"}, new Node{"y"}}}, new Node{"/", new Node{"x"}, new Node{"y"}} };
    cout << "Preorder: ";
    preorder(root1);
    cout << "\nInorder: ";
    inorder(root1);
    cout << "\nPostorder: ";
    postorder(root1);

    Node* root2 = new Node{ "+", new Node{"x"}, new Node{"/", new Node{"+", new Node{"*", new Node{"x"}, new Node{"y"}}, new Node{"x"}}, new Node{"y"}} };
    cout << "Preorder: ";
    preorder(root2);
    cout << "\nInorder: ";
    inorder(root2);
    cout << "\nPostorder: ";
    postorder(root2);




    Node* root3 = new Node{ "<>", new Node{"-", new Node{"^", new Node{"p"}, new Node{"q"}}}, new Node{"v", new Node{"-", new Node{"p"}}, new Node{"-", new Node{"q"}}} };
    cout << "Preorder: ";
    preorder(root3);
    cout << "\nInorder: ";
    inorder(root3);
    cout << "\nPostorder: ";
    postorder(root3);


    Node* root4 = new Node{ "v", new Node{"^", new Node{"-", new Node{"p"}}, new Node{"<>", new Node{"q"}, new Node{"-", new Node{"p"}}}}, new Node{"-", new Node{"q"}} };
    cout << "Preorder: ";
    preorder(root4);
    cout << "\nInorder: ";
    inorder(root4);
    cout << "\nPostorder: ";
    postorder(root4);



    Node* root5 = new Node{ "-", new Node{"n", new Node{"A"}, new Node{"B"}}, new Node{"U", new Node{"A"}, new Node{"-", new Node{"B"}, new Node{"A"}}} };
    cout << "Preorder: ";
    preorder(root5);




    return 0;
}
