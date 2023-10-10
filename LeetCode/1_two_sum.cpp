/**
 *  TWO SUM
 * 
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

Example 1:

Input: nums = [2,7,11,15], target = 9
Output: [0,1]
Explanation: Because nums[0] + nums[1] == 9, we return [0, 1].
Example 2:

Input: nums = [3,2,4], target = 6
Output: [1,2]
Example 3:

Input: nums = [3,3], target = 6
Output: [0,1]
 

Constraints:

2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
Only one valid answer exists.

*/
#include <iostream>
#include <iomanip>
using namespace std;

class Solution {
    public:
    /**
     * Time Complexity = O(N)
     * As it traverses through the vector list only once
     * 
     * So an unordered_map is there,
     * For every element of the array we will check,
     * 
     * If the (target - nums[i]) is available in the unordered_map
     * => return the index of (target - nums[i]) & i
     * 
     * Else, we will include the (target - nums[i]) in the unordered_map
     * 
     * For ex. nums = [2, 7, 11, 15], target = 9
     * 
     * For i = 0, we will check if 9-2 is there in unordered_map - it is not there 
     * => We will add (2, 0(i.e. i in this case)) in the unordered_map
     * 
     * Now, for i = 1, we will check if 9-7 is there in unordered_map - it is there!!!
     * => We will directly return {i, <INDEX OF THE DIFF>} => {i, m[target - nums[i]]}
    */
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> m;
            for(int i = 0; i < nums.size(); i++) {
                if(m.count(target - nums[i])) return {i, m[target - nums[i]]};
                m[nums[i]] = i;
            }
            return {};
        }
};

int main() {
    int T;
    std::cin >> T;
    while(T--) {
        int n, target;
        std::cin >> n;
        vector<int> nums(n);
        for(int i = 0; i < n; i++) cin >> nums[i];
        cin >> target;
        Solution ob;
        for(auto x: ob.twoSum(nums, target)) cout << x << " ";
        cout << endl;
    }
    return 0;
}