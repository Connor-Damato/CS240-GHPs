/*  HashVector.h - Header file to define a HashVector object
    that stores and queries strings based on a specific hash function
    Written by: Connor Damato

    12/8/23
    Language: C++, GNU GCC Ver. 11.4.0
*/

#include <iostream>
#include <vector>

#ifndef STACK
#define STACK

class HashVector {
    public:
        /*  HashVector(): constructs a new HashVector object and initializes the size to 15
            Written by: Connor Damato
            12/8/23
        */
        HashVector();


        /*  insert(): inserts a new string into the vector using hashing
            Written by: Connor Damato
            12/8/23
        */
        void insert(string query);


        /*  find(): searches the vector for the given string using hashing
            Written by: Connor Damato
            12/8/23
        */
        bool find(string query);


        /*  getPosition(): the hash function to determine where the string should be
            placed/searched for
            ((first_letter*2) + (last_letter-1))% 15
            Preconditions: assumes the string isn't empty
            Written by: Connor Damato
            12/8/23
        */
        int getPosition(string query);


        /*  display(): displays the current contents of the HashVector in a numbered list
            Written by: Connor Damato
            12/8/23
        */
        void display(ostream & out);

    private:
        //holds the strings so they can be accessed later
        vector<string> values;




};

#endif // HASHVECTOR
