#ifndef QUEUE_H
#define QUEUE_H

template <typename T>
//a class  for the traditional queue class which is to be used for searching in the trie data structure
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };
    Node* front;
    Node* rear;
public:
    Queue();
    ~Queue();
    void enqueue(const T& value);
    void dequeue();
    T top();
    bool isEmpty() const;
};
#endif
