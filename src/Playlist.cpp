#include "Playlist.h"
#include <iostream>

using namespace std;


// PlaylistNode constructor: Initializes a new node with a pointer to a Song, and sets the next and previous pointers to nullptr.
PlaylistNode::PlaylistNode(Song* song) : song(song), next(nullptr), prev(nullptr) {
    // `song` is initialized with the passed argument, `next` and `prev` are initialized to nullptr.
}


// Playlist constructor: Initializes an empty Playlist with head and tail pointers set to nullptr.
Playlist::Playlist() : head(nullptr), tail(nullptr) {
    // `head` and `tail` are initialized to nullptr, indicating an empty playlist.
}


// Playlist destructor: Deletes all songs and nodes in the playlist to free memory.
Playlist::~Playlist() {
    PlaylistNode* current = head;
    // Traverse through the playlist from head to tail.
    while (current) {
        PlaylistNode* temp = current;
        current = current->next;
        delete temp->song; // Delete the song object to free memory.
        delete temp;       // Delete the node itself.
    }
}


// Method to add a new song to the playlist.
void Playlist::addSong(Song* song) {
    // Check if the song already exists in the playlist.
    PlaylistNode* current = head;
    while (current) {
        if (*current->song == *song) { // Compare the current song with the new song.
            cout << "Song already exists in the playlist.\n"; // If they match, print a message and return.
            return;
        }
        current = current->next;
    }

    // Create a new node with the song.
    PlaylistNode* newNode = new PlaylistNode(song);

    if (!head) {
        // If the playlist is empty, the new node becomes both the head and tail.
        head = tail = newNode;
    } else {
        // If the playlist is not empty, add the new node to the end (tail) of the playlist.
        tail->next = newNode;  // Set the current tail's next to the new node.
        newNode->prev = tail;  // Set the new node's previous pointer to the current tail.
        tail = newNode;        // Update the tail pointer to the new node.
    }
}


// Method to remove a song from the playlist by title.
void Playlist::removeSong(const string& title) {
    if (!head) {
        // If the playlist is empty, print a message and return.
        cout << "Playlist is empty.\n";
        return;
    }

    PlaylistNode* current = head;
    while (current) {
        if (current->song->getTitle() == title) {
            // If the song title matches, remove it from the playlist.
            if (current->prev) current->prev->next = current->next; // Update the previous node's next pointer if it exists.
            if (current->next) current->next->prev = current->prev; // Update the next node's prev pointer if it exists.
            if (current == head) head = current->next; // If the node is the head, move the head pointer.
            if (current == tail) tail = current->prev; // If the node is the tail, move the tail pointer.

            delete current->song; // Delete the song object to free memory.
            delete current;       // Delete the node itself to free memory.

            cout << "Removed: " << title << "\n"; // Output the title of the removed song.
            return;
        }
        current = current->next; // Move to the next node.
    }

    // If no song with the given title was found, output a message.
    cout << "Song not found: " << title << "\n";
}


// Method to display all songs in the playlist.
void Playlist::display() const {
    PlaylistNode* current = head;
    while (current) {
        current->song->display(); // Display the current song's details.
        current = current->next; // Move to the next node.
    }
}


// Method to check if the playlist contains a song by title.
bool Playlist::contains(const string& title) const {
    PlaylistNode* current = head;
    while (current) {
        if (current->song->getTitle() == title) {
            return true; // Return true if a song with the matching title is found.
        }
        current = current->next; // Move to the next node.
    }
    return false; // Return false if no matching song is found.
}


// Method to retrieve a song by its title.
Song* Playlist::getSong(const string& title) const {
    PlaylistNode* current = head;
    while (current) {
        if (current->song->getTitle() == title) {
            return current->song; // Return the song if the title matches.
        }
        current = current->next; // Move to the next node.
    }
    return nullptr; // Return nullptr if no song with the title is found.
}


// Method to check if the playlist is empty.
bool Playlist::isEmpty() const {
    return head == nullptr; // Return true if the head is nullptr, meaning the playlist is empty.
}


