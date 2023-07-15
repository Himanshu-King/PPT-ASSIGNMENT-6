/*

The **product sum** of two equal-length arrays a and b is equal to the sum of a[i] * b[i] for all 0 <= i < a.length (**0-indexed**).

- For example, if a = [1,2,3,4] and b = [5,2,3,1], the **product sum** would be 1*5 + 2*2 + 3*3 + 4*1 = 22.

Given two arrays nums1 and nums2 of length n, return *the **minimum product sum** if you are allowed to **rearrange** the **order** of the elements in* nums1.

*/

#include <iostream>
#include <vector>
#include <algorithm>

int minProductSum(std::vector<int>& nums1, std::vector<int>& nums2) {
    std::sort(nums1.begin(), nums1.end());
    std::sort(nums2.rbegin(), nums2.rend());
    
    int productSum = 0;
    
    for (int i = 0; i < nums1.size(); i++) {
        productSum += nums1[i] * nums2[i];
    }
    
    return productSum;
}

int main() {
    std::vector<int> nums1 = {5, 3, 4, 2};
    std::vector<int> nums2 = {4, 2, 2, 5};

    int minProduct = minProductSum(nums1, nums2);

    std::cout << "Minimum product sum: " << minProduct << std::endl;

    return 0;
}
