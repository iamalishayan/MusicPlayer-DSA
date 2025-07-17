#ifndef PLAYBACKQUEUE_H
#define PLAYBACKQUEUE_H
#include<vector>
#include "Song.h"

//making a node class for the main queue , can also use structure here
class QueueNode {
public:
    Song* song;
    QueueNode* next;
    QueueNode(Song* song);
};
//queue class for the playback queue to play the songs back to back with the FILO principal
class PlaybackQueue {
    QueueNode* front;
    QueueNode* rear;
public:
    PlaybackQueue();
    ~PlaybackQueue();
    void enqueue(Song* song);
    void dequeue();
    bool isEmpty() const;
    Song* top() const;
    void displayPlayBackQueue() const;
    vector<Song*> getAllSongs() const;
    void rebuildFromShuffledList(vector<Song*>& songs);
};

#endif
