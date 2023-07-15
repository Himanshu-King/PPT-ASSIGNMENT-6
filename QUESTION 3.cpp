/*

Given an array of integers arr, return *true if and only if it is a valid mountain array*.

Recall that arr is a mountain array if and only if:

- arr.length >= 3
- There exists some i with 0 < i < arr.length - 1 such that:
    - arr[0] < arr[1] < ... < arr[i - 1] < arr[i]
    - arr[i] > arr[i + 1] > ... > arr[arr.length - 1]

*/

#include <iostream>
#include <vector>

bool validMountainArray(const std::vector<int>& arr) {
    int n = arr.size();
    int left = 0;
    int right = n - 1;
    
    if (n < 3) {
        return false;
    }
    
    while (left < right && arr[left] < arr[left + 1]) {
        left++;
    }
    
    while (right > 0 && arr[right - 1] > arr[right]) {
        right--;
    }
    
    if (left == 0 || right == n - 1 || left == right) {
        return false;
    }
    
    return left == right + 1;
}

int main() {
    std::vector<int> arr = {2, 1};

    bool isValidMountain = validMountainArray(arr);

    std::cout << std::boolalpha << "Valid mountain array: " << isValidMountain << std::endl;

    return 0;
}
