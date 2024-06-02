//  Countingsort.cpp
//  Include function declaration
#include "CountingSort.hpp"

// Function to perform a counting sort and calculate statistical data
void countingSort(const std::string& header, std::vector<int> data){
    std::unordered_map<int, int> counts;  // Count occurrences of each integer using an unordered_map
    for (const int& value : data) {
        counts[value]++;
    }

    std::vector<std::pair<int, int>> sortedData(counts.begin(), counts.end());      // Transfer counts to a vector and sort by integer value
    std::sort(sortedData.begin(), sortedData.end());

    
    int totalNumbers = 0;
    for (const auto& pair : sortedData) {
        totalNumbers += pair.second;    // Calculate total number of values 
    }
    int min = sortedData.front().first; // Determine minimum 
    int max = sortedData.back().first; // Determine maximum

    // Calculate percentiles P25, P50, and P75
    int cumulativeCount = 0;
    int p25 = 0, p50 = 0, p75 = 0;
    for (const auto& pair : sortedData) {
        cumulativeCount += pair.second;
        if (!p25 && cumulativeCount >= totalNumbers * 0.25) {
            p25 = pair.first;
        }
        if (!p50 && cumulativeCount >= totalNumbers * 0.5) {
            p50 = pair.first;
        }
        if (!p75 && cumulativeCount >= totalNumbers * 0.75) {
            p75 = pair.first;
        }
    }

    std::cout << header << std::endl;
    std::cout << "Min: " << min << std::endl; // Print Minimum 
    std::cout << "P25: " << p25 << std::endl;   //Print P25
    std::cout << "P50: " << p50 << std::endl;   // Print p50 
    std::cout << "P75: " << p75 << std::endl;   // Print P75
    std::cout << "Max: " << max << std::endl;   // Print Maximum 
    std::cout << "Unique: " << counts.size() << std::endl; //Print Unique Values 
}