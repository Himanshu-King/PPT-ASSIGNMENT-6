/*

Given two sparse matrices mat1 of size m x k and mat2 of size k x n, return the result of 
mat1 x mat2. You may assume that multiplication is always possible.

*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> multiply(std::vector<std::vector<int>>& mat1, std::vector<std::vector<int>>& mat2) {
    int m = mat1.size();
    int k = mat1[0].size();
    int n = mat2[0].size();
    
    std::vector<std::vector<int>> result(m, std::vector<int>(n, 0));
    
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int sum = 0;
            for (int p = 0; p < k; p++) {
                sum += mat1[i][p] * mat2[p][j];
            }
            result[i][j] = sum;
        }
    }
    
    return result;
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    for (const auto& row : matrix) {
        for (int num : row) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> mat1 = {{1, 0, 0}, {-1, 0, 3}};
    std::vector<std::vector<int>> mat2 = {{7, 0, 0}, {0, 0, 0}, {0, 0, 1}};

    std::vector<std::vector<int>> result = multiply(mat1, mat2);

    std::cout << "Result Matrix:" << std::endl;
    printMatrix(result);

    return 0;
}
