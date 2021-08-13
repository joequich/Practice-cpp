#include <iostream>
#include <vector>
#include <chrono>

using std::vector;
using namespace std::chrono;

class Solution {
    public:
        // my solution
        int pivotIndex(vector<int>& nums) {
            int sumTotal = 0;
            int left = 0;
            
            if(nums.size() < 2) return -1;
            
            for(int i = 0; i < nums.size(); i++) {
                sumTotal += nums[i];
            }
            
            for(int j = 0; j < nums.size(); j++) { // j= 2     left= -2      rigth= -4--2--0 = -2
                if(left == sumTotal - left - nums[j]){
                    return j;
                }
                left += nums[j];
            }
            return -1;
        }
        // nyx's solution
        int pivotIndex1(vector<int>& nums) {
            int leftSum = 0;
            int rightSum = 0;

            for(int number : nums) {
                rightSum += number;
            }

            for(int i = 0; i < nums.size(); i++) {
                rightSum -= nums[i];
                if(leftSum == rightSum) {
                    return i;
                }
                leftSum += nums[i];
            }
            return -1;
        }
};

int main() {
    //1,2,3 OUTPUT: -1      2,1,-1 OUTPUT: 0
    vector<int> nums = {1,7,3,6,5,6};   // output: 3
    int res;

    Solution sol;

    auto start = high_resolution_clock::now();
    res = sol.pivotIndex1(nums);
    auto stop = high_resolution_clock::now();

    duration<double, std::milli> float_ms = stop - start;
    auto int_ms = duration_cast<milliseconds>(stop - start);

    std::cout << "Output: ";
    std::cout << res;
    std::cout << std::endl;
    std::cout << "Time is " << float_ms.count() << "ms " <<"(" << int_ms.count() << " milliseconds)" << std::endl;

    return 0;
}