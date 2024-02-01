/*  HashVector - Class to implement HashVector object that
    stores and queries strings.
    Written by: Connor Damato

    12/8/23
    Language: C++, GNU GCC Ver. 11.4.0
*/
#include <iostream>
#include <string>
#include <cassert>
#include <vector>
using namespace std;

#include "HashVector.h"

/*  HashVector constructor
    Written by: Connor Damato
    12/8/23
*/

HashVector::HashVector(){
    values.resize(15);
}


/*  Definition of insert()
    Written by: Connor Damato
    12/8/23
*/
void HashVector::insert(string query) {
    int startPos = getPosition(query);
    int i = startPos;
    bool inserted = false;

    //checks starting point
    if (values[i] == "") {
        values[i] = query;
        inserted = true;
    } else {
        i = (i + 1) % 15;
    }

    while(i != startPos && !inserted)  {
        if (values[i] == "") {
            values[i] = query;
            inserted = true;
        }
        i = (i + 1) % 15;
    }
}

/*  Definition of find()
    Written by: Connor Damato
    12/8/23
*/
bool HashVector::find(string query) {
    int startPos = getPosition(query);
    int i = startPos;
    bool found = false;

    //checks starting point
    if (values[i] == query) {
        found = true;
    } else {
        i = (i + 1) % 15;
    }

    while(i != startPos  && !found)  {
        if (query == values[i]) {
            found = true;
        }
        i = (i + 1) % 15;
    }

    return found;
}

/*  Definition of getPosition()
    Written by: Connor Damato
    12/8/23
*/
int HashVector::getPosition(string query) {
    return ((query[0] * 2) + (query[query.size() - 1] - 1)) % 15;
}

/*  Definition of display()
    Written by: Connor Damato
    12/8/23
*/
void HashVector::display(ostream & out)
{
   for (int i = 0; i < 15; i++)
      out <<i + 1<<":\t"<<values[i]<< endl;
}

