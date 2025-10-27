#include <iostream>
#include <vector>
#include <list>
#include <set>
#include <chrono>
#include <fstream>
#include <string>
#include <algorithm>
#include <iomanip>
using namespace std;

// use chrono script for timing from canvas
using namespace std::chrono;

// first we create a struct to hold our results
struct mainResults {
    double vectorTime;
    double listTime;
    double setTime;
    
};

// read all 20,000 strings from the file into a vector
    vector<string> readStringsFromFile(const string& filename) { 
        vector<string> strings; 
        ifstream file(filename); 
        string line;
        while (getline(file, line)) { 
            strings.push_back(line);
        }
        return strings;
    }

    // The first race is READING. The challenge is to read the 20,000 data elements into each of these data structures: vector, list, set

    mainResults readingRace(const vector<string>& data) {
        mainResults results = {0.0, 0.0, 0.0};

        // vector reading
        auto start = high_resolution_clock::now(); // start timing  
        vector<string> vec(data); // push data into vector

        auto end = high_resolution_clock::now(); // end timing
        results.vectorTime = duration_cast<microseconds>(end - start).count();  // how long it took

        //list reading
        start = high_resolution_clock::now();
        list<string> lst(data);

        end = high_resolution_clock::now();
        results.listTime = duration_cast<microseconds>(end - start).count();

        //set reading
        start = high_resolution_clock::now();
        set<string> st(data);

        end = high_resolution_clock::now();
        results.setTime = duration_cast<microseconds>(end - start).count();

        return results;
    }

    
// race 2 for sorting the data structures
    mainResults sortingRace(const vector<string>& data) {
        mainResults results = {0.0, 0.0, 0.0};

        // vector sorting
        vector<string> vec(data);
        auto start = high_resolution_clock::now();
        sort(vec.begin(), vec.end());

        auto end = high_resolution_clock::now();
        results.vectorTime = duration_cast<microseconds>(end - start).count();

        // list sorting
        list<string> lst(data);
        start = high_resolution_clock::now();
        lst.sort();

        end = high_resolution_clock::now();
        results.listTime = duration_cast<microseconds>(end - start).count();






int main() {
    
    //input chrono timer from canvas
       // Start timing
    auto start = high_resolution_clock::now();

    // Example loop to measure
    vector<int> numbers;
    for(int i = 0; i < 1000000; ++i) {
        numbers.push_back(i);
    }

    // End timing
    auto end = high_resolution_clock::now();

    // Calculate duration
    auto duration = duration_cast<microseconds>(end - start);

    // Output the duration in microseconds
    std::cout << "Time taken: " << duration.count() << " microseconds\n";

    return 0;
}

/* syntax examples:
auto start = high_resolution_clock::now()
auto end = high_resolution_clock::now()
auto duration = duration_cast<milliseconds>(end - start)
duration.count() references elapsed milliseconds
*/