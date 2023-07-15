/*

Given a binary array nums, return the maximum length of a contiguous subarray with an equal 
number of 0 and 1.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

int findMaxLength(const std::vector<int>& nums) {
    int maxLen = 0;
    int count = 0;
    std::unordered_map<int, int> countMap;
    
    for (int i = 0; i < nums.size(); i++) {
        count += (nums[i] == 1) ? 1 : -1;
        
        if (count == 0) {
            maxLen = i + 1;
        } else if (countMap.count(count) > 0) {
            maxLen = std::max(maxLen, i - countMap[count]);
        } else {
            countMap[count] = i;
        }
    }
    
    return maxLen;
}

int main() {
    std::vector<int> nums = {0, 1};

    int maxLength = findMaxLength(nums);

    std::cout << "Maximum length of contiguous subarray: " << maxLength << std::endl;

    return 0;
}
