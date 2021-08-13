#include <iostream>
#include <vector>
#include <chrono>

using std::vector;
using namespace std::chrono;

class Solution {
public:
    // my solution
    int dominantIndex(vector<int>& nums) {
        int temp = 0;
        int largestNumber = 0;
        int largestIndex = 0;
        for(int i = 0; i < nums.size(); i++) {

            if(nums[i] > largestNumber) {
                temp = largestNumber;
                largestNumber = nums[i];
                largestIndex = i;
            }
            
            if (nums[i] > temp && nums[i] < largestNumber){
                temp = nums[i];
            }
        }
        
        if(largestNumber >= 2*temp ) {
            return largestIndex;
        }
        // return temp;
        return -1;
    }
    // nyx's solution
    int dominantIndex1(vector<int>& nums) {
        int maxValue = 0;
        int secondValue = 0;
        int maxIndex = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > maxValue) {
                secondValue = maxValue;
                maxValue = nums[i];
                maxIndex = i;
            } else if (nums[i] < maxValue && nums[i] > secondValue) {
                secondValue = nums[i];
            }
        }

        if(maxValue >= 2*secondValue) {
            return maxIndex;
        } else {
            return -1;
        }
    }
};

int main() {
    // [3,6,1,0] => 1, [1,2,3,4] => -1, [1] => 0;
    vector<int> nums = {3,1,5,6}; // output: -1
    int res;
    Solution sol;

    auto start = high_resolution_clock::now();
    res = sol.dominantIndex1(nums);
    auto stop = high_resolution_clock::now();

    duration<double, std::milli> float_ms = stop - start;
    auto int_ms = duration_cast<milliseconds>(stop - start);

    std::cout << "Output: ";
    std::cout << res;
    std::cout << std::endl;
    std::cout << "Time is " << float_ms.count() << "ms " <<"(" << int_ms.count() << " milliseconds)" << std::endl;

    return 0;
}