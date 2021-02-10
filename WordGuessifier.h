#ifndef _WORDGUESSIFIER
#define _WORDGUESSIFIER

#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

class WordGuessifier {

public:

    // display output to user. 
    static void RunGame(string words[]) {
        // get a random word
        int wordIndext = rand() % sizeof(words[0]);

    }
    // overload
    static void RunGame(vector<string> words) {
        // get a random word
        int wordIndex = rand() % words.size();
        
    }
};
#endif