/*
 * Problem: Valid Anagram (LeetCode #242)
 * Difficulty: Easy
 * 
 * Given two strings s and t, return true if t is an anagram of s, 
 * and false otherwise.
 * 
 * An anagram is a word or phrase formed by rearranging the letters of 
 * a different word or phrase, using all the original letters exactly once.
 * 
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * Output: true
 * 
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 * 
 * Example 3:
 * Input: s = "listen", t = "silent"
 * Output: true
 * 
 * Constraints:
 * - 1 <= s.length, t.length <= 50,000
 * - s and t consist of lowercase English letters
 */

#include <string>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        // Step 1: Early exit if lengths differ
        // If strings have different lengths, they can't be anagrams
        if (s.length() != t.length()) {
            return false;
        }
        
        // Step 2: Create frequency count array
        // Array of size 26 for each lowercase letter (a-z)
        int count[26] = {0}; // All initialized to 0
        
        // Step 3: Count characters in s (increment)
        // For each character in s, increment its frequency
        for (char c : s) {
            count[c - 'a']++;  // 'a' maps to index 0, 'b' to 1, etc.
        }
        
        // Step 4: Count characters in t (decrement)
        // For each character in t, decrement its frequency
        for (char c : t) {
            count[c - 'a']--;
        }
        
        // Step 5: Verify all counts are zero
        // If s and t are anagrams, all frequencies should cancel out
        for (int i = 0; i < 26; i++) {
            if (count[i] != 0) {
                return false;  // Found a mismatch
            }
        }
        
        return true; // All counts are zero, strings are anagrams!
    }
};

/*
 * Time Complexity: O(n)
 * - O(n) to check length
 * - O(n) to count characters in s
 * - O(n) to count characters in t
 * - O(26) = O(1) to verify counts
 * - Overall: O(n) where n is the length of the strings
 * 
 * Space Complexity: O(1)
 * - Fixed array of size 26 regardless of input size
 * - Much more efficient than hash map which could use O(n) space
 * 
 * Algorithm Explanation:
 * 
 * This solution uses a frequency counting approach with a fixed-size array:
 * 
 * 1. EARLY EXIT: If lengths differ, they can't be anagrams
 *    - Saves time by avoiding unnecessary processing
 * 
 * 2. COUNTING STRATEGY: Use array as frequency counter
 *    - Index 0 = 'a', Index 1 = 'b', ..., Index 25 = 'z'
 *    - Mapping: (character - 'a') gives the index
 * 
 * 3. INCREMENT/DECREMENT TRICK: 
 *    - Increment for each character in s
 *    - Decrement for each character in t
 *    - If anagrams, everything cancels to 0!
 * 
 * 4. VERIFICATION: Check all counts are zero
 *    - Any non-zero value means character mismatch
 * 
 * Visual Example:
 * s = "anagram", t = "nagaram"
 * 
 * After counting s:
 * a: 3, n: 1, g: 1, r: 1, m: 1
 * 
 * After counting t (decrement):
 * a: 3-3=0, n: 1-1=0, g: 1-1=0, r: 1-1=0, m: 1-1=0
 * 
 * All zeros → anagram! ✓
 * 
 * Alternative Approaches:
 * 
 * 1. SORTING (O(n log n) time, O(1) space):
 *    - Sort both strings
 *    - Compare if they're equal
 *    - Slower but simpler
 * 
 * 2. HASH MAP (O(n) time, O(n) space):
 *    - Use unordered_map to count frequencies
 *    - More space than needed for lowercase letters
 * 
 * 3. TWO ARRAYS (O(n) time, O(1) space):
 *    - Count frequencies in separate arrays
 *    - Compare arrays
 *    - Uses twice the space
 * 
 * Our solution is OPTIMAL because:
 * ✓ O(n) time complexity (can't do better)
 * ✓ O(1) space complexity (minimal memory)
 * ✓ Single pass through data
 * ✓ Clean and readable code
 * 
 * When to Use This Approach:
 * - Lowercase letters only (can extend to all ASCII with larger array)
 * - Need optimal space complexity
 * - Want fast, simple solution
 * 
 * Key Insight:
 * Using a fixed array instead of hash map when the character set is known
 * and small is a common optimization in string problems!
 */
