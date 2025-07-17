#include "Song.h"
#include <iostream>

using namespace std;

// Constructor: Initializes a Song object with a title, artist, and duration.
Song::Song(const string& title, const string& artist, int duration)
    : title(title), artist(artist), duration(duration) {
    // Member initializer list assigns the parameters to the private members.
    // `title`, `artist`, and `duration` are initialized with the passed arguments.
}

// Method to display the details of the song.
void Song::display() const {
    // Output the song's title, artist, and duration in a formatted string.
    cout << "Title: " << title               // Print the song's title.
         << ", Artist: " << artist           // Print the song's artist.
         << ", Duration: " << duration       // Print the song's duration in seconds.
         << " seconds\n";                    // End with the unit of time and a newline.
}

// Getter method for the title of the song.
// Returns a reference to the private `title` variable.
string& Song::getTitle() {
    return title; // Provide access to the song's title for modification.
}

// Getter method for the artist of the song.
// Returns a reference to the private `artist` variable.
string& Song::getArtist() {
    return artist; // Provide access to the song's artist for modification.
}

// Getter method for the duration of the song.
// Returns the `duration` as an integer.
// Marked as `const` to indicate it does not modify the object.
int Song::getDuration() const {
    return duration; // Provide access to the song's duration.
}

// Overloaded equality operator to compare two Song objects.
bool Song::operator==(const Song& other) const {
    // Two Song objects are considered equal if their title, artist, and duration match.
    return title == other.title              // Compare the titles.
        && artist == other.artist            // Compare the artists.
        && duration == other.duration;       // Compare the durations.
}
