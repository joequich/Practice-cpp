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
    };
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
    };
    // other solution
    int removeDuplicates2(vector<int>& nums) {
        int length = nums.size();

        for (int i = length - 2; i >= 0; i--) {
            if (nums[i] == nums[i + 1]) {

                for (int j = i + 1; j < length; j++) {
                    nums[j - 1] = nums[j];
                }
            
                length--;
            }
        }
        return length;
    };
    // other solution
    int removeDuplicates3(vector<int>& nums) {
        // Check for edge cases.
        if (nums.size() == 0) {
            return 0;
        }
        
        // Use the two pointer technique to remove the duplicates in-place.
        // The first element shouldn't be touched; it's already in its correct place.
        int writePointer = 1;
        // Go through each element in the Array.
        for (int readPointer = 1; readPointer < nums.size(); readPointer++) {
            // If the current element we're reading is *different* to the previous
            // element...
            if (nums[readPointer] != nums[readPointer - 1]) {
                // Copy it into the next position at the front, tracked by writePointer.
                nums[writePointer] = nums[readPointer];
                // And we need to now increment writePointer, because the next element
                // should be written one space over.
                writePointer++;
            }
        }
        
        // This turns out to be the correct length value.
        return writePointer;
    };
    
};


int main() {
    Solution sol;
    vector<int> nums;
    int res;

    nums = {0,0,1,1,1,2,2,3,3,4};
    res = sol.removeDuplicates3(nums);

    cout << "Output: " << res;

    return 0;
}