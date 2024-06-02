// Include statements for libraries 
#include <iostream>      // For standard I/O operations
#include <fstream>       // For file handling operations
#include <vector>        // For using std::vector container
#include <sstream>       // For parsing strings
#include <chrono>        // For timing code execution

// Include function declarations
#include "StdSort.hpp"   // Include for StdSort function declaration
#include "QuickSelect1.hpp" // Include for QuickSelect1 function declaration
#include "QuickSelect2.hpp" // Include for QuickSelect2 function declaration
#include "CountingSort.hpp" // Include for CountingSort function declaration

// Function to read integers from a file and store them in a vector
std::vector<int> readIntegersFromFile(const std::string& filename, std::vector<int>& values){
    std::ifstream inputFile(filename);    // Create an input file stream to read from the specified file

    // Check if the file was successfully opened
    if(!inputFile.is_open()) {
        std::cerr << "Error: Unable to open file " << filename << std::endl;        // Print an error message if the file cannot be opened
        exit(1);        // Exit the program with a non-zero exit code indicating failure
    }

    std::string line;       // String to hold each line read from the file

    // Read the file line by line
    while(std::getline(inputFile, line)) {
        std::istringstream iss(line);           // Create a string stream from the line for parsing integers
        int num;

        while (iss >> num){
            values.push_back(num);          // Extract integers from the line and add them to the vector
        }
    }

    inputFile.close();      // Close the file to release system resources

    return values;      // Return the populated vector
}

int main(){
    std::string filename = "test_input.txt";        // Define the name of the input file

    std::vector<int> values;    // Vector to store integer values read from the file

    std::vector<int> data = readIntegersFromFile(filename, values);     // Read integers from the specified file into the vector 'values'

    std::string header = "Male elephant seal weights";      // Header to describe the data being processed

    // Measure and print the time taken by stdSort
    auto start = std::chrono::high_resolution_clock::now();
    stdSort(header, data);
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed = end - start;
    std::cout << "Time taken for stdSort: " << elapsed.count() << " ms\n";

    // Measure and print the time taken by quickSelect1
    auto start1 = std::chrono::high_resolution_clock::now();
    quickSelect1(header, data);
    auto end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed1 = end1 - start1;
    std::cout << "Time taken for quickSelect1: " << elapsed1.count() << " ms\n";

    // Measure and print the time taken by quickSelect2
    auto start2 = std::chrono::high_resolution_clock::now();
    quickSelect2(header, data);
    auto end2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed2 = end2 - start2;
    std::cout << "Time taken for quickSelect2: " << elapsed2.count() << " ms\n";

    // Measure and print the time taken by countingSort
    auto start3 = std::chrono::high_resolution_clock::now();
    countingSort(header, data);
    auto end3 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsed3 = end3 - start3;
    std::cout << "Time taken for countingSort: " << elapsed3.count() << " ms\n";

    return 0;
}

