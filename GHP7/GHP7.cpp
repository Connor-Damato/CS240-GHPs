/*  GHP 7 - Driver function that queries the user for 10 words
    and then continuously queries the user for words and checks if they
    are in the given list.
    Written by: Connor Damato

    12/8/23
    Language: C++, GNU GCC Ver. 11.4.0
*/
using namespace std;

#include <iostream>
#include <string>

#include <vector>
#include "HashVector.h"

int main(void) {
    HashVector wordList;
    int i;
    string tempInput = "";

    //fill the HashVector
    for (i = 0; i < 10; i++) {
        cout<<"Input word "<<i + 1<<" for the list: ";
        cin>>tempInput;
        wordList.insert(tempInput);
    }

    //display contents
    wordList.display(cout);

    //search loop
    bool loop = true;
    string query = "";
    cout<<"(Use '/exit' to leave)"<<endl;
    while (loop) {
        cout<<"Input a word to search for: ";
        cin>>query;
        if (query == "/exit") {
            loop = false;
            cout<<"Goodbye"<<endl;
        } else {
            cout<<query<<" is "<<(wordList.find(query)?"":"not ")<<"found."<<endl;
        }
    }
}
