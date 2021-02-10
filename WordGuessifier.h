#ifndef _WORDGUESSIFIER
#define _WORDGUESSIFIER

#include <iostream>
#include <string>
#include <vector>
#include <random>

using namespace std;

class WordGuessifier { // Given that all members are static, this is probably better refactored as a namespace.

public:
    // display output to user. 
    static void GetWord(string words[]) {
        // get a random word
        int wordIndex = rand() % sizeof(words[0]);
        RunGame(words[wordIndex]);
    }
    // overload
    static void GetWord(vector<string> words) {
        // get a random word
        int wordIndex = rand() % words.size();
        RunGame(words[wordIndex]);
    }
    static void RunGame(string wordToGuess) { // eventually will give additional guesses. Just meeting requirements this week :D
        string hiddenWord(wordToGuess.length(), '*');
        cout << "\nYour word to guess: " << hiddenWord << endl;
        string guess;
        cout << "\nEnter guess: ";
        cin >> guess;
        if (guess == wordToGuess)
            cout << "\nCorrect!" << endl;
        else
            cout << "\nIncorrect! Your word was " <<  "'" << wordToGuess << "'" << endl;
    }        
};
#endif
