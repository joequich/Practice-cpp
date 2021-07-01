#include <iostream>
#include <vector>
#include <set>
#include <chrono>

using std::vector;
using std::set;
using std::cout;
using std::endl;
using namespace std::chrono;

class Solution {
public:
    // nyx's solution
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> countValues(nums.size(), 0);
        vector<int> missingValues;

        for (int i = 0; i < nums.size(); i++) {
            countValues[nums[i] - 1]++;
        }

        for (int i = 0; i < countValues.size(); i++) {
            if (countValues[i] == 0) {
                missingValues.push_back(i + 1);
            }
        }
        return missingValues;
    }
    // nyx's solution
    vector<int> findDisappearedNumbers1(vector<int>& nums) { // 4,3,2,7,8,2,3,1
        /* Turn the index value of all numbers present in the array negative 
        as a way to record what values are present */
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0 && nums[nums[i] - 1] > 0) {
                nums[nums[i] - 1] = - nums[nums[i] - 1];
            } else if (nums[i] < 0 && nums[-nums[i] - 1] > 0) {
                nums[-nums[i] - 1] = - nums[-nums[i] - 1];
            }
        }
        // Adjust array to put the values NOT present in the original array in front
        int negCount = 0;
        for (int i = 0; i < nums.size(); i++) { // -4,-3,-2,-7,8,2,-3,-1
            if (nums[i] < 0) {
                negCount++;
            } else {
                nums[i - negCount] = i + 1;
            }
        }

        nums.resize(nums.size() - negCount);

        return nums;
    }
};

int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};
    vector<int> res;

    Solution sol;

    auto start = high_resolution_clock::now();
    res = sol.findDisappearedNumbers1(nums);
    auto stop = high_resolution_clock::now();

    duration<double, std::milli> float_ms = stop - start;
    auto int_ms = duration_cast<milliseconds>(stop - start);

    cout << "Output: ";
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        if (i != res.size()-1) {
            cout << ",";
        }
    }
    cout << endl;
    cout << "Time is " << float_ms.count() << "ms " <<"(" << int_ms.count() << " milliseconds)" << endl;

    return 0;
}