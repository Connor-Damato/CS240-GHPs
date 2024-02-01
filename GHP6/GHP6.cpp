/*  GHP 6 - A program to query the user for 7 integer inputs and
    displays various statistics based on the data.

    Written by: Connor Damato

    11/30/23
    Language: C++, GNU GCC Ver. 11.4.0
*/
using namespace std;

#include <iostream>
#include <string>

#include <vector>
#include <numeric>
#include <algorithm>

string toString(vector<int> nums);

int main(void) {
    int i, daysDFs;
    vector<int> weeklyDFs(0);
    for(i = 1; i <= 7; i++){
        cout<<"Input the number of cases of dooflingies produced on day "<<i<<": ";
        cin>>daysDFs;
        weeklyDFs.push_back(daysDFs);
    }

    int highest,lowest;
    double avg;

    //part a
    highest = *max_element(weeklyDFs.begin(), weeklyDFs.end());
    lowest = *min_element(weeklyDFs.begin(), weeklyDFs.end());
    avg = ((double)accumulate(weeklyDFs.begin(), weeklyDFs.end(), 0))/weeklyDFs.size();

    //part b
    vector<int> differences(7);
    adjacent_difference(weeklyDFs.begin(), weeklyDFs.end(), differences.begin());

    //part c
    vector<int> runningTotal(7);
    partial_sum(weeklyDFs.begin(), weeklyDFs.end(), runningTotal.begin());


    //outputs
    cout<<"The highest number of dooflingies produced in one day is: "<<highest<<endl;
    cout<<"The lowest number of dooflingies produced in one day is: "<<lowest<<endl;
    cout<<"The average number of dooflingies produced per day is: "<<avg<<endl;

    cout<<"The differences in the dooflingies per day are: "<<toString(differences)<<endl;
    cout<<"The running total of dooflingies per day over the week are: "<<toString(runningTotal)<<endl;

    return 0;
}


/*  Function to take a vector of integers and turn it into a formatted string

    Precondition: vector is not empty

    Written by Connor Damato
    11/30/23
    Language: C++, GNU GCC Ver. 11.4.0
*/
string toString(vector<int> nums) {
    string output = "[";
    int i;
    int size = nums.size() - 1;
    for(i = 0; i < size; i++) {
        output += to_string(nums[i]) + ", ";
    }
    return output + to_string(nums[i]) + "]";
}
