/*
 * Problem: First Bad Version (LeetCode #278)
 * Difficulty: Easy
 * 
 * You are a product manager and currently leading a team to develop a new 
 * product. Unfortunately, the latest version of your product fails the 
 * quality check. Since each version is developed based on the previous 
 * version, all the versions after a bad version are also bad.
 * 
 * Suppose you have n versions [1, 2, ..., n] and you want to find out 
 * the first bad one, which causes all the following ones to be bad.
 * 
 * You are given an API bool isBadVersion(version) which returns whether 
 * version is bad. Implement a function to find the first bad version. 
 * You should minimize the number of calls to the API.
 * 
 * Example 1:
 * Input: n = 5, bad = 4
 * Output: 4
 * Explanation:
 * call isBadVersion(3) -> false
 * call isBadVersion(5) -> true
 * call isBadVersion(4) -> true
 * Then 4 is the first bad version.
 * 
 * Example 2:
 * Input: n = 1, bad = 1
 * Output: 1
 */

// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lhs = 1;      // Left boundary (first version)
        int rhs = n;      // Right boundary (last version)
        
        // Binary search to find first bad version
        while(lhs < rhs) {
            // Calculate middle (avoiding integer overflow)
            int mid = lhs + (rhs - lhs) / 2;
            
            if(isBadVersion(mid)) {
                // mid is bad, so first bad version is at mid or before
                // Search LEFT side, including mid (could be the answer)
                rhs = mid;
            } else {
                // mid is good, so first bad version is after mid
                // Search RIGHT side, excluding mid
                lhs = mid + 1;
            }
        }
        
        // When loop ends, lhs == rhs, which is the first bad version
        return lhs;
    }
};

/*
 * Time Complexity: O(log n)
 * - Binary search halves the search space each iteration
 * - For n versions, we need at most log₂(n) API calls
 * - Example: n = 1,000,000 → ~20 API calls max
 * 
 * Space Complexity: O(1)
 * - Only using two pointers (lhs and rhs)
 * - No recursion, so no call stack overhead
 * 
 * Algorithm: Binary Search (Modified)
 * 
 * Why Binary Search Works Here:
 * - Versions are sorted: [1, 2, 3, ..., n]
 * - Once a version is bad, ALL following versions are bad
 * - We're looking for the FIRST occurrence (leftmost bad version)
 * - This is a "find first occurrence" binary search variant
 * 
 * Key Differences from Standard Binary Search:
 * 
 * Standard: Find exact target
 * → if (arr[mid] == target) return mid;
 * 
 * This problem: Find FIRST bad version
 * → if (isBadVersion(mid)) rhs = mid;  // DON'T exclude mid!
 * 
 * Visual Example:
 * n = 10, first bad = 7
 * [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
 * [G, G, G, G, G, G, B, B, B, B]   (G=Good, B=Bad)
 * 
 * Step 1: lhs=1, rhs=10, mid=5
 *         isBadVersion(5) = false → lhs = 6
 * 
 * Step 2: lhs=6, rhs=10, mid=8
 *         isBadVersion(8) = true  → rhs = 8
 * 
 * Step 3: lhs=6, rhs=8, mid=7
 *         isBadVersion(7) = true  → rhs = 7
 * 
 * Step 4: lhs=6, rhs=7, mid=6
 *         isBadVersion(6) = false → lhs = 7
 * 
 * Step 5: lhs=7, rhs=7 → EXIT LOOP
 *         Return 7 ✓
 * 
 * Critical Detail: Overflow Prevention
 * 
 * ❌ WRONG: int mid = (lhs + rhs) / 2;
 *    Problem: If lhs + rhs > INT_MAX, it overflows!
 *    Example: lhs=2000000000, rhs=2000000000 → overflow
 * 
 * ✓ CORRECT: int mid = lhs + (rhs - lhs) / 2;
 *    Why: (rhs - lhs) is always small, no overflow
 *    This is mathematically equivalent but safer
 * 
 * Why We Use lhs < rhs (not lhs <= rhs):
 * - We want to stop when search space has size 1
 * - At that point, lhs == rhs == answer
 * - Using <= would cause infinite loop when lhs == rhs
 * 
 * Why We Set rhs = mid (not rhs = mid - 1):
 * - mid could be the first bad version!
 * - If we did rhs = mid - 1, we'd skip the answer
 * - This is different from finding an exact target
 * 
 * Edge Cases:
 * 1. n = 1, first bad = 1 → Returns 1 immediately
 * 2. All versions bad (first bad = 1) → Returns 1
 * 3. Only last version bad (first bad = n) → Returns n
 * 
 * Comparison with Linear Search:
 * 
 * Linear Search:
 * for(int i = 1; i <= n; i++) {
 *     if(isBadVersion(i)) return i;
 * }
 * - Time: O(n)
 * - For n=1,000,000, could need 1 million API calls!
 * 
 * Binary Search (Our Solution):
 * - Time: O(log n)  
 * - For n=1,000,000, need only ~20 API calls!
 * 
 * Real-World Applications:
 * - Git bisect (finding commit that introduced bug)
 * - Version control systems
 * - Finding when software regression occurred
 * - Database rollback to last good state
 * - Testing deployment rollbacks
 * 
 * Related Binary Search Problems:
 * - Search Insert Position (LeetCode #35)
 * - Find First and Last Position (LeetCode #34)
 * - Search in Rotated Sorted Array (LeetCode #33)
 */
