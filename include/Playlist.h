#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "Song.h"
#include "vector"

using namespace std;

//a node class to work with the linkedlist of the playlist class
class PlaylistNode {
public:
    Song* song;
    PlaylistNode* next;
    PlaylistNode* prev;
    PlaylistNode(Song* song);
};

//a linkedlist implementation for the playlist , for fast traversal and easy operations
class Playlist {
    PlaylistNode* head;
    PlaylistNode* tail;
public:
    Playlist();
    ~Playlist();
    void addSong(Song* song);
    void removeSong(const string& title);

    bool contains(const string& title) const;
    bool isEmpty() const;
    Song* getSong(const string& title) const;

    void display() const;
};
#endif
