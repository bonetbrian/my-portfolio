#ifndef BinarySearchTree_h
#define BinarySearchTree_h

/** Link-based implementation of the ADT binary search tree.
@file BinarySearchTree.h */
#include "BinaryTreeInterface.h"
#include "BinaryNode.h"
#include "BinaryNodeTree.h"
#include "PrecondViolatedExcep.h"

template <class ItemType>
class BinarySearchTree : public BinaryNodeTree<ItemType> {
private:
   

protected:
    BinaryNode<ItemType>* insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNode);
    BinaryNode<ItemType>* removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success);
    BinaryNode<ItemType>* removeNode(BinaryNode<ItemType>* nodePtr);
    BinaryNode<ItemType>* removeLeftmostNode(BinaryNode<ItemType>* subTreePtr, ItemType& inorderSuccessor);
    BinaryNode<ItemType>* findNode(BinaryNode<ItemType>* treePtr, const ItemType& target, bool& success) const;

public:
    struct Node {
        ItemType data;
        Node* left;
        Node* right;
        Node(const ItemType& data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;

    void inorderTraversal(Node* node, void visit(ItemType&)) const {
        if (node != nullptr) {
            inorderTraversal(node->left, visit);
            visit(node->data);
            inorderTraversal(node->right, visit);
        }
    }

    void insert(Node*& node, const ItemType& data) {
        if (node == nullptr) {
            node = new Node(data);
        }
        else if (data < node->data) {
            insert(node->left, data);
        }
        else {
            insert(node->right, data);
        }
    }

    void destroyTree(Node* node) {
        if (node != nullptr) {
            destroyTree(node->left);
            destroyTree(node->right);
            delete node;
        }
    }

    double calculateAverageBFP(Node* node, int& count) const {
        if (node == nullptr) return 0.0;

        double leftSum = calculateAverageBFP(node->left, count);
        double rightSum = calculateAverageBFP(node->right, count);

        count++; // Increment count for the current node

        return leftSum + rightSum + node->data.bfp;
    }


    BinaryNode<ItemType>* rootPtr;

    Node* getRootPtr() const {
        return root;
    }


    BinarySearchTree();
    BinarySearchTree(const ItemType& rootItem);
    BinarySearchTree(const BinarySearchTree<ItemType>& tree);
    ~BinarySearchTree();

    bool isEmpty() const;
    int getHeight() const;
    int getNumberOfNodes() const;
    ItemType getRootData() const throw (PrecondViolatedExcep);
    void setRootData(const ItemType& newData) const;
    bool add(const ItemType& newEntry);
    bool remove(const ItemType& anEntry);
    void clear();
    ItemType getEntry(const ItemType& anEntry) const throw (PrecondViolatedExcep);
    bool contains(const ItemType& anEntry) const;

    void insert(const ItemType& data);
    void preorderTraverse(void visit(ItemType&)) const;
    void inorderTraverse(void visit(ItemType&)) const;
    void postorderTraverse(void visit(ItemType&)) const;

    BinarySearchTree<ItemType>& operator=(const BinarySearchTree<ItemType>& rightHandSide);
};

// Definition of getRootPtr() method

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::insertInorder(BinaryNode<ItemType>* subTreePtr, BinaryNode<ItemType>* newNodePtr) {
    BinaryNode<ItemType>* tempPtr;
    if (subTreePtr == nullptr)
        return newNodePtr;
    else if (subTreePtr->getItem() > newNodePtr->getItem()) {
        tempPtr = insertInorder(subTreePtr->getLeftChildPtr(), newNodePtr);
        subTreePtr->setLeftChildPtr(tempPtr);
    }
    else {
        tempPtr = insertInorder(subTreePtr->getRightChildPtr(), newNodePtr);
        subTreePtr->setRightChildPtr(tempPtr);
    }
    return subTreePtr;
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeValue(BinaryNode<ItemType>* subTreePtr, const ItemType target, bool& success) {
    BinaryNode<ItemType>* tempPtr;
    if (subTreePtr == nullptr) {
        success = false;
        return nullptr;
    }
    else if (subTreePtr->getItem() == target) {
        subTreePtr = removeNode(subTreePtr);
        success = true;
        return subTreePtr;
    }
    else if (subTreePtr->getItem() > target) {
        tempPtr = removeValue(subTreePtr->getLeftChildPtr(), target, success);
        subTreePtr->setLeftChildPtr(tempPtr);
        return subTreePtr;
    }
    else {
        tempPtr = removeValue(subTreePtr->getRightChildPtr(), target, success);
        subTreePtr->setRightChildPtr(tempPtr);
        return subTreePtr;
    }
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeNode(BinaryNode<ItemType>* nodePtr) {
    BinaryNode<ItemType>* tempPtr = nullptr;
    BinaryNode<ItemType>* nodeToConnectPtr = nullptr;
    ItemType newNodeValue;
    if (nodePtr->isLeaf()) {
        delete nodePtr;
        nodePtr = nullptr;
        return nodePtr;
    }
    else if (nodePtr->isChild()) {
        nodeToConnectPtr = (nodePtr->getLeftChildPtr() != nullptr) ? nodePtr->getLeftChildPtr() : nodePtr->getRightChildPtr();
        delete nodePtr;
        nodePtr = nullptr;
        return nodeToConnectPtr;
    }
    else {
        tempPtr = removeLeftmostNode(nodePtr->getRightChildPtr(), newNodeValue);
        nodePtr->setRightChildPtr(tempPtr);
        nodePtr->setItem(newNodeValue);
        return nodePtr;
    }
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::removeLeftmostNode(BinaryNode<ItemType>* nodePtr, ItemType& inorderSuccesssor) {
    if (nodePtr->getLeftChildPtr() == nullptr) {
        inorderSuccesssor = nodePtr->getItem();
        return removeNode(nodePtr);
    }
    else {
        nodePtr->setLeftChildPtr(removeLeftmostNode(nodePtr->getLeftChildPtr(), inorderSuccesssor));
        return nodePtr;
    }
}

template <class ItemType>
BinaryNode<ItemType>* BinarySearchTree<ItemType>::findNode(BinaryNode<ItemType>* subTreePtr, const ItemType& target, bool& success) const {
    if (subTreePtr == nullptr) {
        success = false;
        return nullptr;
    }
    else if (subTreePtr->getItem() == target) {
        success = true;
        return subTreePtr;
    }
    else if (subTreePtr->getItem() > target) {
        return findNode(subTreePtr->getLeftChildPtr(), target, success);
    }
    else {
        return findNode(subTreePtr->getRightChildPtr(), target, success);
    }
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree() : rootPtr(nullptr) {}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const ItemType& rootItem) {
    rootPtr = new BinaryNode<ItemType>(rootItem, nullptr, nullptr);
}

template <class ItemType>
BinarySearchTree<ItemType>::BinarySearchTree(const BinarySearchTree<ItemType>& tree) {
    rootPtr = this->copyTree(tree.rootPtr);
}

template <class ItemType>
BinarySearchTree<ItemType>::~BinarySearchTree() {
    this->destroyTree(root);
}

template <class ItemType>
bool BinarySearchTree<ItemType>::isEmpty() const {
    return rootPtr == nullptr;
}

template <class ItemType>
int BinarySearchTree<ItemType>::getHeight() const {
    return this->getHeightHelper(rootPtr);
}

template <class ItemType>
int BinarySearchTree<ItemType>::getNumberOfNodes() const {
    return this->getNumberOfNodesHelper(rootPtr);
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getRootData() const throw (PrecondViolatedExcep) {
    if (isEmpty()) {
        throw PrecondViolatedExcep("TreeException: Empty Tree");
    }
    return rootPtr->getItem();
}

template <class ItemType>
void BinarySearchTree<ItemType>::setRootData(const ItemType& newData) const {
    if (!isEmpty()) {
        rootPtr->setItem(newData);
    }
    else {
        rootPtr = new BinaryNode<ItemType>(newData, nullptr, nullptr);
    }
}

template <class ItemType>
bool BinarySearchTree<ItemType>::add(const ItemType& newEntry) {
    BinaryNode<ItemType>* newNodePtr = new BinaryNode<ItemType>(newEntry);
    rootPtr = insertInorder(rootPtr, newNodePtr);
    return true;
}

template <class ItemType>
bool BinarySearchTree<ItemType>::remove(const ItemType& anEntry) {
    bool isSuccessful = false;
    rootPtr = removeValue(rootPtr, anEntry, isSuccessful);
    return isSuccessful;
}

template <class ItemType>
void BinarySearchTree<ItemType>::clear() {
    this->destroyTree(rootPtr);
    rootPtr = nullptr;
}

template <class ItemType>
ItemType BinarySearchTree<ItemType>::getEntry(const ItemType& anEntry) const throw (PrecondViolatedExcep) {
    BinaryNode<ItemType>* tempTree = nullptr;
    bool isSuccessful = false;
    tempTree = findNode(rootPtr, anEntry, isSuccessful);
    if (!isSuccessful) {
        throw PrecondViolatedExcep("TreeException: Entry not found in tree!");
    }
    return (tempTree->getItem());
}

template <class ItemType>
bool BinarySearchTree<ItemType>::contains(const ItemType& anEntry) const {
    BinaryNode<ItemType>* tempTree = nullptr;
    bool isSuccessful = false;
    tempTree = findNode(rootPtr, anEntry, isSuccessful);
    return isSuccessful;
}

template <class ItemType>
void BinarySearchTree<ItemType>::preorderTraverse(void visit(ItemType&)) const {
    this->preorder(visit, rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::inorderTraverse(void visit(ItemType&)) const {
    this->inorder(visit, rootPtr);
}

template <class ItemType>
void BinarySearchTree<ItemType>::postorderTraverse(void visit(ItemType&)) const {
    this->postorder(visit, rootPtr);
}

template <class ItemType>
BinarySearchTree<ItemType>& BinarySearchTree<ItemType>::operator=(const BinarySearchTree<ItemType>& rightHandSide) {
    if (this != &rightHandSide) {
        this->destroyTree(rootPtr);
        rootPtr = this->copyTree(rightHandSide.rootPtr);
    }
    return *this;
}

template <class ItemType>
void BinarySearchTree<ItemType>::insert(const ItemType& data) {
    insert(root, data);
}

#endif /* BinarySearchTree_h */
