/* GHP 4 - Queries the user for a string of pez candies and removes the yellow pez
    utilizing Nyhoff's stack class, returning the candies in the original order
    without the yellow pez.

    Written by: Connor Damato
    References Used: Nyhoff's stack class
    10/18/23
    Language: C++, GNU GCC Ver. 11.4.0
*/
using namespace std;

#include <string>
#include <iostream>

#include "Stack.h"


int main(void) {
    int i;
    string pez;
    Stack dispenser;

    //getting the pez
    cout<<"Input 10 Pez colors as letters (Use only 'Y' for yellow, 'B' for blue, 'R' for red, and 'O' for orange, no spaces):"<<endl;
    cin>>pez;

    //placing the pez in the dispenser (filtering the yellow)
    for (i = pez.size() - 1; i >= 0; i--) {
        if (pez[i] != 'Y'){
            dispenser.push(pez[i]);
        }
    }

    //taking the pez out of the dispenser
    dispenser.display(cout);
}
