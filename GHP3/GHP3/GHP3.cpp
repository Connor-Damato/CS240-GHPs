/* GHP 3 - Alternative: Creates a 26x10 array and fills each cell with
    the number of times a letter appears in it's given position up to words
    of length 10. The program then prints the result.

    Written by: Connor Damato
    References Used: https://cplusplus.com/doc/tutorial/files/
    10/4/23
    Language: C++, GNU GCC Ver. 11.4.0
*/

using namespace std;

#include <iostream>
#include <fstream>
#include <string>

void countWord(string word, int data[26][10]);
int letterToPosition(char letter);
bool isDupeLetter(string word, int pos);
void printData(const int data[26][10]);

int main(void) {
    string fileName, nextWord;
    ifstream fReader;
    int data[26][10] = { 0 };
    int numWords = 0;

    cout<<"Enter the name of the file: ";
    cin>>fileName;

    //if/else logic written using reference
    fReader.open(fileName);
    if (fReader.is_open()) {
        while(fReader>>nextWord) {
            numWords++;
            countWord(nextWord, data);
        }
        fReader.close();
        cout<<"There "<<(numWords==1?"is ":"are ")<<numWords<<" word"<<(numWords!=1?"s":"")<<" in this file."<<endl;
        printData(data);
    } else {
        cout<<"There was an error opening the file"<<endl;
    }

    return 0;
}

/*  Function to fill the 2x2 array with the given word from the text file
    Preconditions: Data has been initialized to zero so we can increment each position
    Postconditions: Data has been adjusted

    Note: We must check bounds from the letterToPosition functions.

    Written by Connor Damato
    10/4/23
    Language: C++, GNU GCC Ver. 11.4.0
*/
void countWord(string word, int data[26][10]) {
    int i, size;
    size = (word.size())>10? 9:word.size() - 1;
    for (i = 0; i < word.size(); i++) {
        if (i == 0 || !isDupeLetter(word, i)) {
            int letterPos = letterToPosition(tolower(word[i]));
            //checks bounds in case of punctuation in file
            if (letterPos >= 0 && letterPos <= 25) {
                data[letterPos][size]++;
            }
        }
    }
}


/*  Function to get the integer position of a letter
    Preconditions: The character is lowercase
    Postconditions: The position in reference to lowercase 'a'

    Note: this function still returns values for non-letter chars, so we must check
    bounds after the value is returned.

    Written by Connor Damato
    10/4/23
    Language: C++, GNU GCC Ver. 11.4.0
*/
int letterToPosition(char letter) {
    return (letter - 'a');
}


/*  Function to check if the letter at a given position already exists in the word
    Preconditions: The word is larger than size 1
    Postconditions: Returns true if the letter is a duplicate, false otherwise

    Written by Connor Damato
    10/13/23
    Language: C++, GNU GCC Ver. 11.4.0
*/
bool isDupeLetter(string word, int pos) {
    int i = 0;
    bool isDupe = false;
    while (i < pos && !isDupe) {
        if (word[i] == word[pos]) {
            isDupe = true;
        }
        i++;
    }

    return isDupe;
}


/*  Function to print the data to the terminal
    Preconditions: Data is initialized and filled

    Written by Connor Damato
    10/4/23
    Language: C++, GNU GCC Ver. 11.4.0
*/
void printData(const int data[26][10]) {
    int row, col;
    for (row = 0; row < 26; row++) {
        //data labels
        cout<<(char)('A' + row)<<":\t";
        for (col = 0; col < 10; col++) {
            //data nums
            cout<<data[row][col]<<"\t";
        }
        cout<<endl;
    }
}
