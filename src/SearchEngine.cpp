#include "SearchEngine.h"
#include <cctype>
#include <iostream>
using namespace std;

// TrieNode Constructor: Initializes all children to nullptr and marks the end of the word as false.
TrieNode::TrieNode() : isEndOfWord(false) {
    for (int i = 0; i < 37; ++i) {  // Loop through all children (37 characters: a-z, 0-9, space).
        children[i] = nullptr;  // Initialize all child pointers to nullptr.
    }
}

// SearchEngine Constructor: Initializes the root node of the Trie.
SearchEngine::SearchEngine() : root(new TrieNode()) {}

// SearchEngine Destructor: Cleans up dynamically allocated memory for Trie nodes.
SearchEngine::~SearchEngine() {
    destroy(root); // Calls destroy function to delete all nodes starting from the root.
}

// Helper function to delete Trie nodes recursively.
void SearchEngine::destroy(TrieNode* node) {
    for (int i = 0; i < 37; ++i) {  // Loop through all children (37 characters: a-z, 0-9, space).
        if (node->children[i]) {
            destroy(node->children[i]); // Recursively delete child nodes.
        }
    }
    delete node; // Delete the current node.
}

// Helper function to map characters to Trie indices.
int SearchEngine::charToIndex(char c) {
    if (islower(c)) {
        return c - 'a';  // Convert lowercase letters to an index (0-25).
    } else if (isdigit(c)) {
        return c - '0' + 26;  // Map digits 0-9 to indices 26-35.
    } else if (c == ' ') {
        return 36;  // Map space character to index 36.
    }
    return -1;  // Return -1 for invalid characters.
}

// Insert method: Insert a title into the Trie while handling spaces, case insensitivity, and digits.
void SearchEngine::insert(const string& title) {
    for (size_t start = 0; start < title.size(); ++start) {
        TrieNode* current = root; // Start at the root node.

        for (size_t i = start; i < title.size(); ++i) {
            char c = title[i]; // Get the current character.

            if (isalpha(c)) {
                c = tolower(c);  // Convert to lowercase for case-insensitive matching.
            }

            int index = charToIndex(c);  // Map character to index in the Trie.
            if (index == -1) continue;  // Skip invalid characters (e.g., punctuation).

            if (!current->children[index]) {
                current->children[index] = new TrieNode();  // Create a new node if it doesn't exist.
            }

            current = current->children[index]; // Move to the next node in the Trie.
        }

        current->isEndOfWord = true; // Mark the end of a valid word.
        current->originalTitle = title;  // Store the original title in the node.
    }
}

// Search method: Search for titles starting with the given prefix.
vector<string> SearchEngine::search(const string& prefix) {
    TrieNode* current = root; // Start at the root node.
    vector<string> results;  // Vector to store the matching titles.

    // Traverse the Trie for the prefix.
    for (char c : prefix) {
        if (isalpha(c)) {
            c = tolower(c);  // Convert to lowercase for case insensitivity.
        }

        int index = charToIndex(c);  // Map character to index.
        if (index == -1) {
            return results;  // Return empty results if invalid character is found in prefix.
        }

        if (!current->children[index]) {
            return results;  // Return empty results if prefix doesn't match.
        }

        current = current->children[index]; // Move to the next node in the Trie.
    }

    // Collect all matching titles that start with the prefix.
    collect(current, prefix, results);
    return results; // Return the list of matching titles.
}

// Helper function to collect words starting with the current node.
void SearchEngine::collect(TrieNode* node, const string& prefix, vector<string>& results) {
    if (node == nullptr) return; // Base case: return if node is null.

    Queue<TrieNode*> q;  // Create a queue to traverse the Trie nodes.
    q.enqueue(node);  // Enqueue the current node.

    while (!q.isEmpty()) {
        TrieNode* currentNode = q.top(); // Get the first node from the queue.
        q.dequeue(); // Remove the node from the queue.

        if (currentNode->isEndOfWord) {
            results.push_back(currentNode->originalTitle); // If it's the end of a word, add to results.
        }

        for (int i = 0; i < 37; ++i) {  // Check all possible child nodes (37 characters).
            if (currentNode->children[i]) {
                q.enqueue(currentNode->children[i]);  // Enqueue child nodes for further processing.
            }
        }
    }
}

// Remove a title from the Trie.
void SearchEngine::remove(const string &title) {
    TrieNode* current = root; // Start at the root node.
    TrieNode* parent = nullptr; // To track the parent of the current node.
    int lastIndex = 0; // Index of the last character in the title.

    for (char c : title) {
        if (isalpha(c)) {
            c = tolower(c);  // Convert to lowercase for case-insensitive search.
        }

        int index = charToIndex(c);  // Map character to index.
        if (index == -1 || !current->children[index]) {
            cout << "Title not found in the search engine.\n";  // Title doesn't exist.
            return;
        }

        parent = current;  // Set parent to current node.
        current = current->children[index]; // Move to the next node in the Trie.
        lastIndex = index;  // Store the index of the last character in the title.
    }

    if (current->isEndOfWord) {
        current->isEndOfWord = false; // Mark this node as no longer an end of a word.

        // Check if the current node has children.
        bool hasChildren = false;
        for (int i = 0; i < 37; ++i) {
            if (current->children[i]) {
                hasChildren = true; // Node has children, so it can't be deleted.
                break;
            }
        }

        // If no children exist, delete the node and unlink it from the parent.
        if (!hasChildren) {
            delete current;
            parent->children[lastIndex] = nullptr; // Unlink the node from its parent.
        }

        cout << "Title removed from the search engine.\n";
    } else {
        cout << "Title not found as an exact match.\n";  // Exact match not found.
    }
}
