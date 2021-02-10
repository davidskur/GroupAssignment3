#include <iostream>
#include "Parameters.h"
#include "FileReadifierTurbo.h"
#include "WordGuessifier.h"

using namespace std;

// forward dec
double CheckInput(string strPrompt);

int main(int argc, char* argv[])
{
    CheckForCommandLineParameters(argc, argv);

    // Create pointer variable. Don't bother creating an object unless the user requests file input.
    FileReadifierTurbo* fileReader = NULL;

    bool bRunAgain;
    do 
    {
        bRunAgain = false;
        cout << "\n----------------------" << endl;
        cout << "\nMake a selection:" << endl;
        cout << "\n1) Get words from a sample file." << endl;
        cout << "\n2) Enter your own words." << endl;
        cout << "\n3) Press any other key to bring up the exit prompt." << endl;
        
        int intSelection = CheckInput("\nSelection: ");

        switch (intSelection) {
        case 1: // read from file
        {
            cout << "\n----------------------" << endl;
            cout << "\nChoose directory: " << endl;
            cout << "\n1) Working Directory" << endl;
            cout << "\n2) Specify a Path" << endl;

            int fileSelection = CheckInput("\nSelection: ");

            // create new reader objects, get file info
            fileReader = new FileReadifierTurbo;
            if (fileSelection == 1){                 
                WordGuessifier::GetWord(fileReader->GetWordList()); // Static method call. todo: research templates
            }
            else {
                string path;
                cout << "\nEnter a file path verbatim: ";
                cin >> path;
                WordGuessifier::GetWord(fileReader->GetWordList(path)); // overload
            }
            // destroy reader object
            delete fileReader;
            break;
        }
        case 2: // input words
        {
            string wordArray[10];
            for (int i = 0; i < sizeof(wordArray)/sizeof(wordArray[0]); i++) {
            	cout << "\nEnter a string (" << (i+1) << " of 10): ";
            	cin >> wordArray[i];
            }
            bool bPlayAgain;
            do {
                bPlayAgain = false;
                WordGuessifier::GetWord(wordArray); // another static method call

                // check for another run
		        string strResponse;
		        cout << "\nRun game again? (y/n) ";
		        cin >> strResponse;
		        if (strResponse == "y" || strResponse == "yes") bPlayAgain = true;

            } while (bPlayAgain);
            break;
        }
        default:
            break;
        }
        // check for another run
        string strResponse;
        cout << "\nRun program again? (y/n) ";
        cin >> strResponse;
        if (strResponse == "y" || strResponse == "yes") bRunAgain = true;

    } while (bRunAgain);
}
// functions
double CheckInput(string strPrompt) {
    string strInput;
    cout << strPrompt;
    cin >> strInput;
    return strtod(strInput.c_str(), NULL); // strtod doesn't throw exceptions
}
