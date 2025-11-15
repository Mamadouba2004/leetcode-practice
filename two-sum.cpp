/*
 * Problem: Two Sum (LeetCode #1)
 * Difficulty: Easy
 * 
 * Given an array of integers nums and an integer target, 
 * return indices of the two numbers such that they add up to target.
 * 
 * Example:
 * Input: nums = [2,7,11,15], target = 9
 * Output: [0,1]
 * Explanation: nums[0] + nums[1] = 2 + 7 = 9
 */

#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // Hash map to store value and its index
        unordered_map<int, int> numMap;
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // Check if complement exists in map
            if (numMap.find(complement) != numMap.end()) {
                return {numMap[complement], i};
            }
            
            // Store current number and its index
            numMap[nums[i]] = i;
        }
        
        return {}; // No solution found
    }
};

/*
 * Time Complexity: O(n)
 * Space Complexity: O(n)
 * 
 * Approach: Use hash map to store each number and its index.
 * For each number, check if (target - number) exists in the map.
 */
