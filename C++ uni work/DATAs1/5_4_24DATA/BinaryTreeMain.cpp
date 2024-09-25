#include<iostream>
using namespace::std;
#include "BinaryNodeTree.h"
template<class T>
void display(T& anItem) {
	cout << anItem << ",";
}
int main() {
	BinaryNodeTree <int> balanceTree;
	balanceTree.add(1);
	balanceTree.add(2);
	balanceTree.add(3);
	balanceTree.add(4);
	balanceTree.add(5);
	balanceTree.add(6);
	balanceTree.add(7);
	balanceTree.add(8);
	balanceTree.add(9);
	balanceTree.add(10);
	cout << "\nRecorrido Preorder:";
	balanceTree.preorderTraverse(display);
	//Caso de eliminar la raiz del arbol
	balanceTree.remove(1);
	cout << "\nRecorrido Preorder:";
	balanceTree.preorderTraverse(display);
	system("pause");
	return 0;
}//end main
/*
Recorrido Preorder:1,2,4,7,6,3,5,8,
Recorrido Preorder:2,4,7,6,3,5,8,
Press any key to continue . . .*/