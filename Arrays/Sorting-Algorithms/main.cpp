#include <iostream>
#include <vector>
#include <chrono>

using std::vector;
using std::cout;
using std::endl;
using namespace std::chrono;

class Algorithms {
public:
    vector<int> bubbleSort(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            for (int j = nums.size() - 1; j > i; j--) {
                if (nums[j] < nums[j - 1]) {
                    int tmp = nums[j - 1];
                    nums[j - 1] = nums[j];
                    nums[j] = tmp;
                }
            }
        }
        return nums;
    };
    vector<int> bubbleSortOpt(vector<int>& nums) {
        bool desorden;
        do {
            desorden = false;
            for (int j = nums.size() - 1; j > 0; j--) {
                if (nums[j] < nums[j - 1]) {
                    int tmp = nums[j - 1];
                    nums[j - 1] = nums[j];
                    nums[j] = tmp;
                    desorden = true;
                }
            }
        } while (desorden);
        
        return nums;
    };
    vector<int> selectionSort(vector<int>& nums) {
        for (int i = 0; i < nums.size() - 1; i++) {
            int min = i;
            for (int j = i + 1; j < nums.size(); j++) {
                if (nums[j] < nums[min]) {
                    min = j;
                }
            }
            int temp = nums[i];
            nums[i] = nums[min];
            nums[min] = temp;
        }
        
        return nums;
    };
    vector<int> insertionSort(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            int pos = i - 1;
            int value = nums[i];
            while (pos >= 0 && nums[pos] > value) {
                nums[pos+1] = nums[pos];
                pos--;
            }
            nums[pos+1] = value;
        }
        return nums;
    };
};

int main() {
    
    // vector<int> nums = {1,2,3,6,7,4,5,9,6,5,3,2,4,7,8,6,4,5,7,8,7,5,3,0,2,4,6,7,8};
    vector<int> nums = {2,2,3,1};
    
    vector<int> sortedNums;

    Algorithms alg;

    auto start = high_resolution_clock::now();
    sortedNums = alg.insertionSort(nums);
    auto stop = high_resolution_clock::now();

    duration<double, std::milli> float_ms = stop - start;
    auto int_ms = duration_cast<milliseconds>(stop - start);

    cout << "Time is " << float_ms.count() << "ms " <<"(" << int_ms.count() << " milliseconds)" << endl;

    for (int i = 0; i < sortedNums.size(); i++) {
        cout << sortedNums[i];
        if (i != sortedNums.size()-1) {
            cout << ",";
        }
    }
    return 0;
}