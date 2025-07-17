// MusicPlayer.h
#ifndef MUSIC_PLAYER_H
#define MUSIC_PLAYER_H

#include "Playlist.h"
#include "PlaybackQueue.h"
#include "SearchEngine.h"
#include "Shuffle.h"
#include <string>

//final application class which contains all the functionalities
class MusicPlayer {
    Playlist playlist;
    PlaybackQueue playbackQueue;
    SearchEngine searchEngine;
public:
    //constructor
    MusicPlayer();
    //to display the menu
    void displayMenu();
    //do add a song in the playlist
    void addSong();
    // to remove the song from the playlist
    void removeSong();
    //to display the playlist
    void displayPlaylist();
    //to display the playback queue
    void displayPlaybackQueue();
    //to enqueue song in the playback queue
    void enqueueSong();
    //to play the next song in the playback queue
    void playNextSong();
    //shuffle the playlist
    void shufflePlaybackQueue();
    //search for a song in the playlist
    void searchSong();
    //run the application
    void run();
};

#endif
