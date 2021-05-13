#include <iostream>
#include <vector>

using std::vector;
using std::cout;

class Solution {
public:
    // my solution
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() == 0) return 0;
        
        int currentValue = nums[0];
        int countVal = 0;
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] == currentValue) {
                countVal++;
            } else {
                currentValue = nums[i];
                nums[i - countVal] = nums[i];;
            }
        }
        return nums.size() - countVal;
    }
    // nyx's solution
    int removeDuplicates1(vector<int>& nums) {
        int countDup = 0;
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i-1] == nums[i]) {
                countDup++;
            } else {
                nums[i - countDup] = nums[i];;
            }
        }
        return nums.size() - countDup;
    }
};


int main() {
    Solution sol;
    vector<int> nums;
    int res;

    nums = {0,0,1,1,1,2,2,3,3,4};
    res = sol.removeDuplicates1(nums);

    cout << "Output: " << res;

    return 0;
}