#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

class Solution {
public:
    vector<int> merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0; i < nums2.size(); i++) {
            nums1[m+i] = nums2[i];
        }
        
        std::sort(nums1.begin(), nums1.end());
        
        return nums1;
    };
    vector<int> merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> newArr(m + n);
        int indexNums1 = 0;
        int indexNums2 = 0;
        int indexNewArr = 0;
        
        while (indexNums1 < m && indexNums2 < n) {
            if (nums1[indexNums1] < nums2[indexNums2]) {
                newArr[indexNewArr] = nums1[indexNums1];
                indexNums1++;
                indexNewArr++;
            } else {
                newArr[indexNewArr] = nums2[indexNums2];
                indexNums2++;
                indexNewArr++;
            }
        }
        
        while (indexNums1 < m) {
            newArr[indexNewArr] = nums1[indexNums1];
            indexNums1++;
            indexNewArr++;
        }
        
        while (indexNums2 < n) {
            newArr[indexNewArr] = nums2[indexNums2];
            indexNums2++;
            indexNewArr++;
        }
        
        nums1 = newArr;
        
        return nums1;
    };
    
    vector<int> merge3(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (m == 0) {
            nums1 = nums2;
        }
        
        int nums1Index = m - 1; // 2
        int nums2Index = n - 1; // 2
        int enteredIndex = m + n - 1; //5
        
        while (nums1Index >= 0 && nums2Index >= 0) {
            if (nums1[nums1Index] > nums2[nums2Index]) {
                nums1[enteredIndex] = nums1[nums1Index];
                nums1Index--;
                enteredIndex--;
            } else {
                nums1[enteredIndex] = nums2[nums2Index];
                nums2Index--;
                enteredIndex--;
            }
        }
        
        while (nums2Index >= 0) {
            nums1[enteredIndex] = nums2[nums2Index];
            nums2Index--;
            enteredIndex--;
        }
        
        return nums1;
    };
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    // nums1 = [4,5,6,0,0,0], m = 3, nums2 = [1,3,5], n = 3
//    vector<int> nums1 = {4,5,6,0,0,0};
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3;
    int n = 3;
    
    vector<int> res;
    Solution sol;
    
//    res = sol.merge1(nums1, m, nums2, n);
    res = sol.merge3(nums1, m, nums2, n);
    
    for (int i = 0; i < res.size(); i++) {
        std::cout << res[i] << ",";
    }
    
    return 0;
}
