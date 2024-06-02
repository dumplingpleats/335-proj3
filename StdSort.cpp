//stdsort.cpp
//include function declaration
#include "StdSort.hpp"

//Function calling standard library sort to print 5 number summary of dataset
void stdSort (const std::string & header, std::vector<int> data){
    sort(data.begin(), data.end()); // Call std::sort
    std::cout<<header<<std::endl;  //   Print header 
    std::cout<<"Min: "<<data[0]<<std::endl;     //  Print Minimum
    std::cout<<"P25: "<<data[data.size()/4]<<std::endl;    //   Print P25
    std::cout<<"P50: "<<data[data.size()/2]<<std::endl;     //  Print P50
    std::cout<<"P75: "<<data[data.size()/4+data.size()/2 -1]<<std::endl; //    Print P75
    std::cout<<"Max: "<<data[data.size()-1]<<std::endl;     // Print Maximum
}