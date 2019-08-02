/*
 * @lc app=leetcode id=605 lang=cpp
 *
 * [605] Can Place Flowers
 *
 * https://leetcode.com/problems/can-place-flowers/description/
 *
 * algorithms
 * Easy (31.12%)
 * Likes:    497
 * Dislikes: 277
 * Total Accepted:    66.4K
 * Total Submissions: 213.3K
 * Testcase Example:  '[1,0,0,0,1]\n1'
 *
 * Suppose you have a long flowerbed in which some of the plots are planted and
 * some are not. However, flowers cannot be planted in adjacent plots - they
 * would compete for water and both would die.
 * 
 * Given a flowerbed (represented as an array containing 0 and 1, where 0 means
 * empty and 1 means not empty), and a number n, return if n new flowers can be
 * planted in it without violating the no-adjacent-flowers rule.
 * 
 * Example 1:
 * 
 * Input: flowerbed = [1,0,0,0,1], n = 1
 * Output: True
 * 
 * 
 * 
 * Example 2:
 * 
 * Input: flowerbed = [1,0,0,0,1], n = 2
 * Output: False
 * 
 * 
 * 
 * Note:
 * 
 * The input array won't violate no-adjacent-flowers rule.
 * The input array size is in the range of [1, 20000].
 * n is a non-negative integer which won't exceed the input array size.
 * 
 * 
 */
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int zero_c = 0;
        int size = (int)flowerbed.size();
        if (!size) {
            return false;
        }
        if (size == 1 ) {
            return !(n && flowerbed[0]);
        }
        int sum = 0;
        int i = 0;
        while (!flowerbed[i] && i < size) {
            zero_c++;
            i++;
        }
        sum += zero_c / 2;
        if (zero_c == size) {
            return (size + 1) / 2 >= n;
        }
        zero_c = 0;
        i++;
        while (i < size) {
            while (!flowerbed[i] && i < size) {
                zero_c++;
                i++;
            }
            if (i >= size) {
                break;
            }
            i++;
            sum += (zero_c - 1) / 2;
            zero_c = 0;
        }
        sum += zero_c / 2;
        return sum >= n;
    }
};


