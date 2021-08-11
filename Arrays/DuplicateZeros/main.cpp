#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> duplicateZeros1(std::vector<int>& arr) {
        for (int i = 0; i < arr.size(); i++) {
            if(arr[i] == 0) {
                for (int j = arr.size() - 2; j >= i; j--) {
                    arr[j+1] = arr[j];
                }
                i++;
            }
        }
        return arr;
    };
    std::vector<int> duplicateZeros2(std::vector<int>& arr) {
        std::vector<int> dupZero;
        int counter = 0;
        for (int i = 0; counter < arr.size(); i++) {
            if(arr[i] == 0) {
                dupZero.push_back(arr[i]);
                counter++;
                if(counter < arr.size()) {
                    dupZero.push_back(arr[i]);
                    counter++;
                }
            } else if (arr[i] != 0) {
                dupZero.push_back(arr[i]);
                counter++;
            }
        }
        arr = dupZero;
        return arr;
    };
    // nyx's solution
    std::vector<int> duplicateZeros3(std::vector<int>& arr) {
        int countZerosToDup = 0;
        int counterZeros = 0;
        for (int i = 0; i < arr.size() - countZerosToDup; i++) {
            if (arr[i] == 0 && i != arr.size() - 1 - countZerosToDup) {
                countZerosToDup++;
            }
            if (arr[i] == 0) {
                counterZeros++;
            }
        }
        
        for (int i = arr.size() - 1 - countZerosToDup; countZerosToDup > 0; i--) {
            // handles starting zero by shifting
            if (i == arr.size() - 1 - countZerosToDup && arr[i] == 0 && counterZeros != countZerosToDup) {
                arr[i + countZerosToDup] = 0;
            } // handles non-zero values 
            else if (arr[i] != 0) {
                arr[i + countZerosToDup] = arr[i];
            } // handles duplicating zeros 
            else {
                arr[i + countZerosToDup] = 0;
                arr[i + countZerosToDup - 1] = 0;
                countZerosToDup--;
            }
        }
        
   
        return arr;
    };
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::vector<int> v = {1,0,2,3,0,4,5,0};
    std::vector<int> res;

    Solution sol;
    
//    res = sol.duplicateZeros1(v);
    res = sol.duplicateZeros3(v);
    
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << ",";
    }
    
//    std::cout << "Hello, World!\n";
    return 0;
}