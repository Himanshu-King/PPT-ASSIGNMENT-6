/*

An integer array original is transformed into a **doubled** array changed by appending **twice the value** of every element in original, and then randomly **shuffling** the resulting array.

Given an array changed, return original *if* changed *is a **doubled** array. If* changed *is not a **doubled** array, return an empty array. The elements in* original *may be returned in **any** order*.

*/

#include <iostream>
#include <vector>
#include <unordered_map>

std::vector<int> findOriginalArray(const std::vector<int>& changed) {
    std::vector<int> original;
    std::unordered_map<int, int> count;
    
    for (int num : changed) {
        count[num]++;
    }
    
    for (int num : changed) {
        if (count[num] > 0) {
            if (count[num * 2] < count[num]) {
                return std::vector<int>();
            }
            count[num * 2] -= count[num];
            original.push_back(num);
        }
    }
    
    if (original.size() == changed.size() / 2) {
        return original;
    } else {
        return std::vector<int>();
    }
}

int main() {
    std::vector<int> changed = {1, 3, 4, 2, 6, 8};

    std::vector<int> original = findOriginalArray(changed);

    std::cout << "Original array: ";
    for (int num : original) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
