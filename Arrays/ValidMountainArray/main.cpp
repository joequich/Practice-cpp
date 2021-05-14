#include <iostream>
#include <vector>

using std::vector;
using std::cout;

class Solution {
public:
    // my solution
    bool validMountainArray(vector<int>& arr) {
        if (arr.size() < 3) return false;

        int top = 0;
        // 2; 1 < 2; i++
        for (int i = 1; i < arr.size() - 1; i++) {
            if (top == 0 && arr[i - 1] >= arr[i]) return false;
            if (top != 0 && arr[i] <= arr[i + 1]) return false; 
            
            if (arr[i - 1] < arr[i] && arr[i] > arr[i+1]) {
                top++;
            }
        }

        if (top == 1) {
            return true;
        }

        return false;
    };
    // nyx's solution
    bool validMountainArray1(vector<int>& arr) {
        int hiker = 1;
        bool goingUphill = false;

        if (arr.size() < 3) {
           return false;
        }
        // uuppp
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i - 1] < arr[i]) {
                hiker++;
                if (goingUphill == false) {
                    goingUphill = true;
                }
            } else {
                break;
            }
        }
        // check array
        if (hiker == arr.size() || goingUphill == false) {
            return false;
        }
        // down
        for (int i = hiker; i < arr.size(); i++) {
            if (arr[i - 1] > arr[i]) {
                hiker++;
            } else {
                return false;
            }
        }

        return true;
    };
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> v6 = {0,3,2,1}; // true
    bool res6;

    Solution sol;

    res6 = sol.validMountainArray(v6);
    
    cout << "V6: " << res6 << "\n";
    
    return 0;
}