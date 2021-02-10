#include <iostream>
#include "Parameters.h"
#include "FileReadifierTurbo.h"

// forward dec
double CheckInput(string strPrompt);

int main(int argc, char* argv[])
{
    CheckForCommandLineParameters(argc, argv);

    // Create pointer variable. No need to create an object unless the user requests file input.
    FileReadifierTurbo* fileReader = NULL;

    bool bRunAgain;
    do 
    {
        bRunAgain = false;
        cout << "\nMake a selection:" << endl;
        cout << "\n1) Get words from a sample file." << endl;
        cout << "\n2) Enter your own words." << endl;
        
        int intSelection = CheckInput("\nSelection: ");

        switch (intSelection) {
        case 1: // read from file
        {
            // create new reader object
            fileReader = new FileReadifierTurbo;
            fileReader->GetFileText("words.txt");

            // destroy
            delete fileReader;
        }
        case 2: // input words
        {

        }
        default:
            cout << "\nUnknown input! Please make another selection." << endl;
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
