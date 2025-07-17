#include "PlaybackQueue.h"
#include <iostream>

using namespace std;


/* QueueNode constructor:
   Initializes a new node with a pointer to a Song and sets the next pointer to nullptr. */
QueueNode::QueueNode(Song* song) : song(song), next(nullptr) {
    // `song` is initialized with the passed argument, `next` is initialized to nullptr.
}


/* PlaybackQueue constructor:
   Initializes an empty queue with front and rear pointers set to nullptr. */
PlaybackQueue::PlaybackQueue() : front(nullptr), rear(nullptr) {
    // `front` and `rear` are initialized to nullptr, indicating an empty queue.
}


/* PlaybackQueue destructor:
   Dequeues all nodes in the queue to free memory. */
PlaybackQueue::~PlaybackQueue() {
    while (!isEmpty()) {
        dequeue(); // Continuously dequeue until the queue is empty, freeing memory.
    }
}


/* Method to add a song to the queue.
   Creates a new QueueNode and inserts it at the end (rear) of the queue. */
void PlaybackQueue::enqueue(Song* song) {
    QueueNode* newNode = new QueueNode(song); // Create a new node for the song.

    if (isEmpty()) {
        // If the queue is empty, set both front and rear to the new node.
        front = rear = newNode;
    } else {
        // If the queue is not empty, add the new node to the end of the queue.
        rear->next = newNode; // Set the current rear's next to the new node.
        rear = newNode;       // Update the rear pointer to the new node.
    }
}


/* Method to remove a song from the front of the queue (dequeue).
   Displays the song being played and deletes the node. */
void PlaybackQueue::dequeue() {
    if (isEmpty()) {
        cout << "Queue is empty.\n"; // If the queue is empty, print a message and return.
        return;
    }

    QueueNode* temp = front;     // Save the current front node in a temporary pointer.
    front = front->next;         // Update the front pointer to the next node.

    if (!front) {
        // If the front is now nullptr (queue is empty), set rear to nullptr as well.
        rear = nullptr;
    }

    cout << "Now playing: ";      // Print a message indicating the song is being played.
    temp->song->display();       // Call the display method on the song at the front.
    delete temp;                 // Delete the temporary node to free memory.
}


/* Method to check if the queue is empty.
   Returns true if front is nullptr (empty queue), false otherwise. */
bool PlaybackQueue::isEmpty() const {
    return front == nullptr; // Return true if front is nullptr, indicating the queue is empty.
}


/* Method to view the song at the front of the queue (top of the queue).
   Returns a pointer to the song at the front or nullptr if the queue is empty. */
Song* PlaybackQueue::top() const {
    if (isEmpty()) {
        cout << "Queue is empty.\n"; // If the queue is empty, print a message and return nullptr.
        return nullptr;
    }
    return front->song; // Return the song at the front of the queue.
}


/* Method to display all songs in the queue.
   Iterates through the queue and calls the display method for each song. */
void PlaybackQueue::displayPlayBackQueue() const {
    if (isEmpty()) {
        cout << "Queue is empty.\n"; // If the queue is empty, print a message.
    }

    QueueNode* temp = front; // Start at the front of the queue.

    while (temp) {
        temp->song->display(); // Display the song at the current node.
        temp = temp->next;     // Move to the next node in the queue.
    }
}

vector<Song*> PlaybackQueue::getAllSongs() const {
    if (isEmpty()) {
        cout << "Queue is empty.\n";
    }
    QueueNode* temp = front;
    vector<Song *> songs;
    while (temp) {
        songs.push_back(temp->song);
        temp = temp->next;
    }
    return songs;
}

void PlaybackQueue::rebuildFromShuffledList(vector<Song*> &songs) {
    while (!isEmpty()) {
        QueueNode* temp = front;
        front = front->next;
        delete temp;
    }
    rear = nullptr;
    for (Song* song : songs) {
        enqueue(song);
    }
}
