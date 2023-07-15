/*

A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

- s[i] == 'I' if perm[i] < perm[i + 1], and
- s[i] == 'D' if perm[i] > perm[i + 1].

Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return **any of them**.

*/

#include <iostream>
#include <vector>

std::vector<int> reconstructPermutation(const std::string& s) {
    std::vector<int> perm;
    int n = s.size();
    int current = 0;

    for (char ch : s) {
        if (ch == 'I') {
            perm.push_back(current);
            current++;
        } else if (ch == 'D') {
            perm.push_back(n);
            n--;
        }
    }

    perm.push_back(n);

    return perm;
}

int main() {
    std::string s = "IDID";

    std::vector<int> perm = reconstructPermutation(s);

    std::cout << "Reconstructed permutation: [";
    for (int i = 0; i < perm.size(); i++) {
        std::cout << perm[i];
        if (i != perm.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;

    return 0;
}
