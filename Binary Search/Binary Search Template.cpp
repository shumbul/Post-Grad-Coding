// Binary Search - iterative
int binarySearchIterative(vector<int> arr, int valueToSearch) {
    int low = 0, high = arr.size()-1;
    while(low<=high){
        int mid = (low+high)/2;
        if(valueToSearch == arr[mid])
            return mid;
        else if(valueToSearch > arr[mid])   // valueToSearch is on the right
            low = mid + 1;
        else                                // valueToSearch is on the left
            high = mid - 1;
    }
    return -1;
}

// Binary Search - recursive
int binarySearchRecursive(vector<int> arr, int valueToSearch, int low, int high) {
    if(low>high)
        return -1;
    int mid = low + (high-low)/2;
    if(valueToSearch == arr[mid])
        return mid;
    else if(valueToSearch > arr[mid])   // valueToSearch is on the right
            return binarySearchRecursive(arr, valueToSearch, mid+1, high);
    else                                // valueToSearch is on the left
            return binarySearchRecursive(arr, valueToSearch, low, mid-1);
}
int binarySearch(vector<int> arr, int valueToSearch) {
    return binarySearchRecursive(arr, valueToSearch, 0, arr.size()-1);
}