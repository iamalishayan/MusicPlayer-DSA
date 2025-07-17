// Created by muz on 11/30/24.

#include "MusicPlayer.h"
#include <iostream>
#include <vector>

using namespace std;


/* MusicPlayer constructor:
   Initializes the playlist with some songs and inserts them into the search engine. */
MusicPlayer::MusicPlayer() {
    // Create some song objects with title, artist, and duration.
    Song* song1 = new Song("Song A", "Artist 1", 200);
    Song* song2 = new Song("Song B", "Artist 2", 180);
    Song* song3 = new Song("Song C", "Artist 3", 240);
    Song* song4 = new Song("Song D", "Artist 4", 220);

    // Add created songs to the playlist.
    playlist.addSong(song1);
    playlist.addSong(song2);
    playlist.addSong(song3);
    playlist.addSong(song4);

    // Insert song titles into the search engine for future search functionality.
    searchEngine.insert("Song A");
    searchEngine.insert("Song B");
    searchEngine.insert("Song C");
    searchEngine.insert("Song D");
}


/* Displays the menu of available options for the user to interact with the MusicPlayer. */
void MusicPlayer::displayMenu() {
    // Display options for managing songs, queue, and playback.
    cout << "\n1. Add Song to Playlist\n";
    cout << "2. Remove Song from Playlist\n";
    cout << "3. Display Playlist\n";
    cout << "4. Enqueue Song to Playback Queue\n";
    cout << "5. Display PlayBackQueue\n";
    cout << "6. Play Next Song\n";
    cout << "7. Shuffle Playback Queue\n";
    cout << "8. Search for Song\n";
    cout << "9. Exit\n";
}


/* Allows the user to add a new song to the playlist by providing song details (title, artist, duration). */
void MusicPlayer::addSong() {
    string title, artist;
    int duration;

    // Prompt the user to enter the song's title, artist, and duration.
    cout << "Enter song title: ";
    cin.ignore();
    getline(cin, title);
    cout << "Enter artist name: ";
    getline(cin, artist);
    cout << "Enter song duration in seconds: ";
    cin >> duration;

    // Create a new song object and add it to the playlist and search engine.
    Song* newSong = new Song(title, artist, duration);
    playlist.addSong(newSong);
    searchEngine.insert(title);
    cout << "Song added to playlist.\n";
}


/* Allows the user to remove a song from the playlist by specifying the title. */
void MusicPlayer::removeSong() {
    string title;

    // Prompt the user for the song title to remove.
    cout << "Enter song title to remove: ";
    cin.ignore();
    getline(cin, title);

    // Check if the song exists in the playlist.
    if (!playlist.contains(title)) {
        cout << "Song not found in the playlist.\n";
        return;
    }

    // Remove the song from the playlist and the search engine.
    playlist.removeSong(title);
    searchEngine.remove(title);
    cout << "Song removed from playlist.\n";
}


/* Displays the current playlist. If the playlist is empty, it displays a message. */
void MusicPlayer::displayPlaylist() {
    if (playlist.isEmpty()) {
        cout << "The playlist is empty.\n";  // If playlist is empty, notify the user.
        return;
    }

    // Otherwise, display all the songs in the playlist.
    playlist.display();
}


/* Adds a song to the playback queue by first ensuring it exists in the playlist. */
void MusicPlayer::enqueueSong() {
    string title;

    // Ask the user for the title of the song to enqueue.
    cout << "Enter song title to enqueue: ";
    cin.ignore();
    getline(cin, title);

    // Retrieve the song from the playlist.
    Song* song = playlist.getSong(title);
    if (!song) {
        cout << "Song not found in the playlist.\n";  // If the song doesn't exist, notify the user.
        return;
    }

    // Enqueue the song to the playback queue.
    playbackQueue.enqueue(song);
    cout << "Song added to playback queue.\n";
}


/* Plays the next song in the playback queue and dequeues it. */
void MusicPlayer::playNextSong() {
    if (playbackQueue.isEmpty()) {
        cout << "Playback queue is empty.\n";  // Notify if the queue is empty.
        return;
    }

    // Retrieve and display the song at the top of the playback queue.
    Song* song = playbackQueue.top();
    cout << "Now playing: " << song->getTitle() << " by " << song->getArtist() << "\n";

    // Dequeue the song after it's played.
    playbackQueue.dequeue();
}


/* Shuffles the playlist by retrieving all songs, converting them into an array, and using a Shuffle class. */
void MusicPlayer::shufflePlaybackQueue() {
    if (playbackQueue.isEmpty()) {
        cout << "The playback queue is empty. Cannot shuffle.\n";
        return;
    }

    // Retrieve all songs from the playback queue
    vector<Song*> allSongs = playbackQueue.getAllSongs();

    // Shuffle using the Shuffle class
    int size = allSongs.size();
    Song* songArray[size];
    for (int i = 0; i < size; ++i) {
        songArray[i] = allSongs[i];
    }
    Shuffle::shuffle(songArray, size);

    // Rebuild the playback queue with the shuffled order
    vector<Song*> shuffledSongs(songArray, songArray + size);
    playbackQueue.rebuildFromShuffledList(shuffledSongs);

    // Display the shuffled playback queue
    cout << "Shuffled Playback Queue:\n";
    for (Song* song : shuffledSongs) {
        song->display();
    }
}


/* Allows the user to search for songs by a prefix and display matching results. */
void MusicPlayer::searchSong() {
    string prefix;

    // Prompt the user to enter a prefix for searching songs.
    cout << "Enter song prefix to search: ";
    cin.ignore();
    getline(cin, prefix);

    // Perform the search using the search engine and display the results.
    vector<string> results = searchEngine.search(prefix);
    if (results.empty()) {
        cout << "No songs found.\n";  // Notify if no songs match the search.
    } else {
        cout << "Found songs:\n";
        for (const string& song : results) {
            cout << song << "\n";  // Display each found song.
        }
    }
}


/* Displays the current state of the playback queue. */
void MusicPlayer::displayPlaybackQueue() {
    playbackQueue.displayPlayBackQueue();  // Display all songs currently in the playback queue.
}


/* The main loop that runs the music player, continuously displaying the menu and processing user choices. */
void MusicPlayer::run() {
    bool running = true;
    while (running) {
        // Display the menu of available actions.
        displayMenu();

        int choice;
        cin >> choice;

        // Process the user's menu choice and call the appropriate method.
        switch (choice) {
            case 1: addSong(); break;
            case 2: removeSong(); break;
            case 3: displayPlaylist(); break;
            case 4: enqueueSong(); break;
            case 5: displayPlaybackQueue(); break;
            case 6: playNextSong(); break;
            case 7: shufflePlaybackQueue(); break;
            case 8: searchSong(); break;
            case 9: running = false; break;  // Exit the loop and stop the music player.
            default: cout << "Invalid choice.\n";  // Notify if the user enters an invalid choice.
        }
    }
}
