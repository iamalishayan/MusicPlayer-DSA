#ifndef SEARCHENGINE_H
#define SEARCHENGINE_H
#include <vector>
#include <string>
#include "Queue.h"
using namespace std;
//implementation of the trie data structure for prefix based searching
class TrieNode {
public:
    TrieNode* children[37];
    bool isEndOfWord;
    string originalTitle;
    TrieNode();
};

//a complete search engine class using the implementaion of the trie DS
class SearchEngine {
    TrieNode* root;
    //for collection for words to insert in the trie
    void collect(TrieNode* node, const string& prefix, vector<string>& results);
    //for mapping the characters in the prefix to appropriate indices of the trie
    int charToIndex(char c);
public:
    //initialie the trie node
    SearchEngine();
    //deallocate the memory for the trie
    ~SearchEngine();
    //insert a song in the trie and handle all the case sensitivities
    void insert(const string& title);
    //main search engine implementation for prefix based searching
    vector<string> search(const string& prefix);
    //for recursive removal of trie nodes
    void destroy(TrieNode* node);
    //for removing a song from the trie
    void remove(const string& title);
};
#endif
