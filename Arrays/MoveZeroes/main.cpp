#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    // my solution
    vector<int> moveZeroes(vector<int>& nums) {
        int countZeroes = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                countZeroes++;
            } else {
                int currentValue = nums[i];
                nums[i] = nums[i - countZeroes];
                nums[i - countZeroes] = currentValue;
            }
        }
        
        return nums;
    };
    // my solution
    vector<int> moveZeroes1(vector<int>& nums) {
        int countZeroes = 0;
        vector<int> newArr(nums.size());
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                newArr[nums.size() - 1 - countZeroes] = nums[i];
                countZeroes++;
            } else {
                newArr[i - countZeroes] = nums[i];
            }
        }
        nums = newArr;
        return nums;
    };
    // my solution
    vector<int> moveZeroes2(vector<int>& nums) {
        int countZeroes = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                countZeroes++;
            } else if (nums[i] != 0 && countZeroes > 0) {
                nums[i - countZeroes] = nums[i];
                nums[i] = 0;
            }
        }

        return nums;
    };
    // nyx's solution
    vector<int> moveZeroes3(vector<int>& nums) {
        int countZeros = 0;

        if (nums.size() < 2) {
            return nums;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                countZeros++;
            } else {
                nums[i - countZeros] = nums[i];
            }
        }

        // don't bother with the second loop if array is all zeros
        if (countZeros == nums.size()) {
            return nums;
        }

        // needed so the for loop accurately handles the condition
        int numZeros = nums.size() - countZeros;

        for (int i = nums.size() - 1; i >= numZeros; i--) {
            if (nums[i] != 0) {
                nums[i] = 0;
            } else {
                continue;
            }
            
        }

        return nums;
    };
    // nyx's solution
    vector<int> moveZeroes4(vector<int>& nums) {
        int zeroPosition = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != 0 && i == zeroPosition) {
                zeroPosition++;
            } else if (nums[i] != 0 && i != zeroPosition) {
                nums[zeroPosition] = nums[i];
                nums[i] = 0;
                zeroPosition++;
            }
        }

        return nums;
    };
};

int main(int argc, const char * argv[]) {
    vector<int> v = {0,1,0,3,12};

    Solution sol;
    vector<int> res;

    res = sol.moveZeroes4(v);

    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i];
        if (i != res.size()-1) {
            std::cout << ",";
        }
    }
    

    return 0;
}