#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>

using std::vector;
using std::cout;
using std::map;
using std::unordered_map;

class Solution {
public:
    // my solution
    bool checkIfExist(vector<int>& arr) {
        int length = arr.size();
        
        for (int i = 0; i < length; i++) {
            for (int j = length - 1; j > i; j--) {
                if (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i]) {
                    return true;
                }
            }
        }
        return false;
    };
    // nyx's solution
    bool checkIfExist1(vector<int>& arr) {
        // [7,1,14,11]
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[i] == 2 * arr[j] || arr[j] == 2 * arr[i]) {
                    return true;
                }
            }
        }
        return false;
    };
    // nyx's solution
    bool checkIfExist2(vector<int>& arr) {
        map<int, int> valueCount; // with map,complexity is logarithmic

        for (int i = 0; i < arr.size(); i++) {
            valueCount[arr[i]]++;
        }

        if (valueCount[0] > 1) {
            return true;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                i++;
            } else {
                if (valueCount.find(2*arr[i]) != valueCount.end()) {
                    return true;
                }
            }
        }
        
        return false;
    };
    // nyx's solution
    bool checkIfExist3(vector<int>& arr) {
        unordered_map<int, int> valueCount; // with unordered_map, complexity is constant

        for (int i = 0; i < arr.size(); i++) {
            valueCount[arr[i]]++;
        }

        if (valueCount[0] > 1) {
            return true;
        }

        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] == 0) {
                i++;
            } else {
                if (valueCount.find(2*arr[i]) != valueCount.end()) {
                    return true;
                }
            }
        }
        
        return false;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> v = {7,1,14,11};
    bool res;

    Solution sol;
    
    res = sol.checkIfExist2(v);
    
    cout << res;
    
    return 0;
}