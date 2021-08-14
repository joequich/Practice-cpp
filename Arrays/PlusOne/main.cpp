#include <iostream>
#include <vector>
#include <chrono>

using std::vector;
using namespace std::chrono;

class Solution {
public:
    // my solution
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size() - 1;
        while(i >= 0) {
            if(i == 0 && digits[i] == 9) {
                digits[i] = 0;
                digits.insert(digits.begin(),1);
            } else if(i != 0 && digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                i=0;
            }
            i--;
        }
        return digits;
    }
    // nyx's solution
    vector<int> plusOne1(vector<int>& digits) {
        int countNines = 0;
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] == 9) {
                digits[i] = 0;
                countNines++;
            } else if (digits[i] != 9) {
                digits[i] += 1;
                break;
            }
        }
        if(countNines == digits.size()) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
    // nyx's solution
    vector<int> plusOne2(vector<int>& digits) {
        for(int i = digits.size() - 1; i >= 0; i--) {
            if(digits[i] == 9) {
                digits[i] = 0;
            } else if(digits[i] != 9) {
                digits[i] += 1;
                return digits;
            }
        }

        vector<int> newDigits (digits.size() + 1);
        newDigits[0] = 1;

        for(int i = 0; i < digits.size(); i++) {
            newDigits[i + 1] = 0;
        }
        return newDigits;
    }
};

int main() {
    vector<int> nums = {9,9,9};
    vector<int> res;

    Solution sol;

    auto start = high_resolution_clock::now();
    res = sol.plusOne2(nums);
    auto stop = high_resolution_clock::now();

    duration<double, std::milli> float_ms = stop - start;
    auto int_ms = duration_cast<milliseconds>(stop - start);

    std::cout << "Output: ";
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i];
        if (i != res.size()-1) {
            std::cout << ",";
        }
    }
    std::cout << std::endl;
    std::cout << "Time is " << float_ms.count() << "ms " <<"(" << int_ms.count() << " milliseconds)" << std::endl;
    return 0;
}