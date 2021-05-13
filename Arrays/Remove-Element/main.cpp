#include <iostream>
#include <vector>

using std::vector;
using std::cout;

class Solution {
public:
    // my solution
    int removeElement(vector<int>& nums, int val) {
        int length = nums.size();
        int numsIndex = 0;
        while (numsIndex < length) {
            if(nums[numsIndex] == val) {
                for (int j = numsIndex+1; j < length; j++) {
                    nums[j - 1] = nums[j];
                }
                length--;
                numsIndex--;
            }   
            numsIndex++;
        }

        return length;
    };

    // nyx's solution
    int removeElement1(vector<int>& nums, int val) {
        int countVal = 0;
        for (int i = 0; i < nums.size(); i++) {
            if(nums[i] == val) {
                countVal++;
            } else {
                nums[i - countVal] = nums[i];
            }
        }

        return nums.size() - countVal;
    };
};


int main(int argc, const char * argv[]) {
    Solution sol;
    vector<int> nums;
    int res;

    nums = {0,1,2,2,3,0,4,2};
    res = sol.removeElement1(nums, 2);

    cout << "Output: " << res;

    return 0;
}