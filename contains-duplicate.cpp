/*
 * Problem: Contains Duplicate (LeetCode #217)
 * Difficulty: Easy
 * 
 * Given an integer array nums, return true if any value appears at least 
 * twice in the array, and return false if every element is distinct.
 * 
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: true
 * 
 * Example 2:
 * Input: nums = [1,2,3,4]
 * Output: false
 * 
 * Example 3:
 * Input: nums = [1,1,1,3,3,4,3,2,4,2]
 * Output: true
 */

#include <vector>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> seen; // keeps track of numbers we've found so far
        
        for(int num : nums) {
            // If we've seen this number before, we found a duplicate
            if(seen.count(num)) {
                return true;
            }
            // Add current number to the set
            seen.insert(num);
        }
        
        // No duplicates found
        return false;
    }
};

/*
 * Time Complexity: O(n)
 * - We iterate through the array once
 * - Hash set insert and lookup are O(1) on average
 * 
 * Space Complexity: O(n)
 * - In worst case, we store all n elements in the hash set
 * - This happens when there are no duplicates
 * 
 * Approach:
 * - Use hash set to track numbers we've already seen
 * - For each number, check if it's in the set
 * - If yes, we found a duplicate → return true
 * - If no, add it to the set and continue
 * - If we finish the loop, no duplicates → return false
 * 
 * Why Hash Set?
 * - Fast O(1) lookup to check if element exists
 * - Fast O(1) insertion to add new elements
 * - Perfect for "have we seen this before?" problems
 * 
 * Alternative Approaches:
 * 1. Sorting: Sort array, check adjacent elements - O(n log n) time, O(1) space
 * 2. Brute force: Compare every pair - O(n²) time, O(1) space (too slow!)
 */
