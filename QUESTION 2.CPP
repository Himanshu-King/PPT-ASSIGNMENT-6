/*

You are given an m x n integer matrix matrix with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer target, return true *if* target *is in* matrix *or* false *otherwise*.

You must write a solution in O(log(m * n)) time complexity.

*/

#include <iostream>
#include <vector>

bool searchMatrix(const std::vector<std::vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    
    int left = 0;
    int right = m * n - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        int row = mid / n;
        int col = mid % n;
        
        if (matrix[row][col] == target) {
            return true;
        } else if (matrix[row][col] > target) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    
    return false;
}

int main() {
    std::vector<std::vector<int>> matrix = {{1, 3, 5, 7},
                                            {10, 11, 16, 20},
                                            {23, 30, 34, 60}};
    int target = 3;

    bool found = searchMatrix(matrix, target);

    std::cout << std::boolalpha << "Target found: " << found << std::endl;

    return 0;
}
