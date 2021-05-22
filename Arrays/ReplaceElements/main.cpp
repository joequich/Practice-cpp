#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    // my solution
    vector<int> replaceElements(vector<int>& arr) {
        int current = 0;
        for (int i = arr.size() - 1; i > 0; i--) {
            current = arr[i-1];
            arr[i-1] = arr[arr.size() - 1];

            if (current > arr[arr.size() - 1]) {
                arr[arr.size() - 1] = current;
            }
        }
        arr[arr.size() - 1] = -1;
        return arr;
    };
    // nyx's solution
    vector<int> replaceElements1(vector<int>& arr) {
        int maxNumber = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            for (int j = i + 1; j < arr.size(); j++) {
                if (arr[j] > maxNumber) {
                    maxNumber = arr[j];
                }
            }
            arr[i] = maxNumber;
            maxNumber = 0;
        }
        arr[arr.size() - 1] = -1;
        return arr;
    };
    // nyx's solution
    vector<int> replaceElements2(vector<int>& arr) {
        int maxNumber = -1;
        for (int i = arr.size() - 1; i >= 0; i--) {
            int currentNumber = arr[i];
            arr[i] = maxNumber;

            if (currentNumber > maxNumber) {
                maxNumber = currentNumber;
            }
        }
        return arr;
    };
};

int main() {
    /*
        [17,18,5,4,6,1] => [18,6,6,6,1,-1];
        [17,18,5,4,3,1] => [18,5,4,3,1,-1];
        [17,18,5,6,9,10] => [18,10,10,10,10,-1];
        [17,30,5,20,9,10] => [30,20,20,10,10,-1];
        [100] => [-1];
    */
    vector<int> v = {17,18,5,4,6,1};
    vector<int> res;

    Solution sol;
    res = sol.replaceElements2(v);

    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i];

        if (i != res.size()-1) {
            std::cout << ",";
        }
    }
    return 0;
}