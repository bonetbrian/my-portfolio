#include <iostream>
#include "LinkedList.h"

template<class ItemType>
class ListQueue {
private:
    LinkedList<ItemType> list; // Using LinkedList via composition

public:
    bool isEmpty() const {
        return list.isEmpty();
    }

    bool enqueue(const ItemType& newEntry) {
        return list.insertAtEnd(newEntry);
    }

    bool dequeue() {
        return list.removeFirst();
    }

    ItemType peekFront() const {
        try {
            return list.getEntry(1);
        }
        catch (const PrecondViolatedExcep& e) {
            throw e;
        }
    }
};

int main() {
    // Create a ListQueue of integers
    ListQueue<int> queue;

    // Enqueue some elements
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    // Display the front element
    try {
        std::cout << "Front element: " << queue.peekFront() << std::endl;
    }
    catch (const PrecondViolatedExcep& e) {
        std::cerr << e.what() << std::endl;
    }

    // Dequeue an element
    queue.dequeue();

    // Display the front element again
    try {
        std::cout << "Front element after dequeue: " << queue.peekFront() << std::endl;
    }
    catch (const PrecondViolatedExcep& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
