// Quickselect1.cpp
// Include function declaration 
#include "QuickSelect1.hpp" 

// Helper function to perform insertion sort on a segment of data specified by left and right indices
void insertionSort(std::vector<int>& data, int left, int right){
    // Iterate over the segment of data from 'left' to 'right'
    for(int i = left + 1; i <= right; ++i) {
        int key = data[i]; // Store the current element in 'key'
        int j = i - 1; // Initialize j to the previous index
        while (j >= left && data[j] > key){ // Move elements greater than 'key' to the right
            data[j + 1] = data[j]; // Shift the element to the right
            --j; // Decrement j
        }
        data[j + 1] = key; // Insert 'key' into its correct position
    }
}

// Helper function to rearrange elements in 'data' between indices 'left' and 'right' around a pivot
int partition(std::vector<int>& data, int left, int right, int pivotIndex){
    int pivotValue = data[pivotIndex]; // Select the pivot value
    std::swap(data[pivotIndex], data[right]); // Move the pivot element to the end
    int storeIndex = left; // Initialize the store index

    // Iterate over the segment of data
    for(int i = left; i < right; ++i) {
        if(data[i] < pivotValue) { // If the current element is less than the pivot value
            std::swap(data[i], data[storeIndex]); // Swap the elements
            ++storeIndex; // Increment the store index
        }
    }
    std::swap(data[storeIndex], data[right]); // Move the pivot element to its final position
    return storeIndex; // Return the pivot index
}

// Function definition: finds the k-th smallest element between left and right indexes
void quickSelect(std::vector<int>& data, int left, int right, int k){
    // Iterate until the segment size is small
    while(right - left > 20) {
        int pivotIndex = partition(data, left, right, (left + right) / 2); // Select the pivot index

        if(k == pivotIndex){// If the pivot index is equal to k
            return; // Exit the function
        } 
        else if(k < pivotIndex) { // If k is less than the pivot index
            right = pivotIndex - 1; // Update the right index
        } 
        else { // If k is greater than the pivot index
            left = pivotIndex + 1; // Update the left index
        }
    }
    insertionSort(data, left, right); // Perform insertion sort on the remaining segment
}

// Function calling quickselect to print a 5-number summary 
void quickSelect1(const std::string &header, std::vector<int> data){
    std::cout << header << std::endl; // Output the header
    int n = data.size(); // Get the size of the data vector
    int medianIndex = n / 2; // Calculate the index of the median 
    int firstQuartileIndex = n / 4; // Calculate the index of the first quartile
    int thirdQuartileIndex = (3 * n) / 4; // Calculate the index of the third quartile

    // Perform QuickSelect operation to find the median, first quartile, and third quartile
    quickSelect(data, 0, n - 1, medianIndex); // Find the median
    quickSelect(data, 0, medianIndex - 1, firstQuartileIndex); // Find the first quartile
    quickSelect(data, medianIndex + 1, n - 1, thirdQuartileIndex - 1); // Find the third quartile

    int min = *std::min_element(data.begin(), data.begin() + firstQuartileIndex); // Find the minimum value
    int max = *std::max_element(data.begin() + thirdQuartileIndex, data.end()); // Find the maximum value

    std::cout << "Min: " << min << std::endl; // Print Minimum
    std::cout << "P25: " << data[firstQuartileIndex] << std::endl; // Print P25
    std::cout << "P50: " << data[medianIndex] << std::endl; // Print P50
    std::cout << "P75: " << data[thirdQuartileIndex] << std::endl; // Print P70
    std::cout << "Max: " << max << std::endl; // Print Maximum
}