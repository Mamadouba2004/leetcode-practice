/*
 * Problem: Valid Palindrome (LeetCode #125)
 * Difficulty: Easy
 * 
 * Given a string s, return true if it is a palindrome, 
 * or false otherwise. Only consider alphanumeric characters 
 * and ignore cases.
 * 
 * Example:
 * Input: s = "A man, a plan, a canal: Panama"
 * Output: true
 * Explanation: "amanaplanacanalpanama" is a palindrome.
 */

#include <string>
#include <cctype>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;
        
        while (left < right) {
            // Skip non-alphanumeric characters from left
            while (left < right && !isalnum(s[left])) {
                left++;
            }
            
            // Skip non-alphanumeric characters from right
            while (left < right && !isalnum(s[right])) {
                right--;
            }
            
            // Compare characters (case-insensitive)
            if (tolower(s[left]) != tolower(s[right])) {
                return false;
            }
            
            left++;
            right--;
        }
        
        return true;
    }
};

/*
 * Time Complexity: O(n)
 * Space Complexity: O(1)
 * 
 * Approach: Two pointer technique, skip non-alphanumeric chars,
 * compare characters in lowercase.
 */
