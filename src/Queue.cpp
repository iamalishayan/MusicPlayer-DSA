#include "Queue.h"
#include <stdexcept>
#include "SearchEngine.h"

template <typename T>
// Constructor: Initializes an empty Queue with front and rear pointers set to nullptr.
Queue<T>::Queue() : front(nullptr), rear(nullptr) {
    // `front` and `rear` are initialized to nullptr, indicating an empty queue.
}

template <typename T>
// Destructor: Deallocates all dynamically allocated memory for the queue's nodes.
Queue<T>::~Queue() {
    // Continue dequeuing until the queue is empty, deleting nodes as we go.
    while (!isEmpty()) {
        dequeue(); // Call `dequeue` to remove elements and delete them.
    }
}

template <typename T>
// Method to enqueue (add) a new element to the rear of the queue.
void Queue<T>::enqueue(const T& value) {
    // Create a new node with the given value.
    Node* newNode = new Node(value);

    if (rear) {
        // If the queue is not empty, set the next pointer of the current rear node to the new node.
        rear->next = newNode;
    } else {
        // If the queue is empty, the new node will be both the front and rear of the queue.
        front = newNode;
    }

    // Update the rear pointer to the new node, as it is now the last node in the queue.
    rear = newNode;
}

template <typename T>
// Method to dequeue (remove) an element from the front of the queue.
void Queue<T>::dequeue() {
    // If the queue is empty, throw an exception indicating the operation cannot be performed.
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty"); // Throw an exception if the queue is empty.
    }

    // Temporarily store the current front node.
    Node* temp = front;

    // Retrieve the data from the front node to return later.
    T value = front->data;

    // Move the front pointer to the next node in the queue.
    front = front->next;

    // If the queue becomes empty after dequeuing, reset the rear pointer to nullptr.
    if (front == nullptr) {
        rear = nullptr;
    }

    // Delete the old front node to free its memory.
    delete temp;
}

template<typename T>
// Method to return the element at the front of the queue without removing it.
T Queue<T>::top() {
    // If the queue is empty, throw an exception indicating the operation cannot be performed.
    if (isEmpty()) {
        throw std::out_of_range("Queue is empty"); // Throw an exception if the queue is empty.
    }

    // Return the data of the front node.
    return front->data;
}

template <typename T>
// Method to check if the queue is empty by checking if the front pointer is null.
bool Queue<T>::isEmpty() const {
    // If `front` is nullptr, the queue is empty.
    return front == nullptr;
}

// Explicit instantiation for TrieNode* type in the queue (necessary for SearchEngine).
template class Queue<TrieNode*>; // Instantiate the template for Queue with TrieNode* as the type.
