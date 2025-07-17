#ifndef SONG_H
#define SONG_H

#include <string>

using namespace std;

//a seperate class for a functional object of this music player
class Song {
    string title;
    string artist;
    int duration;
public:
    //constructor
    Song(const string& title, const string& artist, int duration);
    //display the info of the song
    void display() const;
    //getter for the title of the song
    string& getTitle();
    //getter fot the artist of the song
    string& getArtist();
    //getter for the duration of the song
    int getDuration() const;
    //overloading the == operator for comparisons
    bool operator==(const Song& other) const;
};

#endif
