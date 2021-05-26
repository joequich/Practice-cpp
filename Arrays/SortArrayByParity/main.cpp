#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    // my solution
    vector<int> sortArrayByParity(vector<int>& nums) {
        int countOdd = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 != 0) {
                countOdd++;
            } else {
                int currentValue = nums[i];
                nums[i] = nums[i - countOdd];
                nums[i - countOdd] = currentValue;
            }
        }
        
        return nums;
    };
    // my solution
    vector<int> sortArrayByParity1(vector<int>& nums) {
        int oddPosition = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] % 2 == 0 && i == oddPosition) {
                oddPosition++;
            } else if ((nums[i] % 2 == 0) && i != oddPosition){
                int currentValue = nums[oddPosition];
                nums[oddPosition] = nums[i];
                nums[i] = currentValue;
                oddPosition++;
            }
        }
        
        return nums;
    };

    // nyx's solution
    vector<int> sortArrayByParity2(vector<int>& nums) {
        int startingIndex = 0;
        int endIndex = nums.size() - 1;
        int tempHolder;

        while (startingIndex < endIndex) {
            // start is even, end is odd
            if (nums[startingIndex] % 2 == 0 && nums[endIndex] % 2 != 0) {
                startingIndex++;
                endIndex--;
            }
            // both are even
            else if (nums[startingIndex] % 2 == 0 && nums[endIndex] % 2 == 0) {
                startingIndex++;
            }
            // both are odd
            else if (nums[startingIndex] % 2 != 0 && nums[endIndex] % 2 != 0) {
                endIndex--;
            }
            // start is odd, end is even
            else if (nums[startingIndex] % 2 != 0 && nums[endIndex] % 2 == 0) {
                tempHolder = nums[startingIndex];
                nums[startingIndex] = nums[endIndex];
                nums[endIndex] = tempHolder;
            }
        }
        
        return nums;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> v = {3,1,2,4,7};

    Solution sol;
    vector<int> res,res1,res2,res3;

    res = sol.sortArrayByParity2(v);

    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i];
        if (i != res.size()-1) {
            std::cout << ",";
        }
    }
    

    return 0;
}