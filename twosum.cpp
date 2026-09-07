#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>

std::pair<int, int> twoSumBruteForce(const std::vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (nums[i] + nums[j] == target) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

std::pair<int, int> twoSumHash(const std::vector<int>& nums, int target) {
    std::unordered_map<int, int> index;  

    for (int i = 0; i < nums.size(); i++) {
        int needed = target - nums[i];

        if (index.count(needed)) {
            return {index[needed], i};
        } 

        index[nums[i]] = i; 
    }

    return {-1, -1};
}

bool isResultValid(const std::vector<int>& nums, int target, std::pair<int, int> result){
    if (result.first != -1 && 
        result.second != -1 && 
        nums[result.first] + nums[result.second] == target) {
        return true; 
    }
    else {
        return false;
    }
}

void runTestCase(const std::vector<int>& nums, int target){
    std::pair<int, int> bruteForceResult = twoSumBruteForce(nums, target);
    std::pair<int, int> hashMapResult = twoSumHash(nums, target);

    bool bruteForceValid = isResultValid(nums, target, bruteForceResult);
    bool hashMapValid = isResultValid(nums, target, hashMapResult);

    if (bruteForceValid) {
        std::cout << "Brute Force Indices: [" << bruteForceResult.first 
                  << ", " << bruteForceResult.second << "]\n";
        std::cout << "Brute Force Values: [" << nums[bruteForceResult.first] 
                  << ", " << nums[bruteForceResult.second] <<  "]\n";
        std::cout << "Brute force result is valid.\n\n";
    }
    else {
        std::cout << "Brute force result is not valid.\n\n";
    }

    if (hashMapValid) {
        std::cout << "Hashmap Indices: [" << hashMapResult.first 
                  << ", " << hashMapResult.second << "]\n";
        std::cout << "Hashmap Values: [" << nums[hashMapResult.first] 
                  << ", " << nums[hashMapResult.second] <<  "]\n";
        std::cout << "Hashmap result is valid.\n\n";
    }
    else {
        std::cout << "Hashmap result is not valid.\n\n";
    }
}

int main() {
    std::vector<int> nums1 = {15, 4, 18, 8, 19, 22, 24, 59, 59, 20, 18, 12, 36, 42, 9};
    int target1 = 24;

    std::vector<int> nums2 = {3, 6, 11, 15, 18, 23};
    int target2 = 9;

    std::vector<int> nums3 = {2, 4, 6, 8, 10, 12};
    int target3 = 14;

    std::vector<int> nums4 = {-6, 4, 11, 13, -8, 17};
    int target4 = -14;

    std::vector<int> nums5 = {1, 3, 5, 9, 12, 16};
    int target5 = 28;

    runTestCase(nums1, target1);
    runTestCase(nums2, target2);
    runTestCase(nums3, target3);
    runTestCase(nums4, target4);
    runTestCase(nums5, target5);

    return 0;
}