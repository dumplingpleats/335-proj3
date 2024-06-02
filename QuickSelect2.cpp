// Quickselect2.cpp
//  Include function declarations
#include "QuickSelect2.hpp" 

// Function to perform insertion sort on a segment of data
void insertionSort2(std::vector<int>& data, int left, int right){
    for(int i = left + 1; i <= right; ++i){ // Iterate over the segment of data from 'left' to 'right'
        int key = data[i]; // Store the current element in 'key'
        int j = i - 1; // Initialize 'j' to the previous index
        while (j >= left && data[j] > key) // Move elements greater than 'key' to the right
        {
            data[j + 1] = data[j]; // Shift the element to the right
            j--; // Decrement 'j'
        }
        data[j + 1] = key; // Insert 'key' into its correct position
    }
}

// Function to partition the data around a pivot element
int partition2(std::vector<int>& data, int left, int right, int pivotIndex){
    int pivotValue = data[pivotIndex]; // Select the pivot value
    std::swap(data[pivotIndex], data[right]); // Move the pivot element to the end
    int storeIndex = left; // Initialize the store index
    for(int i = left; i < right; ++i) // Iterate over the segment of data
    {
        if(data[i] < pivotValue) // If the current element is less than the pivot value
        {
            std::swap(data[i], data[storeIndex]); // Swap the elements
            storeIndex++; // Increment the store index
        }
    }
    std::swap(data[storeIndex], data[right]); // Move the pivot element to its final position
    return storeIndex; // Return the pivot index
}

// Function to perform a QuickSelect operation targeted to multiple keys
void quickSelect(std::vector<int>& data, int left, int right, std::set<int>& keys){
    if(right - left <= 20) // If the segment size is small
    {
        insertionSort2(data, left, right); // Perform insertion sort
        return;
    }
    if(left < right && !keys.empty()) // If there are keys to be selected
    {
        int pivotIndex = partition2(data, left, right, (left + right) / 2); // Select the pivot index
        std::set<int> leftKeys, rightKeys; // Create sets to store keys on the left and right
        for(int key : keys) // Iterate over the keys
        {
            if (key < pivotIndex) // If the key is on the left
                leftKeys.insert(key); // Insert it into the left set
            else if (key > pivotIndex) // If the key is on the right
                rightKeys.insert(key); // Insert it into the right set
        }
        if(!leftKeys.empty()) // If there are keys on the left
            quickSelect(data, left, pivotIndex - 1, leftKeys); // Recursively select keys on the left
        if(!rightKeys.empty()) // If there are keys on the right
            quickSelect(data, pivotIndex + 1, right, rightKeys); // Recursively select keys on the right
    }
}

// Function to perform QuickSelect2 operation and display results
void quickSelect2(const std::string& header, std::vector<int> data){
    int n = data.size(); // Get the size of the data vector
    std::set<int> keys = {0, n / 4, n / 2, 3 * n / 4, n - 1}; // Set keys for min, 25th percentile, median, 75th percentile, and max
    quickSelect(data, 0, n - 1, keys); // Perform QuickSelect operation

    std::cout << header << std::endl; // Print the header
    std::cout << "Min: " << data[0] << std::endl; // Print the minimum value
    std::cout << "P25: " << data[n / 4] << std::endl; // Print the 25th percentile
    std::cout << "P50: " << data[n / 2] << std::endl; // Print the median
    std::cout << "P75: " << data[3 * n / 4] << std::endl; // Print the 75th percentile
    std::cout << "Max: " << data[n - 1] << std::endl; // Print the maximum value
}
