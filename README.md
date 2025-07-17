# MusicPlayer-DSA

# DSA-Based Music Player (C++)

A console-based Music Player developed in **C++** using fundamental **Data Structures and Algorithms (DSA)**. This project simulates a basic music player with core features like play, next, previous, add, delete, and search — built using **Linked Lists**, **Queues**, and **Tries**.

---

## Data Structures Used

| Feature         | Data Structure     | Purpose                                                    |
|----------------|--------------------|------------------------------------------------------------|
| Playlist        | Doubly Linked List | To navigate between songs (forward/backward traversal)     |
| "Next Up" Queue | Queue              | To manage upcoming songs in a linear order                 |
| Search Songs    | Trie               | For efficient prefix-based searching of song names         |

---

## How to Run

1. Make sure you have **Code::Blocks** installed.  
   🔗 [Download Code::Blocks](http://www.codeblocks.org/downloads)

2. Open the project file: MusicPlayerDSAProject.cbp

3. Click **Build and Run** (or press `F9`) in Code::Blocks.

4. Use the interactive console interface to:
- Add/Delete songs
- Play/Skip songs
- Search songs using Trie

---

## Features

- Add new songs to the playlist.
- Play songs and move to next/previous.
- Efficient song search using prefix matching (Trie).
- Display the full playlist.
- Console-based, interactive interface.
- Written completely in **C++ without external libraries**.

---

## Future Enhancements

- Add file I/O to save/load playlists.
- GUI integration using libraries like Qt.
- Shuffle and repeat options.
- Display song metadata (duration, artist, etc.)

---

## Author

- **Ali Shayan** – [GitHub Profile](https://github.com/iamalishayan)