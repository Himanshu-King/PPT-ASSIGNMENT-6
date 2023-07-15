/*

Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

*/

#include <iostream>
#include <vector>

std::vector<std::vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    int num = 1;
    int target = n * n;
    int rowStart = 0, rowEnd = n - 1;
    int colStart = 0, colEnd = n - 1;

    while (num <= target) {
        for (int col = colStart; col <= colEnd; col++) {
            matrix[rowStart][col] = num++;
        }
        rowStart++;

        for (int row = rowStart; row <= rowEnd; row++) {
            matrix[row][colEnd] = num++;
        }
        colEnd--;

        if (rowStart <= rowEnd) {
            for (int col = colEnd; col >= colStart; col--) {
                matrix[rowEnd][col] = num++;
            }
            rowEnd--;
        }

        if (colStart <= colEnd) {
            for (int row = rowEnd; row >= rowStart; row--) {
                matrix[row][colStart] = num++;
            }
            colStart++;
        }
    }

    return matrix;
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
    int n = 3;
    std::vector<std::vector<int>> matrix = generateMatrix(n);

    std::cout << "Generated Matrix:" << std::endl;
    printMatrix(matrix);

    return 0;
}
