#ifndef _FILEREADIFIERTURBO
#define _FILEREADIFIERTURBO

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class FileReadifierTurbo {

private:
    fstream wordFile;
	
public:
	// constructor
	FileReadifierTurbo() {};
	// destructor
	~FileReadifierTurbo() { wordFile.close(); } // TODO: Read more about destructors. This pry isn't needed.

    // current dir, included txt file
    vector<string> GetWordList() {
        vector<string> words;

        wordFile.open("words.txt", fstream::in);
        if (!wordFile) {
            cout << "\nFile not found!" << endl;
            return { }; // list initialization
        }
        else if (wordFile.is_open()) { // file found
            string newLine;
            while (getline(wordFile, newLine)) {
                words.push_back(newLine);
            }
        }
        wordFile.close();
        return words;
    }
    // overload
	vector<string> GetWordList(string fileName) {
        vector<string> words;
        
        wordFile.open(fileName, fstream::in);
        if (!wordFile) {
            cout << "\nFile not found!" << endl;
            return { };
        }
        else if (wordFile.is_open()) {
            string newLine;
            while (getline(wordFile, newLine)) {
                words.push_back(newLine);
            }
        }
        wordFile.close();
        return words;
	}
};
#endif
