"""
Problem: Reverse String (LeetCode #344)
Difficulty: Easy

Write a function that reverses a string in-place.
The input string is given as an array of characters s.

Example:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
"""

from typing import List

class Solution:
    def reverseString(self, s: List[str]) -> None:
        """
        Do not return anything, modify s in-place instead.
        """
        # Two pointer approach
        left = 0
        right = len(s) - 1
        
        while left < right:
            # Swap characters
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1

# Test cases
if __name__ == "__main__":
    solution = Solution()
    
    # Test 1
    s1 = ["h","e","l","l","o"]
    solution.reverseString(s1)
    print(s1)  # Output: ["o","l","l","e","h"]
    
    # Test 2
    s2 = ["H","a","n","n","a","h"]
    solution.reverseString(s2)
    print(s2)  # Output: ["h","a","n","n","a","H"]

"""
Time Complexity: O(n)
Space Complexity: O(1) - in-place modification

Approach: Use two pointers starting from both ends, 
swap characters and move pointers toward center.
"""
