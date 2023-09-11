/*
* Write a C++ program that given two vector of integeres returns the common elements 
* found in both elements.

* When solving the solution take a look at the amount of time that'be taken when I use the nested 
* for loop i.e. Line 55 - 59 O(N* M); for the one with using std::set O(N + M) Line 45 - 50
* for the one with using std::unordered_set O(N log(n)) as it uses binary search trees. 
* comment and uncomment them to see the time differences. 
*/

#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <chrono>
#include <vector>
#include <numeric>
#include <set>

class Timer {
public:
    Timer() {}
    void Start() {
        start = std::chrono::high_resolution_clock::now();
    }

    void Stop() {
        end = std::chrono::high_resolution_clock::now();
    }

    std::chrono::microseconds GetExecutionTime() {
        return std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    }

private:
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    std::chrono::time_point<std::chrono::high_resolution_clock> end;
};

std::vector<int>commonElements(const std::vector<int>& vec1, const std::vector<int>& vec2) {
    std::vector<int>cmnElems{};
    //std::set<int>buffer{}; 
    std::unordered_set<int>buffer{};

    ///*
    for (const auto& i : vec1)
        buffer.insert(i);

    for (const auto& i : vec2)
        if (buffer.find(i) != end(buffer))
            cmnElems.push_back(i);
    //*/


    /*
    for (const auto& i : vec1) {
        for (const auto& j : vec2)
            if (i == j)
                cmnElems.push_back(i);
    }
    */

    return cmnElems;
}

int main() {
    Timer obj1;

    obj1.Start();
    std::vector<int>myVec(100000);
    std::vector<int>secVec(100000);

    // Populate my vectors with some elements 
    std::iota(myVec.begin(), myVec.end(), 10);
    std::iota(secVec.begin(), secVec.end(), -255);

    std::vector<int>theCommons = commonElements(myVec, secVec);

    obj1.Stop();
    std::cout << "The time takes for the above calculation is: " << obj1.GetExecutionTime().count() << std::endl;
}

