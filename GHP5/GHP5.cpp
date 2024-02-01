/*  GHP 5 - Alternative: The program takes a file name from the user and then searches the file for
    palindromes and palindromes with the letter m, outputting them and displaying the stats for the file.

    Written by: Connor Damato
    References:
    https://cplusplus.com/reference/string/string/npos/   <- used for the string find() function for m palindromes
    https://cplusplus.com/reference/string/to_string/     <- used for the to_string() function in cout
    https://cplusplus.com/reference/stack/stack/?kw=stack <- used for stack functions
    https://cplusplus.com/reference/queue/queue/?kw=queue <- used for queue functions

    11/7/23
    Language: C++, GNU GCC Ver. 11.4.0
*/

using namespace std;

#include <String>
#include <iostream>
#include <fstream>
#include <stack>
#include <queue>

bool isPalindrome(string word);
bool isMPal(string word);
void printMPals(string filename, int maxPal);

int main(void) {
    int totalWords = 0;
    int mPalindromes = 0;
    int numPals = 0;
    int numMax = 0;
    int maxM = 0;
    int maxPal = 0;
    string maxPalWord ="";
    string filename, nextWord;
    ifstream fReader;
    cout<<"Enter the filename for the palindromes: ";
    cin>>filename;

    fReader.open(filename);
    if (fReader.is_open()) {
        while(fReader>>nextWord) {
            //regular palindrome data
            totalWords++;
            if(isPalindrome(nextWord)) {
                numPals++;
                cout<<nextWord<<endl;

                //biggest pal
                if (nextWord.size() > maxPal) {
                    maxPal = nextWord.size();
                    maxPalWord = nextWord;

                }

                //'m' palindrome data
                if((nextWord).find('m') != string::npos) {
                    mPalindromes++;
                    int size = nextWord.size();
                    if (size > maxM) {
                        maxM = size;
                        numMax = 1;
                    } else if (size == maxM) {
                        numMax++;
                    }
                }
            }
        }

        fReader.close();

        //displaying the data collected
        cout<<"There "<<(totalWords==1?"is ":"are ")<<(totalWords==0?"no":to_string(totalWords))<<" word"<<(totalWords==1?"":"s")<<" in this file."<<endl;
        if (totalWords!=0) {
            cout<<((numPals==totalWords && numPals==1)?"The":to_string(numPals))<<" word"<<(numPals==1?" ":"s ")<<(numPals==1?"is a ":"are ")<<"palindrome"<<(numPals==1?".":"s.")<<endl;

            if (numPals!=0) {
                cout<<((mPalindromes==numPals && mPalindromes==1)?"The":to_string(mPalindromes))<<" palindrome"<<(mPalindromes==1?"":"s")<<" contain"<<(mPalindromes==1?"s":"")<<" letter 'm'."<<endl;

                if (mPalindromes != 0) {
                    cout<<"The length of the longest palindrome containing the letter 'm' is "<<maxM<<"."<<endl;
                    cout<<"The "<<numMax<<" palindrome"<<(numMax!=1?"s":"")<<" of length "<<maxM<<" that contain"<<(numMax==1?"s":"")<<" the letter 'm' "<<(numMax==1?"is:":"are:")<<endl;
                     printMPals(filename, maxM);
                }
            }
        }

    } else {
        cout<<"There was an error opening the file"<<endl;
    }


    cout<<"Longest Palindrome: "<<maxPalWord<<endl;
    cout<<"Length: "<<maxPal<<endl;
    return 0;
}

/*  Function to check if the given string is a palindrome using both
    queue and stack structures.

    Precondition: word is not longer than 128 letters

    Written by Connor Damato
    11/7/23
    Language: C++, GNU GCC Ver. 11.4.0
*/
bool isPalindrome(string word) {
    stack<char> sWord;
    queue<char> qWord;
    int i,j;
    int size = word.size();
    bool isPal = true;

    //fill stack & queue
    for (i = 0; i < size; i++) {
        sWord.push(tolower(word[i]));
        qWord.push(tolower(word[i]));
    }

    //check for differences
    for (j = 0; j < (size / 2) && isPal; j++) {
        if (qWord.front() != sWord.top()) {
            isPal = false;
        } else {
            sWord.pop();
            qWord.pop();
        }
    }
    return isPal;
}

/*  Function to check if the given string is a palindrome that contains
    the letter 'm'

    Precondition: word is not longer than 128 letters

    Written by Connor Damato
    11/2/23
    Language: C++, GNU GCC Ver. 11.4.0
*/
bool isMPal(string word) {
    return(isPalindrome(word) && word.find("m") != string::npos);
}

/*  Function to go through the given file and print the longest
    palindrome(s) that contain the letter 'm'

    Written by Connor Damato
    11/2/23
    Language: C++, GNU GCC Ver. 11.4.0
*/
void printMPals(string filename, int maxPal) {
    string nextWord;
    ifstream fReader;
    fReader.open(filename);
    if (fReader.is_open()) {
        while(fReader>>nextWord) {
            int size = nextWord.size();
            if(size == maxPal && isMPal(nextWord)) {
               cout<<nextWord<<endl;
            }
        }
    } else {
        cout<<"An error occurred while opening the file"<<endl;
    }
}
