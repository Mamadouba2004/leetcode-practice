/*
 * Problem: Best Time to Buy and Sell Stock (LeetCode #121)
 * Difficulty: Easy
 * 
 * You are given an array prices where prices[i] is the price of a given 
 * stock on the ith day.
 * 
 * You want to maximize your profit by choosing a single day to buy one 
 * stock and choosing a different day in the future to sell that stock.
 * 
 * Return the maximum profit you can achieve from this transaction. 
 * If you cannot achieve any profit, return 0.
 * 
 * Example 1:
 * Input: prices = [7,1,5,3,6,4]
 * Output: 5
 * Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), 
 * profit = 6-1 = 5.
 * 
 * Example 2:
 * Input: prices = [7,6,4,3,1]
 * Output: 0
 * Explanation: No profit possible, prices only decrease.
 */

#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_price = INT_MAX;  // Start with the highest possible value
        int max_profit = 0;       // No profit initially
        
        for(int price : prices) {
            // Update minimum price seen so far
            if(price < min_price) {
                min_price = price;
            }
            
            // Calculate profit if we sell at current price
            int profit = price - min_price;
            
            // Update maximum profit if current profit is better
            if(profit > max_profit) {
                max_profit = profit;
            }
        }
        
        return max_profit;
    }
};

/*
 * Time Complexity: O(n)
 * - Single pass through the array
 * - We visit each price exactly once
 * 
 * Space Complexity: O(1)
 * - Only using two variables (min_price and max_profit)
 * - No additional data structures needed
 * 
 * Algorithm Approach:
 * 
 * Key Insight: To maximize profit, we need to:
 * 1. Buy at the LOWEST price seen so far
 * 2. Sell at a price that gives us MAXIMUM profit
 * 
 * We don't need to try all pairs of buy/sell days (which would be O(n²)).
 * Instead, we can solve it in one pass by:
 * - Tracking the minimum price encountered so far
 * - For each price, calculating profit if we sold today
 * - Keeping track of the maximum profit
 * 
 * Visual Example:
 * prices = [7, 1, 5, 3, 6, 4]
 * 
 * Day 0: price=7, min=7,  profit=0, max_profit=0
 * Day 1: price=1, min=1,  profit=0, max_profit=0
 * Day 2: price=5, min=1,  profit=4, max_profit=4  (buy at 1, sell at 5)
 * Day 3: price=3, min=1,  profit=2, max_profit=4
 * Day 4: price=6, min=1,  profit=5, max_profit=5  (buy at 1, sell at 6)
 * Day 5: price=4, min=1,  profit=3, max_profit=5
 * 
 * Final answer: 5
 * 
 * Why This Works:
 * - We always know the best price to buy (minimum so far)
 * - We calculate profit for selling at each day
 * - We keep the maximum profit we've seen
 * - This guarantees we find the optimal buy/sell pair
 * 
 * Edge Cases Handled:
 * 1. Prices always decrease → max_profit stays 0
 * 2. Single price → no transaction possible, returns 0
 * 3. All same prices → profit is 0
 * 
 * Alternative Approaches:
 * 
 * 1. Brute Force (NOT recommended):
 *    - Try all pairs of buy/sell days
 *    - Time: O(n²), Space: O(1)
 * 
 * 2. Dynamic Programming:
 *    - Track max profit at each day
 *    - Time: O(n), Space: O(n)
 *    - Our solution is better (O(1) space)
 * 
 * Related Problems:
 * - Best Time to Buy and Sell Stock II (multiple transactions)
 * - Best Time to Buy and Sell Stock III (at most 2 transactions)
 * - Maximum Subarray (similar "track min and max" pattern)
 */
