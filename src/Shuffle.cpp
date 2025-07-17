#include "Shuffle.h"
#include <algorithm>
#include <cstdlib>
using namespace std;

//Method to shuffle the playback Queue.
//Uses random number generator to shuffle songs in the playback Queue.
void Shuffle::shuffle(Song* songs[], int size) {
    for (int i = size - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        swap(songs[i], songs[j]);
    }
}

