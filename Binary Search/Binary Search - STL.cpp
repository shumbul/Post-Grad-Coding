// Binary Search - C++ STL
bool binarySearchSTL(vector<int> arr, int valueToSearch) {
    auto startAddress = arr.begin();
    auto endAddress = arr.end();

    bool ans = binary_search(startAddress, endAddress, valueToSearch);
    return ans;
    
    /*
        lower_bound -> n iterator to the lower bound of val in the range
                    returns an iterator to the lower bound of key in the range
    */
    /*
        upper_bound -> the element just greater than valueToSearch
                    returns an iterator to the upper bound of val in the range
    */
}