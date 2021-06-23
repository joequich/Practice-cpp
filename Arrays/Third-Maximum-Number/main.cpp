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
    int thirdMax(vector<int>& nums) {
        set<int> orderedNumbers;
        for (int number : nums) {
            orderedNumbers.insert(number);
        }

        if (orderedNumbers.size() < 3) {
            return *(orderedNumbers.rbegin());
        } else {
            return *(next(orderedNumbers.end(), -3));
        }
    }
    // nyx's solution
    int thirdMax1(vector<int>& nums) {
        long long maxNumber = -3000000000;
        long long secondMax = -3000000000;
        long long thirdMax = -3000000000;

        for (int number: nums) {
            // skip duplicates
            if (number <= thirdMax || number == secondMax || number == maxNumber) {
                continue;
            }
            if (number > maxNumber) {
                thirdMax = secondMax;
                secondMax = maxNumber;
                maxNumber = number;
            } 
            else if (number < maxNumber && number > secondMax) {
                thirdMax = secondMax;
                secondMax = number;
            }
            else if (number < secondMax && number > thirdMax) {
                thirdMax = number;
            }
        }
        return thirdMax == -3000000000 ? maxNumber : thirdMax;
    }
    // nyx's solution
    int thirdMax2(vector<int>& nums) {
        long long maxNumber = LLONG_MIN;
        long long secondMax = LLONG_MIN;
        long long thirdMax = LLONG_MIN;
        int tempHolder;

        for (int number: nums) {
            // skip duplicates
            if (number <= thirdMax || number == secondMax || number == maxNumber) {
                continue;
            }
            thirdMax = number;
            if (thirdMax > secondMax) {
                tempHolder = thirdMax;
                thirdMax = secondMax;
                secondMax = tempHolder;
            } 
            if (secondMax > maxNumber) {
                tempHolder = secondMax;
                secondMax = maxNumber;
                maxNumber = tempHolder;
            }
        }
        return thirdMax == LLONG_MIN ? maxNumber : thirdMax;
    }
};

int main() {
    vector<int> nums = {2,2,3,1,4,7,7};
    int res;

    Solution sol;

    auto start = high_resolution_clock::now();
    res = sol.thirdMax1(nums);
    auto stop = high_resolution_clock::now();

    duration<double, std::milli> float_ms = stop - start;
    auto int_ms = duration_cast<milliseconds>(stop - start);

    cout << "Output: " << res << endl;
    cout << "Time is " << float_ms.count() << "ms " <<"(" << int_ms.count() << " milliseconds)" << endl;

    return 0;
}